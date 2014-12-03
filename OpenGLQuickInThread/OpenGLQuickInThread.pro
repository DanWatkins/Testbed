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
    Src/OpenGLQuickItem.h \
    Src/OpenGLQuickItem/RenderThread.h \
    Src/OpenGLQuickItem/TextureNode.h \
    Src/MyOpenGLQuickItem.h

SOURCES += \
    Src/OpenGLQuickItem/Main.cpp \
    Src/OpenGLQuickItem/OpenGLQuickItem.cpp \
    Src/OpenGLQuickItem/RenderThread.cpp \
    Src/OpenGLQuickItem/TextureNode.cpp

