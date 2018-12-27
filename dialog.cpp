#include "dialog.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QPicture>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QMouseEvent>
#include "myshadow.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //root window setting
    setWindowFlags(Qt::FramelessWindowHint|Qt::Window);
	
	dpiX = this->logicalDpiX();
	dpiY = this->logicalDpiY();

	switch (dpiX)
	{
	case 96:
	{
		scaleX = 1;
		break;
	}
	case 120:
	{
		scaleX = 1.25;
		break;
	}
	case 144:
	{
		scaleX = 1.5;
		break;
	}
	case 168:
	{
		scaleX = 1.75;
		break;
	}
	case 192:
	{
		scaleX = 2;
		break;
	}
	case 216:
	{
		scaleX = 2.25;
		break;
	}
	case 240:
	{
		scaleX = 2.5;
		break;
	}
	case 288:
	{
		scaleX = 3;
		break;
	}
	default:
	{
		scaleX = 1;
		break;
	}
	}
	switch (dpiY)
	{
	case 96:
	{
		scaleY = 1;
		break;
	}
	case 120:
	{
		scaleY = 1.25;
		break;
	}
	case 144:
	{
		scaleY = 1.5;
		break;
	}
	case 168:
	{
		scaleY = 1.75;
		break;
	}
	case 192:
	{
		scaleY = 2;
		break;
	}
	case 216:
	{
		scaleY = 2.25;
		break;
	}
	case 240:
	{
		scaleY = 2.5;
		break;
	}
	case 288:
	{
		scaleY = 3;
		break;
	}
	default:
	{
		scaleY = 1;
		break;
	}
	}
	
	double resizedW = width*scaleX;
	double resizedH = height*scaleY;
	width = resizedW;
	height = resizedH;
	
	setMaximumSize(width,height);
	setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

	setAutoFillBackground(false);
	setAttribute(Qt::WA_TranslucentBackground, true);
	QPalette palette;
	palette.setBrush(QPalette::Window, QBrush(Qt::white));

	frame = new QFrame(this);
	frame->setFrameStyle(QFrame::NoFrame);
	frame->setPalette(palette);
	frame->setAutoFillBackground(true);
	frame->setMinimumSize(width - 10, height - 10);

	MyShadow *shadow = new MyShadow(this);
	shadow->setBlurRadius(10.0);
	shadow->setDistance(1.0);
	shadow->setColor(QColor(0, 0, 0, 200));
	frame->setGraphicsEffect(shadow);
	

    title = new Widget_Title(scaleX, scaleY, this);
    connect(title,SIGNAL(closeWindow()),this,SLOT(close()));
    connect(title,SIGNAL(minimizeWindow()),this,SLOT(showMinimized()));

    pageHard = new Page_hard(scaleX, scaleY, this);
    pageSoft = new Page_soft(scaleX, scaleY, this);
    pageTest = new Page_test(scaleX, scaleY, this);

    stackWidget = new QStackedWidget();
    
    stackWidget->setPalette(palette);
    stackWidget->setAutoFillBackground(true);

    stackWidget->addWidget(pageHard);
    stackWidget->addWidget(pageSoft);
    stackWidget->addWidget(pageTest);

    connect(title,SIGNAL(turnPage(int)),this,SLOT(turnPage(int)));

    QGridLayout *sublayout = new QGridLayout;
	sublayout->setRowStretch(0, 1);
	sublayout->setRowStretch(1, 5);
	sublayout->addWidget(title,0,0);
	sublayout->addWidget(stackWidget,1,0);
	sublayout->setSpacing(0);
	sublayout->setContentsMargins(0,0,0,0);
	frame->setLayout(sublayout);

	QGridLayout *rootlayout = new QGridLayout;
	rootlayout->setContentsMargins(5, 5, 5, 5);
	rootlayout->addWidget(frame, 0, 0, 1, 1, Qt::AlignCenter);
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
		pageSoft->reset();
		pageTest->reset();
        stackWidget->setCurrentWidget(pageHard);
        break;
    }
    case 1:
    {
		pageHard->reset();
		pageTest->reset();
        stackWidget->setCurrentWidget(pageSoft);
        break;
    }
    case 2:
    {
		pageHard->reset();
		pageSoft->reset();
        stackWidget->setCurrentWidget(pageTest);
		
        break;
    }
    default:
    {
		pageSoft->reset();
		pageTest->reset();
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
		m_windowPoint = this->frameGeometry().topLeft();
    }
}
void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(mousemove)
    {
        //move(this->x()+event->globalPos().x()-oldPos.x(),this->y()+event->globalPos().y()-oldPos.y());
		QPoint relativePos = event->globalPos() - oldPos;
		move(m_windowPoint + relativePos);
    }
}
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    mousemove=false;
}
