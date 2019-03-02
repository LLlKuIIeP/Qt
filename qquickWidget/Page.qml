import QtQuick 2.10
import QtQuick.Controls 2.3

Item {
    id: root

    width: 500
    height: 400

    property alias minimalWidth: root.width
    property alias minimalHeight: root.height

    onMinimalWidthChanged: {
        console.log(width)
    }

    onMinimalHeightChanged: {
        console.log(height)
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
