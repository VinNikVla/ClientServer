#-------------------------------------------------
#
# Project created by QtCreator 2021-01-26T00:58:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/../CPP/

SOURCES += \
        main.cpp \
        widget.cpp \
    settings.cpp \
    conditioner.cpp \
    ../CPP/global.cpp \
    elementongui.cpp \
    ../CPP/UDP/udpclient.cpp \
    ../CPP/ValueModel/valuemodel.cpp \
    ../CPP/ViewModel/view.cpp \
    ../CPP/ViewModel/control.cpp \
    ../CPP/humadity.cpp \
    ../CPP/pressure.cpp \
    ../CPP/temperature.cpp \
    ../CPP/server.cpp \
    circlestate.cpp

HEADERS += \
        widget.h \
    settings.h \
    ../CPP/global.h \
    conditioner.h \
    elementongui.h \
    ../CPP/UDP/udpclient.h \
    ../CPP/ValueModel/valuemodel.h \
    ../CPP/ViewModel/view.h \
    ../CPP/ViewModel/control.h \
    ../CPP/humadity.h \
    ../CPP/pressure.h \
    ../CPP/temperature.h \
    ../CPP/server.h \
    circlestate.h

FORMS += \
        widget.ui
