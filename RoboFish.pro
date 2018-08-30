#-------------------------------------------------
#
# Project created by QtCreator 2018-08-11T23:37:35
#
#-------------------------------------------------

QT       += core gui svg network axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoboFish
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    videosdk_widget.cpp \
    dialog.cpp \
    LayoutSquare.cpp \
    qfi_PFD.cpp \
    WidgetPFD.cpp \
    mapwidget.cpp \
    qjoystick.cpp \
    udpmaster.cpp

HEADERS += \
        mainwindow.h \
    videosdk_widget.h \
    bin/H264Play.h \
    bin/netsdk.h \
    dialog.h \
    LayoutSquare.h \
    qfi_PFD.h \
    WidgetPFD.h \
    mapwidget.h \
    qjoystick.h \
    udpmaster.hpp

FORMS += \
        mainwindow.ui \
    dialog.ui \
    WidgetPFD.ui \
    mapwidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/bin/ -lNetSdk
else: win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/bin/ -lNetSdkd

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/bin/ -lH264Play
else: win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/bin/ -lH264Playd

win32:CONFIG(release, debug|release): LIBS += -ldinput8 -ldxguid
else: win32:CONFIG(debug, debug|release): LIBS += -ldinput8 -ldxguid

CONFIG += c++11

INCLUDEPATH += $$PWD/bin
DEPENDPATH += $$PWD/bin

RESOURCES += \
    res.qrc
