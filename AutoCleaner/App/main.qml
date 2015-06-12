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

    minimumWidth: splitView.Layout.minimumWidth
    minimumHeight: splitView.Layout.minimumHeight

    menuBar: MainMenuBar { }

    SplitView {
        id: splitView
        anchors.fill: parent
        Layout.minimumWidth: 600
        Layout.minimumHeight: 400

        Item {
            Layout.minimumWidth: 300
            Layout.minimumHeight: 300

            GroupBox {
                id: groupBox_deletionRules
                width: 400
                anchors.fill: parent
                anchors.margins: 5
                title: qsTr("Deletion Rules")

                DeletionRulesTableView { }
            }
        }

        Item {
            Layout.minimumWidth: 200
            Layout.minimumHeight: 300

            GroupBox {
                id: groupBox_conditions
                width: 300
                anchors.fill: parent
                anchors.margins: 5
                title: qsTr("Conditions")

                RuleConditionsTableView { }
            }
        }
    }
}
