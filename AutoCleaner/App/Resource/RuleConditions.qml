import QtQuick 2.0
import QtQuick.Controls 1.2

GroupBox {
    title: qsTr("Conditions")

    TableView {
        id: tableView_conditions
        width: 260
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 29
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0

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

    Button {
        id: button_add
        x: -316
        y: 506
        text: qsTr("Add")
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
    }

    Button {
        id: button_delete
        x: -236
        y: 506
        text: qsTr("Delete")
        anchors.left: button_add.right
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
    }
}
