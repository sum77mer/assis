#include "widget_maintab.h"

Widget_mainTab::Widget_mainTab(QWidget *parent,QString title,QString iconname)
    :QPushButton(parent)
{
	setFont(*font);
	setText(btnTitle);
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
	
	btnTitle = title;
	titleWidth = this->fontMetrics().maxWidth()*title.length();
	titleHeight = this->fontMetrics().height();
    
	iconName = iconname;
	//iconHeight = titleHeight*3;
	iconHeight = QPixmap(iconName).height()*scaleV;
	iconWidth = QPixmap(iconName).width()*scaleH;
	//double ratio = QPixmap(iconName).width();
	//ratio = ratio / QPixmap(iconName).height();
	//iconWidth = ratio*iconHeight;

	btnWidth = 70 * scaleH;
	btnHeight = 70 * scaleV;
	//btnWidth = titleWidth;
	//if (btnWidth < iconWidth)
	//	btnWidth = iconWidth;
	//btnHeight = iconHeight + titleHeight+5;
	
	btnStatus = NORMAL;
	mousePress = false;
	choosed = false;
	
	setMinimumSize(btnWidth, btnHeight);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}
Widget_mainTab::~Widget_mainTab()
{}
/*
void Widget_mainTab::setIcon(QString icon_name)
{

}
*/

/*void Widget_mainTab::setText(const QString text)
{
    btnTitle=text;
}*/
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
	QRect target = this->rect();
	int x = (this->rect().width() - iconWidth) / 2 + this->rect().x();
	target.setX(x);
	target.setWidth(iconWidth);
	target.setHeight(iconHeight);

	QRect source = pixmap.rect();
    painter.drawPixmap(target,pixmap,source);
    painter.setFont(*font);
    painter.setPen(QColor(255,255,255));

	QRect titleRect = this->rect();
	titleRect.setHeight(titleRect.height() - 7);
    painter.drawText(titleRect,Qt::AlignBottom|Qt::AlignHCenter,btnTitle);
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
