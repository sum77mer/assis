#include "soft_autoboot.h"
#include "UIdata.h"
#include <QLabel>
soft_autoboot::soft_autoboot(QWidget *parent)
{
	setFont(*normalFont);
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void soft_autoboot::paintEvent(QPaintEvent *event)
{}
void soft_autoboot::initializeUI()
{
	title = new QLabel(this);
	title->setFont(*titleFont);
	title->setText(QStringLiteral("×ÔÆô¶¯"));
	title->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));

	value = new QLabel(this);
	value->setFrameStyle(QFrame::NoFrame);
	value->setText("Default");
}
void soft_autoboot::setupLayout()
{
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(10, 20, 10, 10);
	sublayout->setSpacing(5);
	sublayout->setRowStretch(0, 0);
	sublayout->setRowStretch(1, 0);
	sublayout->setRowStretch(2, 1);
	sublayout->addWidget(title, 0, 0);
	sublayout->addWidget(value, 1, 0);

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
void soft_autoboot::setConnection()
{}
void soft_autoboot::initializeData()
{
	QString string;
	vector<GetData::Auto_Information> x;
	data.getAutoList(x);
	for (auto i : x)
	{
		string += "Name: " + i.name + "\r\n";
		string += "Type: " + i.type + "\r\n";
		string += "Data: " + i.data + "\r\n\r\n";
	}
	value->setText(string);
}
void soft_autoboot::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}
void soft_autoboot::updateData()
{
	data.updateSoftware();
	initializeData();
}
