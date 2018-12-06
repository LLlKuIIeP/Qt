import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

import Country 1.0;

Window {
    id: page5
    visible: true
    width: Screen.desktopAvailableWidth / 2
    height: Screen.desktopAvailableHeight / 1.1
    title: qsTr("TWIPS")

    signal qml_signal_next_page(string str)

    Country {
        id: country
    }

    Connections {
        target: rootResponse

        onSignalError: {
            console.log("Page5.qml->Connections: response error: " + error)
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

                model: country.m_arr

                background: Rectangle {
                    implicitWidth: 90
                    implicitHeight: 30
                    border.width: 1
                    border.color: "#858585"
                    opacity: 0.5
                    radius: 5
                }

                onActivated: {
                    console.log(nameCountry.currentText)
                }
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
                    if(country.saveUserInfo() === true) {
                        country.saveCountry(nameCountry.currentText)
                        qml_signal_next_page("Page6.qml")
                        close()
                    }
                }
            }
        }
    }
}
