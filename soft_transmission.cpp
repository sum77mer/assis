#include "soft_transmission.h"
#include"UIconst.h"
#include <QLabel>
soft_transmission::soft_transmission(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
	setFont(enNormalFont);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void soft_transmission::paintEvent(QPaintEvent *event)
{}
void soft_transmission::initializeUI()
{
	title = new QLabel(this);
	title->setFont(enTitleFont);
	title->setText(QStringLiteral("ÍøÂç´«Êä"));
	title->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));

	tcpValue = new QLabel(this);
	tcpValue->setFrameStyle(QFrame::NoFrame);
	tcpValue->setText("default");

	udpValue = new QLabel(this);
	udpValue->setFrameStyle(QFrame::NoFrame);
	udpValue->setText("default");
}
void soft_transmission::setupLayout()
{
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(10, 20, 10, 10);
	sublayout->setSpacing(5);
	sublayout->setRowStretch(0, 0);
	sublayout->setRowStretch(1, 0);
	sublayout->setRowStretch(2, 0);
	sublayout->setRowStretch(3, 1);
	sublayout->addWidget(title, 0, 0);
	sublayout->addWidget(tcpValue, 1, 0);
	sublayout->addWidget(udpValue, 2, 0);

	QWidget *widget = new QWidget(this);
	widget->setWindowFlags(Qt::FramelessWindowHint);
	widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	widget->setLayout(sublayout);

	scrollarea = new QScrollArea;
	scrollarea->setBackgroundRole(QPalette::Window);
	scrollarea->setFrameStyle(QFrame::NoFrame);
	scrollarea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	scrollarea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	scrollarea->setAlignment(Qt::AlignCenter);
	scrollarea->setAutoFillBackground(true);
	scrollarea->setWidgetResizable(true);
	scrollarea->setWidget(widget);

	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(scrollarea);

	setLayout(layout);
}
void soft_transmission::setConnection()
{}
void soft_transmission::initializeData()
{
	QString str_tcp = "----------TCP----------\r\n";
	QString str_udp = "----------UDP----------\r\n";
	vector<GetData::Connection_Information> x;
	data.getTCP(x);
	for (auto i : x)
	{
		str_tcp += "PID: " + i.PID + "\r\n";
		str_tcp += "uPro: " + i.uPro + "\r\n";
		str_tcp += "state: " + i.state + "\r\n";
		str_tcp += "local IP: " + i.localIP + "\r\n";
		str_tcp += "remote IP: " + i.remoteIP + "\r\n";
		str_tcp += "local Port: " + i.localPort + "\r\n";
		str_tcp += "remote Port: " + i.remotePort + "\r\n";
		str_tcp += "Path: " + i.strPath + "\r\n\r\n";
	}
	data.getUDP(x);
	for (auto i : x)
	{
		str_udp += "PID: " + i.PID + "\r\n";
		str_udp += "uPro: " + i.uPro + "\r\n";
		str_udp += "state: " + i.state + "\r\n";
		str_udp += "local IP: " + i.localIP + "\r\n";
		str_udp += "remote IP: " + i.remoteIP + "\r\n";
		str_udp += "local Port: " + i.localPort + "\r\n";
		str_udp += "remote Port: " + i.remotePort + "\r\n";
		str_udp += "Path: " + i.strPath + "\r\n\r\n";
	}
	tcpValue->setText(str_tcp);
	udpValue->setText(str_udp);
}
void soft_transmission::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}
void soft_transmission::updateData()
{
	data.updateSoftware();
	initializeData();
}
