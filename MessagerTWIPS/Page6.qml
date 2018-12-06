import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

import ForEndPage 1.0

Window {
    id: page6
    visible: true
    width: Screen.desktopAvailableWidth / 2
    height: Screen.desktopAvailableHeight / 1.1
    title: qsTr("TWIPS")

    signal qml_signal_next_page(string str)

    ForEndPage {
        id: forEnaPage
    }

    Connections {
        target: rootResponse

        onSignalError: {
            console.log("Page1.qml->Connections: response error: " + error)
        }

        onSignalOk: {
        }
    }

    Rectangle {
        id: rootRectangle
        height: parent.height
        width: parent.width

        Text {
            id: selectCountry
            text: qsTr("Congratulations")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 90
        }

        Column {
            id: column
            width: parent.width * 0.7
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: selectCountry.bottom
            anchors.topMargin: 50
            spacing: 20

            Text {
                id: firstName
                text: "Name: " + forEnaPage.getFirstName()
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: surname
                text: "Surname: " + forEnaPage.getSurname()
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: nickname
                text: "Nickname: " + forEnaPage.getNickname()
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: phoneNumber
                text: "Phone number: " + forEnaPage.getPhoneNumber()
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: userId
                text: "User ID: " + forEnaPage.getUserId()
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: userCountry
                text: "User country: " + forEnaPage.setUserCountry()
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: jwsToken
                width: parent.width * 0.7
                text: "JWT token: " + forEnaPage.getJwtToken()
                font.pixelSize: 17
                horizontalAlignment: Text.AlignLeft //выравнивание по левому краю
                anchors.horizontalCenter: parent.horizontalCenter
                wrapMode: Text.Wrap         //перенос текста на след строку, если текст не умещается в ширину
            }

            Button {
                id: buttonNext
                text: qsTr("Done")
                anchors.horizontalCenter: parent.horizontalCenter
                height: 50
                font.bold: true //жирный шрифт
                font.pixelSize: 20
                opacity: 0.5    //прозрачность

                contentItem: Text {
                    id: buttonContent
                    text: buttonNext.text
                    font: buttonNext.font
                    color: "blue"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {
                    id: buttonBbackground
                    implicitWidth: 90
                    implicitHeight: 30
                    border.color: "blue"
                    border.width: 1
                    radius: 35
                }

                onClicked: {
                    console.log(jwsToken.text)
                    close()
                }
            }
        }
    }
}
