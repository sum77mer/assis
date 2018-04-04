import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.2 as QtPopUp
import QtQuick 2.2

TableView{
    id:mytableview

    //backgroundVisible: false
    //frameVisible: false
    headerDelegate: Rectangle{
        id:headerdel

        color:"transparent"
        anchors.fill:parent
        border{width:1;color:"#505050"}
        radius:3
    }
    rowDelegate: Rectangle{
        id:rowdel

        color:"transparent"
        anchors.fill:parent
        //border{width:1; color:"#696969"}

        Component.onCompleted: {
            //console.log("*******row height*********")
            //console.log(rowdel.height)
        }
    }
    itemDelegate: Rectangle{
        id:itemdel

        color:"#ffffe1"
        anchors.fill:parent
        //anchors.margins: 1
        Text{
            text:styleData.value; color:"black"
            elide:Text.ElideMiddle
            anchors.fill:parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

            Component.onCompleted: {
                /*console.log("************tableview fontsize*****************")
                console.log(font.pixelSize)*/
            }
        }
        BasicPopUp{
            id:edit
        }
        MouseArea{
            anchors.fill:parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                console.log("*****single click*******");
                       if (mouse.button == Qt.RightButton)
                       {
                           parent.color = 'blue';
                           console.log("*****right click*******");
                       }
                   }
            onDoubleClicked: {
                edit.open();
                console.log("*****double click*******");
            }

        }
    }

    function createTableViewColumn(arrayData){
        var arrayTitle=arrayData[1];
        var arrayWidth=arrayData[2];
        var arrayRole=arrayData[0];



        var prefix='import QtQuick 2.7;
                    import QtQuick.Controls.Styles 1.4
                    import QtQuick.Controls 2.2 as QtPopUp
                    import QtQuick.Controls 1.4;
                    import QtQuick 2.2
                    TableViewColumn {width: ';
        for(var i=0;i<arrayRole.length;i++)
        {
            var str=prefix+arrayWidth[i]+";resizable:false;movable:false;role:\""+
                    arrayRole[i]+"\";title:\""+arrayTitle[i]+"\"}";
            //var str=prefix+"resizable:false;movable:false;role:\""+

            //if(i=)
            var ob=mytableview.addColumn(Qt.createQmlObject(str,mytableview,"dynamicSnippet1"));
            //console.log("**************")
            //for(var p in ob)
            //    console.log(p,":",ob[p])
            //console.log("**************")
            //console.log("#",i,"#",str)
        }
    }
}
