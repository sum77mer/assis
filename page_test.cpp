#include "page_test.h"
#include <QPushButton>
#include <QPalette>
#include <QCheckBox>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
Page_test::Page_test(QWidget *parent)
{
    setFixedSize(900,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QStringList stringlist;
    stringlist<<"CPU"<<"Memory"<<"Disk";
    sideTabGroup = new Widget_sideTabGroup(0,stringlist);

    pbtnoutput = new QPushButton("输出报告",this);
    pbtnoutput->setFixedSize(70,25);
    connect(pbtnoutput,SIGNAL(clicked(bool)),this,SLOT(reportWindow()));


    QGridLayout *tablayout=new QGridLayout;
    tablayout->setSpacing(0);
    tablayout->setContentsMargins(0,0,0,0);
    tablayout->setRowStretch(0,1);
    tablayout->setRowStretch(1,0);
    tablayout->setRowStretch(2,0);
    tablayout->addWidget(sideTabGroup,0,0,Qt::AlignTop|Qt::AlignLeft);
    tablayout->addWidget(pbtnoutput,1,0,Qt::AlignCenter);
    tablayout->setRowMinimumHeight(2,20);

    testCPU = new Test_CPU(this);
    testMemory = new Test_Memory(this);
    testStorage = new Test_Storage(this);

    stackWidget = new QStackedWidget();
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(Qt::transparent));
    stackWidget->setPalette(palette);
    stackWidget->setAutoFillBackground(true);

    stackWidget->addWidget(testCPU);
    stackWidget->addWidget(testMemory);
    stackWidget->addWidget(testStorage);

    connect(sideTabGroup,SIGNAL(turnPage(int)),this,SLOT(turnPage(int)));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->addLayout(tablayout,0,0,Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(stackWidget,0,1,Qt::AlignTop|Qt::AlignLeft);

    setLayout(layout);
}
void Page_test::paintEvent(QPaintEvent *event)
{
}
void Page_test::turnPage(int index)
{
    switch(index)
    {
    case 0:
    {
        stackWidget->setCurrentWidget(testCPU);
        break;
    }
    case 1:
    {
        stackWidget->setCurrentWidget(testMemory);
        break;
    }
    case 2:
    {
        stackWidget->setCurrentWidget(testStorage);
        break;
    }
    default:
    {
        stackWidget->setCurrentWidget(testCPU);
        break;
    }
    }
}
void Page_test::reportWindow()
{
    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QString("Hardware report"));
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
    checkbox6->setText(QString("Memory"));
    QCheckBox *checkbox7 = new QCheckBox(this);
    checkbox7->setText(QString("Disk"));

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
void Page_test::outputReport()
{}
