import QtQuick 2.0
import QtQuick.Controls 2.2 as QPopup
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
QPopup.Popup{//id:edit;
    width:200; height:50;
    focus:true;
    //modal:true;
    //closePolicy:QtPopUp.Popup.CloseOnEscape|QtPopUp.Popup.CloseOnPressOutsideParent;
    background:Rectangle{
        width:200; height:50;
        color:"white";
    }
    ColumnLayout{
        spacing:3
        anchors{horizontalCenter:parent.horizontalCenter;verticalCenter:parent.verticalCenter}
        RowLayout{
            id:row_edit_bin
            spacing:5

            TextInput{
                id:edit1
                Layout.preferredWidth: 15
                Layout.preferredHeight:15
                maximumLength: 1
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.top:parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    width:15; height:1; color:"black"
                }
            }
            TextInput{
                id:edit2
                Layout.preferredWidth: 15
                Layout.preferredHeight:15
                maximumLength: 1
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.top:parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    width:15; height:1; color:"black"
                }
            }
            TextInput{
                id:edit3
                Layout.preferredWidth: 15
                Layout.preferredHeight:15
                maximumLength: 1
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.top:parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    width:15; height:1; color:"black"
                }
            }
            TextInput{
                id:edit4
                Layout.preferredWidth: 15
                Layout.preferredHeight:15
                maximumLength: 1
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.top:parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    width:15; height:1; color:"black"
                }
            }
            TextInput{
                id:edit5
                Layout.preferredWidth: 15
                Layout.preferredHeight:15
                maximumLength: 1
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.top:parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    width:15; height:1; color:"black"
                }
            }
            TextInput{
                id:edit6
                Layout.preferredWidth: 15
                Layout.preferredHeight:15
                maximumLength: 1
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.top:parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    width:15; height:1; color:"black"
                }
            }
            TextInput{
                id:edit7
                Layout.preferredWidth: 15
                Layout.preferredHeight:15
                maximumLength: 1
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.top:parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    width:15; height:1; color:"black"
                }
            }
            TextInput{
                id:edit8
                Layout.preferredWidth: 15
                Layout.preferredHeight:15
                maximumLength: 1
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.top:parent.bottom
                    anchors.horizontalCenter:parent.horizontalCenter
                    width:15; height:1; color:"black"
                }
            }
            Button{
                id:done
                text:"Done"
                Layout.preferredWidth:40
                Layout.preferredHeight:20
            }
        }
        RowLayout{
            id:row_edit_hex
            spacing:10
            TextEdit{
                id:edit_input_hex
                Layout.preferredWidth:150
                Layout.preferredHeight:15
                horizontalAlignment:TextEdit.AlignHCenter
                Rectangle{
                    anchors.fill:parent
                    anchors.margins: -2
                    color:"transparent"
                    border{width:1; color:"black"}
                }
            }
            Button{
                id:cancel

                text:"Cancel"
                Layout.preferredWidth:40
                Layout.preferredHeight:20
            }
        }
    }
}
/*
                MouseArea{
                    drag.target: edit
                    drag.axis:Drag.XAxis
                    //Drag.minimumX: 0
                    //Drag.maximumX: mytableview.width-edit.width
                }
*/
