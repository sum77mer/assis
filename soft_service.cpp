#include "soft_service.h"
#include "UIdata.h"
#include <QLabel>
soft_service::soft_service(QWidget *parent)
{
	setFont(*normalFont);
    setWindowFlags(Qt::FramelessWindowHint);

	initializeUI();
	setupLayout();
	setConnection();
	initializeData();  
}
void soft_service::paintEvent(QPaintEvent *event)
{}
void soft_service::initializeUI()
{
	title = new QLabel(this);
	title->setFont(*titleFont);
	title->setText(QStringLiteral("·þÎñ"));
	title->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));

	value = new QLabel(this);
	value->setFrameStyle(QFrame::NoFrame);
	value->setText("default");
}
void soft_service::setupLayout()
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
void soft_service::setConnection()
{

}
void soft_service::initializeData()
{
	QString string;
	vector<GetData::Service_Information> x;
	data.getService(x);
	for (auto i : x)
	{
		string += "Name: " + i.name + "\r\n";
		string += "Display Name: " + i.disName + "\r\n";
		string += "Status: " + i.status + "\r\n";
		string += "Type: " + i.starttype + "\r\n";
		string += "Path: " + i.path + "\r\n";
		string += "Description: " + i.description + "\r\n";
		string += "\r\n";
	}
	value->setText(string);
}
void soft_service::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}
void soft_service::updateData()
{
	data.updateSoftware();
	initializeData();
}
