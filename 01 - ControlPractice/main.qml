import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0
import com.test.text 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextEditor {
        id: textEditor
    }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { text: "New" }
            MenuItem { text: "Open" }
            MenuItem
            {
                text: "Save"
                onTriggered:
                {
                    var component = Qt.createComponent("SaveFileDialog.qml");
                    var dialog = component.createObject(root);

                    textEditor.saveText("blah");
                }
            }
            MenuItem { text: "Exit" }
        }
    }

    TextArea {
        anchors.fill: parent
    }
}
