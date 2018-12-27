#include "widget_sidetab.h"

Widget_sideTab::Widget_sideTab(QWidget *parent,QString title)
{
	setFont(*font);
    btnStatus=NORMAL;
    mousePress=false;
    choosedflag=false;
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
	setText(title);
	
	switch (this->logicalDpiY())
	{
	case 96:
	{
		scaleV = 1;
		break;
	}
	case 120:
	{
		scaleV = 1.25;
		break;
	}
	case 144:
	{
		scaleV = 1.5;
		break;
	}
	case 168:
	{
		scaleV = 1.75;
		break;
	}
	case 192:
	{
		scaleV = 2.0;
		break;
	}
	case 216:
	{
		scaleV = 2.25;
		break;
	}
	case 240:
	{
		scaleV = 2.5;
		break;
	}
	case 288:
	{
		scaleV = 3.0;
		break;
	}
	default:
	{
		scaleV = 1.0;
		break;
	}
	}
	switch (this->logicalDpiX())
	{
	case 96:
	{
		scaleH = 1;
		break;
	}
	case 120:
	{
		scaleH = 1.25;
		break;
	}
	case 144:
	{
		scaleH = 1.5;
		break;
	}
	case 168:
	{
		scaleH = 1.75;
		break;
	}
	case 192:
	{
		scaleH = 2.0;
		break;
	}
	case 216:
	{
		scaleH = 2.25;
		break;
	}
	case 240:
	{
		scaleH = 2.5;
		break;
	}
	case 288:
	{
		scaleH = 3.0;
		break;
	}
	default:
	{
		scaleH = 1.0;
		break;
	}
	}
	btnHeight *= scaleV;
	leftMargin *= scaleH;
	dotR *= scaleV;
	setMinimumHeight(btnHeight);
	//setContentsMargins(2, 2, 2, 2);
    btnTitle=title;
}
Widget_sideTab::~Widget_sideTab()
{}
void Widget_sideTab::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    painter.setFont(*font);
	QRect circleRect = this->rect();
	circleRect.setX(this->rect().x() + leftMargin);
	int y = this->rect().y();
	y = y + this->rect().height() / 2 - dotR;
	circleRect.setY(y);
	circleRect.setHeight(dotR*2);
	circleRect.setWidth(dotR*2);
    switch(btnStatus)
    {
    case NORMAL:
    {
		painter.setPen(Qt::NoPen);
        brush.setColor(backgroundColor_normal);//background:white
        painter.setBrush(brush);
        painter.drawRect(this->rect());
		brush.setColor(titleColor_normal);//dot:black
		painter.setPen(titleColor_normal);//
		painter.setBrush(brush);
		painter.drawEllipse(circleRect);
        break;
    }
    case ENTER:
    {
		painter.setPen(Qt::NoPen);
        brush.setColor(backgroundColor_enter);//background:black
        painter.setBrush(brush);
        painter.drawRect(this->rect());
		brush.setColor(titleColor_enter);
		painter.setPen(titleColor_enter);
		painter.setBrush(brush);
		painter.drawEllipse(circleRect);
        break;
    }
    case PRESS:
    {
		painter.setPen(Qt::NoPen);
        brush.setColor(backgroundColor_choosed);//background:black
        painter.setBrush(brush);
        painter.drawRect(this->rect());
		brush.setColor(titleColor_enter);
		painter.setPen(titleColor_enter);
		painter.setBrush(brush);
		painter.drawEllipse(circleRect);
        break;
    }
    case NOSTATUS:
    {
		painter.setPen(Qt::NoPen);
        brush.setColor(backgroundColor_normal);//background:white
        painter.setBrush(brush);
        painter.drawRect(this->rect());
		brush.setColor(titleColor_normal);
		painter.setPen(titleColor_normal);
		painter.setBrush(brush);
		painter.drawEllipse(circleRect);
        break;
    }
    default:
    {
		painter.setPen(Qt::NoPen);
        brush.setColor(backgroundColor_normal);//background:white
        painter.setBrush(brush);
        painter.drawRect(this->rect());
		brush.setColor(titleColor_normal);
		painter.setPen(titleColor_normal);
		painter.setBrush(brush);
		painter.drawEllipse(circleRect);
        break;
    }
    }
	QRect titleRect = this->rect();
	int x = titleRect.x();
	x += leftMargin+dotR*2+10;
	titleRect.setX(x);
	painter.drawText(titleRect, Qt::AlignVCenter|Qt::AlignLeft, btnTitle,&titleRect);
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
