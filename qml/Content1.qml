import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Rectangle {
    id:vtabwidget

    function currentChangedv(curIndex)
    {
        maincontent.currentChangedmaincontent(curIndex)
    }

    width:80; height:parent.height
    //border{width:1;color:"red"}

    Column{
        id:vtab

        property int current: 0

        function setCurrentvTabBtn()
        {
            for(var i = 0; i < vtab.children.length; i++)
            {
                vtab.children[i].state = (vtab.current == i ? 'checked' : 'leave')
            }
            vtabwidget.currentChangedv(vtab.current)
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
    }
}
