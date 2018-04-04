import QtQuick 2.0
import QtQuick 2.7

Rectangle{
    id:tabbtn

    property alias picSrc: pic.source
    property alias btnText: label.text
    property int index:0
    property color bkColor: "#00FFFFFF"

    signal clicked(int btnIndex)

    width:80; height:65
    gradient: on
    //border.width:20
    //border.color:"yellow"
    Gradient
    {
        id:on

        GradientStop { position: 0.0; color: "#00FFFFFF" }
        GradientStop { position: 1.0; color: bkColor }
    }
    Image{
        id:pic

        //width:40; height:40
        anchors{topMargin: 5;horizontalCenter: parent.horizontalCenter}
    }
    Text
    {
        id: label

        color: "#ffffff"
        font{pointSize: 9;bold: true;family: "微软雅黑"}
        anchors{horizontalCenter: pic.horizontalCenter;top: pic.bottom;topMargin: 3}
     }
    MouseArea
    {
        hoverEnabled: true
        anchors.fill: parent
        onEntered:tabbtn.state == 'checked' ? tabbtn.state = 'checked' : tabbtn.state = 'hover'
        onExited:tabbtn.state == 'checked' ? tabbtn.state = 'checked' : tabbtn.state = 'leave'
        onPressed:
        {
            tabbtn.state = 'checked';
            tabbtn.clicked(tabbtn.index);
        }
    }

    states:
    [
        State {
            name: "checked"
            PropertyChanges { target: tabbtn; bkColor:"#aa000000" }
        },

        State {
            name: "hover"
            PropertyChanges { target: tabbtn; bkColor:"#aa000000" }
        },

        State {
            name: "leave"
            PropertyChanges { target: tabbtn; bkColor:"#00000000" }
        }
    ]

    transitions:
    [
        Transition
        {
            PropertyAnimation
            {
                property:"bkColor"
                easing.type: Easing.Linear
                duration: 200
            }
        }
    ]
}
