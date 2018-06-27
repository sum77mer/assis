#include "widget_maintab.h"

Widget_mainTab::Widget_mainTab(QWidget *parent)
    :QPushButton(parent)
{
    btnStatus=NORMAL;
    mousePress=false;
    choosed=false;
}
Widget_mainTab::~Widget_mainTab()
{}
void Widget_mainTab::setIcon(QString icon_name)
{
    iconName=icon_name;
    btnWidth=QPixmap(iconName).width()+25;
    btnHeight=QPixmap(iconName).height()+25;
    setFixedSize(btnWidth,btnHeight);
}
void Widget_mainTab::setText(const QString text)
{
    btnTitle=text;
}
void Widget_mainTab::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap;
    QLinearGradient lineargradient(this->rect().x(),
                                   this->rect().y(),
                                   this->rect().x(),
                                   this->rect().y()+btnHeight);
    lineargradient.setColorAt(0,QColor(0,0,0,0));
    lineargradient.setColorAt(1,QColor(0,0,0,255));
    switch(btnStatus)
    {
    case NORMAL:
    {
        pixmap.load(iconName);
        break;
    }
    case ENTER:
    {
        pixmap.load(iconName);
        painter.setBrush(lineargradient);
        //painter.setBrush(Qt::LinearGradientPattern);
        painter.setPen(Qt::NoPen);
        painter.drawRect(this->rect());
        break;
    }
    case PRESS:
    {
        pixmap.load(iconName);
        painter.setBrush(lineargradient);
        painter.setPen(Qt::NoPen);
        painter.drawRect(this->rect());
        break;
    }
    case NOSTATUS:
    {
        pixmap.load(iconName);
        break;
    }
    default:
    {
        pixmap.load(iconName);
        break;
    }
    }
    QRect iconrect;
    int x=(this->rect().width()-pixmap.rect().width())/2+this->rect().x();
    iconrect.setX(x);
    iconrect.setY(0);
    iconrect.setWidth(pixmap.rect().width());
    iconrect.setHeight(pixmap.rect().height());
    painter.drawPixmap(iconrect,pixmap);
    QFont font("微软雅黑",11,QFont::Bold);
    painter.setFont(font);
    painter.setPen(QColor(255,255,255));
    painter.drawText(this->rect(),Qt::AlignBottom|Qt::AlignHCenter,btnTitle);
}
void Widget_mainTab::enterEvent(QEvent *event)
{
    if(!choosed)
    {
        btnStatus=ENTER;
        update();
    }
}
void Widget_mainTab::leaveEvent(QEvent *event)
{
    if(!choosed)
    {
        btnStatus=NORMAL;
        update();
    }
}
void Widget_mainTab::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        mousePress=true;
        choosed=!choosed;
        if(choosed)
        {
            btnStatus=PRESS;
        }
        else
            btnStatus=NORMAL;
        emit clicked();
        update();
    }
}
void Widget_mainTab::mouseReleaseEvent(QMouseEvent *e)
{
    /*
    if(mousePress&&this->rect().contains(e->pos()))
    {
        mousePress=false;
        btnStatus=ENTER;
        update();
        emit clicked();
    }
*/

}
void Widget_mainTab::setMousePress(bool mouse_press)
{
    mousePress=mouse_press;
    if(mouse_press)
    {
        btnStatus=PRESS;
        choosed=true;
    }
    else
    {
        choosed=false;
        btnStatus=NORMAL;
    }
    update();
}
