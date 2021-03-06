#-------------------------------------------------
#
# Project created by QtCreator 2017-08-01T19:17:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ePasswordGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
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
    userpasswordinput.cpp \
    elementinfowidget.cpp \
    elementbutton.cpp \
    usernameinput.cpp \
    usernoteinput.cpp \
    cryptor.cpp \
    epasswordcore.cpp

HEADERS += \
        mainwindow.h \
    userpasswordinput.h \
    elementinfowidget.h \
    elementbutton.h \
    usernameinput.h \
    usernoteinput.h \
    cryptor.h \
    epasswordcore.h

RESOURCES += \
    res/res.qrc

DISTFILES += \
    res/icon.icns

macx:ICON = res/icon.icns
