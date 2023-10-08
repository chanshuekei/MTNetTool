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
    // 设置程序编码:UTF-8
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    //设置程序默认字体
    a.setFont(QFont("黑体", 12));
    // 生成日志文件夹
    if(!QDir("./logs").exists())
    {
        QDir().mkpath("./logs");
    }
    LOG(INFO) << X("启动网络调试工具,版本:%1").arg(PROGRAM_VER);
    MainWdt w;
    w.show();
    return a.exec();
}
