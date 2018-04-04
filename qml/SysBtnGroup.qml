import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
Row{
    id:sysbtngroup

    signal feedback
    signal menu
    signal min
    signal close

    spacing:0

    BasicSysBtn{
        id:configuration

        picHover:"qrc:/image/feedback/feedback_hover.png"
        picNormal: "qrc:/image/feedback/feedback_normal.png"
        picPressed: "qrc:/image/feedback/feedback_pressed.png"
        onClicked:
        {
            //console.log("configuration btn clicked");
            sysbtngroup.feedback();
        }
    }
    BasicSysBtn
    {
        id:menu

        picHover: "qrc:/image/menu/menu_hover.png"
        picNormal: "qrc:/image/menu/menu_normal.png"
        picPressed: "qrc:/image/menu/menu_pressed.png"
        onClicked:
        {
           // console.log("menu btn clicked")
            sysbtngroup.menu();
            childmenu.popup();
        }
        Menu{
            id:childmenu

            style:MenuStyle{
                    id:menustyle
                    //我的代码

                    frame:Rectangle{
                          id:frame

                          color:"#00e9e9e9"
                          //anchors.top:menu.bottm
                          border{width:1;color:"#f9f9f9"}
                          //width:60
                          //height:50
                          //source: styleData.iconSource ? styleData.iconSource : ""

                          Rectangle{
                              width:1; height:parent.height-4; color:"#e0e0e0"
                              anchors{left:frame.left;leftMargin:18;top:parent.top;topMargin: 2}
                          }
                          Rectangle{
                              width:1; height:parent.height-4; color:"#f9f9f9"
                              anchors{left:frame.left;leftMargin:19;top:parent.top;topMargin: 2}              
                          }
                      }
                    /*
                    separator:Item{
                        Rectangle{
                            //anchors.centerIn:frame
                            width:parent.width*0.9; height:1; color:"black"
                            //Component.onCompleted:  styleData.type===MenuItemType.Separator ? console.log("MenuItemType.Separator"):console.log("nope")
                        }
                    }
                    */

                    itemDelegate.background:Rectangle{
                        id:background

                        color:styleData.selected ? "#10B2DFEE":"#00e9e9e9"
                        //anchors{top:menu.bottm;left:parent.left; leftMargin: 20}
                        anchors.margins: 5
                        border{width:1;color: styleData.selected ? "#87CEFF": "#00e9e9e9"}
                        //width:implicitWidth-10; height:implicitHeight
                        //implicitWidth:50; implicitHeight:100
                    }
                    itemDelegate.label:Text{
                        id:label

                        width:implicitWidth + 10; height:implicitHeight + 10; color:"black"
                        font.pointSize:10
                        anchors{left:parent.left;leftMargin: 5}//anchors.centerIn:parent//anchors.top:menu.top
                        verticalAlignment: Text.AlignVCenter
                        //width:50; height:20
                        text:formatMnemonic(styleData.text,true)//styleData.text
                        Component.onCompleted: console.log("what is text.alignvcenter",Text.AlignVCenter);
                    }
                    itemDelegate.shortcut:Text{
                        id:shortcut

                        color:"black"
                        text:styleData.shortcut
                        verticalAlignment: Text.AlignVCenter
                    }

/*
                    frame:Rectangle{
                        border.width: 1
                        border.color: "#444"
                        //グラデーションで塗りつぶし
                        gradient: Gradient {
                          GradientStop { position: 0   ; color: "#aaa" }
                          GradientStop { position: 0.4 ; color: "#888" }
                          GradientStop { position: 1   ; color: "#666" }
                            }
                        }

                    itemDelegate.background:Rectangle{
                        //枠線（カーソルがのったら表示する）
                        border.width: styleData.selected ? 1 : 0
                        border.color: "#222"
                        //背景色（カーソルが乗ったらグレー。普段は透明）
                        gradient: Gradient {
                          GradientStop { position: 0   ; color: styleData.selected ? "#ddd" : "transparent" }
                          GradientStop { position: 0.4 ; color: styleData.selected ? "#ddd" : "transparent" }
                          GradientStop { position: 1   ; color: styleData.selected ? "#aaa" : "transparent" }
                        }
                        //アイコン [4]
                        Image {
                          width: height
                          anchors.left: parent.left
                          anchors.margins: 2
                          anchors.verticalCenter: parent.verticalCenter
                          source: styleData.iconSource ? styleData.iconSource : ""
                        }
                        //サブメニューのガイド  [5]
                        Image {
                          anchors.right: parent.right
                          anchors.rightMargin: 5
                          anchors.verticalCenter: parent.verticalCenter
                          visible: styleData.type === MenuItemType.Menu
                          //source: styleData.selected ? "sub_sel.png" : "sub_nor.png"
                        }
                    }
                    itemDelegate.label: Text {
                        id: labelText
                        width: implicitWidth + 10
                        height: implicitHeight + 10
                        verticalAlignment: Text.AlignVCenter
                        text: formatMnemonic(styleData.text, true)    //表示する文字列を指定
                        color: "white"
                        states: [ State {
                        when: !styleData.enabled   //無効になったらグレー
                        PropertyChanges { target: labelText; color: "darkgray" }
                      }, State {
                        when: styleData.selected   //カーソルがのったら黒
                        PropertyChanges { target: labelText; color: "black" }
                      }
                    ]
                  }
                    itemDelegate.shortcut: Text {
                    id: shortcutText
                    verticalAlignment: Text.AlignVCenter
                    text: styleData.shortcut                              //ショートカットの文字列を指定
                    color: "white"
                    states: [ State {
                        when: !styleData.enabled   //無効になったらグレー
                        PropertyChanges { target: shortcutText; color: "darkgray" }
                      }, State {
                        when: styleData.selected   //カーソルがのったら黒
                        PropertyChanges { target: shortcutText; color: "black" }
                      }
                    ]
                  }
                    separator: Rectangle{
                    anchors.centerIn: parent
                          width: parent.width * 0.9
                          height: 1
                          color: "lightgray"
                }
                    itemDelegate.checkmarkIndicator: Image {
                    visible: styleData.checked
                    source: "check.png"
                  }
                    itemDelegate.submenuIndicator: Item { }
*/
            }
            MenuItem{
                text:"帮助"
                shortcut:"Ctrl+H"
                //iconSource:"image/icon.PNG"
                //iconName:"help"
                //onTriggered:fun1()
            }
            MenuSeparator { }
            MenuItem{
                text:"关于"
                shortcut:"Ctrl+A"
                //iconSource:"image/close_hover.png"
                //iconName:"help"
                //onTriggered:
            }

        }

    }

    BasicSysBtn
    {
        id:min

        picHover: "qrc:/image/min/min_hover.png"
        picNormal: "qrc:/image/min/min_normal.png"
        picPressed: "qrc:/image/min/min_pressed.png"
        onClicked:
        {
            //console.log("min btn clicked");
            sysbtngroup.min();
        }
    }

    BasicSysBtn
    {
        id:close

        picHover: "qrc:/image/close/close_hover.png"
        picNormal: "qrc:/image/close/close_normal.png"
        picPressed: "qrc:/image/close/close_pressed.png"
        onClicked:
        {
           // console.log("close btn clicked");
            sysbtngroup.close();
        }
    }

}
