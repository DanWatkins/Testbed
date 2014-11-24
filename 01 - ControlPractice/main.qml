import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TableView {
        anchors.fill: parent

        TableViewColumn {
            title: "Values"
            role: "author"
        }

        model: dataModel
    }
}
