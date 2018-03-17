import QtQuick 2.7

Rectangle
{
    id: tabwidget

    function currentChanged(curIndex)
    {
        content.currentChangedmain(curIndex)
    }

    color: "transparent"

    Row
    {
        id: toolbar

        property int current: 0

        function setCurrentToolBtn()
        {
            for(var i = 0; i < toolbar.children.length; i++)
            {
                toolbar.children[i].state = (toolbar.current == i ? 'checked' : 'leave')
            }
            tabwidget.currentChanged(toolbar.current)
        }

        spacing: 20
        anchors{left: tabwidget.left;leftMargin: 80}
        onCurrentChanged:setCurrentToolBtn()

        BasicTabBtn
        {
            index:0
            state:"checked"
            picSrc: "qrc:/image/hard.png"
            btnText:"硬件助手"
            onClicked:toolbar.current=btnIndex
        }
        BasicTabBtn
        {
            index:1
            picSrc: "qrc:/image/soft.png"
            btnText:"软件助手"
            onClicked:toolbar.current=btnIndex
        }
        BasicTabBtn
        {
            index:2
            picSrc: "qrc:/image/test.png"
            btnText:"性能测试"
            onClicked:toolbar.current=btnIndex
        }
    }

    Rectangle
    {
        id:content

        property int current: 0

        function currentChangedmain(curIndex)
        {
            content.children[curIndex].x=width
            content.children[curIndex].state='active'
            content.children[current].state='hide'
            current = curIndex
        }

        width:tabwidget.width; height: 594; color:"white"
        anchors{top: toolbar.bottom;left:parent.left}
        //border.color:"red"
        //border.width:1

        BasicMainWidget
        {
            id:widget1

            anchors{top:parent.top;left:parent.left}
            state:"active"
            Content1
            {
                anchors.top:parent.top
            }
        }
        BasicMainWidget
        {
            id:widget2

            anchors{top:parent.top;left:parent.left}
            Content2
            {
            }
        }
        BasicMainWidget
        {
            id:widget3

            anchors{top:parent.top;left:parent.left}
            Content3
            {
            }
        }
    }
}
