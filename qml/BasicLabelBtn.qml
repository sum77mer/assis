import QtQuick 2.0

Rectangle {
    id:labelbtn

    property string picSrc: ""
    property string text:""

    width:50; height:50

    Image
    {
        id: image

        source:labelbtn.picSrc
    }
    Text
    {
        id: label

        text:labelbtn.text; color: "#000000"
        font{pointSize: 9;family: "微软雅黑"}
        anchors{horizontalCenter: image.horizontalCenter;top: image.bottom;topMargin: 3}
    }
}
