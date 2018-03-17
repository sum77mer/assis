import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
TextEdit{
    id:textEdit
    Rectangle {
                id:back

                radius: 2
                width:parent.width; height:parent.height; color:"transparent"
                Rectangle{
                    id:topline

                    radius:2
                    color:"#a0a0a0"
                    width:parent.width-1
                    height:1
                    anchors{top:parent.top;left:parent.left}
                }
                Rectangle{
                    id:bottomline

                    radius:2
                    width:parent.width-1; height:1; color:"#ffffff"
                    anchors{top:rightline.bottom;left:leftline.right}
                }
                Rectangle{
                    id:leftline

                    radius:2
                    width:1; height:parent.height-1; color:"#a0a0a0"
                    anchors{top:topline.bottom;left:parent.left}
                }
                Rectangle{
                    id:rightline

                    radius:2
                    width:1; height:parent.height-1; color:"#ffffff"
                    anchors{top:parent.top;left:topline.right}
                }
            }
}
/*
TextField {
    id:textedit

    property alias textstring:textedit.text
    //property int textwidth:Text.contentWidth
    //property alias borderwidth:back.implicitWidth
    //property alias borderheight:back.implicitHeight
    //property alias textcolor:textfieldstyle.textColor

    text:"undefined"
    style: TextFieldStyle {
        id:textfieldstyle

        textColor: "black"
        background: Rectangle {
            id:back

            radius: 2
            //width:Text.contentWidth
            width:parent.width; height:parent.height; color:"#f0f0f0"

            Rectangle{
                id:topline

                radius:2
                color:"#a0a0a0"
                width:parent.width-1
                height:1
                anchors{top:parent.top;left:parent.left}
            }
            Rectangle{
                id:bottomline

                radius:2
                width:parent.width-1; height:1; color:"#ffffff"
                anchors{top:rightline.bottom;left:leftline.right}
            }
            Rectangle{
                id:leftline

                radius:2
                width:1; height:parent.height-1; color:"#a0a0a0"
                anchors{top:topline.bottom;left:parent.left}
            }
            Rectangle{
                id:rightline

                radius:2
                width:1; height:parent.height-1; color:"#ffffff"
                anchors{top:parent.top;left:topline.right}
            }
        }
    }
}

*/

