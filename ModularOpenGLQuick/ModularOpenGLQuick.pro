QT += quick

# To make threaded gl check...
QT += core-private gui-private

CONFIG += c++11

HEADERS += OpenGLQuickItem.h \
	RenderThread.h \
	TextureNode.h
SOURCES +=  OpenGLQuickItem.cpp \
	RenderThread.cpp \
	TextureNode.cpp \
	main.cpp

INCLUDEPATH += ../shared

RESOURCES += \
    main.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/scenegraph/textureinthread
INSTALLS += target
