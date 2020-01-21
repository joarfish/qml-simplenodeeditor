import QtQuick 2.13
import QtQuick.Shapes 1.12

Shape {

    property OutputPort outPort
    property InputPort inPort
    property real outX: 0
    property real outY: 0
    property real inX: 0
    property real inY: 0

    property int edgeId: -1

    id: root
    state: "CONNECTED"

    states: [
        State {
            name: "CONNECTED"
            PropertyChanges {
                target: root
            }
        },
        State {
            name: "CREATING"
            PropertyChanges {
                target: root
            }
        }
    ]

    function getInPointItem() {
        return inPoint;
    }

    function getOutPointItem() {
        return outPoint;
    }

    Item {
        id: inPoint
        x: inX
        y: inY
    }

    Item {
        id: outPoint
        x: outX
        y: outY
    }

    ShapePath {
        strokeWidth: 1.5
        strokeColor: "#333333"
        startX: outPoint.x
        startY: outPoint.y
        fillColor: "transparent"

        PathCubic {
            relativeControl1X: (inX - outX) * 0.325
            relativeControl1Y: (inY - outY) * 0.125
            relativeControl2X: (inX - outX) * 0.75
            relativeControl2Y: (inY - outY) * 0.95
            x: inPoint.x
            y: inPoint.y
        }
    }

}
