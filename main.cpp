#include "mainwdt.h"
#include <QApplication>
#include <QDir>
#include <QTextCodec>
#include "easylogging++.h"
#pragma execution_character_set("utf-8")

INITIALIZE_EASYLOGGINGPP
void SetupEasyLogging(int argc, char *argv[])
{
    el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);
    el::Configurations conf;
    conf.setGlobally(el::ConfigurationType::Format, "%datetime{%H:%m:%s.%g} [%levshort] [%thread] [%line@%fbase] %msg");
    conf.setGlobally(el::ConfigurationType::Filename, "./logs/MtNetTool_%datetime{%Y%M%d}.log");
    el::Loggers::reconfigureLogger("default", conf);
    START_EASYLOGGINGPP(argc, argv);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SetupEasyLogging(argc, argv);
    // ���ó������:UTF-8
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    //���ó���Ĭ������
    a.setFont(QFont("����", 12));
    // ������־�ļ���
    if(!QDir("./logs").exists())
    {
        QDir().mkpath("./logs");
    }
    LOG(INFO) << X("����������Թ���,�汾:%1").arg(PROGRAM_VER);
    MainWdt w;
    w.show();
    return a.exec();
}
