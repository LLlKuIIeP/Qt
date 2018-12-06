import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

Window {
    id: startWindow
    visible: true
    width: Screen.desktopAvailableWidth / 2
    height: Screen.desktopAvailableHeight / 1.1
    title: qsTr("TWIPS")

    signal qml_signal_next_page(string str)

    Rectangle {
        id: circleIMG
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.verticalCenter
        height: 360
        width: height
        color: "blue"
        radius: width * 0.5
        opacity: 0.7    //прозрачность
    }

    Text {
        anchors.horizontalCenter: circleIMG.horizontalCenter
        anchors.verticalCenter: circleIMG.verticalCenter
        font.pointSize: circleIMG.width / 6
        font.family: "monospace"    //семейство щрифта
        font.bold: true             //жирный шрифт
        color: "white"
        text: qsTr("TWIPS")
    }

   Text {
        id: textInfo
        text: qsTr("Community unites people with common interests or hobbies. In community you can create group chats and news channels.")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter  //выравнивание по центру
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: circleIMG.bottom
        anchors.topMargin: 20
        wrapMode: Text.Wrap         //перенос текста на след строку, если текст не умещается в ширину
        width: circleIMG.width
    }

    Button {
        id: buttonStart
        text: qsTr("Start messaging")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: textInfo.bottom
        anchors.topMargin: 200
        width: 300
        height: 50
        font.bold: true //жирный шрифт
        font.pixelSize: 20
        opacity: 0.7    //прозрачность

        contentItem: Text {
            text: buttonStart.text
            font: buttonStart.font
            color: "blue"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        background: Rectangle {
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
}
