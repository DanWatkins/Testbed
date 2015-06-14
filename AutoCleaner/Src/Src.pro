#-------------------------------------------------
#
# Project created by QtCreator 2015-06-07T16:16:44
#
#-------------------------------------------------

QT       -= gui

TARGET = AutoCleaner
TEMPLATE = lib
CONFIG += staticlib
CONFIG  += c++14

SOURCES += \
    AutoCleaner.cpp

HEADERS += \
    AutoCleaner.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
