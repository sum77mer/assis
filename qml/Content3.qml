import QtQuick 2.0
import io.qt.examples.backend 1.0
Item {
    anchors.horizontalCenter: parent.horizontalCenter

    BackEnd {
        id: backend
    }
    /**/
   // Info_out{
   //     id:infoouttest
   // }
    Text{

        color:"red"
        anchors.horizontalCenter: parent.horizontalCenter
        font{pointSize: 9;family: "微软雅黑"}
        text:backend.userName
    }
}
