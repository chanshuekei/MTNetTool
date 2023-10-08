QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CONFIG(debug, debug|release) {
    OBJECTS_DIR = debug/obj
}

CONFIG(release, debug|release) {
    OBJECTS_DIR = release/obj
}

#版本信息(Windows)
VERSION=1.0.0.0
RC_LANG=0x0004
QMAKE_TARGET_PRODUCT=网络调试工具
QMAKE_TARGET_COMPANY=月上打字员(MoonTypist)
QMAKE_TARGET_COPYRIGHT=版本所有(C)2023
DEFINES += PROGRAM_VER=\\\"$$VERSION\\\"

include($$PWD/easylogging/easylogger.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwdt.cpp

HEADERS += \
    mainwdt.h

FORMS += \
    mainwdt.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
