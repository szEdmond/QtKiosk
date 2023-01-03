import QtQuick 2.15
import QtQuick.Layouts 1.3

import Singleton

Item {

    property bool isBurger : true
    property var items: control.getBurgers()
    property var images: control.burgerImages()

    ListModel{
        id: sideMenuListModel
        ListElement {
            menuText: "Burgers"
            img: "burger.png"
        }
        ListElement {
            menuText: "Sides"
            img: "fries.png"
        }
        ListElement {
            menuText: "Drinks"
            img: "soda.png"
        }
    }

    Component{
        id: rightSide
        GridView{
            anchors.fill: parent

            cellWidth: parent.width
            cellHeight: 120  // items * ~30 ???
            model: items.length
            delegate: Rectangle {
                width: parent.width
                height: 100
                radius:5
                color: "#48D"
                Rectangle{
                    radius:4
                    anchors.left: parent.left
                    anchors.top: parent.top
                    width: 100
                    height: parent.height
                    color: "black"
                    Image{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        source: "qrc:/UI/Assets/" + images[index]
                    }
                }

                Text{
                    id: itemName
                    width: parent.width -100
                    anchors{
                        right: parent.right
                        verticalCenter: parent.verticalCenter
                    }
                    font.pixelSize: 22

                    // index based on model ??
                    text: items[index]
                    color:"black"
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: "PointingHandCursor"
                    onClicked: {
                        // make a chosen item object copy
                        control.setChosenItem(itemName.text, isBurger)
                        // next step
                        stackView.push("ItemBuilder.qml")

                    }
                }
            }
        }
    }

    //Component(delegate) for listview
    Component{
        id: menuitemDelegate
        Rectangle{
            id: selectedButton
            width: 100
            height: 100
            radius: 50
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter

            Image{
                source: "/UI/Assets/" + model.img
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MouseArea{
                anchors.fill:parent
                cursorShape: "PointingHandCursor"
                onPressed:{
                    selectedButton.color = "grey"
                }
                onReleased: {
                    selectedButton.color = "black"
                }
                onClicked:{
                    // Replacing items based on categories
                    if(model.menuText === "Sides"){
                        items = control.getSides()
                        images = control.sideImages()
                        isBurger = false;
                    }
                    else if( model.menuText === "Burgers"){
                        items = control.getBurgers()
                        images = control.burgerImages()
                        isBurger = true;
                    }
                    else if( model.menuText === "Drinks"){
                        items = control.getDrinks()
                        images = control.drinkImages()
                        isBurger = false;
                    }
                }
            }
        }
    }

    // LEFT side FoodGroup selection MENU
    Rectangle{
        id: foodGroupRectangle
        height: parent.height
        width: 200
        anchors {
            top: parent.top
            left:parent.left
        }
        color: "#222"
        // left side button holder
        ListView{
            id: foodMenuListView
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top:parent.top
            height:parent.height

            model: sideMenuListModel

            spacing: 30
            delegate:menuitemDelegate
        }
    }

    // RIGHT SIDE ItemList
    Rectangle {
        id: foodListingRectangle
        height: parent.height
        width: parent.width-foodGroupRectangle.width
        anchors{
            top:parent.top
            right:parent.right
        }
        color:"#334"

        Loader{
            id: ld
            sourceComponent: rightSide
            active:true
            anchors.fill: parent
        }
    }
}

