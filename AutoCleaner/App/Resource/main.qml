import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: rootWindow
    width: 800
    height: 600
    visible: true

    menuBar: MainMenuBar { }

    SplitView {
        anchors.fill: parent
        orientation: Qt.Vertical

        GroupBox {
            id: groupBox1
            height: 300
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            title: qsTr("Rules")

            RulesTableView {
                id: rulesTableView
                x: 5
                y: 5
                anchors.bottomMargin: 0
            }
        }

        RuleDetails {
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.top: groupBox1.bottom
            anchors.topMargin: 5
        }
    }
}
