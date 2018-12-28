#include "soft_taskscheduler.h"
#include"UIconst.h"
#include <QLabel>

soft_taskscheduler::soft_taskscheduler(QWidget *parent)
{
	setFont(enNormalFont);
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void soft_taskscheduler::paintEvent(QPaintEvent *event)
{}
void soft_taskscheduler::initializeUI()
{
	title = new QLabel(this);
	title->setFont(enTitleFont);
	title->setText(QStringLiteral("任务计划"));
	title->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));

	folderValue = new QLabel(this);
	folderValue->setFrameStyle(QFrame::NoFrame);
	folderValue->setText("Default");

	runningValue = new QLabel(this);
	runningValue->setFrameStyle(QFrame::NoFrame);
	runningValue->setText("Default");
}
void soft_taskscheduler::setupLayout()
{
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(10, 20, 10, 10);
	sublayout->setSpacing(5);
	sublayout->setRowStretch(0, 0);
	sublayout->setRowStretch(1, 0);
	sublayout->setRowStretch(2, 0);
	sublayout->setRowStretch(3, 1);
	sublayout->addWidget(title, 0, 0);
	sublayout->addWidget(folderValue, 1, 0);
	sublayout->addWidget(runningValue, 2, 0);

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
void soft_taskscheduler::setConnection()
{
	
}
void soft_taskscheduler::initializeData()
{
	QString str_folder;
	QString str_running;
	vector<GetData::Task_Information> x;
	data.getFolderTask(x);
	for (auto i : x)
	{
		str_folder += "Name: " + i.name + "\r\n";
		str_folder += "State: " + i.state + "\r\n\r\n";
	}
	data.getRunningTask(x);
	for (auto i : x)
	{
		str_running += "Name: " + i.name + "\r\n";
		str_running += "State: " + i.state + "\r\n\r\n";
	}
	folderValue->setText(str_folder);
	runningValue->setText(str_running);
}
void soft_taskscheduler::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}
void soft_taskscheduler::updateData()
{
	data.updateSoftware();
	initializeData();
}
