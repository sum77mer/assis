import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Rectangle{
    id:pci

    width:parent.width; height:parent.height; color:"#f0f0f0"
    anchors{left:parent.left;top:parent.top}
    state:"hide"
    //border.color:"lightsalmon"
    //border.width:10

    ScrollView{
        id:scrollview_PCI

        anchors.fill:parent
        verticalScrollBarPolicy: Qt.ScrollBarAlwaysOn
        Rectangle{
            width:parent.width; height:1000; color:"transparent"
            Rectangle{
                id:tree_PCI

                width:700; height:200
                anchors{top:parent.top;topMargin:20;left:parent.left;leftMargin:50}

                BasicTreeView{
                    anchors.fill:parent
                    model:ListModel{
                        id:treemodel

                        ListElement{
                            text:"Bus 0  Device 0 Function 0"
                        }
                        ListElement{
                            text:"Bus 1 Device 0 Function 0"
                            elements:[
                                ListElement{
                                    text:"Bus 1 Device 1 Function 1"
                                    elements:[
                                        ListElement{text:"Bus1 Device 1 Function 2"}
                                    ]
                                },
                                ListElement{text:"Bus1 Device 2 Function 0"}
                            ]
                        }
                        ListElement{text:"Bus 2 Device 1 Function 0"}
                    }

                }
            }
            ComboBox{
                id:chosed_PCI

                anchors{top:tree_PCI.bottom;topMargin:20;left:parent.left;leftMargin:100}
                width:400
                currentIndex:1
                model:ListModel{
                    ListElement{text:"Bus 0 Dev 0 Fun 0 Intel Corporation Host Bridge"}
                    ListElement{text:"Bus 0 Dev 1 Fun 0 Intel Corporation Host Bridge"}
                    ListElement{text:"Bus 0 Dev 2 Fun 0 Intel Corporation Host Bridge"}
                    ListElement{text:"Bus 0 Dev 3 Fun 0 Intel Corporation Host Bridge"}
                    ListElement{text:"Bus 1 Dev 0 Fun 0 Intel Corporation Host Bridge"}
                    ListElement{text:"Bus 1 Dev 1 Fun 0 Intel Corporation Host Bridge"}
                    ListElement{text:"Bus 3 Dev 0 Fun 0 Intel Corporation Host Bridge"}
                    ListElement{text:"Bus 6 Dev 0 Fun 0 Intel Corporation Host Bridge"}
                    ListElement{text:"Bus A Dev 0 Fun 0 Intel Corporation Host Bridge"}
                }
                style:ComboBoxStyle{
                    id:combo_style

                    background: Rectangle{
                        id:combo_backgnd

                        color:"white"
                        width:100
                        height:50
                        Rectangle{
                            id:outside_topline

                            width:parent.width+2; height:1; color:"#a0a0a0"
                            anchors{top:parent.top;topMargin:-8;left:parent.left}
                        }
                        Rectangle{
                            id:inside_topline

                            width:parent.width; height:1; color:"#696969"
                            anchors{top:parent.top;topMargin:-7;left:parent.left;leftMargin:1}
                        }
                        Rectangle{
                            id:outside_bottomline

                            width:parent.width+2; height:1; color:"#ffffff"
                            anchors{top:parent.bottom;topMargin:7;left:parent.left}
                        }
                        Rectangle{
                            id:inside_bottomline

                            width:parent.width+1; height:1; color:"#e3e3e3"
                            anchors{top:parent.bottom;topMargin:6;left:parent.left;leftMargin:1}
                        }
                        Rectangle{
                            id:outside_leftline

                            width:1; height:parent.height+15; color:"#a0a0a0"
                            anchors{top:parent.top;topMargin:-7;left:parent.left}
                        }
                        Rectangle{
                            id:inside_leftline

                            width:1; height:parent.height+13; color:"#696969"
                            anchors{top:parent.top;topMargin:-6;left:parent.left;leftMargin:1}
                        }
                        Rectangle{
                            id:outside_rightline

                            width:1; height:parent.height+16; color:"#ffffff"
                            anchors{top:parent.top;topMargin:-8;left:parent.right;leftMargin:2}
                        }
                        Rectangle{
                            id:inside_rightline

                            width:1; height:parent.height+14; color:"#e3e3e3"
                            anchors{top:parent.top;topMargin:-7;left:parent.right;leftMargin:1}
                        }

                        Rectangle{
                            id:btn

                            width:15; height:15; color:"#f0f0f0"
                            anchors{verticalCenter:parent.verticalCenter;right:parent.right;rightMargin:1}
                            Rectangle{
                                id:btn_outside_topline

                                width:parent.width+3; height:1; color:"#e3e3e3"
                                anchors{top:parent.top;topMargin:-2;left:parent.left;leftMargin:-2}
                            }
                            Rectangle{
                                id:btn_inside_topline

                                width:parent.width+1; height:1; color:"#ffffff"
                                anchors{top:parent.top;topMargin:-1;left:parent.left;leftMargin:-1}
                            }
                            Rectangle{
                                id:btn_outside_bottomline

                                width:parent.width+4; height:1; color:"#696969"
                                anchors{top:parent.bottom;topMargin:1;left:parent.left;leftMargin:-2}
                            }
                            Rectangle{
                                id:btn_inside_bottomline

                                width:parent.width+2; height:1; color:"#a0a0a0"
                                anchors{top:parent.bottom;left:parent.left;leftMargin:-1} //anchors.topMargin:1
                            }
                            Rectangle{
                                id:btn_outside_leftline

                                width:1; height:parent.height+3; color:"#e3e3e3"
                                anchors{top:parent.top;topMargin:-2;left:parent.left;leftMargin:-2}
                            }
                            Rectangle{
                                id:btn_inside_leftline

                                width:1; height:parent.height+1; color:"#ffffff"
                                anchors{top:parent.top;topMargin:-1;left:parent.left;leftMargin:-1}
                            }
                            Rectangle{
                                id:btn_outside_rightline

                                width:1; height:parent.height+3; color:"#696969"
                                anchors{top:parent.top;topMargin:-2;left:parent.right;leftMargin:1}
                            }
                            Rectangle{
                                id:btn_inside_rightline

                                width:1; height:parent.height+1; color:"#a0a0a0"
                                anchors{top:parent.top;topMargin:-1;left:parent.right}
                            }
                            //***************
                            Rectangle{
                                id:triangle7

                                width:7; height:1; color:"#000000"
                                anchors{top:parent.top;topMargin:5;left:parent.left;leftMargin:3}
                            }
                            Rectangle{
                                id:triangle5

                                width:5; height:1; color:"#000000"
                                anchors{top:parent.top;topMargin:6;left:parent.left;leftMargin:4}
                            }
                            Rectangle{
                                id:triangle3

                                width:3; height:1; color:"#000000"
                                anchors{top:parent.top;topMargin:7;left:parent.left;leftMargin:5}
                            }
                            Rectangle{
                                id:triangle1

                                width:1; height:1; color:"#000000"
                                anchors{top:parent.top;topMargin:8;left:parent.left;leftMargin:6}
                            }
                        }

                    }
                }

            }
            BasicTableView{
                id:table_PCI

                width:30*table_PCI.columnCount; height:table_PCI.rowCount*16+1
                anchors{top:chosed_PCI.bottom;topMargin:20;left:parent.left;leftMargin:20}
                model:ListModel{
                    ListElement{
                        col1:"0"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"00"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"01"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"02"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"03"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"04"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"05"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"06"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"07"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"08"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"09"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"0A"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"0B"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"0C"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"0D"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"0E"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                    ListElement{
                        col1:"0F"
                        col2:"00"
                        col3:"01"
                        col4:"02"
                        col5:"03"
                        col6:"04"
                        col7:"05"
                        col8:"06"
                        col9:"07"
                        col10:"08"
                        col11:"09"
                        col12:"0A"
                        col13:"0B"
                        col14:"0C"
                        col15:"0D"
                        col16:"0E"
                        col17:"0F"
                    }
                }
                Component.onCompleted: table_PCI.createTableViewColumn([["col1","col2","col3","col4","col5","col6","col7","col8","col9","col10","col11","col12","col13","col14","col15","col16","col17"],//
                                                                             ["Col1","Col2","Col3","Col4","Col5","Col6","Col7","Col8","Col9","Col10","Col11","Col12","Col13","Col14","Col15","Col16","Col17"],//
                                                                             [30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30]])

            }
            TextEdit{
                id:pci_summary

                width:300
                anchors{top:table_PCI.top;left:table_PCI.right;leftMargin:10}
                wrapMode:TextEdit.Wrap
                text:"Device/Vendor ID	0x8C148086
Revision ID	0xD5
Class Code	0x060400
Cacheline Size	0x10
Latency Timer	0x00
Interrupt Pin	INTC
Interrupt Line	None
BAR1		0x00000000
BAR2		0x00000000
Primary Bus#	0x00
Secondary Bus#	0x03
Subordinate Bus#	0x03
IO Range
   0x0000D000 - 0x0000DFFF
Memory Range
   0xF7200000 - 0xF72FFFFF
Prefetchable Memory Range
   0xF2100000 - 0xF21FFFFF
Expansion ROM	0x00000000
"
            }
        }
    }
    Component.onCompleted: {
        //console.log("pci's state is",pci.state)
    }
    states:
    [
        State
        {
            name:"active"
            PropertyChanges
            {
                target: pci
                //x:parent.x
                //anchors.left:parent.left
                visible:true
            }

        },
        State
        {
            name:"hide"
            PropertyChanges
            {
                target: pci
                //x:maincontent.x + 2*width
                //anchors.left:parent.right
                visible:false
            }
        }

    ]

    transitions:Transition
    {
        PropertyAnimation
        {
            property:"visible"
            duration: 100
            easing.type: Easing.OutBounce
            easing.amplitude: 0.1
        }
    }
}
