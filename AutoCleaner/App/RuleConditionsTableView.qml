import QtQuick 2.0
import QtQuick.Controls 1.2

TableView {
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 30
    anchors.right: parent.right
    anchors.rightMargin: 0
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.top: parent.top
    anchors.topMargin: 0

    TableViewColumn {
        role: "title"
        title: "Title"
        width: 120
    }

    TableViewColumn {
        role: "value"
        title: "Value"
        width: 80
    }


    model: ListModel {
        ListElement {
            title: "Max size"
            value: "500 MiB"
        }

        ListElement {
            title: "Is Hidden"
            value: "false"
        }
    }
}
