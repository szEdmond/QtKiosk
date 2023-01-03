import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import Singleton 1.0

Window {
    id: root
    width: 540
    height: 1000
    visible: true
    title: qsTr("BurgerChain Kiosk")

    MyController{
        id: control
    }

    StatusBar{
        id: statusBar
    }

    Loader{
        id: mainLoader
        anchors{
            left:parent.left
            right:parent.right
            top: statusBar.bottom
            bottom: parent.bottom
        }
        source: "StackViewPage.qml"
    }



}
