import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
Rectangle{
    id:memory;

    width:parent.width; height:parent.height; color:"#f0f0f0";
    anchors{left:parent.left;top:parent.top;}
    state:"hide";

    ScrollView{
        id:scrollview_memory;
        parent:memory
        anchors.fill:parent;
        verticalScrollBarPolicy: Qt.ScrollBarAlwaysOn
        Component.onCompleted: console.log("memory scroll:",width,"**",height)
        Rectangle{
            id:emptylayer

            color:"transparent"
            BasicGroupBox{
                id:groupbox_memory_general;

                anchors{top:parent.top;topMargin:20;left:parent.left; leftMargin:40}

                titlestr:"常规"
                boxWidth:690; boxHeight:60
                backColor:"#f0f0f0"
               RowLayout{
                    id:memory_general_gridlayout
                    anchors.top:parent.top; anchors.topMargin:20
                    //anchors.horizontalCenter: parent.horizontalCenter
//col1
                    Text{
                        id:title_leixing;

                        text:"类型";
                        Layout.leftMargin:100
                    }
                    BasicEditControl{
                           id:edit_leixing;

                           width:50; height:Text.contentHeight;//Text.contentWidth;
                           Layout.leftMargin:5
                           readOnly: true;
                           text:"DDR3";
                       }
                    Text{
                        id:title_daxiao;

                        text:"大小";
                        Layout.leftMargin:35
                        Layout.alignment: Qt.AlignRight
                    }
                    BasicEditControl{
                        id:edit_daxiao;

                        width:50; height:Text.contentHeight;//Text.contentWidth
                        Layout.leftMargin:5
                        readOnly: true;
                        text:"24 GBytes";
                    }
//col3
                    Text{
                        id:title_tongdaoshu;

                        text:"通道数";
                        Layout.leftMargin:35
                    }
                    BasicEditControl{
                        id:edit_tongdaoshu;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        Layout.leftMargin:5
                        readOnly: true;
                        text:"双通道";
                        //anchors{top:title_tongdaoshu.top;topMargin:-5;left:title_tongdaoshu.right;leftMargin:5;}
                    }
                    Text{
                        id:title_pinlv;

                        text:"频率";
                        Layout.leftMargin:35
                        Layout.alignment: Qt.AlignRight
                    }
                    BasicEditControl{
                        id:edit_pinlv;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        Layout.leftMargin:5
                        readOnly: true;
                        text:"3192.4 MHz";
                    }
                }
            }
            BasicGroupBox{
                id:groupbox_memory_clock;

                anchors{top:groupbox_memory_general.bottom;topMargin:20;left:parent.left; leftMargin:40}

                titlestr:"时序"
                boxWidth:690; boxHeight:100
                backColor:"#f0f0f0"
                GridLayout{
                    id:memory_clock_gridlayout
                    rows:2; rowSpacing:10
                    flow:GridLayout.TopToBottom
                    anchors{top:parent.top; topMargin:20;horizontalCenter:parent.horizontalCenter}
//col1
                    Text{
                        id:title_neicunpinlv;

                        text:"内存频率";
                        Layout.leftMargin:20
                        Layout.alignment: Qt.AlignRight
                    }
                    Text{
                        id:title_zongxianneicun;

                        text:"前端总线：内存";
                        Layout.alignment: Qt.AlignRight
                    }
//col2
                    BasicEditControl{
                        id:edit_neicunpinlv;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"665.1 MHz";
                        Layout.leftMargin:5
                        //anchors{top:title_neicunpinlv.top;topMargin:-5;left:title_neicunpinlv.right;leftMargin:5;}
                    }

                    BasicEditControl{
                        id:edit_zongxianneicun;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        Layout.leftMargin:5
                        text:"1：5";
                    }

//col3
                    Text{
                        id:title_casyanchi;

                        text:"CAS延迟";
                        Layout.alignment: Qt.AlignRight
                        Layout.leftMargin:10
                    }
                    Text{
                        id:title_rascas;

                        text:"RAS到CAS";
                        Layout.alignment: Qt.AlignRight
                        Layout.leftMargin:10
                    }

//col4
                    BasicEditControl{
                        id:edit_casyanchi;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        Layout.leftMargin:5
                        readOnly: true;
                        text:"9.0时钟";
                    }

                    BasicEditControl{
                        id:edit_rascas;

                        width:50; height:Text.contentHeight;//Text.contentWidth
                        Layout.leftMargin:5
                        readOnly: true;
                        text:"9时钟";
                    }


//col5


                    Text{
                        id:title_rasyuchongdian;

                        text:"RAS预充电";
                        Layout.alignment: Qt.AlignRight
                        Layout.leftMargin:10
                    }
                    Text{
                        id:title_xunhuanzhouqi;

                        text:"循环周期";
                        Layout.alignment: Qt.AlignRight
                        Layout.leftMargin:10

                    }
//col6
                    BasicEditControl{
                        id:edit_rasyuchongdian;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"9时钟";
                       Layout.leftMargin:5
                        //anchors{top:title_rasyuchongdian.top;topMargin:-5;left:title_rasyuchongdian.right;leftMargin:5;}
                    }

                    BasicEditControl{
                        id:edit_xunhuanzhouqi;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"24 时钟";
                        Layout.leftMargin:5
                        //anchors{top:title_xunhuanzhouqi.top;topMargin:-5;left:title_xunhuanzhouqi.right;leftMargin:5;}
                    }


//col7
                    Text{
                        id:title_rrct;

                        text:"Row Refresh Cycle Time";
                        Layout.alignment: Qt.AlignRight
                        Layout.leftMargin:10
                    }
                    Text{
                        id:title_zhilingbilv;

                        text:"指令比率";
                        Layout.alignment: Qt.AlignRight
                        Layout.leftMargin:10
                    }


//col8
                    BasicEditControl{
                        id:edit_rrct;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"200 时钟";
                        Layout.leftMargin:5
                        //anchors{top:title_rrct.top;topMargin:-5;left:title_rrct.right;leftMargin:5;}
                    }

                    BasicEditControl{
                        id:edit_zhilingbilv;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"2T";
                        Layout.leftMargin:5
                        //anchors{top:title_zhilingbilv.top;topMargin:-5;left:title_zhilingbilv.right;leftMargin:5}
                    }
                }
            }
            Button{
                id:btn_addr;

                text:"Addr=0x00000000";
                anchors{top:groupbox_memory_clock.bottom;topMargin:20;left:mytableview.left;}
            }
            BasicTableView{
                id:mytableview;

                width:40*mytableview.columnCount; height:mytableview.rowCount*16+1;
                anchors{top:btn_addr.bottom;topMargin:10;left:parent.left;leftMargin:60;}//anchors.horizontalCenter: parent.horizontalCenter;//anchors.right:parent.right;
                model:ListModel{
                    ListElement{
                        col1:"0";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"00";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"01";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"02";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"03";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"04";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"05";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"06";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"07";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"08";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"09";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"0A";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"0B";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"0C";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"0D";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"0E";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                    ListElement{
                        col1:"0F";
                        col2:"00";
                        col3:"01";
                        col4:"02";
                        col5:"03";
                        col6:"04";
                        col7:"05";
                        col8:"06";
                        col9:"07";
                        col10:"08";
                        col11:"09";
                        col12:"0A";
                        col13:"0B";
                        col14:"0C";
                        col15:"0D";
                        col16:"0E";
                        col17:"0F";
                    }
                }
                Component.onCompleted: {
                    mytableview.createTableViewColumn(
                                                               [["col1","col2","col3","col4","col5","col6","col7","col8","col9","col10","col11","col12","col13","col14","col15","col16","col17"],//
                                                                ["Col1","Col2","Col3","Col4","Col5","Col6","Col7","Col8","Col9","Col10","Col11","Col12","Col13","Col14","Col15","Col16","Col17"],//
                                                                [40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40]]);//
                }
                }
            Rectangle{//不起作用？？
                id:emptyrec

                width:20; height:20; color:"transparent"
                anchors.top:mytableview.bottom
            }
        }
    }
    states:
    [
        State
        {
            name:"active";
            PropertyChanges
            {
                target: memory;
                //x:parent.x;
                //anchors.left:parent.left;
                visible:true;
            }

        },
        State
        {
            name:"hide";
            PropertyChanges
            {
                target: memory;
                //x:maincontent.x + 2*width;
                //anchors.left:parent.right;
                visible:false;
            }
        }

    ]
    transitions:Transition
    {
        PropertyAnimation
        {
            property:"visible";
            duration: 100;
            easing.type: Easing.OutBounce;
            easing.amplitude: 0.1;
        }
    }
}
