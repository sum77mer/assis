#include "hard_other.h"
#include <QPainter>
#include <QLabel>
#include <QGridLayout>
Hard_Other::Hard_Other(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QStringLiteral("声卡 High Definition Audio Controller(nVIDIA unknown)"));
    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QStringLiteral("声卡 Intel Lynx Point PCH-High Definition Audio"));
    QLabel *label3 = new QLabel(this);
    label3->setFrameStyle(QFrame::NoFrame);
    label3->setText(QStringLiteral("鼠标 HID-compliant mouse"));
    QLabel *label4 = new QLabel(this);
    label4->setFrameStyle(QFrame::NoFrame);
    label4->setText(QStringLiteral("键盘 HIS Keyboard Device"));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->setRowStretch(0,0);
    layout->setRowStretch(1,0);
    layout->setRowStretch(2,0);
    layout->setRowStretch(3,0);
    layout->setRowStretch(4,1);
    layout->addWidget(label1,0,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(label2,1,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(label3,2,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(label4,3,0,1,1,Qt::AlignLeft|Qt::AlignTop);

    setLayout(layout);
}
void Hard_Other::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("other"));
}
