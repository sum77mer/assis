#include "widget_title.h"
#include <QPainter>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSignalMapper>
#include <QMenu>
#include <QAction>
Widget_Title::Widget_Title(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(900,106);
    //sys button
    close_btn=new Widget_PushButton();
    min_btn=new Widget_PushButton();
    config_btn=new Widget_PushButton();
    more_btn=new Widget_PushButton();

    close_btn->setIcon(QString(":/close"));
    min_btn->setIcon(QString(":/min"));
    config_btn->setIcon(QString(":/feedback"));
    more_btn->setIcon(QString(":/menu"));

    QMenu *menu = new QMenu();
    helpaction = menu->addAction(QString("Help"));
    aboutaction = menu->addAction(QString("About"));
    more_btn->setMenu(menu);

    connect(close_btn,SIGNAL(clicked(bool)),this,SIGNAL(closeWindow()));
    connect(min_btn,SIGNAL(clicked(bool)),this,SIGNAL(minimizeWindow()));
    connect(config_btn,SIGNAL(clicked(bool)),this,SLOT(configWindow()));
    connect(menu,SIGNAL(triggered(QAction *)),this,SLOT(helpWindow(QAction *)));
    connect(menu,SIGNAL(triggered(QAction *)),this,SLOT(aboutWindow(QAction *)));

    QHBoxLayout *btnlayout=new QHBoxLayout;
    btnlayout->addWidget(min_btn);
    btnlayout->addWidget(config_btn);
    btnlayout->addWidget(more_btn);
    btnlayout->addWidget(close_btn);

    btnlayout->setSpacing(0);
    btnlayout->setAlignment(Qt::AlignRight|Qt::AlignTop);
    btnlayout->setContentsMargins(0,0,0,0);


    QHBoxLayout *tablayout = new QHBoxLayout();
    QSignalMapper *signal_mapper=new QSignalMapper(this);
    QStringList title_list;
    QStringList icon_list;
    title_list<<"硬件助手"<<"软件助手"<<"性能测试";
    icon_list<<":/hard"<<":/soft"<<":/test";
    for(int i=0;i<title_list.size();i++)
    {
        Widget_mainTab *tab=new Widget_mainTab();
        tab->setIcon(icon_list.at(i));
        tab->setText(title_list.at(i));
        btnList.append(tab);
        connect(tab,SIGNAL(clicked()),signal_mapper,SLOT(map()));
        signal_mapper->setMapping(tab,QString::number(i,10));
        tablayout->addWidget(tab,0,Qt::AlignBottom);
        if(i==0)
            tab->setMousePress(true);
    }
    connect(signal_mapper,SIGNAL(mapped(QString)),this,SLOT(pageChange(QString)));
    tablayout->addStretch();
    tablayout->setSpacing(10);
    tablayout->setContentsMargins(100,0,0,0);

    QGridLayout *layout = new QGridLayout();
    layout->addLayout(tablayout,1,1,Qt::AlignLeft|Qt::AlignBottom);
    layout->addLayout(btnlayout,1,1,Qt::AlignRight|Qt::AlignTop);
    layout->setContentsMargins(0,0,0,0);

    setLayout(layout);
}
void Widget_Title::paintEvent(QPaintEvent *event)
{
    QPainter titlepainter(this);
    titlepainter.drawText(QRect(0,0,100,50),Qt::AlignCenter,tr("SV-ASSIST"));
    QRectF target(0.0,0.0,900.0,106.0);
    QRectF source(0.0,0.0,900.0,106.0);
    QPixmap pixmap;
    pixmap.load(":/panel");
    QPainter painter(this);
    painter.drawPixmap(target,pixmap,source);
}
void Widget_Title::pageChange(QString index)
{
    //qDebug()<<"child choosed"<<index;
    bool ok;
    int current_index=index.toInt(&ok,10);
    for(int i=0;i<btnList.count();i++)
    {
        Widget_mainTab *tab=btnList.at(i);
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
void Widget_Title::configWindow()
{
    qDebug()<<"config clicked";
    windowConfig = new Window_config(this);
    windowConfig->show();

}
void Widget_Title::helpWindow(QAction *action)
{
    if(action==helpaction)
    {
        qDebug()<<"help triggered";
        windowHelp = new Window_help(this);
        windowHelp->show();
    }
}
void Widget_Title::aboutWindow(QAction *action)
{
    if(action==aboutaction)
    {
        qDebug()<<"about triggered";
        windowAbout = new Window_about(this);
        windowAbout->show();
    }
}
