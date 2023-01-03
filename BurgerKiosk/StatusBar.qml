import QtQuick 2.15
import QtQuick.Layouts 1.3

Rectangle {
    id: statusBar
    height:150
    anchors{
        top: parent.top
        left: parent.left
        right: parent.right
    }
    color: "#111"

    property alias cartsize : cartsize
    Image{
        width:50
        height:50
        anchors{
            right: parent.right
            topMargin: 10
            rightMargin: 10
        }
        source: "/UI/Assets/" + "cart.png"

        Text{
            id: cartsize
            text: control.getCartSize()
            font.pixelSize: 22
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            color: "white"
            font.bold: true
        }
        MouseArea{
            cursorShape: "PointingHandCursor"
            anchors.fill: parent
            onClicked: {
                mainLoader.source = "Cart.qml"
            }
        }
    }

    Text{
        text: "BANNER"
        font.pixelSize: 32
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color: "white"
    }
}
