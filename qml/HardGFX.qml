import QtQuick 2.0

Rectangle {
    id:gfx

    width:parent.width; height:parent.height; color:"#f0f0f0"
    anchors{left:parent.left;top:parent.top}
    state:"hide";

    Component.onCompleted: {
       // console.log("board's state is",board.state);
    }
    BasicGroupBox{
        id:gfx_group
        boxWidth:parent.width-40; boxHeight:100; backColor:"#f0f0f0"
        anchors{top:parent.top; topMargin:10; left:parent.left; leftMargin:20}
        titlestr:"显卡"
        ListView{
            id:gfx_list
            width:contentWidth;height:contentHeight
            anchors{top:parent.top;topMargin:20;left:parent.left;leftMargin:20}
            spacing:10
            model:ListModel{
                ListElement{
                    title:"显卡";
                    content:"Dell Inc";
                }
                ListElement{
                    title:"Version";
                    content:"A08";
                }
                ListElement{
                    title:"Date";
                    content:"04/16/2014";
                }
            }
            delegate:Text{
                text:title+"   "+content;
            }
        }
    }
    BasicGroupBox{
        id:monitor_group
        boxWidth:parent.width-40; boxHeight:100; backColor:"#f0f0f0"
        anchors{top:gfx_group.bottom; topMargin:10; left:parent.left; leftMargin:20}
        titlestr:"显示器"
        ListView{
            id:monitor_list
            width:contentWidth;height:contentHeight
            anchors{top:parent.top;topMargin:20;left:parent.left;leftMargin:20}
            spacing:10
            model:ListModel{
                ListElement{
                    title:"显示器";
                    content:"Dell Inc";
                }
                ListElement{
                    title:"Version";
                    content:"A08";
                }
                ListElement{
                    title:"Date";
                    content:"04/16/2014";
                }
            }
            delegate:Text{
                text:title+"   "+content;
            }
        }
    }
    BasicTopology{
        id:edid_topo
        anchors{top:monitor_group.bottom;topMargin:20;left:parent.left;leftMargin:50}
        model:ListModel{
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
            ListElement{name:""}
        }
    }

    states:
    [
        State
        {
            name:"active";
            PropertyChanges
            {
                target: gfx;
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
                target: gfx
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
