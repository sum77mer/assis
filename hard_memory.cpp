#include "hard_memory.h"
#include "UIdata.h"
#include"UIconst.h"
Hard_Memory::Hard_Memory(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
	setFont(enNormalFont);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Hard_Memory::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("Memory"));
}
void Hard_Memory::initializeUI()
{
	/*
	title_modelType = new QLabel(this);
	title_modelType->setFrameStyle(QFrame::NoFrame);
	title_modelType->setText(QStringLiteral("Module Type"));
	value_modelType = new QLabel(this);
	value_modelType->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_modelType->setText(QStringLiteral(""));
	value_modelType->setMinimumHeight(value_modelType->sizeHint().height() + 6);
	value_modelType->setMinimumWidth(value_modelType->sizeHint().width() + 10);

	title_modelSize = new QLabel(this);
	title_modelSize->setFrameStyle(QFrame::NoFrame);
	title_modelSize->setText(QStringLiteral("Module Size"));
	value_modelSize = new QLabel(this);
	value_modelSize->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_modelSize->setText(QStringLiteral(""));
	value_modelSize->setMinimumHeight(value_modelSize->sizeHint().height() + 6);
	value_modelSize->setMinimumWidth(value_modelSize->sizeHint().width() + 10);

	title_channel = new QLabel(this);
	title_channel->setFrameStyle(QFrame::NoFrame);
	title_channel->setText(QStringLiteral("Channel"));
	value_channel = new QLabel(this);
	value_channel->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_channel->setText(QStringLiteral(""));
	value_channel->setMinimumHeight(value_channel->sizeHint().height() + 6);
	value_channel->setMinimumWidth(value_channel->sizeHint().width() + 10);

	title_frequency = new QLabel(this);
	title_frequency->setFrameStyle(QFrame::NoFrame);
	title_frequency->setText(QStringLiteral("Frequency"));
	value_frequency = new QLabel(this);
	value_frequency->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_frequency->setText(QStringLiteral(""));
	value_frequency->setMinimumHeight(value_frequency->sizeHint().height() + 6);
	value_frequency->setMinimumWidth(value_frequency->sizeHint().width() + 10);

	title_memoryFre = new QLabel(this);
	title_memoryFre->setFrameStyle(QFrame::NoFrame);
	title_memoryFre->setText(QStringLiteral("Memory Frequency"));
	value_memoryFre = new QLabel(this);
	value_memoryFre->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_memoryFre->setText(QStringLiteral(""));
	value_memoryFre->setMinimumHeight(value_memoryFre->sizeHint().height() + 6);
	value_memoryFre->setMinimumWidth(value_memoryFre->sizeHint().width() + 10);

	title_CASDelay = new QLabel(this);
	title_CASDelay->setFrameStyle(QFrame::NoFrame);
	title_CASDelay->setText(QStringLiteral("CAS Delay"));
	value_CASDelay = new QLabel(this);
	value_CASDelay->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_CASDelay->setText(QStringLiteral(""));
	value_CASDelay->setMinimumHeight(value_CASDelay->sizeHint().height() + 6);
	value_CASDelay->setMinimumWidth(value_CASDelay->sizeHint().width() + 10);

	title_RASprecharge = new QLabel(this);
	title_RASprecharge->setFrameStyle(QFrame::NoFrame);
	title_RASprecharge->setText(QStringLiteral("RAS Precharge"));
	value_RASprecharge = new QLabel(this);
	value_RASprecharge->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_RASprecharge->setText(QStringLiteral(""));
	value_RASprecharge->setMinimumHeight(value_RASprecharge->sizeHint().height() + 6);
	value_RASprecharge->setMinimumWidth(value_RASprecharge->sizeHint().width() + 10);

	title_rowRefreshCycleTime = new QLabel(this);
	title_rowRefreshCycleTime->setFrameStyle(QFrame::NoFrame);
	title_rowRefreshCycleTime->setText(QStringLiteral("Row Refresh Cycle Time"));
	value_rowRefreshCycleTime = new QLabel(this);
	value_rowRefreshCycleTime->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_rowRefreshCycleTime->setText(QStringLiteral(""));
	value_rowRefreshCycleTime->setMinimumHeight(value_rowRefreshCycleTime->sizeHint().height() + 6);
	value_rowRefreshCycleTime->setMinimumWidth(value_rowRefreshCycleTime->sizeHint().width() + 10);

	title_frontBusMemory = new QLabel(this);
	title_frontBusMemory->setFrameStyle(QFrame::NoFrame);
	title_frontBusMemory->setText(QStringLiteral("Front Bus Memory"));
	value_frontBusMemory = new QLabel(this);
	value_frontBusMemory->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_frontBusMemory->setText(QStringLiteral(""));
	value_frontBusMemory->setMinimumHeight(value_frontBusMemory->sizeHint().height() + 6);
	value_frontBusMemory->setMinimumWidth(value_frontBusMemory->sizeHint().width() + 10);

	title_rasTOcas = new QLabel(this);
	title_rasTOcas->setFrameStyle(QFrame::NoFrame);
	title_rasTOcas->setText(QStringLiteral("RAS to CAS"));
	value_rasTOcas = new QLabel(this);
	value_rasTOcas->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_rasTOcas->setText(QStringLiteral(""));
	value_rasTOcas->setMinimumHeight(value_rasTOcas->sizeHint().height() + 6);
	value_rasTOcas->setMinimumWidth(value_rasTOcas->sizeHint().width() + 10);

	title_cycle = new QLabel(this);
	title_cycle->setFrameStyle(QFrame::NoFrame);
	title_cycle->setText(QStringLiteral("Cycle"));
	value_cycle = new QLabel(this);
	value_cycle->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_cycle->setText(QStringLiteral(""));
	value_cycle->setMinimumHeight(value_cycle->sizeHint().height() + 6);
	value_cycle->setMinimumWidth(value_cycle->sizeHint().width() + 10);

	title_voltage = new QLabel(this);
	title_voltage->setFrameStyle(QFrame::NoFrame);
	title_voltage->setText(QStringLiteral("Voltage"));
	value_voltage = new QLabel(this);
	value_voltage->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_voltage->setText(QStringLiteral(""));
	value_voltage->setMinimumHeight(value_voltage->sizeHint().height() + 6);
	value_voltage->setMinimumWidth(value_voltage->sizeHint().width() + 10);
	*/
	
	label = new QLabel(this);
	label->setFrameStyle(QFrame::NoFrame);
	label->setText("default");

	setAddr = new QPushButton(this);
	setAddr->setText(QString("Addr=0x00000000"));

	tableviewRW = new QTableView(this);
	tableviewRW->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	tableviewRW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tableviewRW->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	for (unsigned int i = 0; i<16; ++i)
	{
		model->setHorizontalHeaderItem(i, new QStandardItem(QString("%0").arg(i)));
	}
	for (unsigned int i = 0; i<16; i++)
	{
		for (unsigned int j = 0; j<16; j++)
		{
			model->setItem(i, j, new QStandardItem("0x1"));
		}
	}
	tableviewRW->setModel(model);
	tableviewRW->setEditTriggers(QAbstractItemView::DoubleClicked);
	
	tableviewRW->setMinimumHeight(tableviewRW->rowHeight(1) * 17);
}
void Hard_Memory::setupLayout()
{
	QGridLayout *group1layout = new QGridLayout;
	group1layout->setContentsMargins(20, 10, 20, 10);
	group1layout->setHorizontalSpacing(5);
	group1layout->setVerticalSpacing(10);
	group1layout->setColumnStretch(0, 0);
	group1layout->setColumnStretch(1, 3);
	group1layout->setColumnStretch(2, 1);
	group1layout->setColumnStretch(3, 0);
	group1layout->setColumnStretch(4, 3);
	group1layout->setColumnStretch(5, 1);
	group1layout->setColumnStretch(6, 0);
	group1layout->setColumnStretch(7, 3);
	group1layout->setColumnStretch(8, 1);
	group1layout->setColumnStretch(9, 0);
	group1layout->setColumnStretch(10, 3);
	group1layout->addWidget(label, 0, 0,1,8);
	/*
	group1layout->addWidget(title_modelType, 0, 0);
	group1layout->addWidget(value_modelType, 0, 1);
	group1layout->addWidget(title_modelSize, 0, 3);
	group1layout->addWidget(value_modelSize, 0, 4);
	group1layout->addWidget(title_channel, 0, 6);
	group1layout->addWidget(value_channel, 0, 7);
	group1layout->addWidget(title_frequency, 0, 9);
	group1layout->addWidget(value_frequency, 0, 10);
	*/
	
	QGridLayout *group2layout = new QGridLayout;
	group2layout->setContentsMargins(20, 10, 20, 10);
	group2layout->setColumnStretch(0, 0);
	group2layout->setColumnStretch(1, 3);
	group2layout->setColumnStretch(2, 1);
	group2layout->setColumnStretch(3, 0);
	group2layout->setColumnStretch(4, 3);
	group2layout->setColumnStretch(5, 1);
	group2layout->setColumnStretch(6, 0);
	group2layout->setColumnStretch(7, 3);
	group2layout->setColumnStretch(8, 1);
	group2layout->setColumnStretch(9, 0);
	group2layout->setColumnStretch(10, 3);

	/*
	group2layout->addWidget(title_memoryFre, 0, 0);
	group2layout->addWidget(value_memoryFre, 0, 1);
	group2layout->addWidget(title_CASDelay, 0, 3);
	group2layout->addWidget(value_CASDelay, 0, 4);
	group2layout->addWidget(title_RASprecharge, 0, 6);
	group2layout->addWidget(value_RASprecharge, 0, 7);
	group2layout->addWidget(title_rowRefreshCycleTime, 0, 9);
	group2layout->addWidget(value_rowRefreshCycleTime, 0, 10);
	group2layout->addWidget(title_frontBusMemory, 1, 0);
	group2layout->addWidget(value_frontBusMemory, 1, 1);
	group2layout->addWidget(title_rasTOcas, 1, 3);
	group2layout->addWidget(value_rasTOcas, 1, 4);
	group2layout->addWidget(title_cycle, 1, 6);
	group2layout->addWidget(value_cycle, 1, 7);
	group2layout->addWidget(title_voltage, 1, 9);
	group2layout->addWidget(value_voltage, 1, 10);
	*/
	

	QGroupBox *groupbox1 = new QGroupBox(tr("常规"));
	groupbox1->setLayout(group1layout);
	//groupbox1->setMinimumWidth(750);
	QGroupBox *groupbox2 = new QGroupBox(tr("时序"));
	groupbox2->setLayout(group2layout);
	//groupbox2->setMinimumWidth(750);
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(10, 10, 10, 10);
	sublayout->setSpacing(5);
	sublayout->setRowStretch(0, 0);
	sublayout->setRowStretch(1, 0);
	sublayout->setRowStretch(2, 0);
	sublayout->setRowMinimumHeight(2, 20);
	sublayout->setRowStretch(3, 0);
	sublayout->setRowStretch(4, 1);
	sublayout->addWidget(groupbox1, 0, 0);
	sublayout->addWidget(groupbox2, 1, 0);
	sublayout->addWidget(setAddr, 3, 0, Qt::AlignLeft | Qt::AlignBottom);
	sublayout->addWidget(tableviewRW, 4, 0, Qt::AlignCenter);

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
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(scrollarea,0,0);

	setLayout(layout);
}
void Hard_Memory::setConnection()
{
	connect(setAddr, SIGNAL(clicked(bool)), this, SLOT(setAddress()));
	connect(tableviewRW, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(tableInputing(QModelIndex)));
	connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(tableItemChanged(QStandardItem*)));
	
}
void Hard_Memory::initializeData()
{
	vector<GetData::Memory_Information> x;
	data.getMemory(x);
	QString str;
	for (auto &i : x)
	{
		str += "Modul Type:" + QString::fromStdString(i.modulType) + "\r\n";
		str += "Module Size:" + QString("%0").arg(i.moduleSize) + "GB\r\n";
		str += "Module Manufacture:" + QString::fromStdString(i.moduleManufacture) + "\r\n";
		str += "DRAM Manufacture:" + QString::fromStdString(i.dramManufacture) + "\r\n";
		str += "Part Number:" + QString::fromStdString(i.partNum) + "\r\n";
		str += "Serial Number:" + QString::fromStdString(i.serialNum) + "\r\n";
		str += "Product Date:" + QString::fromStdString(i.productDate) + "\r\n";
		str += "\r\n";
	}
	label->setText(str);
	setAddr->setText(QString("Addr=0x%0").arg(begin_addr));
	getMemoryAddress(begin_addr);
}
void Hard_Memory::updateData()
{
	data.updateHardware();
	initializeData();
}
void Hard_Memory::setAddress()
{
	if (window_memoryAddress == NULL)
	{
		window_memoryAddress = new Window_memoryAddress(this);
		connect(window_memoryAddress, SIGNAL(send_input(uint)), this, SLOT(getMemoryAddress(uint)));
	}
	window_memoryAddress->show();
}
void Hard_Memory::getMemoryAddress(unsigned int addr)
{
	table_changing = true;
	bool rflag = false;
	begin_addr = addr;
	for (unsigned int i = 0; i < 256; i++)
	{
		unsigned int output;
		if (data.readMemory(addr, output))
		{
			model->setItem(i / 16, i % 16, new QStandardItem(QString("%0").arg(output, 0, 16)));
			model_list.append(QString("%0").arg(output, 0, 16));
			addr++;
		}
		else
		{
			QMessageBox *messagebox = new QMessageBox(this);
			messagebox->setText("read fail:getmemoryaddress");
			messagebox->exec();
		}
	}
	setAddr->setText(QString("Addr=0x%0").arg(begin_addr, 0, 16));
	table_changing = false;
}
void Hard_Memory::tableInputing(QModelIndex index)
{
    lastvalue = model->data(index).toString();
}
void Hard_Memory::tableItemChanged(QStandardItem *item)
{
	if (!table_changing)
	{
		QString str_data = item->data(Qt::EditRole).toString();
		QRegExp regexp("[0-9a-fA-F]+");
		if (!regexp.exactMatch(str_data))
		{
			item->setData(QVariant(lastvalue), Qt::EditRole);
		}
		else if (str_data != model_list.at(item->row() * 16 + item->column()))
		{
			bool ok;
			unsigned int addr = begin_addr + item->row() * 16 + item->column();
			unsigned int input = str_data.toInt(&ok, 16);
			if (data.writeMemory(addr, input) == 1)
			{
				model_list.replace(item->row() * 16 + item->column(), str_data);
			}
			else
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("write fail:tableItemchanged");
				messagebox->exec();
				model->setItem(item->row(), item->column(), new QStandardItem(QString("0x%0").arg(lastvalue)));
			}
		}
	}
}
void Hard_Memory::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);//
}
