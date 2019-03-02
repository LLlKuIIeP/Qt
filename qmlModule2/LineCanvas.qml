import QtQuick 2.10

Canvas {
    id: canvas

    property var lines: []
    property string colorLine
    property real widthLine

    function fun(color, width , points) {
        lines.push({ color: color, width: width, points: [ { x: points[0].x, y: points[0].y }, { x: points[1].x, y: points[1].y } ] })
    }

    function removeColor(color)
    {
        canvas.lines = canvas.lines.filter(function (line) {
                if(line.color === color ) {
                    return false
                }
                return true
            }
        )

        canvas.requestPaint()
    }

    onPaint: {
        var ctx = getContext("2d");
        ctx.clearRect(0, 0, width, height);

        for(var i = 0; i < lines.length; ++i) {
            ctx.strokeStyle = lines[i].color
            ctx.lineWidth = lines[i].width

            ctx.beginPath()
            ctx.moveTo(lines[i].points[0].x, lines[i].points[0].y)
            ctx.lineTo(lines[i].points[1].x, lines[i].points[1].y)

            ctx.stroke()
        }
    }

    MouseArea {
        anchors.fill: parent

        property real xMx
        property real yMy

        onPressed: { xMx = mouseX; yMy = mouseY }

        onPositionChanged: {
            canvas.fun(canvas.colorLine, canvas.widthLine, [{x: xMx, y: yMy}, {x: mouseX, y: mouseY}]);
            xMx = mouseX;
            yMy = mouseY;
            canvas.requestPaint();
        }
    }
}

