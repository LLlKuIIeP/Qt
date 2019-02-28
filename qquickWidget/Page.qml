import QtQuick 2.10
import QtQuick.Controls 2.3

Item {
    width: 500
    height: 400

    property real minimalWidth: 100

    onMinimalWidthChanged: {
        console.log(minimalWidth)
    }

    signal signalOk()

    Column {
        id: column
        width: parent.width
        spacing: 20

        Rectangle {
            id: rectangle

            width: parent.width
            height: 30
            color: "red"
        }

        Button {
            id: button

            text: "Ok"

            onClicked: signalOk();
        }
    }
}
