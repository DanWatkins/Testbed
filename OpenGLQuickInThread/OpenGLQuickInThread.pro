QT += quick

# To make threaded gl check...
QT += core-private gui-private
CONFIG += c++11

RESOURCES += textureinthread.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/scenegraph/textureinthread
INSTALLS += target

OTHER_FILES += \
    main.qml \
    error.qml

HEADERS += \
    logorenderer.h \
    RenderThread.h \
    TextureNode.h \
    OpenGLQuickItem.h

SOURCES += \
    logorenderer.cpp \
    Main.cpp \
    RenderThread.cpp \
    TextureNode.cpp \
    OpenGLQuickItem.cpp
