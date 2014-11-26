TEMPLATE = app
CONFIG += c++11
QT += qml quick widgets

SOURCES += main.cpp \
    Squircle.cpp \
    SquircleRenderer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Squircle.h \
    SquircleRenderer.h
