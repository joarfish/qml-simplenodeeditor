import QtQuick 2.13
import QtQuick.Shapes 1.12

Item {
    id: inputPort

    property int portNumber: 0
    property bool ocupied: false

    width: 12
    height: 12

    Rectangle {
        width: 12
        height: 12
        radius: width*0.5
        color: ocupied ? "#FFCE00" : "grey"
        border.color: "grey"
        border.width: 2

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                console.log("There is something coming!");
            }
        }
    }
}
