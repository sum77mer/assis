#include "widget_sidetabgroup.h"
Widget_sideTabGroup::Widget_sideTabGroup(QWidget *parent,QStringList string_list)
{
    setWindowFlags(Qt::FramelessWindowHint);
	setMinimumHeight(parent->rect().height());
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
	setMinimumWidth(scaleH * 186);
	setStyleSheet(QString("background-color:black"));
    QVBoxLayout *button_layout = new QVBoxLayout();
    QSignalMapper *signal_mapper=new QSignalMapper(this);
    stringList=string_list;
    for(int i=0;i<string_list.size();i++)
    {
        Widget_sideTab *tab=new Widget_sideTab(this,string_list.at(i));
        btnList.append(tab);
        connect(tab,SIGNAL(clicked()),signal_mapper,SLOT(map()));
        signal_mapper->setMapping(tab,QString::number(i,10));
        button_layout->addWidget(tab,0);
        if(i==0)
            tab->setMousePress(true);
    }
    connect(signal_mapper,SIGNAL(mapped(QString)),this,SLOT(childChoosed(QString)));
    button_layout->addStretch();
    button_layout->setSpacing(0);
    button_layout->setContentsMargins(0,0,0,0);

    setLayout(button_layout);
}
void Widget_sideTabGroup::paintEvent(QPaintEvent *event)
{
}
void Widget_sideTabGroup::childChoosed(QString index)//unsigned int index
{
    bool ok;
    int current_index=index.toInt(&ok,10);
    for(int i=0;i<btnList.count();i++)
    {
        Widget_sideTab *tab=btnList.at(i);
        if(current_index==i)
        {
            tab->setMousePress(true);
        }
        else
        {
            tab->setMousePress(false);
        }
    }
    emit turnPage(current_index);
}
void Widget_sideTabGroup::reset()
{
	for (auto it : btnList)
	{
		it->setMousePress(false);
	}
	btnList.at(0)->setMousePress(true);
}
