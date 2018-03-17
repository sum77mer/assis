import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Item {
    anchors{top:parent.top;topMargin:20}
    Column{
        id:checkcpu

        anchors{top:parent.top;left:parent.left;leftMargin:20}//anchors.topMargin:50
        CheckBox{
            text:qsTr("CPU 1")
            checked:false
        }
        CheckBox{
            text:qsTr("CPU 2")
            checked:false
        }
        CheckBox{
            text:qsTr("CPU 3")
            checked:false
        }
        CheckBox{
            text:qsTr("CPU 4")
            checked:false
        }
        CheckBox{
            text:qsTr("All CPU")
            checked:false
        }
    }
    Text{
        id:msr_ecx_title
        //anchors.top:groupbox.bottom
        anchors{topMargin:20;left:checkcpu.right;leftMargin:10}
        text:"ECX:"
        color:"black"
    }
    Text{
        id:msr_ecx_hex

        //anchors.top:groupbox.bottom
        anchors{topMargin:20;left:msr_ecx_title.right;leftMargin:10}
        text:"0x"
        color:"black"
    }
    TextField{
        id:msr_ecx

        width:100; height:15
        text:""
        anchors{verticalCenter:msr_ecx_hex.verticalCenter;left:msr_ecx_hex.right;leftMargin:5}
        style:TextFieldStyle{
            textColor:"black"
            background:Rectangle{
                //width:100
                //height:10
                color:"#f0f0f0"
                Rectangle{
                    id:topline

                    width:parent.width-1; height:1; color:"#a0a0a0"
                    anchors{top:parent.top;left:parent.left}
                }
                Rectangle{
                    id:bottomline

                    width:parent.width-1; height:1; color:"#ffffff"
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left}
                }
                Rectangle{
                    id:leftline

                    width:1;height:parent.height-1;color:"#a0a0a0"
                    anchors{top:parent.top;topMargin:1;left:parent.left}
                }
                Rectangle{
                    id:rightline

                    width:1;height:parent.height;color:"#ffffff"
                    anchors{top:parent.top;right:parent.right}
                }
            }
        }
    }
    Text{
        id:msr_eax_title

        anchors{top:msr_ecx_title.bottom;topMargin:20;left:checkcpu.right;leftMargin:10}
        text:"EAX:"
        color:"black"
    }
    Text{
        id:msr_eax_hex

        anchors{top:msr_ecx_title.bottom;topMargin:20;left:msr_eax_title.right;leftMargin:10}
        text:"0x"
        color:"black"
    }
    TextField{
        id:msr_eax

        width:100; height:15
        text:""
        anchors{verticalCenter:msr_eax_hex.verticalCenter;left:msr_eax_hex.right;leftMargin:5}
        style:TextFieldStyle{
            textColor:"black"
            background:Rectangle{
                color:"#f0f0f0"
                Rectangle{
                    width:parent.width-1;height:1;color:"#a0a0a0"
                    anchors{top:parent.top;left:parent.left}
                }
                Rectangle{
                    width:parent.width-1;height:1;color:"#ffffff"
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left}
                }
                Rectangle{
                    width:1; height:parent.height-1; color:"#a0a0a0"
                    anchors{top:parent.top;topMargin:1;left:parent.left}
                }
                Rectangle{
                    width:1; height:parent.height; color:"#ffffff"
                    anchors{top:parent.top;right:parent.right}
                }
            }
        }
    }
    Text{
        id:msr_edx_title

        anchors{top:msr_eax_title.bottom;topMargin:20;left:checkcpu.right;leftMargin:10}
        text:"EDX:"
        color:"black"
    }
    Text{
        id:msr_edx_hex

        anchors{top:msr_eax_title.bottom;topMargin:20;left:msr_edx_title.right;leftMargin:10}
        text:"0x"
        color:"black"
    }
    TextField{
        id:msr_edx

        width:100; height:15
        anchors{verticalCenter:msr_edx_hex.verticalCenter;left:msr_edx_hex.right;leftMargin:5}
        text:""
        style:TextFieldStyle{
            textColor:"black"
            background:Rectangle{
                color:"#f0f0f0"
                Rectangle{
                    width:parent.width-1; height:1; color:"#a0a0a0"
                    anchors{top:parent.top;left:parent.left}
                }
                Rectangle{
                    width:parent.width-1; height:1; color:"#ffffff"
                    anchors{top:parent.bottom;topMargin:-1;left:parent.left}
                }
                Rectangle{
                    width:1; height:parent.height-1; color:"#a0a0a0"
                    anchors{top:parent.top;topMargin:1;left:parent.left}
                }
                Rectangle{
                    width:1; height:parent.height; color:"#ffffff"
                    anchors{top:parent.top;right:parent.right}
                }
            }
        }
    }
    Button{
        id:msr_read

        text:"读"
        width:50; height:20
        //anchors.top:groupbox.bottom
        anchors{topMargin:20;left:msr_ecx_hex.right;leftMargin:200}
    }
    Button{
        id:msr_write;

        text:"写";
        width:50; height:20;
        anchors{top:msr_read.bottom;topMargin:10;left:msr_ecx_hex.right;leftMargin:200;}
    }
    Button{
        id:msr_fix

        text:"固定"
        width:50; height:20
        anchors{top:msr_write.bottom;topMargin:10;left:msr_ecx_hex.right;leftMargin:200}
        onClicked: libraryModel.append({"addr":"a","cpu1":"b","cpu2":"1","cpu3":"1","cpu4":"1"})
    }
    Button{
        id:msr_delete

        text:"删除"
        width:50; height:20
        anchors{top:msr_fix.bottom;topMargin:10;left:msr_ecx_hex.right;leftMargin:200}
        onClicked: libraryModel.remove(0)
    }
    ListModel {
        id: libraryModel

        ListElement {
            addr: "A Masterpiece"
            cpu1: "Gabriel"
            cpu2:"1"
            cpu3:"1"
            cpu4:"1"
        }
        ListElement {
            addr: "A Masterpiece"
            cpu1: "Gabriel"
            cpu2:"2"
            cpu3:"2"
            cpu4:"2"
        }
        ListElement {
            addr: "A Masterpiece"
            cpu1: "Gabriel"
            cpu2:"3"
            cpu3:"3"
            cpu4:"3"
        }

    }

    TableView {
        anchors{top:msr_edx_title.bottom;topMargin:40;left:parent.left;leftMargin:50}
        width:500
       // MouseArea{
       //     anchors.fill:parent
      //      onClicked:console.log("click on tableview")
      //  }

        TableViewColumn {
            role: "addr"
            title: "Addr"
            width: 100
            movable:false
            resizable:false
            //MouseArea{
                //anchors.fill:parent
           //     onClicked:console.log("click on tableview column addr")
            //}
        }
        TableViewColumn {
            role: "cpu1"
            title: "CPU1"
            width: 100
            movable:false
            resizable:false
        }
        TableViewColumn {
            role: "cpu2"
            title: "CPU2"
            width: 100
            movable:false
            resizable:false
        }
        TableViewColumn {
            role: "cpu3"
            title: "CPU3"
            width: 100
            movable:false
            resizable:false
        }
        TableViewColumn {
            role: "cpu4"
            title: "CPU4"
            width: 100
            movable:false
            resizable:false
        }
        model: libraryModel
        onClicked: console.log("click on tableview line ",libraryModel.get(row))
        onDoubleClicked: {
            var dict=libraryModel.get(row)
            console.log("click on tableview line ",dict)
        }
    }
}
