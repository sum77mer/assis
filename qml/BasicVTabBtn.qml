import QtQuick 2.0

Rectangle{
    id:tabbtn

    property alias btnText: label.text
    property alias btntextcolor:label.color
    property int index:0

    signal clicked(int btnIndex)

    width:80; height:30; color:"white"

    Text
    {
        id: label

        color: "black"
        font{pointSize: 9; family: "微软雅黑"}
        anchors{horizontalCenter: parent.horizontalCenter;verticalCenter: parent.verticalCenter}//anchors.topMargin: 3
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
        onClicked:{
            //console.log("vtabbtn is clicked:",btnText)
        }
    }
    states:
    [
        State {
            name: "checked"
            PropertyChanges { target: tabbtn; color:"#f0333333" ;btntextcolor:"white"}
        },
        State {
            name: "hover"
            PropertyChanges { target: tabbtn; color:"#66909090";btntextcolor:"white" }
        },
        State {
            name: "leave"
            PropertyChanges { target: tabbtn; color:"white";btntextcolor:"black" }
        }
    ]
    transitions:
    [
        Transition
        {
            PropertyAnimation
            {
                property:"tabbtn.color"
                easing.type: Easing.Linear
                duration: 100
            }
        }
    ]
}
