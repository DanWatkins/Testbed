import QtQuick 2.0
import QtQuick.Controls 1.2

MenuBar {
    id: root

    Menu {
        title: "File"
        MenuItem {
            text: "Add Rule"
        }
        MenuItem {
            text: "Import Rules"
        }
        MenuItem {
            text: "Export Rules"
        }
        MenuSeparator { }
        MenuItem {
            text: "Exit"
        }
    }

    Menu {
        title: "Rules"
        MenuItem {
            text: "Start All"
        }
        MenuItem {
            text: "Stop All"
        }
        MenuItem {
            text: "Force Run All"
        }
        MenuItem {
            text: "Delete All"
        }
    }
}
