import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

import RequestUpdateUserInfo 1.0

Window {
    id: page3
    visible: true
    width: Screen.desktopAvailableWidth / 2
    height: Screen.desktopAvailableHeight / 1.1
    title: qsTr("TWIPS")

    property bool next_page: false

    signal qml_signal_next_page(string str)

    Connections {
        target: rootResponse

        onSignalError: {
            console.log("Page3.qml->Connections: response error: " + error)
            textError.text = error
            textError.visible = true
        }

        onSignalOk: {
            qml_signal_next_page("Page4.qml")
            close()
        }
    }

    UpdateUserInfo {
        id: updateUserInfo
    }

    Rectangle {
        height: parent.height
        width: parent.width

        Text {
            id: infoText
            text: qsTr("Enter your info")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 90
        }

        Column {
            id: column
            width: parent.width * 0.7
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: infoText.bottom
            anchors.topMargin: 150
            spacing: 20

            TextField {
                id: firstNameText
                width: column.width
                placeholderText: "First Name"

                onTextChanged: {
                    if (updateUserInfo.checkFirstName(firstNameText.text) === true) {
                        page3.next_page = true
                        buttonNextContent.color = "blue"
                        buttonNextBackground.border.color = "blue"
                    }
                    else {
                        page3.next_page = false
                        buttonNextContent.color = "#858585"
                        buttonNextBackground.border.color = "#858585"
                    }
                }
            }

            TextField {
                id: surnameText
                width: column.width
                placeholderText: "Surname name(optional)"

                onTextChanged: {
                    if(updateUserInfo.checkSurname(surnameText.text) === true) {

                    }
                }
            }

            TextField {
                id: nickname
                width: column.width
                text: "@"
                placeholderText: "nickname(optional)"

                onTextChanged: {
                    var res = nickname.text.search("@");
                    if(res !== 0) {
                        nickname.text = "@" + nickname.text
                    }

                    if(updateUserInfo.checkNickname(nickname.text) === true) {

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

            Button {
                id: buttonNext
                text: qsTr("Next")
                anchors.right: parent.right
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
                    if(page3.next_page == true) {
                        updateUserInfo.sendRequest()
                    }
                }
            }
        }
    }
}
