import QtQuick 2.0

Rectangle {
    id:otherdev

    width:parent.width; height:parent.height; color:"#f0f0f0"
    anchors{left:parent.left;top:parent.top}
    state:"hide";
    Component.onCompleted: {
       // console.log("board's state is",board.state);
    }
    ListView{
        id:audio_list
        width:contentWidth;height:contentHeight
        anchors{top:parent.top;topMargin:20;left:parent.left;leftMargin:20}
        spacing:10
        model:ListModel{
            ListElement{
                title:"声卡";
                content:"High Definition Autio Controller(nVIDIA unknown)";
            }
            ListElement{
                title:"声卡";
                content:"Intel Lynx Point PCH - High Definition Audio Controller(Realtel ALC899)";
            }
        }
        delegate:Text{
            text:title+"   "+content;
        }
    }
    ListView{
        id:mouse_list
        width:contentWidth;height:contentHeight
        anchors{top:audio_list.bottom;topMargin:20;left:parent.left;leftMargin:20}
        spacing:10
        model:ListModel{
            ListElement{
                title:"鼠标";
                content:"HID-compliant mouse";
            }
        }
        delegate:Text{
            text:title+"   "+content;
        }
    }
    ListView{
        id:keyboard_list
        width:contentWidth;height:contentHeight
        anchors{top:mouse_list.bottom;topMargin:20;left:parent.left;leftMargin:20}
        spacing:10
        model:ListModel{
            ListElement{
                title:"键盘";
                content:"HID Keyboard Device";
            }
        }
        delegate:Text{
            text:title+"   "+content;
        }
    }
    states:
    [
        State
        {
            name:"active";
            PropertyChanges
            {
                target: otherdev;
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
                target: otherdev
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
