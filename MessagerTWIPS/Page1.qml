import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

import Phone 1.0
import RequestRegister 1.0

Window {
    id: page1
    visible: true
    width: Screen.desktopAvailableWidth / 2
    height: Screen.desktopAvailableHeight / 1.1
    title: qsTr("TWIPS")

    property bool next_page: false

    signal qml_signal_next_page(string str)

    Phone {
        id: phone
        m_country_code: "+7"
    }

    RequestRegister {
        id: requestRegister
    }

    Connections {
        target: rootResponse

        onSignalError: {
            console.log("Page1.qml->Connections: response error: " + error)
            textError.text = error
            textError.visible = true
        }

        onSignalOk: {
            qml_signal_next_page("Page2.qml")
            close()
        }
    }

    Rectangle {
        id: rootRectangle
        height: parent.height
        width: parent.width

        Text {
            id: selectCountry
            text: qsTr("Select your country")
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

            ComboBox {
                id: nameCountry
                editable: true
                width: column.width

                model: ListModel {
                    id: model
                    ListElement { text: "Russia Federation" }
                    ListElement { text: "USA" }
                    ListElement { text: "China" }
                }

                background: Rectangle {
                    implicitWidth: 90
                    implicitHeight: 30
                    border.width: 1
                    border.color: "#858585"
                    opacity: 0.5
                    radius: 5
                }

                onActivated: {
                    if(!phone.countryNameChanged(nameCountry.currentText)) {

                    }
                }
            }

            Row {
                id: row

                Text {
                    id: plusCode
                    text: phone.m_country_code
                    anchors.verticalCenter: parent.verticalCenter
                }

                TextField {
                    id: phoneNumber
                    width: column.width - plusCode.width
                    placeholderText: "Enter your phone number"
                    inputMethodHints: Qt.ImhDialableCharactersOnly
                    background: Rectangle {
                        border.width: 0
                    }

                    onTextChanged: {
                        if (phone.checkAndSavePhone(nameCountry.currentText, phoneNumber.text) === true) {
                            page1.next_page = true
                            buttonContent.color = "blue"
                            buttonBbackground.border.color = "blue"
                        }
                        else {
                            page1.next_page = false
                            textError.visible = false
                            buttonContent.color = "#858585"
                            buttonBbackground.border.color = "#858585"
                        }
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
                    id: buttonContent
                    text: buttonNext.text
                    font: buttonNext.font
                    color: "#858585"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {
                    id: buttonBbackground
                    implicitWidth: 90
                    implicitHeight: 30
                    border.color: "#858585"
                    border.width: 1
                    radius: 35
                }

                onClicked: {
                    console.log("Selected: " + plusCode.text + " " + nameCountry.currentText)
                    if (page1.next_page === true) {
                        requestRegister.setPhoneNumber(phone.getFullPhoneNumber())
                        requestRegister.sendRequest()
                    }
                }
            }
        }
    }
}
