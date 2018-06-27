#include "hard_gfx.h"
#include <QPainter>
#include <QScrollArea>
#include <QGridLayout>
#include <QGroupBox>
#include <QWidget>
#include <QLabel>
#include "widget_treebrowser.h"
#include "libheaders/gpu.h"
using namespace SV_ASSIST::GPU;
Hard_GFX::Hard_GFX(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QString str_gpu = QString().fromStdString(GPUName());
    //qDebug()
    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QStringLiteral("显卡"));
    QLabel *clabel1 = new QLabel(this);
    clabel1->setFrameStyle(QFrame::NoFrame);
    clabel1->setText(QStringLiteral("Dell Inc"));

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QStringLiteral("Version"));
    QLabel *clabel2 = new QLabel(this);
    clabel2->setFrameStyle(QFrame::NoFrame);
    clabel2->setText(QStringLiteral("A08"));

    QLabel *label3 = new QLabel(this);
    label3->setFrameStyle(QFrame::NoFrame);
    label3->setText(QStringLiteral("Date"));
    QLabel *clabel3 = new QLabel(this);
    clabel3->setFrameStyle(QFrame::NoFrame);
    clabel3->setText(QStringLiteral("04/15/2014"));

    QLabel *label4 = new QLabel(this);
    label4->setFrameStyle(QFrame::NoFrame);
    label4->setText(QStringLiteral("显卡"));
    QLabel *clabel4 = new QLabel(this);
    clabel4->setFrameStyle(QFrame::NoFrame);
    clabel4->setText(QStringLiteral("Dell Inc"));

    QLabel *label5 = new QLabel(this);
    label5->setFrameStyle(QFrame::NoFrame);
    label5->setText(QStringLiteral("Version"));
    QLabel *clabel5 = new QLabel(this);
    clabel5->setFrameStyle(QFrame::NoFrame);
    clabel5->setText(QStringLiteral("A08"));

    QLabel *label6 = new QLabel(this);
    label6->setFrameStyle(QFrame::NoFrame);
    label6->setText(QStringLiteral("Date"));
    QLabel *clabel6 = new QLabel(this);
    clabel6->setFrameStyle(QFrame::NoFrame);
    clabel6->setText(QStringLiteral("04/15/2014"));

    QGridLayout *group1layout = new QGridLayout;
    QGridLayout *group2layout = new QGridLayout;
    group1layout->setContentsMargins(20,10,0,10);
    group2layout->setContentsMargins(20,10,0,10);

    group1layout->setColumnStretch(0,0);
    group1layout->setColumnStretch(1,10);

    group2layout->setColumnStretch(0,0);
    group2layout->setColumnStretch(1,10);

    group1layout->addWidget(label1,0,0,1,1,Qt::AlignLeft);
    group1layout->addWidget(clabel1,0,1,1,1,Qt::AlignLeft);
    group1layout->addWidget(label2,1,0,1,1,Qt::AlignLeft);
    group1layout->addWidget(clabel2,1,1,1,1,Qt::AlignLeft);
    group1layout->addWidget(label3,2,0,1,1,Qt::AlignLeft);
    group1layout->addWidget(clabel3,2,1,1,1,Qt::AlignLeft);

    group2layout->addWidget(label4,0,0,1,1,Qt::AlignLeft);
    group2layout->addWidget(clabel4,0,1,1,1,Qt::AlignLeft);
    group2layout->addWidget(label5,1,0,1,1,Qt::AlignLeft);
    group2layout->addWidget(clabel5,1,1,1,1,Qt::AlignLeft);
    group2layout->addWidget(label6,2,0,1,1,Qt::AlignLeft);
    group2layout->addWidget(clabel6,2,1,1,1,Qt::AlignLeft);


    QGroupBox *groupbox1 = new QGroupBox(tr("graphic card"));
    QGroupBox *groupbox2 = new QGroupBox(tr("monitor"));
    groupbox1->setLayout(group1layout);
    groupbox1->setMinimumWidth(750);
    groupbox2->setLayout(group2layout);
    groupbox2->setMinimumWidth(750);

    QStandardItemModel *model = new QStandardItemModel(this);
    QStandardItem *parentItem = model->invisibleRootItem();
    for(int i = 0;i<4;++i)
    {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        parentItem->appendRow(item);
        parentItem = item;
    }
    for(int i = 1;i<10;++i)
    {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        model->setItem(i,0,item);
    }
    Widget_TreeBrowser *treebrowser = new Widget_TreeBrowser(this,model,740,594);

    QGridLayout *sublayout = new QGridLayout;
    sublayout->setContentsMargins(10,10,10,10);
    sublayout->setRowMinimumHeight(2,20);
    sublayout->setRowStretch(0,0);
    sublayout->setRowStretch(1,0);
    sublayout->setRowStretch(2,0);
    sublayout->setRowStretch(3,0);
    sublayout->addWidget(groupbox1,0,0,Qt::AlignCenter);
    sublayout->addWidget(groupbox2,1,0,Qt::AlignCenter);
    sublayout->addWidget(treebrowser,3,0,1,1,Qt::AlignCenter);

    QWidget *widget = new QWidget(this);
    widget->setWindowFlags(Qt::FramelessWindowHint);
    widget->setLayout(sublayout);

    QScrollArea *scrollarea = new QScrollArea;
    scrollarea->setBackgroundRole(QPalette::Window);
    scrollarea->setFrameStyle(QFrame::NoFrame);
    scrollarea->setWidget(widget);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(scrollarea);
    layout->setContentsMargins(0,0,0,0);

    setLayout(layout);

}
void Hard_GFX::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("gfx"));
}
