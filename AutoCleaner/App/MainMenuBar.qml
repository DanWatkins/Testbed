import QtQuick 2.0
import QtQuick.Controls 1.2

MenuBar {
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
        }

        Menu {
            title: "Edit"
            MenuItem {
                text: "Delete all"
            }
        }
    }
