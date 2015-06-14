import QtQuick 2.0

MouseArea {
    acceptedButtons: Qt.RightButton
    propagateComposedEvents: true

    signal rightClick()

    onReleased: {
        mouse.accepted = false
        rightClick()
    }
}
