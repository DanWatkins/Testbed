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

    minimumWidth: groupBox_deletionRules.Layout.minimumWidth
    minimumHeight: groupBox_deletionRules.Layout.minimumHeight

    menuBar: MainMenuBar { }

    GroupBox {
        id: groupBox_deletionRules
        width: 400
        anchors.fill: parent
        anchors.margins: 5

        Layout.minimumWidth: 300
        Layout.minimumHeight: 300

        title: qsTr("Deletion Rules")

        DeletionRulesTableView { }
    }
}
