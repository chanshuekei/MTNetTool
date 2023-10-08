#ifndef MAINWDT_H
#define MAINWDT_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QMutex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWdt; }
QT_END_NAMESPACE

class MainWdt : public QWidget
{
    Q_OBJECT
    enum DataType
    {
        Ascii,
        Hex,
    };
public:
    MainWdt(QWidget *parent = nullptr);
    ~MainWdt();

signals:
    void appendUdpLog(QString);
    void appendTcpSrvLog(QString);
    void appendTcpCliLog(QString);
private slots:
    void onHaveUdpPendingData();        // ����UDP��Ϣ����
    void onHaveTcpClientPendingData();  // ����TCP�ͻ�����Ϣ����
    void onHaveTcpServerPendingData();  // ����TCP�������Ϣ����
    void on_btnTcpClientSend_clicked(); // ����TCP�ͻ�����Ϣ����
    void on_btnTcpServerSend_clicked(); // ����TCP�������Ϣ����
    void on_btnUdpSend_clicked();       // ����UDP��Ϣ����
    void on_btnTcpClientConn_clicked(); // TCP�ͻ������ӷ����
    void on_btnTcpServerListen_clicked();   // TCP�������������
    void on_btnUdpBind_clicked();           // UDP�󶨶˿�
    void on_btnUdpUnbind_clicked();         // UDP���˿�
    void on_btnTcpClientClrLog_clicked();   // ����TCP�ͻ�����־
    void on_btnTcpServerClrLog_clicked();   // ����TCP�������־
    void on_btnUdpClrLog_clicked();     // ����UDP��־

protected slots:
    void onAppendUdpLog(const QString &log);
    void onAppendTcpSrvLog(const QString &log);
    void onAppendTcpCliLog(const QString &log);
    // TCP�ͻ���״̬����
    void onTcpClientStateChanged(QAbstractSocket::SocketState state);
public:
    DataType getUdpDataType() const;
    DataType getTcpClientDataType() const;
    DataType getTcpServerDataType() const;
private:
    Ui::MainWdt *ui;
    QMutex m_mutex;
    QTcpServer *m_tcpSrv;
    QTcpSocket *m_tcpCli;
    QUdpSocket *m_udp;
    QList<QTcpSocket *> m_tcpConnList;
};
#endif // MAINWDT_H
