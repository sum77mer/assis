import QtQuick 2.0
Item {
    id:gauge
    property int value:0
    property int max:100
    property int min:0
    Rectangle{
        id:background
        width:34;height:206;color:"transparent"
        border.color:"black";border.width:2
        radius:1

        Rectangle{
            width:204;height:32;color:"white"
            anchors.centerIn:parent
            rotation:90
            radius:1
            Rectangle{
                color:"white"
                radius:1
                anchors.fill:parent;anchors.margins:1
                gradient: Gradient{
                    GradientStop{position:0.0;color:"gray"}
                    GradientStop{position:0.5;color:"white"}
                    GradientStop{position:1.0;color:"white"}
                }
            }
        }
        Rectangle{
            width:29
            height:gauge.value/gauge.max*200
            radius:2

            color:gauge.value/gauge.max>=0.9? "red":"#69b0ac";
            anchors{bottom:parent.bottom;bottomMargin: 2;left:parent.left;leftMargin:2}
            Text{
                text:value
                color:"black"
                font.pixelSize: 20
                anchors.top:parent.bottom
                anchors.topMargin:-20
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
