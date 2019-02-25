import QtQuick 2.10

Item {
    visible: true
    width: 680
    height: 500

//        LineCanvas {
//            id: lineCanvas

//            anchors.fill: parent
//        }


    LineCanvas {
        id: lineCanvas

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
                        //textFont.pixelSize: 30
                        color: "lightgray"
                        pressedColor: "gray"
                        opacity: 0.6
                        padding: 10
                        height: parent.width - 6
                        anchors {
                            left: parent.left
                            right: parent.right
                        }

                        anchors.margins: 3

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                if(text === "+") {
                                    lineCanvas.widthLine += 1
                                }
                                else if(text === "-") {
                                    lineCanvas.widthLine = lineCanvas.widthLine > 0 ? lineCanvas.widthLine - 1 : 0
                                }
                                else {
                                    lineCanvas.removeColor(lineCanvas.colorLine)
                                }
                            }
                        }
                    }
                model: ["+", "-", "X"]
            }
        }

        Row {
            id: row

            property var switches: []
            height: 30
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            spacing: 3

            Repeater {
                delegate: Switch {

                    height: parent.height
                    width: height * 2

                    color: modelData
                    backgroundColor: "lightgray"
                    borderRadius: height / 2

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            for(var i = 0; i < row.switches.length; ++i) {
                                row.switches[i].checked = false
                            }

                            trigger();

                            lineCanvas.colorLine = color
                        }
                    }
                }
                model: ["red", "green", "blue", "yellow", "black"]

                onItemAdded: {
                    row.switches.push(item);
                    row.switches[0].checked = true
                    lineCanvas.colorLine = row.switches[0].color
                    lineCanvas.widthLine = 1
                }
            }
        }



    }
}
