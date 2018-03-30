import QtQuick 2.0
import QtQuick.Controls 1.4
//import QtQuick.Controls.Styles 1.4
Rectangle{
    id:zhxx;

    width:parent.width;
    height:parent.height;
    color:"#f0f0f0";
    anchors{left:parent.left;top:parent.top;}
    //border{color:"red";width: 10;}
    state:"active";
    Component.onCompleted: {
        //console.log("zhxx's x,y is:",zhxx.y,zhxx.y);
        //console.log("zhxx is ",zhxx.state);
        //console.log("zhxx's width,height is:",zhxx.width,zhxx.height);
    }
    ScrollView{
        id:scrollview_zhxx;

        anchors.fill:parent;
        //verticalScrollBarPolicy: Qt.ScrollBarAlwaysOn;

        Rectangle{
            id:emptylayer;

            width:parent.width; height:800; color:"transparent";

            Rectangle{
                id:cpulogo;

                width:100; height:100; color:"transparent";
                border{color:"black";width:1;}
                anchors{top:parent.top;topMargin:30;left:parent.left;leftMargin:660;}
                //anchors.right:parent.right;//这个rectangle的right不知道在哪，anchors会消失
                //anchors.rightMargin:15;
                MouseArea{
                    anchors.fill:parent;
                    onClicked:Qt.openUrlExternally("https://www.intel.cn");
                }
                //BasicPopUp{
                    //id:edit;
                //}
            }
            Text{
                id:title_diannaoxinghao;

                text:"电脑型号：";
                anchors{top:parent.top;topMargin:20;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"戴尔 XPS 8700 台式电脑";
                anchors{top:title_diannaoxinghao.top;left:parent.left;leftMargin:70;}
            }
            Text{
                id:title_os;

                text:"操作系统";
                anchors{top:title_diannaoxinghao.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"Windows 7 旗舰版 64位 SP1（DiretX 11）";
                anchors{top:title_os.top;left:parent.left;leftMargin:70;}
            }
            Text{
                id:title_cpu;

                text:"处理器";
                anchors{top:title_os.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"英特尔 第四代酷睿 i5-4460 @3.20GHz 四核";
                anchors{top:title_cpu.top;left:emptylayer.left;leftMargin:70;}
            }
            Text{
                id:title_board;

                text:"主板";
                anchors{top:title_cpu.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"戴尔 0KWVT8（英特尔 Haswell - Lynx Point）";
                anchors{top:title_board.top;left:emptylayer.left;leftMargin:70;}
            }
            Text{
                id:title_memory;

                text:"内存";
                anchors{top:title_board.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"24GB （海力士 DDR3 1600MHz /英睿达 DDR3L 1600 MHz）";
                anchors{top:title_memory.top;left:emptylayer.left;leftMargin:70;}
            }
            Text{
                id:title_zhuyingpan;

                text:"主硬盘";
                anchors{top:title_memory.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:""
                anchors{top:title_zhuyingpan.top;left:emptylayer.left;leftMargin:70;}
            }
            Text{
                id:title_gfx;

                text:"显卡";
                anchors{top:title_zhuyingpan.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"Nvidia GeForce GT 720(1GB /Nvidia)";
                anchors{top:title_gfx.top;left:emptylayer.left;leftMargin:70;}
            }
            Text{
                id:title_monitor;

                text:"显示器";
                anchors{top:title_gfx.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"通用非即插即用监视器";
                anchors{top:title_monitor.top;left:emptylayer.left;leftMargin:70;}
            }
            Text{
                id:title_guangqu;

                text:"光驱";
                anchors{top:title_monitor.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"TSSTcorp DVD + -RW SH-216DB DVD刻录机";
                anchors{top:title_guangqu.top;left:emptylayer.left;leftMargin:70;}
            }
            Text{
                id:title_audiocard;

                text:"声卡";
                anchors{top:title_guangqu.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"瑞昱 ALC899 @英特尔 Lynx Point 高保真音频";
                anchors{top:title_audiocard.top;left:emptylayer.left;leftMargin:70;}
            }
            Text{
                id:title_netcard;

                text:"网卡";
                anchors{top:title_audiocard.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
            Text{
                text:"瑞昱 RTL8168/8111/8112 Gigabit Ethernet Controller/戴尔";
                anchors{top:title_netcard.top;left:emptylayer.left;leftMargin:70;}
            }
            /*
            BasicGauge{
                id:cpu_gauge
                value:70
                anchors{top:title_netcard.bottom;topMargin:10;left:parent.left;leftMargin:30;}
            }
            BasicChart{
                id:cpu_chart
                width:400;height:300
                anchors{top:title_netcard.bottom;topMargin:10;left:cpu_gauge.right;leftMargin:50;}
            }
            BasicChart{
                id:memory_chart
                width:400;height:300
                anchors{top:cpu_chart.bottom;topMargin:10;left:parent.left;leftMargin:10;}
            }
*/

        }
    }
    states:
    [
        State
        {
            name:"active";
            PropertyChanges
            {
                target: zhxx;
                visible:true;
            }

        },
        State
        {
            name:"hide";
            PropertyChanges
            {
                target: zhxx;
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
