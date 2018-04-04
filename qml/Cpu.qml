import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import io.qt.examples.backend 1.0
import QtQuick.Layouts 1.3

Item {
    BackEnd{
        id:dataoffer_cpu;
    }
    BasicGroupBox{
        id:groupbox_cpu

        boxWidth:parent.width-40;boxHeight:280; backColor:"#f0f0f0"
        anchors{top:parent.top; topMargin:20; left:parent.left; leftMargin:20}
        titlestr:"处理器"
        GridLayout{
            id:cpu_layout1

            rows:4;rowSpacing:10
            flow:GridLayout.TopToBottom
            anchors.top:parent.top; anchors.topMargin:20

            Text{
                id:title_name

                text:"名字"
                Layout.leftMargin:40
                Layout.alignment: Qt.AlignRight
            }
            Text{
                id:title_socket

                Layout.alignment: Qt.AlignRight
                text:"插槽"
            }

            Text{
                id:title_family;

                Layout.alignment: Qt.AlignRight
                text:"系列";
            }
            Text{
                id:title_exfamily;

                Layout.alignment: Qt.AlignRight
                text:"扩展系列";
            }
//col1
            BasicEditControl{
                id:edit_cpu

                width:120; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"Intel Core i5-4460"
                readOnly: true;
            }
            BasicEditControl{
                id:edit_socket;


                width:120; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"Socket 1150 LGA";
            }

            BasicEditControl{
                id:edit_family;

                width:50; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:dataoffer_cpu.family;
            }
            BasicEditControl{
                id:edit_exfamily;

                width:50; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:dataoffer_cpu.family;
            }
//col2
            Text{
                id:title_architecture

                Layout.leftMargin:10
                Layout.alignment: Qt.AlignRight
                text:"代号";
            }
            Text{
                id:title_process;

                Layout.leftMargin:10
                Layout.alignment: Qt.AlignRight
                text:"工艺";
            }

            Text{
                id:title_model;

                Layout.leftMargin:10
                Layout.alignment: Qt.AlignRight
                text:"型号";
            }
            Text{
                id:title_exmodel;

                Layout.leftMargin:10
                Layout.alignment: Qt.AlignRight
                text:"扩展型号";
            }
//col3
            BasicEditControl{
                id:edit_architecture;

                width:60; height:Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"Haswell";
            }
            BasicEditControl{
                id:edit_process;


                width:50; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"22纳米";
            }

            BasicEditControl{
                id:edit_model;

                width:50; height:Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:dataoffer_cpu.family;
            }
            BasicEditControl{
                id:edit_exmodel;

                width:50; height:Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:dataoffer_cpu.family;
            }
//col4
            Text{
                id:title_TDP;

                Layout.leftMargin:10
                Layout.alignment: Qt.AlignRight
                text:"TDP";
            }
            Text{
                id:title_voltage;

                Layout.leftMargin:10
                Layout.alignment: Qt.AlignRight
                text:"核心电压";
            }

            Text{
                id:title_step;

                Layout.leftMargin:10
                Layout.alignment: Qt.AlignRight
                text:"步进";
            }
            Text{
                id:title_exstep;

                Layout.leftMargin:10
                Layout.alignment: Qt.AlignRight
                text:"修订";
            }
//col5
            BasicEditControl{
                id:edit_TDP;

                width:50; height:Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"84.0W";
            }
            BasicEditControl{
                id:edit_voltage;

                width:50; height:Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"0.788V";
            }
            BasicEditControl{
                id:edit_step;

                width:50; height:Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:dataoffer_cpu.family;
            }
            BasicEditControl{
                id:edit_exstep;

                width:50; height:Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:dataoffer_cpu.family;
            }
        }
        GridLayout{
            id:cpu_layout2

            rows:2;rowSpacing:10
            flow:GridLayout.TopToBottom
            anchors.top:cpu_layout1.bottom
            anchors.topMargin:10

            Text{
                id:title_guige;

                Layout.leftMargin:40
                Layout.alignment: Qt.AlignRight
                text:"规格";
            }
            Text{
                id:title_instrset;

                Layout.alignment: Qt.AlignRight
                text:"指令集";
            }

            BasicEditControl{
                id:edit_guige;

                width:300; height:Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"Intel(R) Core(TM) i5-4460 CPU @3.20GHz";
            }
            BasicEditControl{
                id:edit_instrset;
                width:300//Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"x86，EM64T，MMX，SSE，SSE2，SSE3，SSSE3 (Super SSE3)，SSE4A，SSE4.1，SSE4.2，AVX，AVX2，AVX-512，VMX";
            }
/*BasicEditControl{
                id:edit_instrset;

                width:300; height:100//Text.contentHeight;//Text.contentWidth;
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                textstring:"x86，EM64T，MMX，SSE，\r\nSSE2，SSE3，SSSE3 (Super SSE3)，SSE4A，SSE4.1，SSE4.2，AVX，AVX2，AVX-512，VMX";
            }*/

        }
    }
    BasicGroupBox{
        id:groupbox_clock

        boxWidth:(parent.width-60)/2;boxHeight:180; backColor:"#f0f0f0"
        anchors{top:groupbox_cpu.bottom; topMargin:10; left:parent.left; leftMargin:20}
        titlestr:"时钟"
        GridLayout{
            id:clock_layout

            rows:4;rowSpacing:10
            flow:GridLayout.TopToBottom
            anchors.top:parent.top; anchors.topMargin:20

            Text{
                id:core_speed

                text:"核心速度"
                Layout.leftMargin:40
            }
            Text{
                id:ratio

                text:"倍频"
                Layout.alignment:Qt.AlignRight
            }
            Text{
                id:bus_speed

                text:"总线速度"
                Layout.alignment:Qt.AlignRight
            }
            Text{
                id:fsb

                text:"额定FSB"
                Layout.alignment:Qt.AlignRight
            }
            BasicEditControl{
                id:edit_corespeed

                width:100; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"798.10MHz"
            }
            BasicEditControl{
                id:edit_ratio

                width:100; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"x 8.0(8-34)"
            }
            BasicEditControl{
                id:edit_busspeed

                width:100; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"99.76MHz"
            }
            BasicEditControl{
                id:edit_fsb

                width:100; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                //textMargin: 5
                text:"     "
            }
        }
    }
    BasicGroupBox{
        id:groupbox_cache

        boxWidth:(parent.width-60)/2;boxHeight:180; backColor:"#f0f0f0"
        anchors{top:groupbox_cpu.bottom; topMargin:10; left:groupbox_clock.right; leftMargin:20}
        titlestr:"缓存"
        GridLayout{
            id:cache_layout

            rows:4;rowSpacing:10
            flow:GridLayout.TopToBottom
            anchors.top:parent.top; anchors.topMargin:20

            Text{
                id:datacache1

                text:"核心速度"
                Layout.leftMargin:40
            }
            Text{
                id:instcache1

                text:"倍频"
                Layout.alignment:Qt.AlignRight
            }
            Text{
                id:cache2

                text:"总线速度"
                Layout.alignment:Qt.AlignRight
            }
            Text{
                id:cache3

                text:"额定FSB"
                Layout.alignment:Qt.AlignRight
            }
            BasicEditControl{
                id:edit_datacache1_size

                width:100; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"4*32KBytes"
            }
            BasicEditControl{
                id:edit_instcache1_size

                width:100; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"4*32KBytes"
            }
            BasicEditControl{
                id:edit_cache2_size

                width:100; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"4*32KBytes"
            }
            BasicEditControl{
                id:edit_cache3_size

                width:100; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"4*32KBytes"
            }
            //
            BasicEditControl{
                id:edit_datacache1_way

                width:50; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"8-way"
            }
            BasicEditControl{
                id:edit_instcache1_way

                width:50; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"8-way"
            }
            BasicEditControl{
                id:edit_cache2_way

                width:50; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"8-way"
            }
            BasicEditControl{
                id:edit_cache3_way

                width:50; height:Text.contentHeight
                Layout.preferredWidth:width;Layout.preferredHeight:height;
                Layout.leftMargin:5
                readOnly: true;
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                text:"8-way"
            }
        }
    }
    BasicGroupBox{
        id:groupbox_choosed

        boxWidth:parent.width-40;boxHeight:50; backColor:"#f0f0f0"
        anchors{top:groupbox_clock.bottom; topMargin:10; left:parent.left; leftMargin:20}
        titlestr:"已选择"
        RowLayout{
            id:choosed_rowlayout

            anchors{top:parent.top; topMargin:15; left:parent.left; leftMargin:40}
            Text{
                id:choosed
                text:"已选择"
            }
            BasicComboBox{
                id:choosed_combo
                Layout.leftMargin:5
                width:80
                anchors{verticalCenter:choosed.verticalCenter;left:choosed.right;leftMargin:5}
                choosedItem:ListModel{
                    ListElement{text:"处理器1"}
                    ListElement{text:"处理器2"}
                    ListElement{text:"处理器3"}
                }
            }
            Text{
                id:corenumber
                text:"核心数"
                Layout.leftMargin:40
            }
            BasicEditControl{
                id:edit_corenumber
                width:50; height:Text.contentHeight
                Layout.leftMargin:5
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                readOnly: true
            }

            Text{
                id:threadnumber
                text:"线程数"
                Layout.leftMargin:10
            }
            BasicEditControl{
                id:edit_threadnumber
                width:50; height:Text.contentHeight
                Layout.leftMargin:5
                wrapMode:TextEdit.WordWrap
                textMargin: 5
                readOnly: true
            }
        }
    }
}
