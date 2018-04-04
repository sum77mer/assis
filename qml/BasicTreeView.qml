import QtQuick 2.0
Rectangle {
    property var model

    anchors.fill: parent
    //contentHeight: content.height; contentWidth: content.width
    height:content.height; width:content.width
    color:"transparent"

    Loader {
        id: content

        property var elements: model
        property bool isRoot: true

        sourceComponent: treeBranch

        Component {
            id: treeBranch

            Item {
                id: root

                implicitHeight: column.implicitHeight; implicitWidth: column.implicitWidth + 4

                Column {
                    id: column

                    x: 2
                    spacing: 2

                    Text { text: !!root.isRoot ? "" : " " }
                    Repeater {
                        model: elements

                        Row {
                            spacing: 2

                            Rectangle {
                                width: 18; height: 18; color:"transparent"
                                opacity: !!model.elements ? 1 : 0

                                Image {
                                    id: expander

                                    source: "qrc:/image/treeview.png"
                                    opacity: mouse.containsMouse ? 1 : 0.7
                                    anchors.centerIn: parent
                                    rotation: loader.expanded ? 90 : 0
                                    Behavior on rotation {NumberAnimation { duration: 120}}
                                }
                                MouseArea {
                                    id: mouse

                                    anchors.fill: parent
                                    hoverEnabled: true
                                    onClicked: loader.expanded = !loader.expanded
                                }
                            }
                            Text { text: model.text }
                            Loader {
                                id: loader

                                property bool expanded: false
                                property var elements: model.elements
                                property var text: model.text

                                height: expanded ? implicitHeight : 0
                                sourceComponent: (expanded && !!model.elements) ? treeBranch : undefined
                            }
                        }
                    }
                }
            }
        }
    }

}
