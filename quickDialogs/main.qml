import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true;
    width: 200;
    height: 150;
    title: qsTr("Dialogs Demo");

    Repeater {
        id: repeter;
        model: [colorDialog, fontDialog, fileDialog];

        Button {
            y: index * (parent .height / repeter.count);
            height: parent.height / repeter.count;
            width: parent.width;
            text: modelData.title;

            onClicked: {
                messageDialog.visible = false;
                modelData.visible = true;
            }
        }
    }

    ColorDialog {
        id: colorDialog;
        visible: false;
        modality: Qt.WindowModal;
        title: "Select color";
        color: "blue";
        onAccepted: {
            messageDialog.informativeText = "Selected color: " + color;
            messageDialog.visible = true;
        }
    }

    FontDialog {
        id: fontDialog;
        visible: false;
        modality: Qt.WindowModal;
        title: "Select font";
        onAccepted: {
            messageDialog.informativeText = "Selected font: " + font;
            messageDialog.visible = true;
        }
    }

    FileDialog {
        id: fileDialog;
        visible: false;
        modality: Qt.WindowModal;
        title: "Select file";
        folder: "file://User/";
        nameFilters: ["Doc (*.txt *.html)", "All files (*)"];
        onAccepted: {
            messageDialog.informativeText = "Selected file: " + fileUrls;
            messageDialog.visible = true;
        }
    }

    MessageDialog {
        id: messageDialog;
        visible: false;
        modality: Qt.WindowModal;
        title: "Message";
    }
}
