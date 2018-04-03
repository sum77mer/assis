import QtQuick 2.0

Rectangle {
    id:net

    width:parent.width; height:parent.height; color:"#f0f0f0"
    anchors{left:parent.left;top:parent.top}
    state:"hide";
    Component.onCompleted: {
       // console.log("board's state is",board.state);
    }
    ListView{
        id:net_list
        width:contentWidth;height:contentHeight;
        anchors{top:parent.top;topMargin:20;left:parent.left;leftMargin:20}
        spacing:10
        model:ListModel{
            ListElement{
                title:"网卡型号";
                content:"Haswell / Lynx Point";
            }
        }
        delegate:Text{
            text:title+"  "+content;
        }
    }
    states:
    [
        State
        {
            name:"active";
            PropertyChanges
            {
                target: net;
                //x:parent.x;
                //anchors.left:parent.left;
                visible:true;
            }

        },
        State
        {
            name:"hide";
            PropertyChanges
            {
                target: net
                visible:false;
            }
        }

    ]

    transitions:Transition
    {
        PropertyAnimation
        {
            property:"visible";
            duration: 100;
            easing.type: Easing.OutBounce;
            easing.amplitude: 0.1;
        }
    }
}
