#include "dialog.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QPicture>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QMouseEvent>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //root window setting
    setWindowFlags(Qt::FramelessWindowHint|Qt::Dialog);
    setMinimumSize(900,700);

    title = new Widget_Title(this);
    connect(title,SIGNAL(closeWindow()),this,SLOT(close()));
    connect(title,SIGNAL(minimizeWindow()),this,SLOT(showMinimized()));

    pageHard = new Page_hard(this);
    pageSoft = new Page_soft(this);
    pageTest = new Page_test(this);

    stackWidget = new QStackedWidget();
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(Qt::white));
    stackWidget->setPalette(palette);
    stackWidget->setAutoFillBackground(true);

    stackWidget->addWidget(pageHard);
    stackWidget->addWidget(pageSoft);
    stackWidget->addWidget(pageTest);

    connect(title,SIGNAL(turnPage(int)),this,SLOT(turnPage(int)));

    QGridLayout *rootlayout = new QGridLayout;
    rootlayout->addWidget(title,0,0,Qt::AlignTop);
    rootlayout->addWidget(stackWidget,1,0,Qt::AlignLeft);
    rootlayout->setSpacing(0);
    rootlayout->setContentsMargins(0,0,0,0);

    setLayout(rootlayout);
}

Dialog::~Dialog()
{

}
void Dialog::paintEvent(QPaintEvent *)
{
}
void Dialog::init()
{

}
void Dialog::turnPage(int index)
{
    switch(index)
    {
    case 0:
    {
        stackWidget->setCurrentWidget(pageHard);
        break;
    }
    case 1:
    {
        stackWidget->setCurrentWidget(pageSoft);
        break;
    }
    case 2:
    {
        stackWidget->setCurrentWidget(pageTest);
        break;
    }
    default:
    {
        stackWidget->setCurrentWidget(pageHard);
        break;
    }
    }
}
void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton&&title->geometry().contains(event->pos()))
    {
        mousemove=true;
        oldPos=event->globalPos();
    }
}
void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(mousemove)
    {
        move(this->x()+event->globalPos().x()-oldPos.x(),this->y()+event->globalPos().y()-oldPos.y());
        oldPos=event->globalPos();
    }
}
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    mousemove=false;
}
