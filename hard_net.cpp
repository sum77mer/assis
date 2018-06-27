#include "hard_net.h"
#include <QPainter>
#include <QGridLayout>
#include <QLabel>
Hard_Net::Hard_Net(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QStringLiteral("网卡型号:Haswell/Lynx Point"));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->setRowStretch(0,0);
    layout->addWidget(label1,0,0,1,1,Qt::AlignLeft|Qt::AlignTop);

    setLayout(layout);
}
void Hard_Net::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("net"));
}
