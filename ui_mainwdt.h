/********************************************************************************
** Form generated from reading UI file 'mainwdt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWDT_H
#define UI_MAINWDT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWdt
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabTcp;
    QHBoxLayout *horizontalLayout;
    QGroupBox *gbTcpClient;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *laTcpClientIp;
    QLineEdit *leTcpClientIp;
    QHBoxLayout *horizontalLayout_3;
    QLabel *laTcpClientPort;
    QLineEdit *leTcpClientPort;
    QPushButton *btnTcpClientConn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *laTcpClientData;
    QLineEdit *leTcpClientData;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QComboBox *cbTcpClient;
    QPushButton *btnTcpClientSend;
    QPlainTextEdit *TcpClientLog;
    QPushButton *btnTcpClientClrLog;
    QGroupBox *gbTcpService;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *laTcpServerIp;
    QLineEdit *leTcpServerIp;
    QHBoxLayout *horizontalLayout_9;
    QLabel *laTcpServerPort;
    QLineEdit *leTcpServerPort;
    QPushButton *btnTcpServerListen;
    QHBoxLayout *horizontalLayout_10;
    QLabel *laTcpServerData;
    QLineEdit *leTcpServerData;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *cbTcpServer;
    QPushButton *btnTcpServerSend;
    QPlainTextEdit *TcpServerLog;
    QPushButton *btnTcpServerClrLog;
    QWidget *tabUdp;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_3;
    QLineEdit *leUdpPort;
    QPushButton *btnUdpUnbind;
    QPushButton *btnUdpBind;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_5;
    QLineEdit *leUdpRemoteIP;
    QLabel *label_4;
    QLineEdit *leUdpRemotePort;
    QComboBox *cbUdpData;
    QPushButton *btnUdpSend;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_6;
    QLineEdit *leUdpSendData;
    QPlainTextEdit *UdpLog;
    QHBoxLayout *horizontalLayout_29;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnUdpClrLog;

    void setupUi(QWidget *MainWdt)
    {
        if (MainWdt->objectName().isEmpty())
            MainWdt->setObjectName(QString::fromUtf8("MainWdt"));
        MainWdt->resize(1024, 720);
        verticalLayout = new QVBoxLayout(MainWdt);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        tabWidget = new QTabWidget(MainWdt);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabTcp = new QWidget();
        tabTcp->setObjectName(QString::fromUtf8("tabTcp"));
        horizontalLayout = new QHBoxLayout(tabTcp);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        gbTcpClient = new QGroupBox(tabTcp);
        gbTcpClient->setObjectName(QString::fromUtf8("gbTcpClient"));
        verticalLayout_3 = new QVBoxLayout(gbTcpClient);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        laTcpClientIp = new QLabel(gbTcpClient);
        laTcpClientIp->setObjectName(QString::fromUtf8("laTcpClientIp"));
        laTcpClientIp->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setPointSize(12);
        laTcpClientIp->setFont(font);

        horizontalLayout_2->addWidget(laTcpClientIp);

        leTcpClientIp = new QLineEdit(gbTcpClient);
        leTcpClientIp->setObjectName(QString::fromUtf8("leTcpClientIp"));
        leTcpClientIp->setMinimumSize(QSize(0, 35));
        leTcpClientIp->setFont(font);

        horizontalLayout_2->addWidget(leTcpClientIp);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        laTcpClientPort = new QLabel(gbTcpClient);
        laTcpClientPort->setObjectName(QString::fromUtf8("laTcpClientPort"));
        laTcpClientPort->setMinimumSize(QSize(0, 35));
        laTcpClientPort->setFont(font);

        horizontalLayout_3->addWidget(laTcpClientPort);

        leTcpClientPort = new QLineEdit(gbTcpClient);
        leTcpClientPort->setObjectName(QString::fromUtf8("leTcpClientPort"));
        leTcpClientPort->setMinimumSize(QSize(80, 35));
        leTcpClientPort->setFont(font);

        horizontalLayout_3->addWidget(leTcpClientPort);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        btnTcpClientConn = new QPushButton(gbTcpClient);
        btnTcpClientConn->setObjectName(QString::fromUtf8("btnTcpClientConn"));
        btnTcpClientConn->setMinimumSize(QSize(120, 35));
        btnTcpClientConn->setFont(font);

        horizontalLayout_4->addWidget(btnTcpClientConn);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        laTcpClientData = new QLabel(gbTcpClient);
        laTcpClientData->setObjectName(QString::fromUtf8("laTcpClientData"));
        laTcpClientData->setMinimumSize(QSize(0, 35));
        laTcpClientData->setFont(font);

        horizontalLayout_5->addWidget(laTcpClientData);

        leTcpClientData = new QLineEdit(gbTcpClient);
        leTcpClientData->setObjectName(QString::fromUtf8("leTcpClientData"));
        leTcpClientData->setMinimumSize(QSize(0, 35));
        leTcpClientData->setFont(font);

        horizontalLayout_5->addWidget(leTcpClientData);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        cbTcpClient = new QComboBox(gbTcpClient);
        cbTcpClient->addItem(QString());
        cbTcpClient->addItem(QString());
        cbTcpClient->setObjectName(QString::fromUtf8("cbTcpClient"));
        cbTcpClient->setMinimumSize(QSize(80, 35));
        cbTcpClient->setFont(font);

        horizontalLayout_6->addWidget(cbTcpClient);

        btnTcpClientSend = new QPushButton(gbTcpClient);
        btnTcpClientSend->setObjectName(QString::fromUtf8("btnTcpClientSend"));
        btnTcpClientSend->setMinimumSize(QSize(100, 35));
        btnTcpClientSend->setFont(font);

        horizontalLayout_6->addWidget(btnTcpClientSend);


        verticalLayout_3->addLayout(horizontalLayout_6);

        TcpClientLog = new QPlainTextEdit(gbTcpClient);
        TcpClientLog->setObjectName(QString::fromUtf8("TcpClientLog"));
        QFont font1;
        font1.setPointSize(10);
        TcpClientLog->setFont(font1);

        verticalLayout_3->addWidget(TcpClientLog);

        btnTcpClientClrLog = new QPushButton(gbTcpClient);
        btnTcpClientClrLog->setObjectName(QString::fromUtf8("btnTcpClientClrLog"));
        btnTcpClientClrLog->setMinimumSize(QSize(100, 35));
        btnTcpClientClrLog->setFont(font);

        verticalLayout_3->addWidget(btnTcpClientClrLog);


        horizontalLayout->addWidget(gbTcpClient);

        gbTcpService = new QGroupBox(tabTcp);
        gbTcpService->setObjectName(QString::fromUtf8("gbTcpService"));
        verticalLayout_2 = new QVBoxLayout(gbTcpService);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        laTcpServerIp = new QLabel(gbTcpService);
        laTcpServerIp->setObjectName(QString::fromUtf8("laTcpServerIp"));
        laTcpServerIp->setMinimumSize(QSize(0, 35));
        laTcpServerIp->setFont(font);

        horizontalLayout_8->addWidget(laTcpServerIp);

        leTcpServerIp = new QLineEdit(gbTcpService);
        leTcpServerIp->setObjectName(QString::fromUtf8("leTcpServerIp"));
        leTcpServerIp->setMinimumSize(QSize(0, 35));
        leTcpServerIp->setFont(font);

        horizontalLayout_8->addWidget(leTcpServerIp);


        horizontalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        laTcpServerPort = new QLabel(gbTcpService);
        laTcpServerPort->setObjectName(QString::fromUtf8("laTcpServerPort"));
        laTcpServerPort->setMinimumSize(QSize(0, 35));
        laTcpServerPort->setFont(font);

        horizontalLayout_9->addWidget(laTcpServerPort);

        leTcpServerPort = new QLineEdit(gbTcpService);
        leTcpServerPort->setObjectName(QString::fromUtf8("leTcpServerPort"));
        leTcpServerPort->setMinimumSize(QSize(80, 35));
        leTcpServerPort->setFont(font);

        horizontalLayout_9->addWidget(leTcpServerPort);


        horizontalLayout_7->addLayout(horizontalLayout_9);

        btnTcpServerListen = new QPushButton(gbTcpService);
        btnTcpServerListen->setObjectName(QString::fromUtf8("btnTcpServerListen"));
        btnTcpServerListen->setMinimumSize(QSize(120, 35));
        btnTcpServerListen->setFont(font);

        horizontalLayout_7->addWidget(btnTcpServerListen);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        laTcpServerData = new QLabel(gbTcpService);
        laTcpServerData->setObjectName(QString::fromUtf8("laTcpServerData"));
        laTcpServerData->setMinimumSize(QSize(0, 35));
        laTcpServerData->setFont(font);

        horizontalLayout_10->addWidget(laTcpServerData);

        leTcpServerData = new QLineEdit(gbTcpService);
        leTcpServerData->setObjectName(QString::fromUtf8("leTcpServerData"));
        leTcpServerData->setMinimumSize(QSize(0, 35));
        leTcpServerData->setFont(font);

        horizontalLayout_10->addWidget(leTcpServerData);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        cbTcpServer = new QComboBox(gbTcpService);
        cbTcpServer->addItem(QString());
        cbTcpServer->addItem(QString());
        cbTcpServer->setObjectName(QString::fromUtf8("cbTcpServer"));
        cbTcpServer->setMinimumSize(QSize(80, 35));
        cbTcpServer->setFont(font);

        horizontalLayout_11->addWidget(cbTcpServer);

        btnTcpServerSend = new QPushButton(gbTcpService);
        btnTcpServerSend->setObjectName(QString::fromUtf8("btnTcpServerSend"));
        btnTcpServerSend->setMinimumSize(QSize(100, 35));
        btnTcpServerSend->setFont(font);

        horizontalLayout_11->addWidget(btnTcpServerSend);


        verticalLayout_2->addLayout(horizontalLayout_11);

        TcpServerLog = new QPlainTextEdit(gbTcpService);
        TcpServerLog->setObjectName(QString::fromUtf8("TcpServerLog"));
        TcpServerLog->setFont(font1);

        verticalLayout_2->addWidget(TcpServerLog);

        btnTcpServerClrLog = new QPushButton(gbTcpService);
        btnTcpServerClrLog->setObjectName(QString::fromUtf8("btnTcpServerClrLog"));
        btnTcpServerClrLog->setMinimumSize(QSize(100, 35));
        btnTcpServerClrLog->setFont(font);

        verticalLayout_2->addWidget(btnTcpServerClrLog);


        horizontalLayout->addWidget(gbTcpService);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        tabWidget->addTab(tabTcp, QString());
        tabUdp = new QWidget();
        tabUdp->setObjectName(QString::fromUtf8("tabUdp"));
        verticalLayout_4 = new QVBoxLayout(tabUdp);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, 5, 5, 5);
        groupBox = new QGroupBox(tabUdp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(35, 35));
        label_3->setFont(font);

        horizontalLayout_12->addWidget(label_3);

        leUdpPort = new QLineEdit(groupBox);
        leUdpPort->setObjectName(QString::fromUtf8("leUdpPort"));
        leUdpPort->setMinimumSize(QSize(35, 35));
        leUdpPort->setFont(font);

        horizontalLayout_12->addWidget(leUdpPort);

        btnUdpUnbind = new QPushButton(groupBox);
        btnUdpUnbind->setObjectName(QString::fromUtf8("btnUdpUnbind"));
        btnUdpUnbind->setMinimumSize(QSize(150, 35));
        btnUdpUnbind->setFont(font);

        horizontalLayout_12->addWidget(btnUdpUnbind);

        btnUdpBind = new QPushButton(groupBox);
        btnUdpBind->setObjectName(QString::fromUtf8("btnUdpBind"));
        btnUdpBind->setMinimumSize(QSize(150, 35));
        btnUdpBind->setFont(font);

        horizontalLayout_12->addWidget(btnUdpBind);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(35, 35));
        label_5->setFont(font);

        horizontalLayout_13->addWidget(label_5);

        leUdpRemoteIP = new QLineEdit(groupBox);
        leUdpRemoteIP->setObjectName(QString::fromUtf8("leUdpRemoteIP"));
        leUdpRemoteIP->setMinimumSize(QSize(35, 35));
        leUdpRemoteIP->setFont(font);

        horizontalLayout_13->addWidget(leUdpRemoteIP);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(35, 0));
        label_4->setFont(font);

        horizontalLayout_13->addWidget(label_4);

        leUdpRemotePort = new QLineEdit(groupBox);
        leUdpRemotePort->setObjectName(QString::fromUtf8("leUdpRemotePort"));
        leUdpRemotePort->setMinimumSize(QSize(35, 35));
        leUdpRemotePort->setFont(font);

        horizontalLayout_13->addWidget(leUdpRemotePort);

        cbUdpData = new QComboBox(groupBox);
        cbUdpData->addItem(QString());
        cbUdpData->addItem(QString());
        cbUdpData->setObjectName(QString::fromUtf8("cbUdpData"));
        cbUdpData->setMinimumSize(QSize(150, 35));
        cbUdpData->setFont(font);

        horizontalLayout_13->addWidget(cbUdpData);

        btnUdpSend = new QPushButton(groupBox);
        btnUdpSend->setObjectName(QString::fromUtf8("btnUdpSend"));
        btnUdpSend->setMinimumSize(QSize(150, 35));
        btnUdpSend->setFont(font);

        horizontalLayout_13->addWidget(btnUdpSend);

        horizontalLayout_13->setStretch(1, 2);
        horizontalLayout_13->setStretch(3, 1);

        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(35, 35));
        label_6->setFont(font);

        horizontalLayout_14->addWidget(label_6);

        leUdpSendData = new QLineEdit(groupBox);
        leUdpSendData->setObjectName(QString::fromUtf8("leUdpSendData"));
        leUdpSendData->setMinimumSize(QSize(35, 35));
        leUdpSendData->setFont(font);

        horizontalLayout_14->addWidget(leUdpSendData);


        verticalLayout_5->addLayout(horizontalLayout_14);

        UdpLog = new QPlainTextEdit(groupBox);
        UdpLog->setObjectName(QString::fromUtf8("UdpLog"));

        verticalLayout_5->addWidget(UdpLog);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_5);

        btnUdpClrLog = new QPushButton(groupBox);
        btnUdpClrLog->setObjectName(QString::fromUtf8("btnUdpClrLog"));
        btnUdpClrLog->setMinimumSize(QSize(150, 35));
        btnUdpClrLog->setFont(font);

        horizontalLayout_29->addWidget(btnUdpClrLog);


        verticalLayout_5->addLayout(horizontalLayout_29);


        verticalLayout_4->addWidget(groupBox);

        tabWidget->addTab(tabUdp, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MainWdt);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWdt);
    } // setupUi

    void retranslateUi(QWidget *MainWdt)
    {
        MainWdt->setWindowTitle(QCoreApplication::translate("MainWdt", "MainWdt", nullptr));
        gbTcpClient->setTitle(QCoreApplication::translate("MainWdt", "TCP\345\256\242\346\210\267\347\253\257", nullptr));
        laTcpClientIp->setText(QCoreApplication::translate("MainWdt", "IP:", nullptr));
        leTcpClientIp->setText(QCoreApplication::translate("MainWdt", "127.0.0.1", nullptr));
        laTcpClientPort->setText(QCoreApplication::translate("MainWdt", "\347\253\257\345\217\243:", nullptr));
        leTcpClientPort->setText(QCoreApplication::translate("MainWdt", "9527", nullptr));
        btnTcpClientConn->setText(QCoreApplication::translate("MainWdt", "\350\277\236\346\216\245", nullptr));
        laTcpClientData->setText(QCoreApplication::translate("MainWdt", "\346\265\213\350\257\225\346\225\260\346\215\256:", nullptr));
        cbTcpClient->setItemText(0, QCoreApplication::translate("MainWdt", "ASCII", nullptr));
        cbTcpClient->setItemText(1, QCoreApplication::translate("MainWdt", "HEX", nullptr));

        btnTcpClientSend->setText(QCoreApplication::translate("MainWdt", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        btnTcpClientClrLog->setText(QCoreApplication::translate("MainWdt", "\346\270\205\347\220\206\346\227\245\345\277\227", nullptr));
        gbTcpService->setTitle(QCoreApplication::translate("MainWdt", "TCP\346\234\215\345\212\241\347\253\257", nullptr));
        laTcpServerIp->setText(QCoreApplication::translate("MainWdt", "IP:", nullptr));
        leTcpServerIp->setText(QCoreApplication::translate("MainWdt", "0.0.0.0", nullptr));
        laTcpServerPort->setText(QCoreApplication::translate("MainWdt", "\347\253\257\345\217\243:", nullptr));
        leTcpServerPort->setText(QCoreApplication::translate("MainWdt", "9527", nullptr));
        btnTcpServerListen->setText(QCoreApplication::translate("MainWdt", "\345\220\257\345\212\250\347\233\221\345\220\254", nullptr));
        laTcpServerData->setText(QCoreApplication::translate("MainWdt", "\346\265\213\350\257\225\346\225\260\346\215\256:", nullptr));
        cbTcpServer->setItemText(0, QCoreApplication::translate("MainWdt", "ASCII", nullptr));
        cbTcpServer->setItemText(1, QCoreApplication::translate("MainWdt", "HEX", nullptr));

        btnTcpServerSend->setText(QCoreApplication::translate("MainWdt", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        btnTcpServerClrLog->setText(QCoreApplication::translate("MainWdt", "\346\270\205\347\220\206\346\227\245\345\277\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTcp), QCoreApplication::translate("MainWdt", "TCP\350\260\203\350\257\225", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWdt", "UDP", nullptr));
        label_3->setText(QCoreApplication::translate("MainWdt", "\347\273\221\345\256\232\347\253\257\345\217\243:", nullptr));
        leUdpPort->setText(QCoreApplication::translate("MainWdt", "31415", nullptr));
        btnUdpUnbind->setText(QCoreApplication::translate("MainWdt", "\350\247\243\347\273\221\347\253\257\345\217\243", nullptr));
        btnUdpBind->setText(QCoreApplication::translate("MainWdt", "\347\273\221\345\256\232\347\253\257\345\217\243", nullptr));
        label_5->setText(QCoreApplication::translate("MainWdt", "\346\216\245\346\224\266\347\253\257IP:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWdt", "\347\253\257\345\217\243:", nullptr));
        cbUdpData->setItemText(0, QCoreApplication::translate("MainWdt", "ASCII", nullptr));
        cbUdpData->setItemText(1, QCoreApplication::translate("MainWdt", "HEX", nullptr));

        btnUdpSend->setText(QCoreApplication::translate("MainWdt", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        label_6->setText(QCoreApplication::translate("MainWdt", "\346\265\213\350\257\225\346\225\260\346\215\256:", nullptr));
        btnUdpClrLog->setText(QCoreApplication::translate("MainWdt", "\346\270\205\347\220\206\346\227\245\345\277\227", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUdp), QCoreApplication::translate("MainWdt", "UDP\350\260\203\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWdt: public Ui_MainWdt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWDT_H
