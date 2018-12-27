#include "hard_zhxx.h"
#include "UIdata.h"
#include <QPainter>
#include <QLabel>
#include <QGridLayout>
#include <QFormLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QMouseEvent>
Hard_ZHXX::Hard_ZHXX(QWidget *parent)
{
	setFont(*normalFont);
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Hard_ZHXX::paintEvent(QPaintEvent *event)
{
}
void Hard_ZHXX::initializeUI()
{
	title_generalInformation = new QLabel(this);
	title_generalInformation->setFont(*titleFont);
	title_generalInformation->setText(QStringLiteral("Ó²¼þ¸ÅÀÀ"));
	title_generalInformation->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));

	title_cpu = new QLabel(this);
	title_cpu->setFrameStyle(QFrame::NoFrame);
	title_cpu->setFont(*normalFont);
	title_cpu->setText("CPU");

	title_gpu = new QLabel(this);
	title_gpu->setFrameStyle(QFrame::NoFrame);
	title_gpu->setFont(*normalFont);
	title_gpu->setText("GPU");

	title_memory = new QLabel(this);
	title_memory->setFrameStyle(QFrame::NoFrame);
	title_memory->setFont(*normalFont);
	title_memory->setText("Memory");

	title_board = new QLabel(this);
	title_board->setFrameStyle(QFrame::NoFrame);
	title_board->setFont(*normalFont);
	title_board->setText("Board");

	title_disk = new QLabel(this);
	title_disk->setFrameStyle(QFrame::NoFrame);
	title_disk->setFont(*normalFont);
	title_disk->setText("Disk");

	value_cpu = new QLabel(this);
	value_cpu->setFrameStyle(QFrame::NoFrame);
	value_cpu->setFont(*normalFont);
	value_cpu->setText("defaul");
	
	value_board = new QLabel(this);
	value_board->setFrameStyle(QFrame::NoFrame);
	value_board->setFont(*normalFont);
	value_board->setText("default");
	
	value_memory = new QLabel(this);
	value_memory->setFrameStyle(QFrame::NoFrame);
	value_memory->setFont(*normalFont);
	value_memory->setText("default");

	value_disk = new QLabel(this);
	value_disk->setFrameStyle(QFrame::NoFrame);
	value_disk->setFont(*normalFont);
	value_disk->setText("default");
	
	value_gpu = new QLabel(this);
	value_gpu->setFrameStyle(QFrame::NoFrame);
	value_gpu->setFont(*normalFont);
	value_gpu->setText("default");

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
}
void Hard_ZHXX::updateData()
{
	data.updateHardware();
	initializeData();
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