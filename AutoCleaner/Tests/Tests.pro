#-------------------------------------------------
#
# Project created by QtCreator 2015-06-13T22:47:47
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_teststest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG  += c++14

TEMPLATE = app

SOURCES += \
    main.cpp

HEADERS += \
    AutoTest.h \
    Test_AutoCleaner.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Src/release/ -lAutoCleaner
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Src/debug/ -lAutoCleaner
else:unix: LIBS += -L$$OUT_PWD/../Src/ -lAutoCleaner

INCLUDEPATH += $$PWD/../Src
DEPENDPATH += $$PWD/../Src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Src/release/libAutoCleaner.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Src/debug/libAutoCleaner.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Src/release/AutoCleaner.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Src/debug/AutoCleaner.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Src/libAutoCleaner.a
