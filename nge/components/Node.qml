import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Shapes 1.12
import QtGraphicalEffects 1.13

import nge.styles 1.0

import "properties"

Item {
    
    property string nodeLabelText: "undefined"
    property int numberOfPorts : 1

    property var inEdges: ({})
    property var outEdges: []

    property double positionX: 0
    property double positionY: 0

    id: node

    signal createEdgeFromOutput(var portDragHandler)

    DropShadow {
        id: hoverShadow
        anchors.fill: nodeRectangle
        color: "#88000000"
        source: nodeRectangle
        radius: 8.0
        horizontalOffset: 0
        verticalOffset: 0
        visible: false
    }


    Rectangle {
        id: nodeRectangle
        height: nodePropertiesRect.height + 10 + nodeLabel.height + 20
        width: nodeProperties.width

        color: "yellow"
        border.color: "#777777"

        radius: 30

        x: positionX
        y: positionY

        Rectangle {
            id: nodePropertiesRect
            anchors.verticalCenter: parent.verticalCenter

            width: parent.width
            clip: true
            height: childrenRect.height

            color: NodeStyles.nodeColor
            border.width: 0

            Column {
                id: nodeProperties
                //y: nodeLabel.height + nodeLabel.y + 10

                padding: 10

                FloatPropertyInput {

                }

                FloatPropertyInput {

                }
            }
        }

        Row {
            id: inputPortsRow
            x: parent.width * 0.5 - childrenRect.width * 0.5
            y: -5
            spacing: 10
        }

        Label {
            id: nodeLabel
            text: nodeLabelText
            y: 8
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 12
            color: "black"
        }

        DragHandler {
            xAxis.minimum: node.parent.x
            xAxis.maximum: node.parent.x + node.parent.width - width
        }

        OutputPort {
            id: outputPort
            ocupied: outEdges.length > 0
        }

        MouseArea {
            anchors.fill: nodeRectangle
            hoverEnabled: true

            onEntered: hoverShadow.visible = true
            onExited: hoverShadow.visible = false
        }

        Component.onCompleted: {
            let inputPortComponent = Qt.createComponent("InputPort.qml");

            for(let i=1; i <= numberOfPorts; i++) {
                inputPortComponent.createObject(inputPortsRow, {portNumber: i, ocupied: inEdges[i]===undefined ? false : true});
            }
        }

        onXChanged: {
            updateEdgePositions();
        }

        onYChanged: {
            updateEdgePositions();
        }
    }

    function updateEdgePositions() {
        const outPortPosition = getOutPortPosition();

        outEdges.forEach( (edge) => {
             edge.outX = outPortPosition.x;
             edge.outY = outPortPosition.y;
        });

        for(let [portNumber, edge] of Object.entries(inEdges)) {
            const inPortPosition = getInPortPosition(portNumber);
            edge.inX = inPortPosition.x;
            edge.inY = inPortPosition.y;
        }
    }

    function getOutPortPosition() {
        const mappedPosition = parent.mapFromItem(nodeRectangle, outputPort.x, outputPort.y);
        return {
            x: 6 + mappedPosition.x,
            y: 6 + mappedPosition.y
        }
    }

    function getInPortPosition(port) {
        const portItem = inputPortsRow.data[port-1];
        const mappedPosition = parent.mapFromItem(inputPortsRow, portItem.x, portItem.y);
        return {
            x: 5 + mappedPosition.x,
            y: 5 + mappedPosition.y
        }
    }

    function addOutputEdge(edge) {
        outEdges.push(edge);
        let outPortPosition = getOutPortPosition();
        edge.outX = outPortPosition.x;
        edge.outY = outPortPosition.y;
    }

    function addInputEdge(edge, slot) {
        inEdges[slot] = edge;
        const inPortPosition = getInPortPosition(slot);

        edge.inX = inPortPosition.x;
        edge.inY = inPortPosition.y;
    }
}
