import QtQuick 2.9
import QtQuick.Window 2.2

import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.0


Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal qml_select_file(string f)
    signal qml_run()
    signal qml_pause()
    signal qml_resume()
    signal qml_stop()
    signal qml_save(string s)

    Column {
        id: column
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 5
        spacing: 5
        width: parent.width

        Button {
            id: loadFile
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Load File")


            onClicked: fileDialog.open();
        }

        Label {
            id: pathFile
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }

        function start_run() {
            if (labelProgressBar.text === "") {
            }
            else {
                labelProgressBar.text = qsTr("Подготовка к сортировки");
                labelProgressBar.color = "Blue"
            }
        }

        Button {
            id: run
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Run")
            font.pixelSize: 15
            font.bold: true

            contentItem: Text {
                text: run.text
                font: run.font
                opacity: enabled ? 1.0 : 0.3
                color: run.down ? "#FF0000" : "#0EF122"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight

            }
            background: Rectangle {
                implicitWidth: 90
                implicitHeight: 30
                opacity: enabled ? 1.0 : 0.3
                //color: run.pressed ? "#A9D4FE" : "#50CDCE"
                border.color: run.down ? "#FF0000" : "#0EF122"
                border.width: 2
                radius: 5
            }

            onClicked: {
                start_run()
                window.qml_run()
            }
        }

        Row {
            id: row
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 5
            Button {
                id: pause
                text: qsTr("Pause")
                onClicked: {
                    labelProgressBar.text = "Пауза"
                    window.qml_pause()
                }
            }

            Button {
                id: resume
                text: qsTr("Resume")
                onClicked: {
                    labelProgressBar.text = "Сортировка"
                    window.qml_resume()
                }
            }

            Button {
                id: stop
                text: qsTr("Stop")
                onClicked: {
                    labelProgressBar.text = "Сортировка остановлена"
                    labelProgressBar.color = "Red"
                    window.qml_stop()
                }
            }
        }

        Label {
            id: labelProgressBar
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 15
        }

        ProgressBar {
            id: progressBar
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
        }
    }


    TextField {
        id: textField
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: buttonSave.left
        anchors.rightMargin: 30
        anchors.top: column.bottom
        anchors.topMargin: 20
        placeholderText: qsTr("Имя файла")
    }

    Button {
        id: buttonSave
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: column.bottom
        anchors.topMargin: 20

        text: qsTr("Save")
        onClicked: {
            window.qml_save(textField.text)
        }
    }

    FileDialog {
        id: fileDialog
        title: qsTr("Load File")
        folder: shortcuts.home
        nameFilters: ["TXT (*.txt)"]

        onAccepted: {
            pathFile.text = fileDialog.fileUrls.toString().substr(8, fileDialog.fileUrls.toString().length)
            //console.log(fileDialog.fileUrls)
            window.qml_select_file(pathFile.text)
        }

    }

    Connections {
        target: parallelSort
        onSignalStartSort: {
            labelProgressBar.text = "Сортировка"
            labelProgressBar.color = "Green"
        }
        onSignalStepSort: {
            progressBar.value = 1 / value
        }
        onSignalStopSort: {
            labelProgressBar.text = "Сортировка завершилась"
            labelProgressBar.indeterminate = true
        }
    }
}
