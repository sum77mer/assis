#include "hard_net.h"
#include "UIdata.h"
#include <QPainter>
#include <QGridLayout>
#include <QLabel>
#include <qdebug.h>
#include"UIconst.h"
Hard_Net::Hard_Net(QWidget *parent)
{
	setFont(enNormalFont);
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Hard_Net::paintEvent(QPaintEvent *event)
{
}
void Hard_Net::initializeUI()
{
	QString str_net;
	value_net = new QLabel(this);
	value_net->setFrameStyle(QFrame::NoFrame);
	value_net->setText(str_net);
}
void Hard_Net::setupLayout()
{
	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(10, 20, 10, 10);
	layout->setRowStretch(0, 0);
	layout->addWidget(value_net, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);

	setLayout(layout);
}
void Hard_Net::setConnection()
{}
void Hard_Net::initializeData()
{
	vector<GetData::Net_Information> x;
	data.getNet(x);
	QString str;
	for (auto &i : x)
	{
		str += "Name:" + QString::fromStdWString(i.name) + "\r\n";
		str += "Device Name:" + QString::fromStdWString(i.deviceName) + "\r\n";
		str += "Media Type:" + QString::fromStdWString(i.mediaType) + "\r\n";
		str += "State:" + QString::fromStdWString(i.state) + "\r\n";
		str += "\r\n";
	}
	value_net->setText(str);
}
void Hard_Net::updateData()
{
	data.updateHardware();
	initializeData();
}
void Hard_Net::reset()
{
	//scrollarea->verticalScrollBar()->setValue(0);
}