import QtQuick 2.6

Item {
    id: root

    property alias text: text.text
    property alias textFont: text.font
    property alias textColor: text.color
    property alias color: backgroundRectangle.color
    property color pressedColor: color
    property color dimmedColor: color
    property real padding: 0
    property alias borderRadius: backgroundRectangle.radius
    property alias isPressed: mouseArea.pressed

    width: text.width + 2 * padding
    height: text.height + 2 * padding

    signal clicked()
    signal pressed()
    signal released()
    signal pressAndHold()

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: root.clicked()
        onPressed: root.pressed()
        onReleased: root.released()
        onPressAndHold: root.pressAndHold()
    }

    Rectangle {
        id: backgroundRectangle

        anchors.fill: parent

        Text {
            id: text
            anchors.centerIn: parent
        }
    }

    states: [
        State {
            name: "pressed"
            when: mouseArea.pressed

            PropertyChanges {
                target: backgroundRectangle
                color: root.pressedColor
            }
        },
        State {
            name: "dimmed"
            when: !root.enabled

            PropertyChanges {
                target: backgroundRectangle
                color: root.dimmedColor
            }
        }
    ]
    transitions: [
        Transition {
            to: "pressed"
            reversible: true

            ColorAnimation { properties: "color"; duration: 200 }
        }
    ]
}
