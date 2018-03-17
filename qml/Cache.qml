import QtQuick 2.0
import QtQuick.Layouts 1.3
Item {
    BasicGroupBox{
        id:groupbox_first_datacache
        boxWidth:parent.width-40; boxHeight:100; backColor:"#f0f0f0"
        anchors{top:parent.top; topMargin:10; left:parent.left; leftMargin:20}
        titlestr:"一级数据缓存"

        RowLayout{
            id:group1_row1
            anchors{top:parent.top; topMargin:20;left:parent.left; leftMargin:40}
            Text{
                text:"大小"
            }
            BasicEditControl{
                text:"6 MBytes";
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
            }
            BasicEditControl{
                text:" "
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
            }
        }
        RowLayout{
            id:group1_row2
            anchors{top:group1_row1.bottom; topMargin:10;left:parent.left; leftMargin:40}
            Text{
                text:"描述";
            }
            BasicEditControl{
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
                text:"12-way set associative, 64-byte line size"
            }
        }



    }
    BasicGroupBox{
        id:groupbox_first_instcache
        boxWidth:parent.width-40; boxHeight:100; backColor:"#f0f0f0"
        anchors{top:groupbox_first_datacache.bottom; topMargin:10; left:parent.left; leftMargin:20}
        titlestr:"一级指令缓存"
        RowLayout{
            id:group2_row1
            anchors{top:parent.top; topMargin:20;left:parent.left; leftMargin:40}
            Text{
                text:"大小"
            }
            BasicEditControl{
                text:"6 MBytes";
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
            }
            BasicEditControl{
                text:" "
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
            }
        }
        RowLayout{
            id:group2_row2
            anchors{top:group2_row1.bottom; topMargin:10;left:parent.left; leftMargin:40}
            Text{
                text:"描述";
            }
            BasicEditControl{
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
                text:"12-way set associative, 64-byte line size"
            }
        }

    }
    BasicGroupBox{
        id:groupbox_second_cache
        boxWidth:parent.width-40; boxHeight:100; backColor:"#f0f0f0"
        anchors{top:groupbox_first_instcache.bottom; topMargin:10; left:parent.left; leftMargin:20}
        titlestr:"二级缓存"
        RowLayout{
            id:group3_row1
            anchors{top:parent.top; topMargin:20;left:parent.left; leftMargin:40}
            Text{
                text:"大小"
            }
            BasicEditControl{
                text:"6 MBytes";
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
            }
            BasicEditControl{
                text:" "
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
            }
        }
        RowLayout{
            id:group3_row2
            anchors{top:group3_row1.bottom; topMargin:10;left:parent.left; leftMargin:40}
            Text{
                text:"描述";
            }
            BasicEditControl{
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
                text:"12-way set associative, 64-byte line size"
            }
        }
    }
    BasicGroupBox{
        id:groupbox_third_box
        boxWidth:parent.width-40; boxHeight:100; backColor:"#f0f0f0"
        anchors{top:groupbox_second_cache.bottom; topMargin:10; left:parent.left; leftMargin:20}
        titlestr:"三级缓存";
        RowLayout{
            id:group4_row1
            anchors{top:parent.top; topMargin:20;left:parent.left; leftMargin:40}
            Text{
                text:"大小"
            }
            BasicEditControl{
                text:"6 MBytes";
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
            }
            BasicEditControl{
                text:" "
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
            }
        }
        RowLayout{
            id:group4_row2
            anchors{top:group4_row1.bottom; topMargin:10;left:parent.left; leftMargin:40}
            Text{
                text:"描述";
            }
            BasicEditControl{
                width:50; height:Text.contentHeight
                textMargin:5
                Layout.leftMargin:5
                text:"12-way set associative, 64-byte line size"
            }
        }
    }
}
