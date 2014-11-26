TEMPLATE = app

QT += qml quick widgets

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    TextEditor.h
SOURCES += \
    Main.cpp
RESOURCES += qml.qrc
