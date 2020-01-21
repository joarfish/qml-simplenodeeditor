import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Shapes 1.12

import nge 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Light Node Graph Editor")

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            Action { text: qsTr("&New...") }
            Action { text: qsTr("&Open...") }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&Edit")
            Action {
                text: qsTr("Add Node")
                onTriggered: nge.createNode()
            }
        }
        Menu {
            title: qsTr("&Help")
            Action {
                text: qsTr("&About")
            }
        }
    }

    NodeGraphEditor {
        id: nge
        anchors.fill: parent
    }
}
