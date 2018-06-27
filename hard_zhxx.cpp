#include "hard_zhxx.h"
#include <QPainter>
#include <QLabel>
#include <QGridLayout>
#include <QFormLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QMouseEvent>
Hard_ZHXX::Hard_ZHXX(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    label_computer_model->setFrameStyle(QFrame::NoFrame);
    label_computer_model->setText(QString("xxxx"));

    label_os->setFrameStyle(QFrame::NoFrame);
    label_os->setText(QString("xxxx"));

    label_cpu->setFrameStyle(QFrame::NoFrame);
    label_cpu->setText(QString("xxxx"));

    label_mainboard->setFrameStyle(QFrame::NoFrame);
    label_mainboard->setText(QString("xxxx"));

    label_memory->setFrameStyle(QFrame::NoFrame);
    label_memory->setText(QString("xxxx"));

    label_disk->setFrameStyle(QFrame::NoFrame);
    label_disk->setText(QString("xxxx"));

    label_graphic->setFrameStyle(QFrame::NoFrame);
    label_graphic->setText(QString("xxxx"));

    label_optical_driver->setFrameStyle(QFrame::NoFrame);
    label_optical_driver->setText(QString("xxxx"));

    label_audio->setFrameStyle(QFrame::NoFrame);
    label_audio->setText(QString("xxxx"));

    label_network->setFrameStyle(QFrame::NoFrame);
    label_network->setText(QString("xxxx"));

    QFormLayout *txtlayout = new QFormLayout;
    txtlayout->addRow(tr("computer model"),label_computer_model);
    txtlayout->addRow(tr("os"),label_os);
    txtlayout->addRow(tr("cpu"),label_cpu);
    txtlayout->addRow(tr("mainboard"),label_mainboard);
    txtlayout->addRow(tr("memory"),label_memory);
    txtlayout->addRow(tr("disk"),label_disk);
    txtlayout->addRow(tr("graphic"),label_graphic);
    txtlayout->addRow(tr("optical driver"),label_optical_driver);
    txtlayout->addRow(tr("audio card"),label_audio);
    txtlayout->addRow(tr("network card"),label_network);
    QPixmap pixmap;
    pixmap.load(QString(":/intel"));
    pixmap=pixmap.scaledToHeight(100);
    pixmap=pixmap.scaledToWidth(100);
    picLabel = new QLabel(this);
    picLabel->setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
    picLabel->setPixmap(pixmap);

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(20,20,40,20);
    layout->addLayout(txtlayout,0,0,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(picLabel,0,1,Qt::AlignRight|Qt::AlignTop);

    setLayout(layout);
}
void Hard_ZHXX::paintEvent(QPaintEvent *event)
{
}

void Hard_ZHXX::mousePressEvent(QMouseEvent *event)
{
   if(picLabel->geometry().contains(event->pos()))
    {
       qDebug()<<"url clicked";
       QDesktopServices::openUrl(QUrl("https://www.intel.cn",QUrl::TolerantMode));
    }
   else if(event->button()==Qt::RightButton)
   {
       //
   }

}
