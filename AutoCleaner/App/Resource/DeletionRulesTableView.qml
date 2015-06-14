import QtQuick 2.0
import QtQuick.Controls 1.2

TableView {
    id: tableView

    anchors.bottom: parent.bottom
    anchors.bottomMargin: 30
    anchors.right: parent.right
    anchors.rightMargin: 0
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.top: parent.top
    anchors.topMargin: 0

    TableViewColumn {
        role: "status"
        title: "Status"
        width: 120
    }

    TableViewColumn {
        role: "lastCleanedDate"
        title: "Last Cleaned Date"
        width: 120
    }

    TableViewColumn {
        role: "path"
        title: "Path"
        width: 250

    }
    TableViewColumn {
        role: "recursive"
        title: "Recursive"
        width: 80
    }

    TableViewColumn {
        role: "cleanFrequency"
        title: "Clean Frequency (hours)"
        width: 120
    }


    model: ListModel {
        ListElement {
            path: "C:/Users/Dan/Desktop/"
            recursive: "Yes"
            cleanFrequency: 10.5
        }

        ListElement {
            path: "C:/Program Files/"
            recursive: "Yes"
            cleanFrequency: 1.5
        }

        ListElement {
            path: "C:/Qt/"
            recursive: "No"
            cleanFrequency: 10.5
        }

        ListElement {
            path: "C:/Qt/bin"
            recursive: "Yes"
            cleanFrequency: 10.5
        }

        ListElement {
            path: "C:/Fraps/"
            recursive: "No"
            cleanFrequency: 10.5
        }
    }

    Menu {
        id: contextMenu
        MenuItem {
            text: qsTr("Start")
        }
        MenuItem {
            text: qsTr("Stop")
        }
        MenuItem {
            text: qsTr("Force run")
        }

        MenuSeparator { }

        MenuItem {
            text: qsTr("Delete")
        }
        MenuItem {
            text: qsTr("Edit conditions...")
        }
    }

    rowDelegate: Item {
        Rectangle {
            anchors {
                left: parent.left
                right: parent.right
                verticalCenter: parent.verticalCenter
            }
            height: parent.height
            color: styleData.selected ? 'lightblue' : 'white'

            RightClickArea {
                anchors.fill: parent

                onRightClick: {
                    tableView.selection.deselect(0, tableView.rowCount-1)
                    tableView.selection.select(styleData.row)
                    contextMenu.popup()
                }
            }
        }
    }
}
