/*
  1. groupbox's width, height
  2. title
*/
import QtQuick 2.0
/*
//dropshadow  escapetime:1.3ms
import QtGraphicalEffects 1.0
Item{
    id:group_box

    property int boxWidth
    property int boxHeight
    property string boxTitle
    property color backColor

    width:boxWidth; height:boxHeight

    Rectangle{
        id:frame

        width:group_box.boxWidth; height:group_box.boxHeight; color:"transparent"
        border{width:1; color:"#a0a0a0"}
    }
    DropShadow{
        id:verticalOffset_shadow

        color:"white"
        anchors.fill:frame
        //cached:true
        horizontalOffset:0
        verticalOffset:1
        radius:0
        samples: 16
        source:frame
        spread:0
        //transparentBorder:
    }
    DropShadow{
        id:horizontal_shadow

        color:"white"
        anchors.fill:frame
        //cached:true
        horizontalOffset:1
        verticalOffset:0
        radius:0
        samples: 16
        source:frame
        spread:0
        //transparentBorder:
    }
    Rectangle{
        id:title_bkg

        width:100; height:20; color:group_box.backColor
        anchors{left:parent.left; leftMargin:20;top:parent.top; topMargin:-10}

        Text{
            id:title

            anchors.centerIn:parent
            text:group_box.boxTitle
        }
    }
}

*/

//这是第一种实现方法
//rectangle duration:5.77us
Rectangle{//id:groupbox
    property string titlestr:"undefined"
    property int boxWidth
    property int boxHeight
    property color backColor

    width:boxWidth; height:boxHeight; color:"transparent"
    border{width:1;color:"#a0a0a0"}

    Rectangle{
        id:groupbox_topline

        width:parent.boxWidth-2; height:1; color:"white"
        anchors{top:parent.top;topMargin: 1;left:parent.left;leftMargin: 1}
    }
    Rectangle{
        id:groupbox_bottomline

        width:parent.boxWidth; height:1; color:"white"
        anchors{top:parent.bottom;left:parent.left}
    }
    Rectangle{
        id:groupbox_leftline

        width:1; height:parent.boxHeight-2; color:"white"
        anchors{top:parent.top;topMargin: 1;left:parent.left;leftMargin: 1}
    }
    Rectangle{
        id:groupbox_rightline

        width:1; height:parent.boxHeight+1; color:"white"
        anchors{top:parent.top; left:parent.right}
    }
    Rectangle{
        id:title

        width:70; height:20; color:"#f0f0f0"
        anchors{top:parent.top;topMargin:-8;left:parent.left;leftMargin:10}

        Text{
            text:titlestr
            anchors.centerIn: parent
        }
    }
}

