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

        delegate: CheckBox {
        }
    }

    TableViewColumn {
        role: "cleanFrequency"
        title: "Clean Frequency (hours)"

        delegate: SpinBox {
            stepSize: 0.1
            minimumValue: 0.0001
            maximumValue: 10000
        }
    }


    model: ListModel {
        ListElement {
            path: "C:/Users/Dan/Desktop/"
            recursive: false
            cleanFrequency: 10.5
        }
    }
}
