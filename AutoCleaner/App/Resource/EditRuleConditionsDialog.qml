import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1

Window {
    visible: true
    width: 450
    height: 300
    title: "Edit rule conditions"

    minimumWidth: editRuleConditons.Layout.minimumWidth
    minimumHeight: editRuleConditons.Layout.minimumHeight

    EditRuleConditions {
        id: editRuleConditons
        anchors.fill: parent
    }
}
