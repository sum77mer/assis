import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
ComboBox{
    id:combo_choosed
    property ListModel choosedItem
    //default property alias choosedItem:list_choosed.
    //width:Text.contentWidth
    currentIndex:1
    model:choosedItem
    style:ComboBoxStyle{
        id:combo_style

        background: Rectangle{
            id:combo_backgnd

            width:100; height:50; color:"#f0f0f0"
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

                        width:3; height:1;color:"#000000"
                        anchors{top:parent.top;topMargin:7;left:parent.left;leftMargin:5}
                    }
                    Rectangle{
                        id:triangle1

                        width:1; height:1; color:"#000000"
                        anchors{top:parent.top;topMargin:8;left:parent.left;leftMargin:6}
                    }
//****************
/*
                Rectangle{
                    id:triangle7
                    color:"#a0a0a0"
                    width:7
                    height:1
                    anchors.top:parent.top
                    anchors.topMargin:5
                    anchors.left:parent.left
                    anchors.leftMargin:3
                }
                Rectangle{
                    id:triangle5
                    color:"#a0a0a0"
                    width:5
                    height:1
                    anchors.top:parent.top
                    anchors.topMargin:6
                    anchors.left:parent.left
                    anchors.leftMargin:4
                }
                Rectangle{
                    id:triangle3
                    color:"#a0a0a0"
                    width:3
                    height:1
                    anchors.top:parent.top
                    anchors.topMargin:7
                    anchors.left:parent.left
                    anchors.leftMargin:5
                }
                Rectangle{
                    id:triangle1
                    color:"#a0a0a0"
                    width:1
                    height:1
                    anchors.top:parent.top
                    anchors.topMargin:8
                    anchors.left:parent.left
                    anchors.leftMargin:6
                }
                Rectangle{
                    id:triangle21
                    color:"#ffffff"
                    width:2
                    height:1
                    anchors.top:parent.top
                    anchors.topMargin:6
                    anchors.left:parent.left
                    anchors.leftMargin:9
                }
                Rectangle{
                    id:triangle22
                    color:"#ffffff"
                    width:2
                    height:1
                    anchors.top:parent.top
                    anchors.topMargin:7
                    anchors.left:parent.left
                    anchors.leftMargin:8
                }
                Rectangle{
                    id:triangle23
                    color:"#ffffff"
                    width:2
                    height:1
                    anchors.top:parent.top
                    anchors.topMargin:8
                    anchors.left:parent.left
                    anchors.leftMargin:7
                }
                Rectangle{
                    id:triangle11
                    color:"#ffffff"
                    width:1
                    height:1
                    anchors.top:parent.top
                    anchors.topMargin:9
                    anchors.left:parent.left
                    anchors.leftMargin:7
                }
*/
            }
        }
    }
}
