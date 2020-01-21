import QtQuick 2.13
import QtQuick.Shapes 1.12

Item {
    id: outputPort

    width: 12
    height: 12

    property bool ocupied: false

    anchors {
        verticalCenter: parent.bottom
        horizontalCenter: parent.horizontalCenter
    }

    Shape {
        Rectangle {
            width: 12
            height: 12
            radius: width*0.5
            color: ocupied ? "#FFCE00" : "grey"
            border.color: "grey"
            border.width: 1

            DragHandler {
                id: dragHandler
                target: null
                onActiveChanged: {
                    if(dragHandler.active) {
                        node.createEdgeFromOutput(this);
                    }
                }
            }
        }
    }
}
