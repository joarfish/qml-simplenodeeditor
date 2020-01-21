import QtQuick 2.9
import QtQml.Models 2.13

import "./components"

import nge 1.0

Item {

    id: nodeGraphEditor

    NodeGraphController {
        id: nodeGraphController
    }

    Rectangle {
        color: "lightblue"
        id: container
        state: "IDLE"
        anchors.fill: parent

        states: [
            State {
                name: "IDLE"
                PropertyChanges { target: container;}
            },
            State {
                name: "CREATING_EDGE"
                PropertyChanges {
                    target: container
                }
                StateChangeScript {
                    script:{

                    }
                }
            }
        ]

        DelegateModel {
            id: edgeModelDelegate
            model: nodeGraphController.edgeModel
            delegate: Edge {
                id: edge
            }
        }

        DelegateModel {
            id: nodeModelDelegate
            model: nodeGraphController.nodeModel
            delegate: Node {
                nodeLabelText: model.label
               // positionX: model.position.x
               // positionY: model.position.y
            }
        }

        Repeater {
            id: edges
            model: edgeModelDelegate
            onItemAdded: function(index, item) {

                // Here we assume that an item's index in the
                // repeater corresponds to the QModelIndex row

                console.log("Edge added: "+index);
                let from = model.items.get(index).model.from.row;
                let to = model.items.get(index).model.to.row;

                nodes.itemAt(from).addOutputEdge(item);
                nodes.itemAt(to).addInputEdge(item, 1);
            }
        }

        Repeater {
            id: nodes
            model: nodeModelDelegate
            onItemAdded: function(index, item) {
                console.log("Edges: "+edgeModelDelegate.items.count)
                console.log("Node added: "+index);
            }
        }

    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: false
        propagateComposedEvents: true
        onPressed: mouse.accepted = false
    } 

    /*signal createNode()

    onCreateNode: {
        nodeGraphController.createNode()
    }*/

    function createNode() {
        nodeGraphController.createNode();
    }
}
