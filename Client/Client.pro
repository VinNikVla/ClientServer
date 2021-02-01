#-------------------------------------------------
#
# Project created by QtCreator 2021-01-31T15:19:16
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
    ../CPP/global.cpp \
    ../CPP/AbstractValueModel/abstractvaluemodel.cpp \
    ../CPP/Settings/settings.cpp \
    ../CPP/AbstractConditioner/abstractconditioner.cpp\
    ../CPP/AbstractValueModel/ChangeStateModel/ChangeMeasurmentsModel/changemeasurment.cpp \
    ../CPP/AbstractValueModel/ChangeStateModel/changestate.cpp \
    ../CPP/AbstractConditioner/ClientConditioner/clientconditioner.cpp \
    ../CPP/AbstractUDP/udpserver.cpp \
    ../CPP/AbstrcatViewModel/abstractgui.cpp \
    ../CPP/AbstrcatViewModel/ChangeMeasurments/changemeasurmentwidget.cpp \
    ../CPP/AbstrcatViewModel/HandlerState/circlestate.cpp \
    ../CPP/AbstrcatViewModel/HandlerState/handlerstate.cpp \
    ../CPP/AbstrcatViewModel/CustomSlider/abstractcontrol.cpp \
    ../CPP/AbstrcatViewModel/CustomSlider/Slider/slidercontrol.cpp \
    ../CPP/AbstrcatViewModel/CustomSlider/ControlButton/controlbutton.cpp
HEADERS += \
        widget.h \
    ../CPP/global.h \
    ../CPP/AbstractValueModel/abstractvaluemodel.h \
    modelchangestate.h \
    ../CPP/Settings/settings.h \
    ../CPP/AbstractConditioner/abstractconditioner.h\
    ../CPP/AbstractValueModel/ChangeStateModel/ChangeMeasurmentsModel/changemeasurment.h \
    ../CPP/AbstractValueModel/ChangeStateModel/changestate.h \
    ../CPP/AbstractConditioner/ClientConditioner/clientconditioner.h \
    ../CPP/AbstractUDP/udpserver.h \
    ../CPP/AbstrcatViewModel/abstractgui.h \
    ../CPP/AbstrcatViewModel/ChangeMeasurments/changemeasurmentwidget.h \
    ../CPP/AbstrcatViewModel/HandlerState/circlestate.h \
    ../CPP/AbstrcatViewModel/HandlerState/handlerstate.h \
    ../CPP/AbstrcatViewModel/CustomSlider/abstractcontrol.h \
    ../CPP/AbstrcatViewModel/CustomSlider/Slider/slidercontrol.h \
    ../CPP/AbstrcatViewModel/CustomSlider/ControlButton/controlbutton.h
