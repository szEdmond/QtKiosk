import QtQuick 2.15

Item {

    property var names : control.getFullList()
    property var prices : control.getFullPriceList()

    Rectangle{
        anchors.fill: parent
        color: "#f5e4b5"

        //Total
        Text{
            id: total
            text:"TOTAL:"
            anchors.left: parent.left
            anchors.leftMargin: 50
            font.pixelSize: 28
            font.bold: true
        }
        Text{
            text: Math.round(control.getTotal()*100)/100
            anchors.right: parent.right
            anchors.rightMargin: 50
            font.pixelSize: 28
            font.bold: true
        }

        //Receipt
        GridView{
            width:parent.width/2
            cellWidth: parent.width/2
            cellHeight: 30
            anchors{
                top: total.bottom
                left:parent.left
                bottom: parent.bottom
                leftMargin: 50
            }
            model: names
            // item name
            delegate: Text{
                text: names[index]
                font.pixelSize: names[index][0]==='\t'? 12 : 18
            }
        }
        GridView{
            width:parent.width/2
            cellWidth: parent.width/2
            cellHeight: 30
            anchors{
                top: total.bottom
                right: parent.right
                bottom: parent.bottom
                rightMargin: 50
            }
            model:prices
            delegate: Text{
                anchors.right: parent.right
                text: prices[index]
                font.pixelSize: prices[index][0] === '+' ? 12 : 18
            }
        }

        // Buy
        Rectangle{
            color: "#3D3"
            width: parent.width/2
            height: 50
            radius: 10
            anchors{
                bottom: parent.bottom
                bottomMargin: 40
                horizontalCenter: parent.horizontalCenter
            }
            Text{
                text:"Buy"
                font.pixelSize: 18
                color:"white"
                anchors.centerIn: parent
                font.bold: true
            }
            MouseArea{
                cursorShape: "PointingHandCursor"
                anchors.fill: parent
                onClicked:{
                    mainLoader.source = "StackViewPage.qml"
                    control.clearCart()
                }
            }
        }

        // BackButton
        Image{
            source: "qrc:/UI/Assets/return.png"
            width:40
            height: 40
            anchors{
                bottom: parent.bottom
                left: parent.left
            }
            MouseArea{
                anchors.fill: parent
                onClicked:{
                    mainLoader.source = "StackViewPage.qml"
                }
            }
        }
    }
}
