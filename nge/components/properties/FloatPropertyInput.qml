import QtQuick 2.0
import QtQuick.Controls 2.12

Item {

    width: childrenRect.width
    height: childrenRect.height

    Row {
        spacing: 2

        Label {
            anchors.verticalCenter: parent.verticalCenter
            id: label
            text: "Float32: "
        }

        TextField {
            anchors.verticalCenter: parent.verticalCenter
            id: input
            placeholderText: "0.0"
            font.pointSize: 10
            height: 12
            width: 50
        }


    }

}
