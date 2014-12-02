QT += quick

# To make threaded gl check...
QT += core-private gui-private

RESOURCES += textureinthread.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/scenegraph/textureinthread
INSTALLS += target

OTHER_FILES += \
    main.qml \
    error.qml

HEADERS += \
    logorenderer.h \
    ThreadRenderer.h \
    RenderThread.h \
    TextureNode.h

SOURCES += \
    logorenderer.cpp \
    ThreadRenderer.cpp \
    Main.cpp \
    RenderThread.cpp \
    TextureNode.cpp
