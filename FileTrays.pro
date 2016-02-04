#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T14:40:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileTrays
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    copythread.cpp \
    cutthread.cpp

HEADERS  += mainwindow.h \
    copythread.h \
    cutthread.h

FORMS    += mainwindow.ui

RESOURCES += \
    iconsMenu.qrc
