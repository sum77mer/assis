import QtQuick 2.0
import QtCharts 2.0
ChartView{
    id:chartview
    width: 400
    height: 300
    //theme: ChartView.ChartThemeBrownSand
    antialiasing: true
    MouseArea{
        id:mousearea
        anchors.fill:parent
        onClicked: {
            chartview.scrollRight(10)
            splineseries.append(20,3.6)
        }
    }
    ValueAxis{
        id:valueaxis
        min:0
        max:20
        minorTickCount: 20
        tickCount: 2
    }
    SplineSeries {
        id:splineseries
            name: "SplineSeries"
            axisX:valueaxis
            XYPoint { x: 0; y: 0.0 }
            XYPoint { x: 1; y: 3.2 }
            XYPoint { x: 2; y: 2.4 }
            XYPoint { x: 3; y: 2.1 }
            XYPoint { x: 4; y: 0.0 }
            XYPoint { x: 5; y: 3.2 }
            XYPoint { x: 6; y: 2.4 }
            XYPoint { x: 7; y: 2.1 }
            XYPoint { x: 8; y: 0.0 }
            XYPoint { x: 9; y: 3.2 }
            XYPoint { x: 10; y: 2.4 }
            XYPoint { x: 11; y: 2.1 }
            XYPoint { x: 12; y: 0.0 }
            XYPoint { x: 13; y: 3.2 }
            XYPoint { x: 14; y: 2.4 }
            XYPoint { x: 15; y: 2.1 }
            XYPoint { x: 16; y: 0.0 }
            XYPoint { x: 17; y: 3.2 }
            XYPoint { x: 18; y: 2.4 }
            XYPoint { x: 19; y: 2.1 }
        }
}
