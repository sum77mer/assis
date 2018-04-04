import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Rectangle{
    id:cpu;

    width:parent.width; height:parent.height
    anchors{left:parent.left;top:parent.top}
    state:"hide";
    //border{color:"yellow";width:10}
    Component.onCompleted: {
        //console.log("cpu's state is",cpu.state);
    }
    TabView{
        id:tabview

        //tabsVisible: true
        frameVisible: true
        anchors{fill:parent;margins: 5}
        style:TabViewStyle{
            frame:Rectangle{
                color:"#f0f0f0";
                border{color:"#a0a0a0";width:1}
            }
           tab:Rectangle{
                anchors.centerIn: parent;
                implicitWidth:90;
                implicitHeight:20;
                color:styleData.selected ? "#f0f0f0":"#c0c0c0";
                border{color:"#a0a0a0";width:1}
                //radius:2
                Text{
                    text:styleData.title
                    color: styleData.selected ? "black" : "gray"
                    anchors{horizontalCenter: parent.horizontalCenter;verticalCenter: parent.verticalCenter;}
                }
            }
        }

        Tab{
            title:"处理器";
            source:"Cpu.qml";
        }
        Tab{
            title:"缓存";
            source:"Cache.qml";
        }
        Tab{
            title:"CPUID";
            source:"CPUID.qml";
        }
        Tab{
            title:"MSR";
            source:"MSR.qml";
        }
    }

    states:
    [
        State
        {
            name:"active";
            PropertyChanges
            {
                target: cpu;
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
                target: cpu
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
