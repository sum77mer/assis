#include "widget_sidetab.h"

Widget_sideTab::Widget_sideTab(QWidget *parent,unsigned int width,unsigned int height,QString title)
{
    btnStatus=NORMAL;
    mousePress=false;
    choosedflag=false;
    btnWidth=width;
    btnHeight=height;
    btnTitle=title;
    setFixedSize(width,height);
}
Widget_sideTab::~Widget_sideTab()
{}
void Widget_sideTab::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(Qt::NoPen);
    QFont font("微软雅黑",10,QFont::Bold);
    painter.setFont(font);
    switch(btnStatus)
    {
    case NORMAL:
    {
        brush.setColor(QColor(255,255,255));//background:white
        painter.setBrush(brush);
        painter.drawRect(this->rect());
        painter.setPen(QColor(0,0,0));
        break;
    }
    case ENTER:
    {
        brush.setColor(QColor(0,0,0));//background:white
        painter.setBrush(brush);
        painter.drawRect(this->rect());
        painter.setPen(QColor(255,255,255));
        break;
    }
    case PRESS:
    {
        brush.setColor(QColor(0,0,0));//background:white
        painter.setBrush(brush);
        painter.drawRect(this->rect());
        painter.setPen(QColor(255,255,255));
        break;
    }
    case NOSTATUS:
    {
        brush.setColor(QColor(255,255,255));//background:white
        painter.setBrush(brush);
        painter.drawRect(this->rect());
        painter.setPen(QColor(0,0,0));
        break;
    }
    default:
    {
        brush.setColor(QColor(255,255,255));//background:white
        painter.setBrush(brush);
        painter.drawRect(this->rect());
        painter.setPen(QColor(0,0,0));
        break;
    }
    }
    painter.drawText(this->rect(),Qt::AlignCenter,btnTitle);
}
void Widget_sideTab::enterEvent(QEvent *event)
{
    if(!choosedflag)
    {
        btnStatus=ENTER;
        update();
    }
}
void Widget_sideTab::leaveEvent(QEvent *event)
{
    if(!choosedflag)
    {
        btnStatus=NORMAL;
        update();
    }
}
void Widget_sideTab::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        mousePress=true;
        choosedflag=!choosedflag;
        if(choosedflag)
            btnStatus=PRESS;
        else
            btnStatus=NORMAL;
        emit clicked();
        update();
    }
}
void Widget_sideTab::mouseReleaseEvent(QMouseEvent *event)
{
    /*
    if(mousePress&&this->rect().contains(event->pos()))
    {
        mousePress=false;
        btnStatus=ENTER;
        update();
        emit clicked();
    }

*/
}
void Widget_sideTab::setMousePress(bool mouse_press)
{
    mousePress=mouse_press;
    if(mouse_press)
    {
        btnStatus=PRESS;
        choosedflag=true;
    }
    else
    {
        btnStatus=NORMAL;
        choosedflag=false;
    }
    update();
}
