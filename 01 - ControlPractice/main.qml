import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    minimumWidth: toolBar.implicitWidth

    toolBar:ToolBar {
        RowLayout {
            width: parent.width
            ToolButton {
                iconSource: "circle_green.bmp"
            }
            ToolButton {
                iconSource: "circle_red.bmp"
            }
            Slider {
                Layout.fillWidth: true
                Layout.minimumWidth: 180
            }
        }
    }

    SplitView {
        anchors.fill: parent
        orientation: Qt.Vertical

        SplitView {
            orientation: Qt.Horizontal
            TableView {
                TableViewColumn {
                    title: "Data Values"
                }

                model: 1000
            }
            TableView {
                TableViewColumn {
                    title: "Values"
                    role: "author"
                }

                model: dataModel
            }
        }

        TableView {
            TableViewColumn {
                title: "Stuff"
            }

            model: 10
        }
    }
/*
    TableView {
        anchors.fill: parent

        TableViewColumn {
            title: "Values"
            role: "author"
        }

        model: dataModel
    }*/
}
