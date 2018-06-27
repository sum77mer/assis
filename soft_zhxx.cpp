#include "soft_zhxx.h"
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QWidget>
Soft_ZHXX::Soft_ZHXX(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QStringLiteral("操作系统名称:xxxx"));

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QStringLiteral("操作系统语言:xxxx"));

    QLabel *label3 = new QLabel(this);
    label3->setFrameStyle(QFrame::NoFrame);
    label3->setText(QStringLiteral("操作系统安装语言:xxxx"));

    QLabel *label4 = new QLabel(this);
    label4->setFrameStyle(QFrame::NoFrame);
    label4->setText(QStringLiteral("操作系统核心类型:xxxx"));

    QLabel *label5 = new QLabel(this);
    label5->setFrameStyle(QFrame::NoFrame);
    label5->setText(QStringLiteral("操作系统版本:xxxx"));

    QLabel *label6 = new QLabel(this);
    label6->setFrameStyle(QFrame::NoFrame);
    label6->setText(QStringLiteral("操作系统版本升级:xxxx"));

    QLabel *label7 = new QLabel(this);
    label7->setFrameStyle(QFrame::NoFrame);
    label7->setText(QStringLiteral("操作系统安装日期:xxxx"));

    QLabel *label8 = new QLabel(this);
    label8->setFrameStyle(QFrame::NoFrame);
    label8->setText(QStringLiteral("注册人:xxxx"));

    QLabel *label9 = new QLabel(this);
    label9->setFrameStyle(QFrame::NoFrame);
    label9->setText(QStringLiteral("注册组织:xxxx"));

    QLabel *label10 = new QLabel(this);
    label10->setFrameStyle(QFrame::NoFrame);
    label10->setText(QStringLiteral("产品ID:xxxx"));

    QLabel *label11 = new QLabel(this);
    label11->setFrameStyle(QFrame::NoFrame);
    label11->setText(QStringLiteral("产品激活:xxxx"));

    QLabel *label12 = new QLabel(this);
    label12->setFrameStyle(QFrame::NoFrame);
    label12->setText(QStringLiteral("计算机名称:xxxx"));

    QLabel *label13 = new QLabel(this);
    label13->setFrameStyle(QFrame::NoFrame);
    label13->setText(QStringLiteral("用户名称:xxxx"));

    QLabel *label14 = new QLabel(this);
    label14->setFrameStyle(QFrame::NoFrame);
    label14->setText(QStringLiteral("登陆域:xxxx"));

    QLabel *label15 = new QLabel(this);
    label15->setFrameStyle(QFrame::NoFrame);
    label15->setText(QStringLiteral("已运行时间:xxxx"));

    QLabel *label16 = new QLabel(this);
    label16->setFrameStyle(QFrame::NoFrame);
    label16->setText(QStringLiteral("操作系统名称:xxxx"));

    QLabel *label17 = new QLabel(this);
    label17->setFrameStyle(QFrame::NoFrame);
    label17->setText(QStringLiteral("操作系统名称:xxxx"));

    QLabel *label18 = new QLabel(this);
    label18->setFrameStyle(QFrame::NoFrame);
    label18->setText(QStringLiteral("操作系统名称:xxxx"));

    QLabel *label19 = new QLabel(this);
    label19->setFrameStyle(QFrame::NoFrame);
    label19->setText(QStringLiteral("操作系统名称:xxxx"));

    QGridLayout *sublayout = new QGridLayout;
    sublayout->setContentsMargins(10,20,10,10);
    sublayout->addWidget(label1,0,0,Qt::AlignLeft);
    sublayout->addWidget(label2,1,0,Qt::AlignLeft);
    sublayout->addWidget(label3,2,0,Qt::AlignLeft);
    sublayout->addWidget(label4,3,0,Qt::AlignLeft);
    sublayout->addWidget(label5,4,0,Qt::AlignLeft);
    sublayout->addWidget(label6,5,0,Qt::AlignLeft);
    sublayout->addWidget(label7,6,0,Qt::AlignLeft);
    sublayout->addWidget(label8,7,0,Qt::AlignLeft);
    sublayout->addWidget(label9,8,0,Qt::AlignLeft);
    sublayout->addWidget(label10,9,0,Qt::AlignLeft);
    sublayout->addWidget(label11,10,0,Qt::AlignLeft);
    sublayout->addWidget(label12,11,0,Qt::AlignLeft);
    sublayout->addWidget(label13,12,0,Qt::AlignLeft);
    sublayout->addWidget(label14,13,0,Qt::AlignLeft);
    sublayout->addWidget(label15,14,0,Qt::AlignLeft);
    sublayout->addWidget(label16,15,0,Qt::AlignLeft);
    sublayout->addWidget(label17,16,0,Qt::AlignLeft);
    sublayout->addWidget(label18,17,0,Qt::AlignLeft);
    sublayout->addWidget(label19,18,0,Qt::AlignLeft);

    QWidget *widget = new QWidget(this);
    widget->setWindowFlags(Qt::FramelessWindowHint);
    widget->setLayout(sublayout);

    QScrollArea *scrollarea = new QScrollArea;
    scrollarea->setBackgroundRole(QPalette::Window);
    scrollarea->setFrameStyle(QFrame::NoFrame);
    scrollarea->setWidget(widget);

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(scrollarea);

    setLayout(layout);

}
void Soft_ZHXX::paintEvent(QPaintEvent *event)
{}
