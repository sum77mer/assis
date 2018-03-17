import QtQuick 2.0
import QtQuick 2.7
//canvas duration:273us
Canvas {//id: mycanvas
    property int drawwidth
    property int drawheight
    property int gap
    property int startx
    property int starty
    property var mainline_color
    property var shadowline_color
    property string title_str

    width: 100
    height: 200
    onPaint: {
        var ctx = getContext("2d");
        var color_str="rgba("+mainline_color[0]+","+mainline_color[1]+","+mainline_color[2]+","+"1"+")";

        ctx.moveTo(startx+30,starty);//1-2
        ctx.lineTo(startx,starty);

        ctx.moveTo(startx+1,starty+1);//2-3
        ctx.lineTo(startx+1,starty+drawheight-3);

        ctx.moveTo(startx,starty+drawheight-2);//3-4
        ctx.lineTo(startx+drawwidth,starty+drawheight-2);

        ctx.moveTo(startx+drawwidth-1,starty+drawheight-3);//4-5
        ctx.lineTo(startx+drawwidth-1,starty+1);

        ctx.moveTo(startx+drawwidth,starty);//5-6
        ctx.lineTo(startx+30+gap,starty);

        ctx.lineWidth=1;
        //ctx.lineCap="butt";
        //ctx.strokeStyle ='rgba(100,100,100,1)';
        ctx.strokeStyle = color_str;
        ctx.stroke();
        //ctx.closePath();
        color_str="rgba("+shadowline_color[0]+","+shadowline_color[1]+","+shadowline_color[2]+","+"1"+")";
        ctx.moveTo(startx+30,starty+2);//1-2
        ctx.lineTo(startx+2,starty+2);

        ctx.moveTo(startx+3,starty+3);//2-3
        ctx.lineTo(startx+3,starty+drawheight-3);

        ctx.moveTo(startx,starty+drawheight);//3-4
        ctx.lineTo(startx+drawwidth+2,starty+drawheight);

        ctx.moveTo(startx+drawwidth+1,starty+drawheight-1);//4-5
        ctx.lineTo(startx+drawwidth+1,starty-1);

        ctx.moveTo(startx+drawwidth-2,starty+2);//5-6
        ctx.lineTo(startx+30+gap,starty+2);

        ctx.lineWidth=1;
        ctx.strokeStyle = color_str;
        ctx.stroke();

    }
}
