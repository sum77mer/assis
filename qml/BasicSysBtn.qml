import QtQuick 2.7
import QtQuick.Controls 1.4
Rectangle {
    id:sysbtn

    property string picCurrent: ""
    property string picNormal:""
    property string picHover:""
    property string picPressed:""

    signal clicked

    width:27; height:22; color:"#00000000"
    state:"normal"
/*
    Button{
        id:btn
        menu:menu
        //opacity:0
    }
    Menu{
        id:menu
        MenuItem{
            text:"帮助"
            shortcut:"Ctrl+H"
            //onTriggered:fun1()
        }
        MenuItem{
            text:"关于"
            shortcut:"Ctrl+A"
            //onTriggered:
        }
    }
*/
    Image{
        source:picCurrent;
    }
    MouseArea{
        hoverEnabled: true
        anchors.fill:parent
        onEntered: sysbtn.state=="pressed"? sysbtn.state = "pressed":sysbtn.state="hover"
        onExited:sysbtn.state=="presssed"? sysbtn.state = "pressed":sysbtn.state="normal"
        onPressed:sysbtn.state="pressed"
        onReleased:
        {
            sysbtn.state="normal"
            sysbtn.clicked()
        }
    }


    states:
        [
        State{
            name:"hover"
            PropertyChanges{
                target:sysbtn
                picCurrent:picHover
            }
        },
        State{
            name:"normal"
            PropertyChanges{
                target:sysbtn
                picCurrent:picNormal
            }
        },
        State{
            name:"pressed"
            PropertyChanges{
                target:sysbtn
                picCurrent:picPressed
            }
        }
    ]
}

