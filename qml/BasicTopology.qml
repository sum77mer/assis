import QtQuick 2.0
Item{
    id:basictopo
    property ListModel model
    ListView{
        id:list
        function currentItemChanged(index){
            content.refresh(index);
        }
        anchors{top:parent.top;topMargin:10}
        width: 180; height: 500
        spacing:3
        highlightFollowsCurrentItem :true
        model: basictopo.model
        highlight: Rectangle {
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
        delegate: Rectangle{
                color:"transparent"
                width:150;height:20
                border{width:1;color:"black"}
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
        property string txt
        function refresh(index){
            //content.clear();
            content.text="refreshed";
        }
        anchors{left:list.right;leftMargin:10;top:parent.top;topMargin:10}
        readOnly:true
        text:txt
    }

}
