#include "widget_pushbutton.h"
Widget_PushButton::Widget_PushButton(QWidget *parent)
    :QPushButton(parent)
{
    status = NORMAL;
    mousePress = false;
}
Widget_PushButton::~Widget_PushButton()
{

}
void Widget_PushButton::setIcon(QString icon_name)
{
    iconName=icon_name;
    btnWidth=QPixmap(iconName).width();
    btnHeight=QPixmap(iconName).height();
    setFixedSize(QPixmap(iconName).size());
}
void Widget_PushButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    switch(status)
    {
        case NORMAL:
        {
            pixmap.load(iconName);
            break;
        }
        case ENTER:
        {
            pixmap.load(iconName + QString("_hover"));
            break;
        }
        case PRESS:
        {
            pixmap.load(iconName + QString("_pressed"));
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
        }
    }
    painter.drawPixmap(this->rect(),pixmap);
}
void Widget_PushButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        mousePress=true;
        status=PRESS;
        if(menu())
        {
            showMenu();
        }
        update();
    }
}
void Widget_PushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(mousePress && this->rect().contains(e->pos()))
    {
        mousePress=false;
        status=ENTER;
        update();
        emit clicked();
    }
}
void Widget_PushButton::leaveEvent(QEvent *)
{
    status=NORMAL;
    update();
}
void Widget_PushButton::enterEvent(QEvent *)
{
    status=ENTER;
    update();
}
