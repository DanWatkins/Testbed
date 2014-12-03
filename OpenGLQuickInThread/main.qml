import QtQuick 2.0
import QtQuick.Controls 1.2
import SceneGraphRendering 1.0

Item {
    width: 800
    height: 600

    OpenGLQuickItem {
        id: renderer
        anchors.fill: parent
        anchors.margins: 0
    }
}
