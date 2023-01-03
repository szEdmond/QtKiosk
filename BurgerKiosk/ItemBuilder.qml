import QtQuick 2.15

Item {
    // IF CHOSEN ITEM == BURGER list ingredients
    // Else dont give building options
    property var extras : control.getExtras()

    Rectangle{
        anchors.fill: parent
        color: "#334"
        Text{
            id: itemName
            text: control.getName()
            font.pixelSize: 44
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }
        // if burger, list ingredients
        GridView{
            // if our object is a burger list ingredients else don't
            model: control.isItBurger() ? extras : ""
            cellWidth: parent.width
            cellHeight: 40
            anchors{
                top:itemName.bottom
                bottom:parent.bottom
                horizontalCenter: parent.horizontalCenter
            }
            delegate: Rectangle{
                width: 200
                height:35
                color:"#48D"
                anchors.horizontalCenter: parent.horizontalCenter
                radius: 5
                Text{
                    id: extraName
                    text: extras[index]
                    font.pixelSize: 20
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text{
                    id: counter
                    text: "0"
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.rightMargin: 5
                    font.pixelSize: 18
                }

                MouseArea{
                    anchors.fill: parent
                    cursorShape: "PointingHandCursor"
                    onClicked:{
                        control.addItem(extraName.text);
                        counter.text++
                    }
                }
            }
        }
    }

    // Add to Cart
    Rectangle{
        width: parent.width/2
        height: 50
        color: "#3D3"
        radius: 10
        anchors{
            bottom: parent.bottom
            bottomMargin: 40
            horizontalCenter: parent.horizontalCenter
        }
        Text{
            text:"Add_To_Cart"
            font.pixelSize: 18
            color:"white"
            anchors.centerIn: parent
            font.bold: true
        }
        MouseArea{
            anchors.fill: parent;
            onClicked:{
                control.addToCart()
                statusBar.cartsize.text = control.getCartSize()
                stackView.pop()
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
                stackView.pop()
            }
        }
    }
}
