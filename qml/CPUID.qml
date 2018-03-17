import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    anchors{top:parent.top;topMargin:20;}
    Column{
        id:checkcpu;

        anchors{top:parent.top;left:parent.left;leftMargin:20;}        //anchors.topMargin:50;
        CheckBox{
            text:qsTr("CPU 1");
            checked:false;
        }
        CheckBox{
            text:qsTr("CPU 2");
            checked:false;
        }
        CheckBox{
            text:qsTr("CPU 3");
            checked:false;
        }
        CheckBox{
            text:qsTr("CPU 4");
            checked:false;
        }
        CheckBox{
            text:qsTr("All CPU");
            checked:false;
        }
    }
    Text{
        id:cpuid_eax_title;

        color:"black";
        anchors{top:parent.top;topMargin:20;left:checkcpu.right;leftMargin:10;}
        text:"EAX:";
    }
    Text{
        id:cpuid_eax_hex;

        color:"black";
        anchors{top:parent.top;topMargin:20;left:cpuid_eax_title.right;leftMargin:10;}
        text:"0x";
    }
    TextField{
        id:cpuid_eax;

        width:100; height:15;
        anchors{verticalCenter:cpuid_eax_hex.verticalCenter;left:cpuid_eax_hex.right;leftMargin:5;}
        text:"";
        style:TextFieldStyle{
            textColor:"black";
            background:Rectangle{
                //width:100;
                //height:10;
                color:"#f0f0f0";
                Rectangle{
                    id:topline;

                    width:parent.width-1; height:1; color:"#a0a0a0";
                    anchors{top:parent.top;left:parent.left;}
                }
                Rectangle{
                    id:bottomline;

                    width:parent.width-1; height:1; color:"#ffffff";
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left;}
                }
                Rectangle{
                    id:leftline;

                    width:1; height:parent.height-1; color:"#a0a0a0";
                    anchors{top:parent.top;topMargin:1;left:parent.left;}
                }
                Rectangle{
                    id:rightline;

                    width:1; height:parent.height; color:"#ffffff";
                    anchors{top:parent.top;right:parent.right;}
                }
            }
        }
    }
    Text{
        id:cpuid_ecx_title;

        color:"black";
        anchors{top:parent.top;topMargin:20;left:cpuid_eax.right;leftMargin:10;}
        text:"ECX:";
    }
    Text{
        id:cpuid_ecx_hex;

        color:"black";
        anchors{top:parent.top;topMargin:20;left:cpuid_ecx_title.right;leftMargin:10;}
        text:"0x";
    }
    TextField{
        id:cpuid_ecx;

        width:100; height:15;
        anchors{verticalCenter:cpuid_ecx_hex.verticalCenter;left:cpuid_ecx_hex.right;leftMargin:5;}
        text:"";
        style:TextFieldStyle{
            textColor:"black";
            background:Rectangle{
                //width:100;
                //height:10;
                color:"#f0f0f0";
                Rectangle{
                    //id:topline;
                    width:parent.width-1; height:1; color:"#a0a0a0";
                    anchors{top:parent.top;left:parent.left;}
                }
                Rectangle{
                    //id:bottomline;
                    width:parent.width-1; height:1; color:"#ffffff";
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left;}
                }
                Rectangle{
                    //id:leftline;
                    width:1; height:parent.height-1; color:"#a0a0a0";
                    anchors{top:parent.top;topMargin:1;left:parent.left;}
                }
                Rectangle{
                    //id:rightline;
                    width:1; height:parent.height; color:"#ffffff";
                    anchors{top:parent.top;right:parent.right;}
                }
            }
        }
    }
    Text{
        id:cpuid_output_eax_title;

        color:"black";
        anchors{top:cpuid_eax_title.bottom;topMargin:20;left:checkcpu.right;leftMargin:10;}
        text:"EAX:";
    }
    Text{
        id:cpuid_output_eax_hex;

        color:"black";
        anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_eax_title.right;leftMargin:10;}
        text:"0x";
    }
    TextField{
        id:cpuid_output_eax;

        width:100; height:15;
        anchors{verticalCenter:cpuid_output_eax_hex.verticalCenter;left:cpuid_output_eax_hex.right;leftMargin:5;}
        text:"";
        style:TextFieldStyle{
            textColor:"black";
            background:Rectangle{
                //width:100;height:10;
                color:"#f0f0f0";
                Rectangle{
                    //id:topline;
                    width:parent.width-1; height:1; color:"#a0a0a0";
                    anchors{top:parent.top;left:parent.left;}
                }
                Rectangle{
                    //id:bottomline;
                    width:parent.width-1; height:1; color:"#ffffff";
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left;}
                }
                Rectangle{
                    //id:leftline;
                    width:1; height:parent.height-1; color:"#a0a0a0";
                    anchors{top:parent.top;topMargin:1;left:parent.left;}
                }
                Rectangle{
                    //id:rightline;
                    width:1; height:parent.height; color:"#ffffff";
                    anchors{top:parent.top;right:parent.right;}
                }
            }
        }
    }
    Text{
        id:cpuid_output_ebx_title;

        color:"black";
        anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_eax.right;leftMargin:10;}
        text:"EBX:";
    }
    Text{
        id:cpuid_output_ebx_hex;

        color:"black";
        anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_ebx_title.right;leftMargin:10;}
        text:"0x";
    }
    TextField{
        id:cpuid_output_ebx;

        width:100; height:15;
        anchors{verticalCenter:cpuid_output_ebx_hex.verticalCenter;left:cpuid_output_ebx_hex.right;leftMargin:5;}
        text:"";
        style:TextFieldStyle{
            textColor:"black";
            background:Rectangle{
                //width:100; height:10;
                color:"#f0f0f0";
                Rectangle{
                    //id:topline;
                    width:parent.width-1; height:1; color:"#a0a0a0";
                    anchors{top:parent.top;left:parent.left;}
                }
                Rectangle{
                    //id:bottomline;
                    width:parent.width-1; height:1; color:"#ffffff";
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left;}
                }
                Rectangle{
                    //id:leftline;
                    width:1; height:parent.height-1; color:"#a0a0a0";
                    anchors{top:parent.top;topMargin:1;left:parent.left;}
                }
                Rectangle{
                    //id:rightline;
                    width:1; height:parent.height; color:"#ffffff";
                    anchors{top:parent.top;right:parent.right;}
                }
            }
        }
    }
    Text{
        id:cpuid_output_ecx_title;

        color:"black";
        anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_ebx.right;leftMargin:10;}
        text:"ECX:";
    }
    Text{
        id:cpuid_output_ecx_hex;

        color:"black";
        anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_ecx_title.right;leftMargin:10;}
        text:"0x";
    }
    TextField{
        id:cpuid_output_ecx;

        width:100; height:15;
        anchors{verticalCenter:cpuid_output_ecx_hex.verticalCenter;left:cpuid_output_ecx_hex.right;leftMargin:5;}
        text:"";
        style:TextFieldStyle{
            textColor:"black";
            background:Rectangle{
                //width:100; height:10;
                color:"#f0f0f0";
                Rectangle{
                    //id:topline;
                    width:parent.width-1; height:1; color:"#a0a0a0";
                    anchors{top:parent.top;left:parent.left;}
                }
                Rectangle{
                    //id:bottomline;
                    width:parent.width-1; height:1; color:"#ffffff";
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left;}
                }
                Rectangle{
                    //id:leftline;
                    width:1; height:parent.height-1; color:"#a0a0a0";
                    anchors{top:parent.top;topMargin:1;left:parent.left;}
                }
                Rectangle{
                    //id:rightline;
                    width:1; height:parent.height; color:"#ffffff";
                    anchors{top:parent.top;right:parent.right;}
                }
            }
        }
    }

    Text{
        id:cpuid_output_edx_title;

        color:"black";
        anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_ecx.right;leftMargin:10;}
        text:"EDX:";
    }
    Text{
        id:cpuid_output_edx_hex;

        color:"black";
        anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_edx_title.right;leftMargin:10;}
        text:"0x";
    }
    TextField{
        id:cpuid_output_edx;

        width:100; height:15;
        anchors{verticalCenter:cpuid_output_edx_hex.verticalCenter;left:cpuid_output_edx_hex.right;leftMargin:5;}
        text:"";
        style:TextFieldStyle{
            textColor:"black";
            background:Rectangle{
                //width:100;
                //height:10;
                color:"#f0f0f0";
                Rectangle{
                    //id:topline;
                    width:parent.width-1; height:1; color:"#a0a0a0";
                    anchors{top:parent.top;left:parent.left;}
                }
                Rectangle{
                    //id:bottomline;
                    width:parent.width-1; height:1; color:"#ffffff";
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left;}
                }
                Rectangle{
                    //id:leftline;
                    width:1; height:parent.height-1; color:"#a0a0a0";
                    anchors{top:parent.top;topMargin:1;left:parent.left;}
                }
                Rectangle{
                    //id:rightline;
                    width:1; height:parent.height; color:"#ffffff";
                    anchors{top:parent.top;right:parent.right;}
                }
            }
        }
    }
    Button{
        id:cpuid_read;

        width:50; height:20;
        anchors{top:parent.top;topMargin:20;left:cpuid_output_edx.right;leftMargin:10;}
        text:"读";
    }

    Button{
        id:cpuid_fix;

        width:50; height:20;
        anchors{top:cpuid_read.bottom;topMargin:10;left:cpuid_output_edx.right;leftMargin:10;}
        text:"固定";
    }
    ListModel {
        id: libraryModel;

        ListElement {
            addr: "A Masterpiece";
            cpu1: "Gabriel";
            cpu2:"1";
            cpu3:"1";
            cpu4:"1";
        }
        ListElement {
            addr: "A Masterpiece";
            cpu1: "Gabriel";
            cpu2:"2";
            cpu3:"2";
            cpu4:"2";
        }
        ListElement {
            addr: "A Masterpiece";
            cpu1: "Gabriel";
            cpu2:"3";
            cpu3:"3";
            cpu4:"3";
        }


    }
    TableView {
        anchors{top:cpuid_output_edx_title.bottom;topMargin:40;left:parent.left;leftMargin:50;}
        width:500;
       // MouseArea{
       //     anchors.fill:parent;
      //      onClicked:console.log("click on tableview");
      //  }
        TableViewColumn {
            role: "addr";
            title: "Addr";
            width: 100;
            //MouseArea{
                //anchors.fill:parent;
           //     onClicked:console.log("click on tableview column addr");
            //}
        }
        TableViewColumn {
            role: "cpu1";
            title: "CPU1";
            width: 100;
        }
        TableViewColumn {
            role: "cpu2";
            title: "CPU2";
            width: 100;
        }
        TableViewColumn {
            role: "cpu3";
            title: "CPU3";
            width: 100;
        }
        TableViewColumn {
            role: "cpu4";
            title: "CPU4";
            width: 100;
        }
        model: libraryModel;
        onClicked: {
            //console.log("click on tableview line ",libraryModel.get(row));
        }
        onDoubleClicked: {
            var dict=libraryModel.get(row);
           // console.log("click on tableview line ",dict);
        }
    }

}
