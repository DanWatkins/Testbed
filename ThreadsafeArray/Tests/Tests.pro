#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T18:30:45
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = Test_ThreadsafeArray
CONFIG   += console
CONFIG   -= app_bundle
CONFIG  += c++14

TEMPLATE = app


SOURCES += \
    main.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    Test_ThreadsafeArray_Basic.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Src/release/ -lThreadsafeArray
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Src/debug/ -lThreadsafeArray
else:unix: LIBS += -L$$OUT_PWD/../Src/ -lThreadsafeArray

INCLUDEPATH += $$PWD/../Src
DEPENDPATH += $$PWD/../Src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Src/release/libThreadsafeArray.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Src/debug/libThreadsafeArray.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Src/release/ThreadsafeArray.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Src/debug/ThreadsafeArray.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Src/libThreadsafeArray.a
