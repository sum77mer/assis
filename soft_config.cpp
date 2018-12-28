#include "soft_config.h"
#include "UIconst.h"
Soft_Config::Soft_Config(QWidget *parent)
{
	setFont(enNormalFont);
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();  
}
void Soft_Config::paintEvent(QPaintEvent *event)
{}
void Soft_Config::initializeUI()
{
	title = new QLabel(this);
	title->setFont(enTitleFont);
	title->setText(QStringLiteral("²âÊÔ»·¾³Ò»¼üÅäÖÃ"));
	title->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));

	checkbox_administrator = new QCheckBox(this);
	checkbox_administrator->setText(QString("change account to Administrator"));
	checkbox_administrator->setEnabled(false);

	checkbox_defender = new QCheckBox(this);
	checkbox_defender->setText(QString("Windows Defender"));
	checkbox_defender->setEnabled(false);

	checkbox_customer_experience_program = new QCheckBox(this);
	checkbox_customer_experience_program->setText(QString("customer experience program"));
	checkbox_customer_experience_program->setEnabled(false);

	checkbox_bluescreen_autoreboot = new QCheckBox(this);
	checkbox_bluescreen_autoreboot->setText(QString("Blue Screen Auto Reboot"));

	checkbox_firewall = new QCheckBox(this);
	checkbox_firewall->setText(QString("Windows Firewall"));

	checkbox_update = new QCheckBox(this);
	checkbox_update->setText(QString("Windows Update"));
	checkbox_update->setEnabled(false);

	checkbox_operation_center = new QCheckBox(this);
	checkbox_operation_center->setText(QString("Turn on or off the message"));
	checkbox_operation_center->setEnabled(false);

	checkbox_power_options = new QCheckBox(this);
	checkbox_power_options->setText(QString("change charge plan"));

	checkbox_system_protect = new QCheckBox(this);
	checkbox_system_protect->setText(QString("close system protect"));
	checkbox_system_protect->setEnabled(false);

	configBtn = new QPushButton(this);
	configBtn->setText(QString("Configure"));
}
void Soft_Config::setupLayout()
{
	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(10, 20, 10, 10);
	layout->setSpacing(5);
	layout->setRowMinimumHeight(2, 10);
	layout->setRowStretch(0, 0);
	layout->setRowStretch(1, 0);
	layout->setRowStretch(2, 0);
	layout->setRowStretch(3, 0);
	layout->setRowStretch(4, 1);
	layout->setColumnStretch(0, 1);
	layout->setColumnStretch(1, 0);
	layout->setColumnStretch(2, 0);
	layout->setColumnStretch(3, 0);
	layout->setColumnStretch(4, 0);
	layout->setColumnStretch(5, 1);
	layout->addWidget(title, 0, 0, 1, 6);
	layout->addWidget(checkbox_administrator, 1, 1, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(checkbox_defender, 1, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(checkbox_firewall, 1, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(checkbox_power_options, 2, 1, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(checkbox_system_protect, 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(checkbox_customer_experience_program, 2, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(checkbox_bluescreen_autoreboot, 3, 1, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(checkbox_operation_center, 3, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(checkbox_update, 3, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(configBtn, 4, 1, 1, 4, Qt::AlignCenter);

	setLayout(layout);
}
void Soft_Config::setConnection()
{
	connect(configBtn, SIGNAL(clicked(bool)), this, SLOT(config()));
}
void Soft_Config::initializeData()
{}
void Soft_Config::config()
{
    if(checkbox_administrator->isChecked())
    {}
    if(checkbox_bluescreen_autoreboot->isChecked())
    {
		//ChangeBlueCrash(false);
	}
    if(checkbox_customer_experience_program->isChecked())
    {}
    if(checkbox_defender->isChecked())
    {}
    if(checkbox_firewall->isChecked())
    {
		//FireWall(true);
	}
    if(checkbox_operation_center->isChecked())
    {}
    if(checkbox_power_options->isChecked())
    {
		//PowerManagement();
	}
    if(checkbox_system_protect->isChecked())
    {}
    if(checkbox_update->isChecked())
    {}
}
void Soft_Config::reset()
{
	//scrollarea->verticalScrollBar()->setValue(0);
}
void Soft_Config::updateData()
{
	data.updateSoftware();
	initializeData();
}
