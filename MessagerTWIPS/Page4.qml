import QtQuick 2.4
import QtQuick.Window 2.10

Window {
    id: page4
    visible: true
    width: Screen.desktopAvailableWidth / 2
    height: Screen.desktopAvailableHeight / 1.1
    title: qsTr("TWIPS")

    signal qml_signal_next_page(string str)

Rectangle {}

    Text {
         id: textInfo
         width: parent.width * 0.7
         text: qsTr("Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed daim nonummy \
nibh euismod ticidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi \
enim ad minim veniam, quis nostrurd exerci tation ullamcorper suscipit \
lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure \
dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore \
eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui \
blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla \
facilisi.Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam \
nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat \
volutpat. Ut wisi enim ad minim venaim, quis nostrud exerci tation \
ullamcorper suscipit lobotris nisl ut aliquip ex ea commodo consequat. Duis \
autem vel eum iriure dolor in hendreit in vulputate velit esse molestie \
consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan \
et uisto odio dignissim qui blandit praesent luptatum zzril delenit augue duis \
dolore te feugait nulla facilisi.");
         font.pixelSize: 17
         horizontalAlignment: Text.AlignLeft //выравнивание по левому краю
         anchors.verticalCenter: parent.verticalCenter
         anchors.horizontalCenter: parent.horizontalCenter
         wrapMode: Text.Wrap         //перенос текста на след строку, если текст не умещается в ширину
     }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            qml_signal_next_page("Page5.qml")
            close()
        }
    }
}
