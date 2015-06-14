import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 800
    height: 200

    GroupBox {
        id: groupBox_ruleDetails
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        anchors.margins: 5
        Layout.minimumWidth: 300
        Layout.minimumHeight: 200


        title: qsTr("Rule Details")

        RuleConditions {
            id: ruleConditions
            anchors.left: groupBox_general.right
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.leftMargin: 5
        }

        GroupBox {
            id: groupBox_general
            width: 250
            title: qsTr("General")

            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0

            TextField {
                id: textField_path
                anchors.left: label_path.right
                anchors.leftMargin: 5
                anchors.top: parent.top
                anchors.topMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.margins: 5
            }

            Label {
                id: label_path
                text: qsTr("Path:")
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.verticalCenter: textField_path.verticalCenter
            }

            SpinBox {
                id: spinBox_cleanFrequency
                anchors.left: label_cleanFrequency.right
                anchors.leftMargin: 5
                anchors.top: textField_path.bottom
                anchors.topMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.margins: 5
            }

            Label {
                id: label_cleanFrequency
                text: qsTr("Clean Frequency (hours):")
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.verticalCenter: spinBox_cleanFrequency.verticalCenter
            }

            CheckBox {
                id: checkBox1
                text: qsTr("Recursive")
                anchors.top: spinBox_cleanFrequency.bottom
                anchors.topMargin: 5
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.margins: 5
            }
        }
    }
}
