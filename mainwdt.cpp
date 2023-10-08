#include "mainwdt.h"
#include "ui_mainwdt.h"
#include <QApplication>
#include <QMutexLocker>
#include <QHostAddress>
#include <QDateTime>
#include "easylogging++.h"
#pragma execution_character_set("utf-8")
// ��ʾ��־
#define LOG_MAX_COUNT 1024

MainWdt::MainWdt(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWdt)
    , m_tcpSrv(nullptr)
    , m_tcpCli(nullptr)
    , m_udp(nullptr)
{
    ui->setupUi(this);
    // ����UI����
    auto title = X("������Թ���v%1").arg(PROGRAM_VER);
    setWindowTitle(title);
    // ������ʾ��־�������
    ui->UdpLog->setMaximumBlockCount(LOG_MAX_COUNT);
    ui->TcpServerLog->setMaximumBlockCount(LOG_MAX_COUNT);
    ui->TcpClientLog->setMaximumBlockCount(LOG_MAX_COUNT);
    ui->UdpLog->setReadOnly(true);
    ui->TcpServerLog->setReadOnly(true);
    ui->TcpClientLog->setReadOnly(true);
    // ��ʼ��
    m_udp = new QUdpSocket();
    m_tcpSrv = new QTcpServer();
    m_tcpCli = new QTcpSocket();
    // ���ź����
    connect(m_udp, &QUdpSocket::readyRead, this, &MainWdt::onHaveUdpPendingData);
    connect(m_tcpCli, &QTcpSocket::readyRead, this, &MainWdt::onHaveTcpClientPendingData);
    connect(m_tcpSrv, &QTcpServer::newConnection, this, &MainWdt::onHaveTcpServerPendingData);
    connect(m_tcpCli, &QTcpSocket::stateChanged, this, &MainWdt::onTcpClientStateChanged);
    // ��ʾ��Ϣ��
    connect(this, &MainWdt::appendUdpLog, this, &MainWdt::onAppendUdpLog);
    connect(this, &MainWdt::appendTcpSrvLog, this, &MainWdt::onAppendTcpSrvLog);
    connect(this, &MainWdt::appendTcpCliLog, this, &MainWdt::onAppendTcpCliLog);
}

MainWdt::~MainWdt()
{
    delete ui;
    if(m_udp)
    {
        m_udp->close();
        m_udp->deleteLater();
    }
    if(m_tcpSrv)
    {
        m_tcpSrv->close();
        m_tcpSrv->deleteLater();
    }
    if(m_tcpCli)
    {
        m_tcpCli->close();
        m_tcpCli->deleteLater();
    }
    while(m_tcpConnList.size() > 0)
    {
        auto client = m_tcpConnList.takeFirst();
        client->deleteLater();
        client = nullptr;
    }
}

void MainWdt::onHaveUdpPendingData()
{
    QMutexLocker loker(&m_mutex);
    // ��ȡ
    QByteArray data;
    data.resize(m_udp->pendingDatagramSize());
    QHostAddress remoteAddr;
    quint16 remotePort;
    auto ok = m_udp->readDatagram(data.data(), data.size(), &remoteAddr, &remotePort);
    if(ok <= 0)
    {
        emit appendUdpLog(X("��ȡ�����쳣!"));
        return;
    }
    else
    {
        ui->leUdpRemoteIP->setText(remoteAddr.toString());
        ui->leUdpRemotePort->setText(QString::number(remotePort));
        if(DataType::Hex == getUdpDataType())
        {
            // HEX
            emit appendUdpLog(X("���յ�����:"));
            emit appendUdpLog(data.toHex().toUpper());
        }
        else
        {
            // ASCII
            emit appendUdpLog(X("���յ�����:"));
            emit appendUdpLog(data);
        }
    }
}

void MainWdt::onHaveTcpClientPendingData()
{
    QMutexLocker loker(&m_mutex);
    emit appendTcpCliLog(X("[�����]:"));
    auto data = m_tcpCli->readAll();
    auto dataType = getTcpClientDataType();
    if(DataType::Hex == dataType)
    {
        auto fromHex = QByteArray::fromHex(data);
        emit appendTcpCliLog(fromHex);
    }
    else
    {
        emit appendTcpCliLog(data);
    }
}

void MainWdt::onHaveTcpServerPendingData()
{
    QMutexLocker loker(&m_mutex);
    while(m_tcpSrv->hasPendingConnections())
    {
        auto newConnector = m_tcpSrv->nextPendingConnection();
        auto log = X("�յ�������:[%1:%2]")
                   .arg(newConnector->peerAddress().toString())
                   .arg(newConnector->peerPort());
        emit appendTcpSrvLog(log);
        // �󶨴�����Ϣ
        connect(newConnector, &QTcpSocket::readyRead, this, [this, newConnector]()
        {
            // emit this->appendTcpSrvLog("QTcpSocket::readyRead");
            emit this->appendTcpSrvLog(X("�ͻ���[%1:%2]:").arg(newConnector->peerAddress().toString()).arg(newConnector->peerPort()));
            auto data = newConnector->readAll();
            if(data.isEmpty())
            {
                emit this->appendTcpSrvLog(X("����Ϊ��!"));
                return;
            }
            else
            {
                auto dataType = this->getTcpServerDataType();
                if(DataType::Hex == dataType)
                {
                    auto fromHex = QByteArray::fromHex(data);
                    emit this->appendTcpSrvLog(data);
                }
                else
                {
                    emit this->appendTcpSrvLog(data);
                }
            }
            // �ظ��յ�����:��ǰʱ��
            auto rst = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz").toLocal8Bit();
            newConnector->write(rst);
            newConnector->flush();
        });
        // �������µĿͻ���
        m_tcpConnList.append(newConnector);
    }
}

void MainWdt::onAppendUdpLog(const QString &log)
{
    if(log.isEmpty())
    {
        return;
    }
    LOG(INFO) << "[UDP]:" << log;
    ui->UdpLog->appendPlainText(log);
    ui->UdpLog->moveCursor(QTextCursor::End);
}

void MainWdt::onAppendTcpSrvLog(const QString &log)
{
    if(log.isEmpty())
    {
        return;
    }
    LOG(INFO) << "[TCP SERVRT]:" << log;
    ui->TcpServerLog->appendPlainText(log);
    ui->TcpServerLog->moveCursor(QTextCursor::End);
}

void MainWdt::onAppendTcpCliLog(const QString &log)
{
    if(log.isEmpty())
    {
        return;
    }
    LOG(INFO) << "[TCP CLIENT]:" << log;
    ui->TcpClientLog->appendPlainText(log);
    ui->TcpClientLog->moveCursor(QTextCursor::End);
}

void MainWdt::onTcpClientStateChanged(QAbstractSocket::SocketState state)
{
    switch(state)
    {
        case QAbstractSocket::ConnectingState:
            // ������
            emit appendTcpCliLog(X("�������ӹܿ�ϵͳ..."));
            break;
        case QAbstractSocket::ConnectedState:
            // ���ӳɹ�
            emit appendTcpCliLog(X("���ӹܿ�ϵͳ�ɹ�!"));
            ui->btnTcpClientConn->setText(X("�Ͽ�"));
            break;
        case QAbstractSocket::ClosingState:
            // �Ͽ���
            emit appendTcpCliLog(X("���ڶϿ��ܿ�ϵͳ����..."));
            break;
        case QAbstractSocket::UnconnectedState:
            // �Ͽ��ɹ�
            emit appendTcpCliLog(X("�ѶϿ��ܿ�ϵͳ����!"));
            ui->btnTcpClientConn->setText(X("����"));
            break;
        default:
            break;
    }
}

MainWdt::DataType MainWdt::getUdpDataType() const
{
    auto type = ui->cbUdpData->currentText();
    if(type.compare("HEX", Qt::CaseInsensitive) == 0)
    {
        return DataType::Hex;
    }
    else
    {
        return DataType::Ascii;
    }
}

MainWdt::DataType MainWdt::getTcpClientDataType() const
{
    auto type = ui->cbTcpClient->currentText();
    if(type.compare("HEX", Qt::CaseInsensitive) == 0)
    {
        return DataType::Hex;
    }
    else
    {
        return DataType::Ascii;
    }
}

MainWdt::DataType MainWdt::getTcpServerDataType() const
{
    auto type = ui->cbTcpServer->currentText();
    if(type.compare("HEX", Qt::CaseInsensitive) == 0)
    {
        return DataType::Hex;
    }
    else
    {
        return DataType::Ascii;
    }
}

void MainWdt::on_btnTcpClientSend_clicked()
{
    QMutexLocker loker(&m_mutex);
    auto dataType = getTcpClientDataType();
    auto data = ui->leTcpClientData->text().trimmed();
    if(data.isEmpty())
    {
        emit appendTcpCliLog(X("�������ݲ���Ϊ��!"));
        return;
    }
    QByteArray ba;
    if(dataType == DataType::Ascii)
    {
        ba = data.toLocal8Bit();
    }
    else
    {
        ba =  QByteArray::fromHex(data.toLocal8Bit());
    }
    // ��������
    if(m_tcpCli->state() == QTcpSocket::ConnectedState)
    {
        auto log = X("��������:") + ba;
        emit appendTcpCliLog(log);
        auto ok = (m_tcpCli->write(ba) > 0 && m_tcpCli->flush());
        log = (ok ? X("���ͳɹ�!") : X("����ʧ��!"));
        emit appendTcpCliLog(log);
    }
    else
    {
        emit appendTcpCliLog(X("TCP�ͻ�������״̬�쳣!"));
    }
}


void MainWdt::on_btnTcpServerSend_clicked()
{
    QMutexLocker loker(&m_mutex);
    auto dataType = getTcpServerDataType();
    auto data = ui->leTcpServerData->text().trimmed();
    if(data.isEmpty())
    {
        emit appendTcpSrvLog(X("�������ݲ���Ϊ��!"));
        return;
    }
    QByteArray ba;
    if(dataType == DataType::Ascii)
    {
        ba = data.toLocal8Bit();
    }
    else
    {
        ba = QByteArray::fromHex(data.toLocal8Bit());
    }
    // ״̬�ж�
    if(m_tcpSrv->isListening())
    {
        // �ж����ӿͻ��˸���
        if(m_tcpConnList.isEmpty()) {return;}
        // ��������
        for(auto it = m_tcpConnList.begin(); it != m_tcpConnList.end(); it++)
        {
            auto ok = it.i->t()->write(ba);
            it.i->t()->flush();
            auto addr = it.i->t()->localAddress();
            auto port = it.i->t()->localPort();
            auto log = X("%1:%2:����%3�ֽ�").arg(addr.toString()).arg(port).arg(ok);
            emit appendTcpSrvLog(log);
        }
    }
    else
    {
        emit appendTcpSrvLog(X("TCP���������״̬�쳣!"));
    }
}

void MainWdt::on_btnUdpSend_clicked()
{
    QMutexLocker loker(&m_mutex);
    auto dataType = getUdpDataType();
    auto data = ui->leUdpSendData->text().trimmed();
    auto ip = ui->leUdpRemoteIP->text().trimmed();
    auto port = ui->leUdpRemotePort->text().toInt();
    if(ip.isEmpty() || port <= 0)
    {
        emit appendUdpLog(X("Զ��UDP��ַ�쳣!"));
        return;
    }
    if(data.isEmpty())
    {
        emit appendUdpLog(X("�������ݲ���Ϊ��!"));
        return;
    }
    QByteArray ba;
    if(dataType == DataType::Ascii)
    {
        ba = data.toLocal8Bit();
    }
    else
    {
        ba = QByteArray::fromHex(data.toLocal8Bit());
    }
    // �ж�UDP״̬
    if(m_udp->isValid())
    {
        auto ok = m_udp->writeDatagram(ba, QHostAddress(ip), port);
        emit appendUdpLog(X("����IP:%1,�˿�:%2,�ֽڴ�С:%3").arg(ip).arg(port).arg(ok));
        if(ok == -1)
        {
            // ����ʧ��
            auto log = X("����ʧ��:") + m_udp->errorString();
            emit appendUdpLog(log);
        }
        else
        {
            emit appendUdpLog(X("���ͳɹ�!"));
        }
    }
    else
    {
        emit appendUdpLog(X("UDP״̬�쳣!"));
    }
}


void MainWdt::on_btnTcpClientConn_clicked()
{
    if(m_tcpCli->state() == QTcpSocket::ConnectedState)
    {
        // �Ͽ�����
        m_tcpCli->disconnectFromHost();
        emit appendTcpCliLog(X("�Ͽ�����"));
    }
    else
    {
        // ����
        auto ip = ui->leTcpClientIp->text().trimmed();
        auto port = ui->leTcpClientPort->text().toInt();
        m_tcpCli->connectToHost(ip, port);
        // �ȴ�����
        if(m_tcpCli->waitForConnected(2000))
        {
            // ���ӳɹ�
            emit appendTcpCliLog(X("���ӳɹ�!"));
        }
        else
        {
            //����ʧ��
            emit appendTcpCliLog(X("����ʧ��!"));
        }
    }
}

void MainWdt::on_btnTcpServerListen_clicked()
{
    if(m_tcpSrv->isListening())
    {
        // �Ͽ�����
        m_tcpSrv->close();
        emit appendTcpSrvLog(X("�ر�TCP����!"));
        // ɾ�����ӵĿͻ���
        while(!m_tcpConnList.isEmpty())
        {
            auto it = m_tcpConnList.takeFirst();
            it->close();
            it->deleteLater();
        }
        ui->btnTcpServerListen->setText(X("��������"));
    }
    else
    {
        auto port = ui->leTcpServerPort->text().toInt();
        // �����˿�
        if(m_tcpSrv->listen(QHostAddress::Any, port))
        {
            emit appendTcpSrvLog(X("����TCP����ɹ�:%1").arg(port));
            ui->btnTcpServerListen->setText(X("ֹͣ����"));
        }
        else
        {
            emit appendTcpSrvLog(X("����TCP����ʧ��:%1").arg(m_tcpSrv->errorString()));
            ui->btnTcpServerListen->setText(X("��������"));
        }
    }
}

void MainWdt::on_btnUdpBind_clicked()
{
    auto port = ui->leUdpPort->text().toInt();
    if(m_udp->bind(QHostAddress::Any, port))
    {
        emit appendUdpLog(X("��UDP�˿�:%1").arg(port));
    }
    else
    {
        emit appendUdpLog(X("��UDP�˿�ʧ��!"));
    }
}

void MainWdt::on_btnUdpUnbind_clicked()
{
    m_udp->abort();
    emit appendUdpLog(X("���UDP�˿�!"));
}

void MainWdt::on_btnTcpClientClrLog_clicked()
{
    ui->TcpClientLog->clear();
}

void MainWdt::on_btnTcpServerClrLog_clicked()
{
    ui->TcpServerLog->clear();
}

void MainWdt::on_btnUdpClrLog_clicked()
{
    ui->UdpLog->clear();
}

