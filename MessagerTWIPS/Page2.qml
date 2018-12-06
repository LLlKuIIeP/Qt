import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

import RequestJwtToken 1.0

Window {
    id: page2
    visible: true
    width: Screen.desktopAvailableWidth / 2
    height: Screen.desktopAvailableHeight / 1.1
    title: qsTr("TWIPS")

    property bool next_page: false

    signal qml_signal_next_page(string str)

    Connections {
        target: rootResponse

        onSignalError: {
            console.log("Page2.qml->Connections: response error: " + error)
            textError.text = error
            textError.visible = true
        }

        onSignalOk: {
            qml_signal_next_page("Page3.qml")
            close()
        }
    }

    RequestJwtToken {
        id: requestJwtToken
    }

    Rectangle {
        id: rectangle
        height: parent.height
        width: parent.width

        Text {
            id: infoText
            text: qsTr("Confirm your number")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 90
        }

        Column {
            id: column
            width: parent.width * 0.7
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: infoText.bottom
            anchors.topMargin: 30
            spacing: 20

            Text {
                 id: textInfo
                 text: qsTr("Twips sent you private message on your other device. Enter the 4 digits from message.")
                 color: "#858585"
                 opacity: 0.7
                 font.pixelSize: 14
                 horizontalAlignment: Text.AlignHCenter  //выравнивание по центру
                 anchors.horizontalCenter: parent.horizontalCenter
                 wrapMode: Text.Wrap         //перенос текста на след строку, если текст не умещается в ширину
                 width: column.width * 0.5
             }

            TextField {
                id: registerText
                width: infoText.width
                placeholderText: "Enter digits"
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter

                background: Rectangle {
                    id: registerTextBackground
                    border.color: "#858585"
                    opacity: 1
                }

                onTextChanged: {
                    if (requestJwtToken.checkRegisterCode(registerText.text) === true) {
                        page2.next_page = true
                        buttonNextContent.color = "blue"
                        buttonNextBackground.border.color = "blue"
                    }
                    else {
                        page2.next_page = false
                        buttonNextContent.color = "#858585"
                        buttonNextBackground.border.color = "#858585"
                    }
                }
            }

            Text {
                 id: textError
                 visible: false
                 color: "red"
                 opacity: 0.7
                 font.pixelSize: 14
                 horizontalAlignment: Text.AlignHCenter  //выравнивание по центру
                 anchors.horizontalCenter: parent.horizontalCenter
                 wrapMode: Text.Wrap         //перенос текста на след строку, если текст не умещается в ширину
                 width: column.width * 0.5
             }
        }

        Rectangle {
            id: rectangleButtons
            anchors.top: column.bottom
            anchors.topMargin: 100
            anchors.horizontalCenter: parent.horizontalCenter
            width: textInfo.width + buttonBack.width + buttonNext.width

            Row {
                id: row
                spacing: rectangleButtons.width - buttonBack.width - buttonNext.width
                anchors.horizontalCenter: parent.horizontalCenter

                Button {
                    id: buttonBack
                    text: qsTr("Back")
                    height: 50
                    font.bold: true //жирный шрифт
                    font.pixelSize: 20
                    opacity: 0.5    //прозрачность

                    contentItem: Text {
                        id: buttonBackContent
                        text: buttonBack.text
                        font: buttonBack.font
                        color: "blue"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        id: buttonBackBackground
                        implicitWidth: 90
                        implicitHeight: 30
                        border.color: "blue"
                        border.width: 1
                        radius: 35
                    }

                    onClicked: {
                        qml_signal_next_page("Page1.qml")
                        close()
                    }
                }

                Button {
                    id: buttonNext
                    text: qsTr("Done")
                    height: 50
                    font.bold: true //жирный шрифт
                    font.pixelSize: 20
                    opacity: 0.5    //прозрачность

                    contentItem: Text {
                        id: buttonNextContent
                        text: buttonNext.text
                        font: buttonNext.font
                        color: "#858585"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    background: Rectangle {
                        id: buttonNextBackground
                        implicitWidth: 90
                        implicitHeight: 30
                        border.color: "#858585"
                        border.width: 1
                        radius: 35
                    }

                    onClicked: {
                        if (page2.next_page === true) {
                            requestJwtToken.sendRequest()
                        }
                    }
                }
            }
        }
    }
}
