import QtQuick 2.10

Item {
    id: root

    property alias color: rectangle.color
    property color backgroundColor: backgroundRectangle.color
    property color dimmedColor: backgroundRectangle.color
    property alias borderRadius: backgroundRectangle.radius
    property bool checked: false
    property int duration: 500

    signal signalChecked()

    function trigger() {
        checked = !checked
    }

    Rectangle {
        id: backgroundRectangle

        width: parent.width
        height: parent.height

        function trigger() {
            root.checked = !root.checked
        }

        Rectangle {
            id: rectangle

            width: parent.width
            height: parent.height

            anchors {
                left: !root.checked ? parent.left : parent.horizontalCenter;
                right: !root.checked ? parent.horizontalCenter : parent.right;
                top: parent.top;
                bottom: parent.bottom;
            }

            radius: parent.radius
            opacity: root.checked ? 1 : 0.7

            Behavior on opacity {
                OpacityAnimator { duration: root.duration }
            }

            MouseArea {
                id: mouseArea

                anchors.fill: parent

                onClicked: {
                    root.trigger();
                    root.signalChecked();
                }
            }
        }

        states: [
            State {
                name: "deactivated"
                when: !root.checked

                AnchorChanges {
                    target: rectangle;
                    anchors.left: backgroundRectangle.left;
                    anchors.right: backgroundRectangle.horizontalCenter;
                }
                PropertyChanges { target: backgroundRectangle; color: root.dimmedColor }
            },
            State {
                name: "activated"
                when: root.checked

                AnchorChanges {
                    target: rectangle;
                    anchors.left: backgroundRectangle.horizontalCenter;
                    anchors.right: backgroundRectangle.right;
                }
                PropertyChanges { target: backgroundRectangle; color: root.backgroundColor }
            }
        ]

        transitions: [
            Transition {
                from: "deactivated"
                to: "activated"
                AnchorAnimation { duration: root.duration }
                PropertyAnimation { properties: "color"; duration: root.duration }

            },
            Transition {
                from: "activated"
                to: "deactivated"
                AnchorAnimation { duration: duration }
                PropertyAnimation { properties: "color"; duration: duration }
            }
        ]
    }
}
