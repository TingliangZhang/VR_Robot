#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T10:43:26
#
#-------------------------------------------------

QT       -= gui

QT += serialport  network

TARGET = DobotDll
TEMPLATE = lib

DEFINES += DOBOTDLL_LIBRARY

include(src/ComPlatform/ComPlatform.pri)
include(src/DobotDevice/DobotDevice.pri)

SOURCES += src/DobotDll.cpp\
           src/CDobot.cpp\
           src/CDobotConnector.cpp\
           src/CDobotProtocol.cpp\
           src/CDobotCommunicator.cpp\

HEADERS += src/dobotdll_global.h \
           src/DobotType.h\
           src/DobotDll.h\
           src/CDobot.h\
           src/CDobotConnector.h\
           src/CDobotProtocol.h\
           src/CDobotCommunicator.h\

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = ../../../DobotDllOutput

CONFIG(debug, debug | release) {
    TARGET = DobotDll_d
} else {
    TARGET = DobotDll
}
