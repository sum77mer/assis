import QtQuick 2.0
//import QtQuick.Layouts 1.3
//import QtQuick.Controls 1.4
Item{
    Component {
        id: highlight
        Rectangle {
            width: 100; height: 20
            color: "lightsteelblue"; radius: 5
            y: list.currentItem.y
            Behavior on y {
                SpringAnimation {
                    spring: 3
                    damping: 0.2
                }
            }
        }
    }
    ListView{
        id:list
        anchors{top:parent.top;topMargin:10}
        width: 180; height: 500
        highlightFollowsCurrentItem :true
        highlight: highlight
        spacing:3
        function currentItemChanged(index){
            content.refresh(index);
        }
            model: ListModel {
                id:listmodel
                ListElement{
                    name:"cpu1"
                }
                ListElement{
                    name:"cpu2"
                }
                ListElement{
                    name:"cpu3"
                }
                ListElement{
                    name:"cpu4"
                }
                ListElement{
                    name:"cpu5"
                }
            }
            delegate: Rectangle{
                color:"transparent"
                width:150;height:20
                Text {
                    id:text
                    text: name
                    anchors.centerIn: parent
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        list.currentIndex=index;
                        console.log("clickde",list.currentIndex);
                        list.currentItemChanged(list.currentIndex);
                    }
                }
            }
    }
    TextEdit{
        id:content
        anchors{left:list.right;leftMargin:10;top:parent.top;topMargin:10}
        function refresh(index){
            //content.clear();
            content.text="refreshed";
        }
        text:"empty"
    }

}
