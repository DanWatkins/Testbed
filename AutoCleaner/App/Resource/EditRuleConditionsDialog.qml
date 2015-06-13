import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

Dialog {
    visible: true
    width: 450
    height: 300
    title: "Edit rule conditions"

    contentItem: EditRuleConditions {
        anchors.fill: parent
    }
}
