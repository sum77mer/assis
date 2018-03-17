import QtQuick 2.0
import QtQuick.Controls 2.2 as QPopup
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4

QPopup.Popup{//id:edit;
    width:200; height:25;
    focus:true;
    //modal:true;
    //closePolicy:QtPopUp.Popup.CloseOnEscape|QtPopUp.Popup.CloseOnPressOutsideParent;
    background:Rectangle{
        width:parent.width; height:parent.height;
        //color:"#7db9de";
        }
        TextField{
            id:edit1

            width:15; height:Text.contentHeight;
            anchors{verticalCenter: parent.verticalCenter;left:parent.left;leftMargin: 10}
            maximumLength: 1
            style:TextFieldStyle{
                background:Rectangle{
                    width:parent.width; height:parent.height;
                    //color:"#f0f0f0";
                    Rectangle{
                        width:15; height:1; color:"#a0a0a0";
                        anchors{top:parent.top;topMargin:20}
                    }
                }
            }
        }
        TextField{
            id:edit2

            width:15; height:Text.contentHeight;
            anchors{verticalCenter: parent.verticalCenter;left:edit1.right;leftMargin: 5}
            maximumLength: 1
            style:TextFieldStyle{
                background:Rectangle{
                    width:parent.width; height:parent.height;
                    //color:"#f0f0f0";
                    Rectangle{
                        width:15; height:1; color:"#a0a0a0";
                        anchors{top:parent.top;topMargin:20;}
                    }
                }
            }
        }
        TextField{
            id:edit3

            width:15; height:Text.contentHeight;
            anchors{verticalCenter: parent.verticalCenter;left:edit2.right;leftMargin: 5;}
            maximumLength: 1
            style:TextFieldStyle{
                background:Rectangle{
                    width:parent.width;
                    height:parent.height;
                    //color:"#f0f0f0";
                    Rectangle{
                        width:15; height:1; color:"#a0a0a0"
                        anchors{top:parent.top;topMargin:20;}
                    }
                }
            }
        }
        TextField{
            id:edit4

            width:15; height:Text.contentHeight;
            anchors{verticalCenter: parent.verticalCenter;left:edit3.right;leftMargin: 5;}
            maximumLength: 1
            style:TextFieldStyle{
                background:Rectangle{
                    width:parent.width; height:parent.height;
                    //color:"#f0f0f0";
                    Rectangle{
                        width:15; height:1; color:"#a0a0a0";
                        anchors{top:parent.top;topMargin:20;}
                    }
                }
            }
        }
        TextField{
            id:edit5

            width:15; height:Text.contentHeight;
            anchors{verticalCenter: parent.verticalCenter;left:edit4.right;leftMargin: 5}
            maximumLength: 1
            style:TextFieldStyle{
                background:Rectangle{
                    width:parent.width; height:parent.height;
                    //color:"#f0f0f0";
                    Rectangle{
                        width:15; height:1; color:"#a0a0a0"
                        anchors{top:parent.top;topMargin:20}
                    }
                }
            }
        }
        TextField{
            id:edit6

            width:15; height:Text.contentHeight;
            anchors{verticalCenter: parent.verticalCenter;left:edit5.right;leftMargin: 5}
            maximumLength: 1
            style:TextFieldStyle{
                background:Rectangle{
                    width:parent.width; height:parent.height;
                    //color:"#f0f0f0";
                    Rectangle{
                        width:15; height:1; color:"#a0a0a0";
                        anchors{top:parent.top;topMargin:20;}
                    }
                }
            }
        }
        TextField{
            id:edit7

            width:15; height:Text.contentHeight;
            anchors{verticalCenter: parent.verticalCenter;left:edit6.right;leftMargin: 5}
            maximumLength: 1
            style:TextFieldStyle{
                background:Rectangle{
                    width:parent.width; height:parent.height;
                    //color:"#f0f0f0";
                    Rectangle{
                        width:15; height:1; color:"#a0a0a0"
                        anchors{top:parent.top;topMargin:20}
                    }
                }
            }
        }
                /*
                      TextField{
                      id:edit8
                    maximumLength: 1
                    width:15
                    height:Text.contentHeight;
                    anchors.verticalCenter: parent.verticalCenter;
                    anchors.left:edit7.right
                    anchors.leftMargin: 5
                    style:TextFieldStyle{
                        background:Rectangle{
                            width:parent.width;
                            height:parent.height;
                            //color:"#f0f0f0";
                            Rectangle{
                                width:15;
                                height:1;
                                color:"#a0a0a0";
                                anchors.top:parent.top;
                                anchors.topMargin:20;
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
            }
