import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 600
    height: 300

    GroupBox {
        id: groupBox_conditions
        width: 300
        Layout.minimumWidth: 300
        Layout.minimumHeight: 200

        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.top: parent.top

        title: qsTr("Conditions")

        TableView {
            id: tableView_conditions
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 29
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
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
            y: 244
            text: qsTr("Add")
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
        }

        Button {
            id: button_delete
            y: 243
            text: qsTr("Delete")
            anchors.left: button_add.right
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
        }
    }

    GroupBox {
        id: groupBox_editCondition
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: groupBox_conditions.right
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        title: qsTr("Edit Condition")
    }
}
