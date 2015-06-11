#-------------------------------------------------
#
# Project created by QtCreator 2015-06-07T16:16:44
#
#-------------------------------------------------

QT       -= gui

TARGET = ThreadsafeArray
TEMPLATE = lib
CONFIG += staticlib
CONFIG  += c++14

SOURCES +=

HEADERS += ThreadsafeArray.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
