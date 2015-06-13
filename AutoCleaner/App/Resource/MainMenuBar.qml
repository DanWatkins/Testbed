import QtQuick 2.0
import QtQuick.Controls 1.2

MenuBar {
    id: root

    Menu {
        title: "File"
        MenuItem {
            text: "Import rules"
        }
        MenuItem {
            text: "Export rules"
        }
        MenuSeparator { }
        MenuItem {
            text: "Exit"
        }
    }

    Menu {
        title: "Rule"
        MenuItem {
            text: "New"
        }
        MenuItem {
            text: "Delete"
        }
        MenuItem {
            text: "Edit conditions..."

            onTriggered: {
                var cmp = Qt.createComponent("EditRuleConditionsDialog.qml")
                var dialog = cmp.createObject(root)
                dialog.open()
            }
        }
    }

    Menu {
        title: "Run"
        MenuItem {
            text: "Start all"
        }
        MenuItem {
            text: "Stop all"
        }
        MenuItem {
            text: "Force run all"
        }
        MenuItem {
            text: "Delete all"
        }
    }
}
