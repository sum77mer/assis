#include "hard_zhxx.h"
//#include "UIdata.h"
#include <QPainter>
#include <QLabel>
#include <QGridLayout>
#include <QFormLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QMouseEvent>
#include"UIconst.h"
Hard_ZHXX::Hard_ZHXX(QWidget *parent)
{
	valueCPUString = "default";
	valueGPUString = "default";
	valueMemoryString = "default";
	valueBoardString = "default";
	valueDiskString = "default";
	setFont(chNormalFont);
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	//initializeData();
}
void Hard_ZHXX::paintEvent(QPaintEvent *event)
{
}
void Hard_ZHXX::initializeUI()
{
	title_generalInformation = new QLabel(this);
	title_generalInformation->setFont(chTitleFont);
	title_generalInformation->setText(titleString);
	title_generalInformation->setStyleSheet(titleStyle);

	title_cpu = new QLabel(this);
	title_cpu->setFrameStyle(QFrame::NoFrame);
	title_cpu->setFont(enNormalFont);
	title_cpu->setText(titleCPUString);

	title_gpu = new QLabel(this);
	title_gpu->setFrameStyle(QFrame::NoFrame);
	title_gpu->setFont(enNormalFont);
	title_gpu->setText(titleGPUString);

	title_memory = new QLabel(this);
	title_memory->setFrameStyle(QFrame::NoFrame);
	title_memory->setFont(enNormalFont);
	title_memory->setText(titleMemoryString);

	title_board = new QLabel(this);
	title_board->setFrameStyle(QFrame::NoFrame);
	title_board->setFont(enNormalFont);
	title_board->setText(titleBoardString);

	title_disk = new QLabel(this);
	title_disk->setFrameStyle(QFrame::NoFrame);
	title_disk->setFont(enNormalFont);
	title_disk->setText(titleDiskString);

	value_cpu = new QLabel(this);
	value_cpu->setFrameStyle(QFrame::NoFrame);
	value_cpu->setFont(enNormalFont);
	value_cpu->setText(valueCPUString);
	
	value_board = new QLabel(this);
	value_board->setFrameStyle(QFrame::NoFrame);
	value_board->setFont(enNormalFont);
	value_board->setText(valueBoardString);
	
	value_memory = new QLabel(this);
	value_memory->setFrameStyle(QFrame::NoFrame);
	value_memory->setFont(enNormalFont);
	value_memory->setText(valueMemoryString);

	value_disk = new QLabel(this);
	value_disk->setFrameStyle(QFrame::NoFrame);
	value_disk->setFont(enNormalFont);
	value_disk->setText(valueDiskString);
	
	value_gpu = new QLabel(this);
	value_gpu->setFrameStyle(QFrame::NoFrame);
	value_gpu->setFont(enNormalFont);
	value_gpu->setText(valueGPUString);

	QPixmap pixmap;
	pixmap.load(QString(":/intel"));
	pixmap = pixmap.scaledToHeight(100);
	pixmap = pixmap.scaledToWidth(100);
	picLabel = new QLabel(this);
	picLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
	picLabel->setPixmap(pixmap);
}
void Hard_ZHXX::setupLayout()
{
	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(20, 20, 40, 20);
	layout->setRowStretch(0, 0);
	layout->setRowStretch(1, 0);
	layout->setRowStretch(2, 0);
	layout->setRowStretch(3, 0);
	layout->setRowStretch(4, 0);
	layout->setRowStretch(5, 0);
	layout->setRowStretch(6, 1);
	layout->setVerticalSpacing(10);
	layout->addWidget(title_generalInformation, 0, 0,1,2);
	layout->addWidget(title_cpu, 1, 0, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(value_cpu, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(title_gpu, 2, 0, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(value_gpu, 2, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(title_memory, 3, 0, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(value_memory, 3, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(title_board, 4, 0, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(value_board, 4, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(title_disk, 5, 0, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(value_disk, 5, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->setColumnStretch(0, 0);
	layout->setColumnStretch(1, 1);
	layout->setColumnStretch(2, 0);
	layout->addWidget(picLabel, 2, 1,6,1, Qt::AlignRight | Qt::AlignTop);

	setLayout(layout);
}
void Hard_ZHXX::setConnection()
{}
void Hard_ZHXX::initializeData()
{
	/*
	GetData::HardwareGeneral x;
	data.getHardwareGeneral(x);
	value_cpu->setText(QString::fromStdString(x.cpuName));
	value_board->setText(QString::fromStdString(x.board));
	QString string;
	for (auto i : x.memory)
	{
		string += QString::fromStdString(i) + "\r\n";
	}
	value_memory->setText(string);
	string.clear();
	for (auto i : x.disk)
	{
		string += QString::fromStdWString(i) + "\r\n";
	}
	value_disk->setText(string);
	string.clear();
	for (auto &i : x.gpuName)
	{
		string += QString::fromStdString(i) + "\r\n";
	}
	value_gpu->setText(string);
	*/
	
}
void Hard_ZHXX::updateData()
{
	//data.updateHardware();
	//initializeData();
}
void Hard_ZHXX::mousePressEvent(QMouseEvent *event)
{
   if(picLabel->geometry().contains(event->pos()))
    {
       qDebug()<<"url clicked";
       QDesktopServices::openUrl(QUrl("https://www.intel.cn",QUrl::TolerantMode));
    }
   else if(event->button()==Qt::RightButton)
   {
       //
   }

}
void Hard_ZHXX::reset()
{
	//scrollarea->verticalScrollBar()->setValue(0);
}
void Hard_ZHXX::setCPU(QString s)
{
	value_cpu->setText(s);
	valueCPUString = s;
}
void Hard_ZHXX::setGPU(QString s)
{
	value_gpu->setText(s);
	valueGPUString = s;
}
void Hard_ZHXX::setMemory(QString s)
{
	value_memory->setText(s);
	valueMemoryString = s;
}
void Hard_ZHXX::setBoard(QString s)
{
	value_board->setText(s);
	valueBoardString = s;
}
void Hard_ZHXX::setDisk(QString s)
{
	value_disk->setText(s);
	valueDiskString = s;
}