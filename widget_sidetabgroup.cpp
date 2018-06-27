#include "widget_sidetabgroup.h"
Widget_sideTabGroup::Widget_sideTabGroup(QWidget *parent,QStringList string_list)
{
    setWindowFlags(Qt::FramelessWindowHint);
    QVBoxLayout *button_layout = new QVBoxLayout();
    QSignalMapper *signal_mapper=new QSignalMapper(this);
    stringList=string_list;
    for(int i=0;i<string_list.size();i++)
    {
        Widget_sideTab *tab=new Widget_sideTab(0,100,30,string_list.at(i));
        btnList.append(tab);
        connect(tab,SIGNAL(clicked()),signal_mapper,SLOT(map()));
        signal_mapper->setMapping(tab,QString::number(i,10));
        button_layout->addWidget(tab,0,Qt::AlignBottom);
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
    //qDebug()<<"child choosed"<<index;
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
