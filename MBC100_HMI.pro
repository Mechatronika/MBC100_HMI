#-------------------------------------------------
#
# Project created by QtCreator 2020-03-11T15:38:27
#
#-------------------------------------------------

QT       += core gui widgets xml charts

TARGET = MBC100_HMI
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

CONFIG += c++11

LIBS        += "C:\TwinCAT\AdsApi\TcAdsDll\Lib\TcAdsDll.lib"
INCLUDEPATH += C:\TwinCAT\AdsApi\TcAdsDll\Include\
DEPENDPATH  += C:\TwinCAT\AdsApi\TcAdsDll\Include\

RC_ICONS = AppIcon.ico

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        accesscontrol.cpp \
        BeckhoffADS/adsworker.cpp \
        NumpadDialogue/dialog.cpp \
    loadingform.cpp \
    saveas_widget.cpp \
    topmessage.cpp

HEADERS += \
        mainwindow.h \
        status.h \
        accesscontrol.h \       
        BeckhoffADS/AdsStructures.h \
        BeckhoffADS/adsworker.h \       
        NumpadDialogue/dialog.h \
    loadingform.h \
    settings.h \
    saveas_widget.h \
    topmessage.h

FORMS += \
        mainwindow.ui \
        accesscontrol.ui \
        NumpadDialogue/dialog.ui \
    loadingform.ui \
    saveas_widget.ui \
    topmessage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icones.qrc
