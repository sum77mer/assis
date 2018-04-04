import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
Item {
    anchors{top:parent.top;topMargin:20;}

    RowLayout{
        id:checkcpu;
        spacing:10

        anchors{top:parent.top;horizontalCenter: parent.horizontalCenter}        //anchors.topMargin:50;
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
    GridLayout{
        id:cpuid_layout
        rows:3; rowSpacing: 10
        flow:GridLayout.TopToBottom
        anchors{left:checkcpu.left; top:checkcpu.bottom; topMargin:20}
        Text{
            id:cpuid_eax_title;

            color:"black";
            //anchors{top:parent.top;topMargin:20;left:checkcpu.right;leftMargin:10;}
            text:"EAX:";
        }
        Text{
            id:cpuid_output_eax_title;

            color:"black";
            Layout.topMargin:20
            //anchors{top:cpuid_eax_title.bottom;topMargin:20;left:checkcpu.right;leftMargin:10;}
            text:"EAX:";
        }
        Text{
            id:cpuid_output_ecx_title;

            color:"black";
            //anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_ebx.right;leftMargin:10;}
            text:"ECX:";
        }
//col2
        Text{
            id:cpuid_eax_hex;

            color:"black";
            Layout.leftMargin:5
            //anchors{top:parent.top;topMargin:20;left:cpuid_eax_title.right;leftMargin:10;}
            text:"0x";
        }
        Text{
            id:cpuid_output_eax_hex;

            color:"black";
            Layout.leftMargin:5
            Layout.topMargin:20
            //anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_eax_title.right;leftMargin:10;}
            text:"0x";
        }
        Text{
            id:cpuid_output_ecx_hex;

            color:"black";
            Layout.leftMargin:5
            //anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_ecx_title.right;leftMargin:10;}
            text:"0x";
        }
//col3

        BasicEditControl{
            id:cpuid_eax

            width:80;height:24
            //anchors{verticalCenter:cpuid_eax_hex.verticalCenter;left:cpuid_eax_hex.right;leftMargin:5;}
            text:"        "
        }
        BasicEditControl{
            id:cpuid_output_eax

            width:80;height:24//Text.contentHeight
            Layout.topMargin:20
            //anchors{verticalCenter:cpuid_output_eax_hex.verticalCenter;left:cpuid_output_eax_hex.right;leftMargin:5;}
            text:"        "
            readOnly: true
        }
        BasicEditControl{
            id:cpuid_output_ecx
            //anchors{verticalCenter:cpuid_output_ecx_hex.verticalCenter;left:cpuid_output_ecx_hex.right;leftMargin:5;}
            width:80;height:24//Text.contentHeight

            text:"        "
            readOnly: true
        }
//col4
        Text{
            id:cpuid_ecx_title;

            color:"black";
            Layout.leftMargin:10
            //anchors{top:parent.top;topMargin:20;left:cpuid_eax.right;leftMargin:10;}
            text:"ECX:";
        }
        Text{
            id:cpuid_output_ebx_title;

            color:"black";
            Layout.leftMargin:10
            Layout.topMargin:20
            //anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_eax.right;leftMargin:10;}
            text:"EBX:";
        }
        Text{
            id:cpuid_output_edx_title;

            color:"black";
            Layout.leftMargin:10
            //anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_ecx.right;leftMargin:10;}
            text:"EDX:";
        }

//col5
        Text{
            id:cpuid_ecx_hex;

            color:"black";
            Layout.leftMargin:5
            //anchors{top:parent.top;topMargin:20;left:cpuid_ecx_title.right;leftMargin:10;}
            text:"0x";
        }
        Text{
            id:cpuid_output_ebx_hex;

            color:"black";
            Layout.leftMargin:5
            Layout.topMargin:20
            //anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_ebx_title.right;leftMargin:10;}
            text:"0x";
        }
        Text{
            id:cpuid_output_edx_hex;

            color:"black";
            Layout.leftMargin:5
            //anchors{top:cpuid_eax_title.bottom;topMargin:20;left:cpuid_output_edx_title.right;leftMargin:10;}
            text:"0x";
        }
//col6
        BasicEditControl{
            id:cpuid_ecx

            width:80;height:24//Text.contentHeight
            //anchors{verticalCenter:cpuid_ecx_hex.verticalCenter;left:cpuid_ecx_hex.right;leftMargin:5;}
            text:"        "
        }
        BasicEditControl{
            id:cpuid_output_ebx

            width:80;height:24//Text.contentHeight
            Layout.topMargin:20
            //anchors{verticalCenter:cpuid_output_ebx_hex.verticalCenter;left:cpuid_output_ebx_hex.right;leftMargin:5;}
            text:"        "
            readOnly: true
        }
        BasicEditControl{
            id:cpuid_output_edx
            //anchors{verticalCenter:cpuid_output_edx_hex.verticalCenter;left:cpuid_output_edx_hex.right;leftMargin:5;}
            width:80;height:24//Text.contentHeight
            text:"        "
            readOnly: true
        }

    }
    ColumnLayout{
        id:btn_row
        spacing:20
        anchors{verticalCenter:cpuid_layout.verticalCenter;left:cpuid_layout.right;leftMargin:20}
        Button{
            id:cpuid_read;

            width:50; height:20;
            text:"读";
        }
        Button{
            id:cpuid_fix;

            width:50; height:20;
            text:"固定";
        }
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
        anchors{top:cpuid_layout.bottom;topMargin:40;horizontalCenter: parent.horizontalCenter}//left:parent.left;leftMargin:50;
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
