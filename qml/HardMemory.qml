import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Rectangle{
    id:memory;

    width:parent.width; height:parent.height; color:"#f0f0f0";
    anchors{left:parent.left;top:parent.top;}
    state:"hide";
    //border{color:"lightpink";width:10}

    ScrollView{
        id:scrollview_memory;
        parent:memory
        anchors.fill:parent;
        verticalScrollBarPolicy: Qt.ScrollBarAlwaysOn;
        Rectangle{
            width:parent.width; height:groupbox_memory.height+btn_addr.height+mytableview.height+150; color:"transparent";

            BasicGroupBox2{
                id:groupbox_memory;

                width:720; height:400;
                anchors{top:parent.top;topMargin:10;left:parent.left;leftMargin:25;}
                drawwidth: width-30; drawheight:height-30;
                startx:x; starty:y;
                gap:title_str.length*title_text.font.pixelSize+10;
                title_str:"基本信息";
                mainline_color:[["0"],["0"],["0"]];
                shadowline_color:[["255"],["255"],["255"]];
                Text{
                    id:title_text;

                    x:parent.startx+35; y:parent.starty-5;
                    text:parent.title_str;
                    //Component.onCompleted: console.log("title_text's x,y:",x,y,"pointsize:",font.pointSize,"pixelsize:",font.pixelSize);
                }

                Row{
                    id:row1;

                    spacing:20;
                    anchors{top:parent.top;topMargin:40;}
                    Text{
                        id:title_leixing;

                        text:"类型";
                        //anchors{left:parent.left;leftMargin:40;}
                    }
                 BasicEditControl{
                        id:edit_leixing;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"DDR3";
                        //anchors{top:title_leixing.top;topMargin:-5;left:title_leixing.right;leftMargin:5;}
                    }
                    Text{
                        id:title_tongdaoshu;

                        text:"通道数";
                        //anchors{left:edit_leixing.right;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_tongdaoshu;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"双通道";
                        //anchors{top:title_tongdaoshu.top;topMargin:-5;left:title_tongdaoshu.right;leftMargin:5;}
                    }
                    Text{
                        id:title_daxiao;

                        text:"大小";
                        //anchors{left:edit_tongdaoshu.right;leftMargin:40;}
                    }

                    BasicEditControl{
                        id:edit_daxiao;

                        width:50; height:Text.contentHeight;//Text.contentWidth
                        readOnly: true;
                        text:"24 GBytes";
                        //anchors{top:title_daxiao.top;topMargin:-5;left:title_daxiao.right;leftMargin:5;}
                    }
                    Text{
                        id:title_pinlv;

                        text:"频率";
                        //anchors{left:edit_daxiao.right;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_pinlv;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"3192.4 MHz";
                        //anchors{top:title_pinlv.top;topMargin:-5;left:title_pinlv.right;leftMargin:5;}
                    }
                }
                Row{
                    id:row2;

                    spacing:20;
                    anchors{top:row1.bottom;topMargin:35;}
                    Text{
                        id:title_neicunpinlv;

                        text:"内存频率";
                        //anchors{left:parent.left;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_neicunpinlv;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"665.1 MHz";
                        //anchors{top:title_neicunpinlv.top;topMargin:-5;left:title_neicunpinlv.right;leftMargin:5;}
                    }
                    Text{
                        id:title_zongxianneicun;

                        text:"前端总线：内存";
                        //anchors{left:edit_neicunpinlv.right;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_zongxianneicun;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"1：5";
                        //anchors{top:title_zongxianneicun.top;topMargin:-5;left:title_zongxianneicun.right;leftMargin:5;}
                    }
                    Text{
                        id:title_casyanchi;

                        text:"CAS延迟";
                        //anchors{left:edit_zongxianneicun.right;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_casyanchi;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"9.0时钟";
                        //anchors{top:title_casyanchi.top;topMargin:-5;left:title_casyanchi.right;leftMargin:5;}
                    }
                    Text{
                        id:title_rascas;

                        text:"RAS到CAS";
                        //anchors{left:edit_casyanchi.right;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_rascas;

                        width:50; height:Text.contentHeight;//Text.contentWidth
                        readOnly: true;
                        text:"9时钟";
                        //anchors{top:title_rascas.top;topMargin:-5;left:title_rascas.right;leftMargin:5;}
                    }
                }
                Row{
                    id:row3;

                    spacing:20;
                    anchors{top:row2.bottom;topMargin:35;}
                    Text{
                        id:title_rasyuchongdian;

                        text:"RAS预充电";
                        //anchors{left:parent.left;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_rasyuchongdian;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"9时钟";
                        //anchors{top:title_rasyuchongdian.top;topMargin:-5;left:title_rasyuchongdian.right;leftMargin:5;}
                    }
                    Text{
                        id:title_xunhuanzhouqi;

                        text:"循环周期";
                        //anchors{left:edit_rasyuchongdian.right;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_xunhuanzhouqi;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"24 时钟";
                        //anchors{top:title_xunhuanzhouqi.top;topMargin:-5;left:title_xunhuanzhouqi.right;leftMargin:5;}
                    }
                    Text{
                        id:title_rrct;

                        text:"Row Refresh Cycle Time";
                        //anchors{left:edit_xunhuanzhouqi.right;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_rrct;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"200 时钟";
                        //anchors{top:title_rrct.top;topMargin:-5;left:title_rrct.right;leftMargin:5;}
                    }
                    Text{
                        id:title_zhilingbilv;

                        text:"指令比率";
                        //anchors{left:edit_rrct.right;leftMargin:40;}
                    }
                    BasicEditControl{
                        id:edit_zhilingbilv;

                        width:50; height:Text.contentHeight;//Text.contentWidth;
                        readOnly: true;
                        text:"2T";
                        //anchors{top:title_zhilingbilv.top;topMargin:-5;left:title_zhilingbilv.right;leftMargin:5}
                    }
                }
            }
            Button{
                id:btn_addr;

                text:"Addr=0x00000000";
                anchors{top:groupbox_memory.bottom;topMargin:20;left:mytableview.left;}
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
            Rectangle{
                id:rec_empty;

                width:parent.width; height:50; color:"transparent";
                anchors{top:mytableview.bottom;topMargin: 20;}
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
  /*
    BasicTableView{
        id:mytableview
        width:parent.width
        anchors.centerIn:parent
        model:ListModel{
            ListElement{
                name:"Name"
                score:"Score"
                grade:"Grade"
            }
            ListElement{
                name:"claire"
                score:"100"
                grade:"A"
            }
            ListElement{
                name:"claire"
                score:"100"
                grade:"A"
            }
            ListElement{
                name:"claire"
                score:"100"
                grade:"A"
            }
        }
        Component.onCompleted: mytableview.createTableViewColumn(
                                   [["name","score","grade"],//,"col7","col8","col9","col10","col11","col12","col13","col14","col15","col16","col17"
                                    ["name","score","grade"],//,"Col7","Col8","Col9","Col10","Col11","Col12","Col13","Col14","Col15","Col16","Col17"
                                    [150,50,20]])//,10,10,10,10,10,10,10,10,10,10,10
        }
    */
}
