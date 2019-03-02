import QtQuick 2.10

Item {
    visible: true
    width: 680
    height: 500

    LineCanvas {
        id: lineCanvas

        property int paintWidth: 1

        onPaintWidthChanged: {
            lineCanvas.widthLine = paintWidth
        }

        anchors.fill: parent

        Column {
            id: column

            width: 30
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter

            spacing: 3

            Repeater {
                delegate: Button {
                        text: modelData
                        textColor: "black"
                        color: "lightgray"
                        pressedColor: "gray"
                        padding: 10
                        height: parent.width - 6
                        anchors {
                            left: parent.left
                            right: parent.right
                        }

                        anchors.margins: 3

                        onClicked: {
                            switch(modelData) {
                            case "+" :
                                ++lineCanvas.paintWidth;
                                break;
                            case "-":
                                ineCanvas.paintWidth = ineCanvas.paintWidth > 1 ? ineCanvas.paintWidth - 1 : 1;
                                break;
                            case "X" :
                                lineCanvas.removeColor(lineCanvas.colorLine);
                                break;
                            default:
                                break;
                            }

                        }
                    }
                model: ["+", "-", "X"]
            }
        }

        Row {
            id: row

            property var switches: []

            function changeColor(color)
            {
                for(var i = 0; i < row.switches.length; ++i) {
                    if(color === row.switches[i].color) {
                        row.switches[i].checked = true;
                    } else {
                        row.switches[i].checked = false;
                    }
                }

                lineCanvas.colorLine = color
            }

            height: 30
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            spacing: 3

            Repeater {
                delegate: Switch {

                    height: parent.height
                    width: height * 2

                    color: modelData
                    backgroundColor: "gray"
                    dimmedColor: "lightgray"
                    borderRadius: height / 2

                    onSignalChecked: {
                        row.changeColor(color)
                    }
                }
                model: ["red", "green", "blue", "yellow", "black"]

                onItemAdded: {
                    row.switches.push(item)

                    if(row.switches.length == 1) {
                        row.switches[0].checked = true;
                        lineCanvas.colorLine = row.switches[0].color;
                        lineCanvas.widthLine = 1;
                    }
                }
            }
        }



    }
}
