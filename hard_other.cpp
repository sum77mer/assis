#include "hard_other.h"
#include "UIdata.h"
#include <QPainter>
#include <QLabel>
#include <QGridLayout>
#include <qscrollarea.h>
#include <qdebug.h>
Hard_Other::Hard_Other(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
	setFont(*normalFont);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();	
}
void Hard_Other::paintEvent(QPaintEvent *event)
{
}
void Hard_Other::initializeUI()
{
	QString str_audio;
	value_audio = new QLabel(this);
	value_audio->setFrameStyle(QFrame::NoFrame);
	value_audio->setText(str_audio);
}
void Hard_Other::setupLayout()
{
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(10, 20, 10, 10);
	sublayout->setRowStretch(0, 0);
	sublayout->setRowStretch(1, 0);
	sublayout->setRowStretch(2, 0);
	sublayout->setRowStretch(3, 0);
	sublayout->setRowStretch(4, 1);
	sublayout->addWidget(value_audio, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	QWidget *widget = new QWidget(this);
	widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	widget->setWindowFlags(Qt::FramelessWindowHint);
	widget->setLayout(sublayout);

	scrollarea = new QScrollArea;
	scrollarea->setBackgroundRole(QPalette::Window);
	scrollarea->setFrameStyle(QFrame::NoFrame);
	scrollarea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	scrollarea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	scrollarea->setAlignment(Qt::AlignCenter);
	scrollarea->setAutoFillBackground(true);
	scrollarea->setWidgetResizable(true);
	//scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollarea->setWidget(widget);
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(scrollarea);

	setLayout(layout);
}
void Hard_Other::setConnection()
{

}
void Hard_Other::initializeData()
{
	vector<GetData::Audio_Information> x;
	data.getAudio(x);
	QString str;
	for (auto &i : x)
	{
		str += "Name:" + QString::fromStdWString(i.name) + "\r\n";
		str += "AudioIf:" + QString::fromStdWString(i.audioif) + "\r\n";
		str += "State:" + QString::fromStdWString(i.state) + "\r\n";
		str += "ID:" + QString::fromStdWString(i.id) + "\r\n";
		str += "Description:" + QString::fromStdWString(i.desc) + "\r\n";
		str + "\r\n";
	}
	value_audio->setText(str);
}
void Hard_Other::updateData()
{
	data.updateHardware();
	initializeData();
}
void Hard_Other::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}