import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: rootWindow
    width: 640
    height: 480
    visible: true

    menuBar: MainMenuBar { }

    GroupBox {
        id: groupBox_deletionRules
        anchors.margins: 5
        anchors.fill: parent
        title: qsTr("Deletion Rules")

        DeletionRulesTableView { }

        Button {
            id: button_new
            y: 252
            text: qsTr("New")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id: button_delete
            y: 251
            text: qsTr("Delete")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: button_new.right
            anchors.leftMargin: 5
        }

        Button {
            id: button_start
            x: 458
            y: 252
            text: qsTr("Start")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.right: button_forceRun.left
            anchors.rightMargin: 5
        }

        Button {
            id: button_forceRun
            x: 539
            y: 252
            text: qsTr("Force Run")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
        }
    }
}
