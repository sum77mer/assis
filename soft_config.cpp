#include "soft_config.h"

Soft_Config::Soft_Config(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);
    checkbox_administrator = new QCheckBox(this);
    checkbox_administrator->setText(QString("change account to Administrator"));

    checkbox_defender = new QCheckBox(this);
    checkbox_defender->setText(QString("Windows Defender"));

    checkbox_customer_experience_program = new QCheckBox(this);
    checkbox_customer_experience_program->setText(QString("customer experience program"));

    checkbox_bluescreen_autoreboot = new QCheckBox(this);
    checkbox_bluescreen_autoreboot->setText(QString("Blue Screen Auto Reboot"));

    checkbox_firewall = new QCheckBox(this);
    checkbox_firewall->setText(QString("Windows Firewall"));

    checkbox_update = new QCheckBox(this);
    checkbox_update->setText(QString("Windows Update"));

    checkbox_operation_center = new QCheckBox(this);
    checkbox_operation_center->setText(QString("Turn on or off the message"));

    checkbox_power_options = new QCheckBox(this);
    checkbox_power_options->setText(QString("change charge plan"));

    checkbox_system_protect = new QCheckBox(this);
    checkbox_system_protect->setText(QString("close system protect"));

    QPushButton *btn  = new QPushButton(this);
    btn->setText(QString("Configure"));

    connect(btn,SIGNAL(clicked(bool)),this,SLOT(config()));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->setSpacing(5);
    layout->setRowMinimumHeight(2,10);
    layout->setRowStretch(0,0);
    layout->setRowStretch(1,0);
    layout->setRowStretch(2,0);
    layout->setRowStretch(3,0);
    layout->setRowStretch(4,1);
    layout->setColumnStretch(0,1);
    layout->setColumnStretch(1,0);
    layout->setColumnStretch(2,0);
    layout->setColumnStretch(3,0);
    layout->setColumnStretch(4,0);
    layout->setColumnStretch(5,1);
    layout->addWidget(checkbox_administrator,0,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox_defender,0,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox_firewall,0,3,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox_power_options,1,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox_system_protect,1,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox_customer_experience_program,1,3,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox_bluescreen_autoreboot,2,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox_operation_center,2,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox_update,2,3,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(btn,3,1,1,4,Qt::AlignCenter);

    setLayout(layout);
}
void Soft_Config::paintEvent(QPaintEvent *event)
{}
void Soft_Config::config()
{
    if(checkbox_administrator->isChecked())
    {}
    if(checkbox_bluescreen_autoreboot->isChecked())
    {}
    if(checkbox_customer_experience_program->isChecked())
    {}
    if(checkbox_defender->isChecked())
    {}
    if(checkbox_firewall->isChecked())
    {}
    if(checkbox_operation_center->isChecked())
    {}
    if(checkbox_power_options->isChecked())
    {}
    if(checkbox_system_protect->isChecked())
    {}
    if(checkbox_update->isChecked())
    {}
}
