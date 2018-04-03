import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Rectangle {
    id:page1_content

    function currentChangedv(curIndex)
    {
        maincontent.currentChangedmaincontent(curIndex)
    }

    width:80; height:parent.height

    ColumnLayout{
        id:vtab

        property int current: 0

        function setCurrentvTabBtn()
        {
            for(var i = 0; i < vtab.children.length; i++)
            {
                vtab.children[i].state = (vtab.current == i ? 'checked' : 'leave')
            }
            page1_content.currentChangedv(vtab.current)
        }

        spacing:0
        anchors{top:parent.top;left:parent.left}//anchors.leftMargin: 5//anchors.topMargin: 5
        onCurrentChanged:setCurrentvTabBtn()

        BasicVTabBtn{
            //color:"red"
            index:0
            btnText:"综合信息"
            onClicked:vtab.current=btnIndex
        }
        BasicVTabBtn{
            //color:"red"
            index:1
            btnText:"主板"
            onClicked:vtab.current=btnIndex
        }
        BasicVTabBtn{
            //color:"red"
            index:2
            btnText:"CPU"
            onClicked:vtab.current=btnIndex
        }
        BasicVTabBtn{
            //color:"red"
            index:3
            btnText:"内存"
            onClicked:vtab.current=btnIndex
        }
        BasicVTabBtn{
            //color:"red"
            index:4
            btnText:"PCI"
            onClicked:vtab.current=btnIndex
        }
        BasicVTabBtn{
            //color:"red"
            index:5
            btnText:"存储设备"
            onClicked:vtab.current=btnIndex
        }
        BasicVTabBtn{
            //color:"red"
            index:6
            btnText:"显示设备"
            onClicked:vtab.current=btnIndex
        }
        BasicVTabBtn{
            //color:"red"
            index:7
            btnText:"网络设备"
            onClicked:vtab.current=btnIndex
        }
        BasicVTabBtn{
            //color:"red"
            index:8
            btnText:"其他设备"
            onClicked:vtab.current=btnIndex
        }
    }
    ColumnLayout{
        id:btn_group
        anchors{top:vtab.top;topMargin:500;horizontalCenter: vtab.horizontalCenter}
        //anchors{top:parent.top;left:parent.left}
        spacing:3
        Rectangle{
            id:autofresh_btn
            //Layout.topMargin:450
            width:60;height:20;color:"#f0f0f0"
            border{width:1;color:"#a0a0a0"}
            //anchors.horizontalCenter: parent.horizontalCenter
            Text{
                id:autofresh_btntxt
                text:"自动刷新"
                font.pointSize: 8
                anchors.centerIn: parent
            }
            MouseArea{
                id:autofresh_btnarea
                anchors.fill:parent
                onClicked: {
                    //manualfresh_btn.color="#f0f0f0"
                    //console.log("")
                    autofresh_btntxt.text="停止刷新"
                }
            }
        }
        Rectangle{
            id:manualfresh_btn
            width:60;height:20;color:"#f0f0f0"
            border{width:1;color:"#a0a0a0"}
            Layout.topMargin:5
            //anchors.horizontalCenter: parent.horizontalCenter
            Text{
                id:manualfresh_btntxt
                text:"手动刷新"
                font.pointSize: 8
                anchors.centerIn: parent
            }
            MouseArea{
                id:manualfresh_btnarea
                anchors.fill:parent
                onClicked: {
                    //manualfresh_btn.color="#f0f0f0"
                    //console.log("")
                }
            }
        }
        Rectangle{
            id:reportoutput_btn
            width:60;height:20;color:"#f0f0f0"
            border{width:1;color:"#a0a0a0"}
            Layout.topMargin:5
            anchors.horizontalCenter: parent.horizontalCenter
            radius:2
            Text{
                text:"输出报告"
                font.pointSize: 8
                anchors.centerIn: parent
            }
            MouseArea{
                id:reportoutput_btnarea
                anchors.fill:parent
                onClicked: {
                    //manualfresh_btn.color="#f0f0f0"
                    //console.log("")
                }
            }
        }
    }
    Rectangle{
        id:frameline

        width:1; height:594; color:"#20666666"
        anchors{left:vtab.right;top:parent.top}
        Component.onCompleted: {
           // console.log("frameline's x,y: ",frameline.x,frameline.y)
        }
    }
    Rectangle{
        id:maincontent

        property int current: 0

        function currentChangedmaincontent(curIndex)
        {
            maincontent.children[curIndex].x=width
            maincontent.children[curIndex].state='active'
            maincontent.children[current].state='hide'
            current = curIndex
        }

        width:819; height:594
        anchors{left:frameline.right;top:parent.top}
        //border{color:"red";width: 10}

        HardZhxx{}
        HardBoard{}
        HardCPU{}
        HardMemory{}
        HardPCI{}
        HardStorage{}
        HardGFX{}
        HardNet{}
        HardOtherDev{}
    }
}
