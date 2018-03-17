import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
Rectangle{
    width:916; height:716; color:"transparent"

    Item{
        id:container

        width: parent.width; height: parent.height;
        anchors.centerIn: parent;

        Rectangle {
            id:mainwindow

            width: container.width-(2*rectShadow.radius); height: container.height - (2*rectShadow.radius)
            visible: true
            //border{color:"red";width:1}
            anchors.centerIn: parent;
            //anchors{verticalCenter: parent.verticalCenter;horizontalCenter: parent.horizontalCenter}
            //title: qsTr("Hello World")
            //flags: "Window|FramelessWindowHint"

            Image{
                id:backgnd

                //width: parent.width; height: parent.height
                source:"qrc:/image/panel.png"

                MouseArea{
                    property variant previousPosition

                    anchors.fill:parent
                    onPressed:previousPosition=Qt.point(mouse.x,mouse.y);
                    onPositionChanged:{
                        if(pressedButtons==Qt.LeftButton){
                            var dx=mouse.x-previousPosition.x;
                            var dy=mouse.y-previousPosition.y;
                            window.x=window.x+dx;
                            window.y=window.y+dy;
                        }
                    }
                }
                MouseArea{
                    id:logopress

                    property variant previousPosition

                    width:118; height:51
                    anchors{top:backgnd.top;topMargin:35;left:backgnd.left;leftMargin:715}
                    //x:715
                    //y:35
                    onClicked:Qt.openUrlExternally("http://www.zhaoxin.com/");
                    onPressed:previousPosition=Qt.point(mouse.x,mouse.y);
                    onPositionChanged:{
                        if(pressedButtons==Qt.LeftButton){
                            var dx=mouse.x-previousPosition.x;
                            var dy=mouse.y-previousPosition.y;
                            window.x=window.x+dx;
                            window.y=window.y+dy;
                        }
                    }
                }
            }
            Text{
                id:title

                anchors{top:mainwindow.top;topMargin:10;left:mainwindow.left;leftMargin:10}
                //x:10
                //y:10
                width:125; height:12; color:"#9e9e9e"
                text:"SV助手"
                font{family:"微软雅黑";bold:true;pixelSize:16}
            }
            TabWidget{
                id: tabwidget

                //x: 0;y: 40;
                width:900; height:660
                anchors{top:mainwindow.top;topMargin:40;left:mainwindow.left}
                //border{width:2;color:"red"}
               // Component.onCompleted: console.log("tabwidget's",x,"-",y)
            }
            SysBtnGroup{
                id: sysbtngrp

                anchors{top:mainwindow.top;left:mainwindow.left;leftMargin:755}
                //x: 755; y: 0
                onMin: window.showMinimized()
                onClose: window.close()
            }
        }
    }
    DropShadow{
        id:rectShadow

        color: "#80000000";
        anchors.fill:source
        cached: true;
        horizontalOffset: 0;
        verticalOffset: 3;
        radius: 8.0;
        samples: 16;
        smooth: true;
        source: container;
    }
}

