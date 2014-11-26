import QtQuick 2.0
import QtQuick.Dialogs 1.2

FileDialog {
    id: fileDialog
    title: "Please choose a file"

    onAccepted: {
        console.log("You chose: " + fileDialog.fileUrls)
    }
    onRejected: {
        console.log("Canceled")
    }
}
