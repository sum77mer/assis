#include "hard_gfx.h"
#include "UIdata.h"
#include <QPainter>
#include <QScrollArea>
#include <QGridLayout>
#include <QGroupBox>
#include <QWidget>
#include <QLabel>
#include <qfile.h>
#include <QTExtStream>
#include <qdebug.h>
#include"UIconst.h"
Hard_GFX::Hard_GFX(QWidget *parent)
{
	setFont(enNormalFont);

	initializeUI();
	setupLayout();
	setConnection();
	initializeData();	
}
void Hard_GFX::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("gfx"));
}
void Hard_GFX::initializeUI()
{
	QString gpuName, gpu_biosversion, gpu_driverversion, gpu_branchversion, temperature, gpuclock, gpu_memoryclock, gpu_usage, gpu_fans;
	QString monitor_name, monitor_serial_number, monitor_manufacturer, monitor_date;
	QString str_EDID;

	title_gpuName = new QLabel(this);
	title_gpuName->setFrameStyle(QFrame::NoFrame);
	title_gpuName->setText(QStringLiteral("GPU Name:"));
	value_gpuName = new QLabel(this);
	value_gpuName->setFrameStyle(QFrame::NoFrame);
	value_gpuName->setText(gpuName);

	title_BIOSVersion = new QLabel(this);
	title_BIOSVersion->setFrameStyle(QFrame::NoFrame);
	title_BIOSVersion->setText(QStringLiteral("GPU BIOS Version:"));
	value_BIOSVersion = new QLabel(this);
	value_BIOSVersion->setFrameStyle(QFrame::NoFrame);
	value_BIOSVersion->setText(gpu_biosversion);

	title_gpuDriverVersion = new QLabel(this);
	title_gpuDriverVersion->setFrameStyle(QFrame::NoFrame);
	title_gpuDriverVersion->setText(QStringLiteral("GPU Driver Version:"));
	value_gpuDriverVersion = new QLabel(this);
	value_gpuDriverVersion->setFrameStyle(QFrame::NoFrame);
	value_gpuDriverVersion->setText(gpu_driverversion);

	title_gpuBranchVersion = new QLabel(this);
	title_gpuBranchVersion->setFrameStyle(QFrame::NoFrame);
	title_gpuBranchVersion->setText(QStringLiteral("GPU Branch Version:"));
	value_gpuBranchVersion = new QLabel(this);
	value_gpuBranchVersion->setFrameStyle(QFrame::NoFrame);
	value_gpuBranchVersion->setText(gpu_branchversion);

	title_temprature = new QLabel(this);
	title_temprature->setFrameStyle(QFrame::NoFrame);
	title_temprature->setText(QStringLiteral("Temperature:"));
	value_temperature = new QLabel(this);
	value_temperature->setFrameStyle(QFrame::NoFrame);
	value_temperature->setText(temperature);

	title_gpuClock = new QLabel(this);
	title_gpuClock->setFrameStyle(QFrame::NoFrame);
	title_gpuClock->setText(QStringLiteral("GPU Clock:"));
	value_gpuClock = new QLabel(this);
	value_gpuClock->setFrameStyle(QFrame::NoFrame);
	value_gpuClock->setText(gpuclock);

	title_gpuMemoryClock = new QLabel(this);
	title_gpuMemoryClock->setFrameStyle(QFrame::NoFrame);
	title_gpuMemoryClock->setText(QStringLiteral("GPU Memory Clock:"));
	value_gpuMemoryClock = new QLabel(this);
	value_gpuMemoryClock->setFrameStyle(QFrame::NoFrame);
	value_gpuMemoryClock->setText(gpu_memoryclock);

	title_gpuUsage = new QLabel(this);
	title_gpuUsage->setFrameStyle(QFrame::NoFrame);
	title_gpuUsage->setText(QStringLiteral("GPU Usage:"));
	value_gpuUsage = new QLabel(this);
	value_gpuUsage->setFrameStyle(QFrame::NoFrame);
	value_gpuUsage->setText(gpu_usage);

	title_gpuFans = new QLabel(this);
	title_gpuFans->setFrameStyle(QFrame::NoFrame);
	title_gpuFans->setText(QStringLiteral("GPU Fans:"));
	value_gpuFans = new QLabel(this);
	value_gpuFans->setFrameStyle(QFrame::NoFrame);
	value_gpuFans->setText(gpu_fans);

	title_monitorName = new QLabel(this);
	title_monitorName->setFrameStyle(QFrame::NoFrame);
	title_monitorName->setText(QStringLiteral("Monitor Name:"));
	value_monitorName = new QLabel(this);
	value_monitorName->setFrameStyle(QFrame::NoFrame);
	value_monitorName->setText(monitor_name);

	//title_monitorSerialNum = new QLabel(this);
	//title_monitorSerialNum->setFrameStyle(QFrame::NoFrame);
	//title_monitorSerialNum->setText(QStringLiteral("Display Serial Number"));
	value_monitorSerialNum = new QLabel(this);
	value_monitorSerialNum->setFrameStyle(QFrame::NoFrame);
	value_monitorSerialNum->setText(monitor_serial_number);

	//title_monitorManufacture = new QLabel(this);
	//title_monitorManufacture->setFrameStyle(QFrame::NoFrame);
	//title_monitorManufacture->setText(QStringLiteral("Manufacture"));
	value_monitorManufacture = new QLabel(this);
	value_monitorManufacture->setFrameStyle(QFrame::NoFrame);
	value_monitorManufacture->setText(monitor_manufacturer);

	//title_monitorDate = new QLabel(this);
	//title_monitorDate->setFrameStyle(QFrame::NoFrame);
	//title_monitorDate->setText(QStringLiteral("Date"));
	value_monitorDate = new QLabel(this);
	value_monitorDate->setFrameStyle(QFrame::NoFrame);
	value_monitorDate->setText(monitor_date);

	value_EDID = new QLabel(this);
	value_EDID->setFrameStyle(QFrame::NoFrame);
	value_EDID->setText(str_EDID);
}
void Hard_GFX::setupLayout()
{
	QGridLayout *group1layout = new QGridLayout;
	QGridLayout *group2layout = new QGridLayout;
	group1layout->setContentsMargins(20, 10, 0, 10);
	group2layout->setContentsMargins(20, 10, 0, 10);

	group1layout->setColumnStretch(0, 0);
	group1layout->setColumnStretch(1, 10);

	group2layout->setColumnStretch(0, 0);
	group2layout->setColumnStretch(1, 10);

	group1layout->addWidget(title_gpuName, 0, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_gpuName, 0, 1, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(title_BIOSVersion, 1, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_BIOSVersion, 1, 1, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(title_gpuDriverVersion, 2, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_gpuDriverVersion, 2, 1, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(title_gpuBranchVersion, 3, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_gpuBranchVersion, 3, 1, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(title_temprature, 4, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_temperature, 4, 1, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(title_gpuClock, 5, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_gpuClock, 5, 1, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(title_gpuMemoryClock, 6, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_gpuMemoryClock, 6, 1, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(title_gpuUsage, 7, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_gpuUsage, 7, 1, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(title_gpuFans, 8, 0, 1, 1, Qt::AlignLeft);
	group1layout->addWidget(value_gpuFans, 8, 1, 1, 1, Qt::AlignLeft);

	// group2layout->addWidget(label10,0,0,1,1,Qt::AlignLeft);
	group2layout->addWidget(title_monitorName, 0, 0, 1, 1, Qt::AlignLeft);
	group2layout->addWidget(value_monitorName, 0, 1, 1, 1, Qt::AlignLeft);
	//group2layout->addWidget(label11,1,0,1,1,Qt::AlignLeft);
	group2layout->addWidget(value_monitorSerialNum, 1, 0, 1, 1, Qt::AlignLeft);
	//group2layout->addWidget(label12,2,0,1,1,Qt::AlignLeft);
	group2layout->addWidget(value_monitorManufacture, 2, 0, 1, 1, Qt::AlignLeft);
	//group2layout->addWidget(label13, 3, 0, 1, 1, Qt::AlignLeft);
	group2layout->addWidget(value_monitorDate, 3, 0, 1, 1, Qt::AlignLeft);


	QGroupBox *groupbox1 = new QGroupBox(tr("Graphic Card"));
	QGroupBox *groupbox2 = new QGroupBox(tr("Monitor"));
	groupbox1->setLayout(group1layout);
	//groupbox1->setMinimumWidth(750);
	groupbox2->setLayout(group2layout);

	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(10, 10, 10, 10);
	sublayout->setRowMinimumHeight(2, 20);
	sublayout->setRowStretch(0, 0);
	sublayout->setRowStretch(1, 0);
	sublayout->setRowStretch(2, 0);
	sublayout->setRowStretch(3, 0);
	sublayout->addWidget(groupbox1, 0, 0);
	sublayout->addWidget(groupbox2, 1, 0);
	sublayout->addWidget(value_EDID, 3, 0, 1, 1);

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
	layout->addWidget(scrollarea);
	layout->setContentsMargins(0, 0, 0, 0);

	setLayout(layout);
}
void Hard_GFX::setConnection()
{}
void Hard_GFX::initializeData()
{
	vector<GetData::GPU_Information> x;
	data.getGPU(x);
	for (auto &i : x)
	{
		value_gpuName->setText(QString::fromStdString(i.gpuName));
		value_BIOSVersion->setText(QString::fromStdString(i.gpuBIOSVersion));
		value_gpuDriverVersion->setText(QString::fromStdString(i.gpuDriverVersion));
		value_gpuBranchVersion->setText(QString::fromStdString(i.gpuBranchVersion));
		value_temperature->setText(QString("%0").arg(i.temperature));
		value_gpuClock->setText(QString("%0").arg(i.gpuClock));
		value_gpuMemoryClock->setText(QString("%0").arg(i.gpuMemoryClock));
		value_gpuUsage->setText(QString("%0").arg(i.usage));
		value_gpuFans->setText(QString("%0").arg(i.fans));
	}
	string str;
	data.getMonitor(str);
	value_monitorName->setText(QString::fromStdString(str));

	QString EDIDstr;
	if (data.getEDID(EDIDstr))
		value_EDID->setText(EDIDstr);
}
void Hard_GFX::updateData()
{
	data.updateHardware();
	initializeData();
}
void Hard_GFX::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}