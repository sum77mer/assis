import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.2 as QtPopUp
import QtQuick 2.2

TableView{
    id:mytableview

    //backgroundVisible: false
    //frameVisible: false
    headerDelegate: Rectangle{
        id:headerdel

        color:"transparent"
        anchors.fill:parent
        border{width:1;color:"#505050"}
        radius:3
    }
    rowDelegate: Rectangle{
        id:rowdel

        color:"transparent"
        anchors.fill:parent
        //border{width:1; color:"#696969"}

        Component.onCompleted: {
            //console.log("*******row height*********")
            //console.log(rowdel.height)
        }
    }
    itemDelegate: Rectangle{
        id:itemdel

        color:"#ffffe1"
        anchors.fill:parent
        //anchors.margins: 1
        Text{
            text:styleData.value; color:"black"
            elide:Text.ElideMiddle
            anchors.fill:parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            Component.onCompleted: {
                /*console.log("************tableview fontsize*****************")
                console.log(font.pixelSize)*/
            }
        }
        MouseArea{
            anchors.fill:parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                console.log("*****single click*******");
                       if (mouse.button == Qt.RightButton)
                       {
                           parent.color = 'blue';
                           console.log("*****right click*******");
                       }
                   }
            onDoubleClicked: {
                edit.open();
                console.log("*****double click*******");
            }
            /*
            BasicPopUp{
                id:edit
            }


            QtPopUp.Popup{
                id:edit;
                width:200;
                height:25;
                background:Rectangle{
                    width:parent.width;
                    height:parent.height;
                    //color:"#7db9de";
                }
                //modal:true;
                focus:true;
                //closePolicy:QtPopUp.Popup.CloseOnEscape|QtPopUp.Popup.CloseOnPressOutsideParent;

                TextField{
                    id:edit1
                    maximumLength: 1
                    width:15
                    height:Text.contentHeight;
                    anchors.verticalCenter: parent.verticalCenter;
                    anchors.left:parent.left
                    anchors.leftMargin: 10
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
                TextField{
                    id:edit2
                    maximumLength: 1
                    width:15
                    height:Text.contentHeight;
                    anchors.verticalCenter: parent.verticalCenter;
                    anchors.left:edit1.right
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
                TextField{
                    id:edit3
                    maximumLength: 1
                    width:15
                    height:Text.contentHeight;
                    anchors.verticalCenter: parent.verticalCenter;
                    anchors.left:edit2.right
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
                TextField{
                    id:edit4
                    maximumLength: 1
                    width:15
                    height:Text.contentHeight;
                    anchors.verticalCenter: parent.verticalCenter;
                    anchors.left:edit3.right
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
                TextField{
                    id:edit5
                    maximumLength: 1
                    width:15
                    height:Text.contentHeight;
                    anchors.verticalCenter: parent.verticalCenter;
                    anchors.left:edit4.right
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
                TextField{
                    id:edit6
                    maximumLength: 1
                    width:15
                    height:Text.contentHeight;
                    anchors.verticalCenter: parent.verticalCenter;
                    anchors.left:edit5.right
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
                TextField{
                    id:edit7
                    maximumLength: 1
                    width:15
                    height:Text.contentHeight;
                    anchors.verticalCenter: parent.verticalCenter;
                    anchors.left:edit6.right
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
                MouseArea{
                    drag.target: edit
                    drag.axis:Drag.XAxis
                    //Drag.minimumX: 0
                    //Drag.maximumX: mytableview.width-edit.width
                }
            }*/
        }
    }

    function createTableViewColumn(arrayData){
        var arrayTitle=arrayData[1];
        //var arrayWidth=arrayData[2];
        var arrayRole=arrayData[0];
        var prefix='import QtQuick 2.7;
                import QtQuick.Controls 1.4;
                TableViewColumn {';//width: ';
        for(var i=0;i<arrayRole.length;i++)
        {
            //var str=prefix+arrayWidth[i]+";resizable:false;movable:false;role:\""+
            var str=prefix+"resizable:false;movable:false;role:\""+
                    arrayRole[i]+"\";title:\""+arrayTitle[i]+"\"}";
            //if(i=)
            var ob=mytableview.addColumn(Qt.createQmlObject(str,mytableview,"dynamicSnippet1"));
            //console.log("**************")
            //for(var p in ob)
            //    console.log(p,":",ob[p])
            //console.log("**************")
            //console.log("#",i,"#",str)
        }
    }
}
