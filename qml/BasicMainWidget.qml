import QtQuick 2.0

Rectangle {
    id:widget

    property int index: 0

    width:parent.width; height:parent.height; color:"white"
    //border.width:5
    //border.color:"blue"
    state:"hide"
    states:
    [
        State
        {
            name:"active"
            PropertyChanges
            {
                target: widget
                visible:true
            }

        },
        State
        {
            name:"hide"
            PropertyChanges
            {
                target: widget
                visible:false
            }
        }

    ]

    transitions:
    [
        Transition
        {
            PropertyAnimation
            {
                property:"visible"
                duration: 200
                easing{type: Easing.Linear;amplitude: 0.1}
            }
        }
    ]
}


