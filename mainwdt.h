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
    void onHaveUdpPendingData();        // 处理UDP信息数据
    void onHaveTcpClientPendingData();  // 处理TCP客户端信息数据
    void onHaveTcpServerPendingData();  // 处理TCP服务端信息数据
    void on_btnTcpClientSend_clicked(); // 发送TCP客户端信息数据
    void on_btnTcpServerSend_clicked(); // 发送TCP服务端信息数据
    void on_btnUdpSend_clicked();       // 发送UDP信息数据
    void on_btnTcpClientConn_clicked(); // TCP客户端连接服务端
    void on_btnTcpServerListen_clicked();   // TCP服务端启动监听
    void on_btnUdpBind_clicked();           // UDP绑定端口
    void on_btnUdpUnbind_clicked();         // UDP解绑端口
    void on_btnTcpClientClrLog_clicked();   // 清理TCP客户端日志
    void on_btnTcpServerClrLog_clicked();   // 清理TCP服务端日志
    void on_btnUdpClrLog_clicked();     // 清理UDP日志

protected slots:
    void onAppendUdpLog(const QString &log);
    void onAppendTcpSrvLog(const QString &log);
    void onAppendTcpCliLog(const QString &log);
    // TCP客户端状态处理
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
