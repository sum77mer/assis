#include "soft_zhxx.h"
#include "UIdata.h"
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QWidget>
Soft_ZHXX::Soft_ZHXX(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
	setFont(*normalFont);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Soft_ZHXX::paintEvent(QPaintEvent *event)
{}
void Soft_ZHXX::initializeUI()
{
	title_general = new QLabel(this);
	title_general->setFont(*titleFont);
	title_general->setText(QStringLiteral("ÏµÍ³¸ÅÀÀ"));
	title_general->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));

	value = new QLabel(this);
	value->setFrameStyle(QFrame::NoFrame);
	value->setText(QStringLiteral("OS:xxxx"));
}
void Soft_ZHXX::setupLayout()
{
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(10, 20, 10, 10);
	sublayout->setRowStretch(0, 0);
	sublayout->setRowStretch(1, 0);
	sublayout->setRowStretch(2, 1);
	sublayout->addWidget(title_general, 0, 0);
	sublayout->addWidget(value, 1, 0, Qt::AlignLeft);

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
void Soft_ZHXX::setConnection()
{}
void Soft_ZHXX::initializeData()
{}
void Soft_ZHXX::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}
void Soft_ZHXX::updateData()
{
	data.updateSoftware();
	initializeData();
}
