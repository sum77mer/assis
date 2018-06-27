#include "page_soft.h"
#include <QPushButton>
#include <QPalette>
#include <QCheckBox>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
Page_soft::Page_soft(QWidget *parent)
{
    setFixedSize(900,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QStringList stringlist;
    stringlist<<"General"<<"Configuration";
    sideTabGroup = new Widget_sideTabGroup(0,stringlist);

    pbtnautofresh = new QPushButton("自动刷新",this);
    pbtnfresh = new QPushButton("手动刷新",this);
    pbtnoutput = new QPushButton("输出报告",this);
    pbtnautofresh->setFixedSize(70,25);
    pbtnfresh->setFixedSize(70,25);
    pbtnoutput->setFixedSize(70,25);
    connect(pbtnautofresh,SIGNAL(clicked(bool)),this,SLOT(onAutoRefresh()));
    connect(pbtnfresh,SIGNAL(clicked(bool)),this,SLOT(onManualRefresh()));
    connect(pbtnoutput,SIGNAL(clicked(bool)),this,SLOT(reportWindow()));

    QGridLayout *tablayout=new QGridLayout;
    tablayout->setSpacing(0);
    tablayout->setContentsMargins(0,0,0,0);
    tablayout->setRowStretch(0,1);
    tablayout->setRowStretch(1,0);
    tablayout->setRowStretch(2,0);
    tablayout->setRowStretch(3,0);
    tablayout->setRowStretch(4,0);
    tablayout->addWidget(sideTabGroup,0,0,Qt::AlignTop|Qt::AlignLeft);
    tablayout->addWidget(pbtnautofresh,1,0,Qt::AlignCenter);
    tablayout->addWidget(pbtnfresh,2,0,Qt::AlignCenter);
    tablayout->addWidget(pbtnoutput,3,0,Qt::AlignCenter);
    tablayout->setRowMinimumHeight(4,20);


    softZHXX = new Soft_ZHXX(this);
    softConfig = new Soft_Config(this);

    stackWidget = new QStackedWidget();
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(Qt::transparent));
    stackWidget->setPalette(palette);
    stackWidget->setAutoFillBackground(true);
    stackWidget->addWidget(softZHXX);
    stackWidget->addWidget(softConfig);

    connect(sideTabGroup,SIGNAL(turnPage(int)),this,SLOT(turnPage(int)));

    /*
    QVBoxLayout *btnlayout = new QVBoxLayout;
    btnlayout->setSpacing(0);
    btnlayout->setContentsMargins(0,0,0,10);
    btnlayout->addWidget(pbtnautofresh,0,Qt::AlignBottom);
    btnlayout->addWidget(pbtnfresh,0,Qt::AlignBottom);
    btnlayout->addWidget(pbtnoutput,0,Qt::AlignBottom);

    tablayout->addWidget(sideTabGroup);
    tablayout->addLayout(btnlayout,0);
    tablayout->setSpacing(0);
    tablayout->setContentsMargins(0,0,0,0);
    setLayout(tablayout);
*/

    QGridLayout *layout = new QGridLayout;
    layout->addLayout(tablayout,0,0,Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(stackWidget,0,1,Qt::AlignTop|Qt::AlignLeft);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    setLayout(layout);

}
void Page_soft::paintEvent(QPaintEvent *event)
{
}
void Page_soft::turnPage(int index)
{
    switch(index)
    {
    case 0:
    {
        stackWidget->setCurrentWidget(softZHXX);
        break;
    }
    case 1:
    {
        stackWidget->setCurrentWidget(softConfig);
        break;
    }
    default:
    {
        stackWidget->setCurrentWidget(softZHXX);
        break;
    }
    }
}
void Page_soft::reportWindow()
{
    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QString("hardware report"));
    QCheckBox *checkbox1 = new QCheckBox(this);
    checkbox1->setText(QString("clean"));
    QCheckBox *checkbox2 = new QCheckBox(this);
    checkbox2->setText(QString("specific"));

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QString("software report"));
    QCheckBox *checkbox3 = new QCheckBox(this);
    checkbox3->setText(QString("clean"));
    QCheckBox *checkbox4 = new QCheckBox(this);
    checkbox4->setText(QString("specific"));

    QLabel *label3= new QLabel(this);
    label3->setText(QString("test"));
    QCheckBox *checkbox5 = new QCheckBox(this);
    checkbox5->setText(QString("CPU"));
    QCheckBox *checkbox6 = new QCheckBox(this);
    checkbox6->setText(QString("memory"));
    QCheckBox *checkbox7 = new QCheckBox(this);
    checkbox7->setText(QString("disk"));

    QPushButton *btn = new QPushButton(this);
    btn->setText(QString("output"));

    connect(btn,SIGNAL(clicked(bool)),this,SLOT(outputReport()));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->setColumnStretch(0,0);
    layout->setColumnStretch(1,0);
    layout->setColumnStretch(2,0);
    layout->setColumnStretch(3,1);
    layout->addWidget(label1,0,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox1,0,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox2,0,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(label2,1,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox3,1,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox4,1,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(label3,2,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox5,2,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox6,2,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox7,2,3,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(btn,3,0,1,4,Qt::AlignHCenter|Qt::AlignTop);

    QWidget *window = new QWidget(this);
    window->setWindowFlags(Qt::Window);
    window->setLayout(layout);
    window->setMinimumSize(200,100);
    window->show();
}
void Page_soft::onAutoRefresh()
{}
void Page_soft::onManualRefresh()
{}
void Page_soft::outputReport()
{}
