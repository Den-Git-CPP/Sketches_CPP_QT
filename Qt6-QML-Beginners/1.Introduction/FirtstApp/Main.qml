import QtQuick
import QtQuick.Window


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        text : "Hello World";
        color: "navy"
        font.pointSize: 42
    }
}
