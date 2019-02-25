import QtQuick 2.10

Item {
    id: root

    property alias color: rectangle.color
    property alias backgroundColor: backgroundRectangle.color
    property color dimmedColor
    property alias borderRadius: backgroundRectangle.radius
    property bool checked: false

    function trigger() {
        root.checked = !root.checked
    }

    Rectangle {
        id: backgroundRectangle

        anchors.fill: parent

        Rectangle {
            id: rectangle

            anchors {
                left: !root.checked ? parent.left : parent.horizontalCenter
                right: !root.checked ? parent.horizontalCenter : parent.right
                top: parent.top
                bottom: parent.bottom
            }

            anchors.margins: 3
            radius: parent.radius
            opacity: 0.4

        }

        states: [
            State {
                name: "deactivated"
                when: !root.checked

                AnchorChanges {
                    target: rectangle
                    anchors.left: backgroundRectangle.left
                    anchors.right: backgroundRectangle.horizontalCenter
                }
                PropertyChanges {
                    target: rectangle
                    opacity: 0.4
                }
            },
            State {
                name: "activated"
                when: root.checked

                AnchorChanges {
                    target: rectangle
                    anchors.left: backgroundRectangle.horizontalCenter
                    anchors.right: backgroundRectangle.right
                }
                PropertyChanges {
                    target: rectangle
                    opacity: 1
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
                from: "deactivated"
                to: "activated"
                AnchorAnimation { duration: 500 }
            },
            Transition {
                from: "activated"
                to: "deactivated"
                AnchorAnimation { duration: 500 }
            }
        ]
    }
}
