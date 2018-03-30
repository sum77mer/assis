import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Rectangle{
    id:board;

    width:parent.width; height:parent.height; color:"#f0f0f0"
    anchors{left:parent.left;top:parent.top}
    state:"hide";
    //border{color:"blue";width:10}
    Component.onCompleted: {
       // console.log("board's state is",board.state);
    }

    ScrollView{
        id:scrollview_board

        anchors.fill:parent
        //highlightOnFocus: true//no diference
        Rectangle{
            id:emptylayer

            color:"transparent"
            width:parent.width;height:1000
            ListView{
                id:boardbasicinfo_list
                width:contentWidth; height:contentHeight;
                anchors{top:parent.top;topMargin:20;left:parent.left;leftMargin:20;}
                spacing:10;
                model:ListModel{
                    ListElement{
                        title:"主板";
                        content:"";
                    }
                    ListElement{
                        title:"主板ID";
                        content:"63-0100-000001-00101111-012413-Chipset$1AQQW000_BIOS DATE: 04/16/14 14:48:12 VER: 04.06.05";
                    }
                    ListElement{
                        title:"主板名称";
                        content:"未知";
                    }
                    ListElement{
                        title:"前端总线特性";
                        content:"";
                    }
                    ListElement{
                        title:"总线类型";
                        content:"BCLK";
                    }
                    ListElement{
                        title:"外部频率";
                        content:"100 MHz";
                    }
                    ListElement{
                        title:"有效频率";
                        content:"100 MHz";
                    }
                    ListElement{
                        title:"内存总线特性";
                        content:"";
                    }
                    ListElement{
                        title:"总线类型";
                        content:"Dual DDR3 SDRAM";
                    }
                    ListElement{
                        title:"总线位宽";
                        content:"128 位";
                    }
                    ListElement{
                        title:"DRAM：FSB";
                        content:"20:3";
                    }
                    ListElement{
                        title:"外部频率";
                        content:"667 MHz (DDR)";
                    }
                    ListElement{
                        title:"有效频率";
                        content:"1333 MHz";
                    }
                    ListElement{
                        title:"带宽";
                        content:"21333 MB/秒";
                    }
                    ListElement{
                        title:"芯片组";
                        content:"";
                    }
                    ListElement{
                        title:"总线类型";
                        content:"Intel Direct Media Interface v2.0";
                    }
                    ListElement{
                        title:"北桥";
                        content:"Intel Haswell-DT IMC";
                    }
                    ListElement{
                        title:"修订";
                        content:"06";
                    }
                    ListElement{
                        title:"工艺技术";
                        content:"22 nm";
                    }
                    ListElement{
                        title:"内存控制器类型";
                        content:"Dual Channel  (128 位)";
                    }
                    ListElement{
                        title:"内存控制器启用模式";
                        content:"Dual Channel  (128 位)";
                    }
                    ListElement{
                        title:"集成图形控制器类型";
                        content:"Intel HD Graphics";
                    }
                    ListElement{
                        title:"集成图形控制器状态";
                        content:"已禁用";
                    }
                }
                delegate:Text{
                    text:title+"    "+content;
                }
            }
            BasicTopology{
                id:smbios_topo
                anchors{top:boardbasicinfo_list.bottom;topMargin:20}
            }
        }

    }
    states:
    [
        State
        {
            name:"active";
            PropertyChanges
            {
                target: board;
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
                target: board;
                //x:maincontent.x + 2*width;
                //anchors.left:parent.right;
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
