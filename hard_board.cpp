#include "hard_board.h"
#include "widget_treebrowser.h"
#include"UIconst.h"
Hard_Board::Hard_Board(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);

	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
	setFont(enNormalFont);
}
void Hard_Board::paintEvent(QPaintEvent *event)
{
}
void Hard_Board::initializeUI()
{
	QString str_BIOS = "";
	QString str_Board = "";
	QString str_Chipset = "";

	boardLabel = new QLabel(this);
	boardLabel->setFrameStyle(QFrame::NoFrame);
	boardLabel->setText(str_Board);
	boardLabel->setAlignment(Qt::AlignLeft);

	chipsetLabel = new QLabel(this);
	chipsetLabel->setFrameStyle(QFrame::NoFrame);
	chipsetLabel->setText(QStringLiteral("Chipset Model:******"));
	chipsetLabel->setAlignment(Qt::AlignLeft);

	biosLabel = new QLabel(this);
	biosLabel->setFrameStyle(QFrame::NoFrame);
	biosLabel->setText(str_BIOS);
	biosLabel->setAlignment(Qt::AlignLeft);

	//io base
	title_IOBase = new QLabel(this);
	title_IOBase->setText(QString("IO RW by Base Address"));
	title_IOBase->setFont(enNormalFont);
	title_IOBase->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-color:rgb(200,200,200);border-style:solid;padding-bottom:3px}"));

	btnIOBase = new QPushButton(this);
	btnIOBase->setText(QString("IO Base:FFFFF"));

	tableIOBase = new QTableView(this);
	tableIOBase->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	tableIOBase->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tableIOBase->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	for (unsigned int i = 0; i<16; ++i)
	{
		modelIOBase->setHorizontalHeaderItem(i, new QStandardItem(QString("%0").arg(i)));
	}
	for (unsigned int i = 0; i<16; i++)
	{
		for (unsigned int j = 0; j<16; j++)
		{
			modelIOBase->setItem(i, j, new QStandardItem("0x1"));
		}
	}
	tableIOBase->setModel(modelIOBase);
	tableIOBase->setEditTriggers(QAbstractItemView::DoubleClicked);
	
	tableIOBase->setMinimumHeight(tableIOBase->rowHeight(1) * 17);//

	//io index
	title_IOIndex = new QLabel(this);
	//title_IOIndex->setFrameStyle(QFrame::NoFrame);
	title_IOIndex->setText(QString("IO RW by Index"));
	title_IOIndex->setFont(enNormalFont);
	title_IOIndex->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));
	btnIndex = new QPushButton(this);
	btnIndex->setText(QString("0x77/0x80"));
	
	tableIOIndex = new QTableView(this);
	tableIOIndex->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	tableIOIndex->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tableIOIndex->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	for (unsigned int i = 0; i<16; ++i)
	{
		modelIndex->setHorizontalHeaderItem(i, new QStandardItem(QString("%0").arg(i)));
	}
	for (unsigned int i = 0; i<16; i++)
	{
		for (unsigned int j = 0; j<16; j++)
		{
			modelIndex->setItem(i, j, new QStandardItem("0x1"));
		}
	}
	
	tableIOIndex->setModel(modelIndex);
	tableIOIndex->setMinimumHeight(tableIOIndex->rowHeight(0) * 17);
	
	//super io
	title_SIO = new QLabel(this);
	//title_SIO->setFrameStyle(QFrame::NoFrame);
	title_SIO->setText(QString("IO RW by SuperIO"));
	title_SIO->setFont(enNormalFont);
	title_SIO->setStyleSheet(QString("QLabel{border-width:0px 0px 1px 0px;border-style:solid;border-color:rgb(200,200,200);padding-bottom:3px}"));
	btnSIO = new QPushButton(this);
	btnSIO->setText(QString("IO Ports"));
	
	//btnSIOKey = new QPushButton(this);
	//btnSIOKey->setText(QString("key"));
	//connect(btnSIOKey,SIGNAL(clicked(bool)),this,SLOT(setSuperIOKey()));
	combobox_SIO_device = new QComboBox(this);
	combobox_SIO_device->insertItem(0, QString("logical device xxxxxxxx"));
	combobox_SIO_device->insertItem(1, QString("logical device xxxxxxxx"));
	combobox_SIO_device->insertItem(2, QString("logical device xxxxxxxx"));

	tableSIO = new QTableView(this);
	tableSIO->setEditTriggers(QAbstractItemView::DoubleClicked);

	for (unsigned int i = 0; i<16; ++i)
	{
		modelSIO->setHorizontalHeaderItem(i, new QStandardItem(QString("%0").arg(i)));
	}
	for (unsigned int i = 0; i<16; i++)
	{
		for (unsigned int j = 0; j<16; j++)
		{
			modelSIO->setItem(i, j, new QStandardItem("0x1"));
		}
	}
	
	tableSIO->setModel(modelSIO);
	tableSIO->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	tableSIO->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tableSIO->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tableSIO->setMinimumHeight(tableSIO->rowHeight(0) * 17);
}
void Hard_Board::setupLayout()
{
	QGridLayout *layout1 = new QGridLayout;
	layout1->setContentsMargins(20, 10, 0, 10);
	layout1->addWidget(boardLabel);
	QGroupBox *boardgroup = new QGroupBox(tr("Board"));
	boardgroup->setLayout(layout1);

	QGridLayout *layout2 = new QGridLayout;
	layout2->setContentsMargins(20, 10, 0, 10);
	layout2->addWidget(chipsetLabel);
	QGroupBox *chipsetgroup = new QGroupBox(tr("Chipset"));
	chipsetgroup->setLayout(layout2);

	QGridLayout *layout3 = new QGridLayout;
	layout3->setContentsMargins(20, 10, 0, 10);
	layout3->addWidget(biosLabel);
	QGroupBox *biosgroup = new QGroupBox(tr("BIOS"));
	biosgroup->setLayout(layout3);

	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(10, 10, 10, 30);
	sublayout->setSpacing(5);

	sublayout->addWidget(boardgroup, 0, 0, 1, 3);
	sublayout->addWidget(chipsetgroup, 1, 0, 1, 3);

	sublayout->addWidget(biosgroup, 2, 0, 1, 3);

	sublayout->setRowMinimumHeight(3, 20);
	sublayout->setRowStretch(3, 1);
	sublayout->addWidget(title_IOBase, 4, 0, 1, 3);
	sublayout->addWidget(btnIOBase, 5, 0, 1, 1, Qt::AlignLeft | Qt::AlignBottom);
	sublayout->addWidget(tableIOBase, 6, 0, 1, 3, Qt::AlignCenter);// 

	sublayout->setRowMinimumHeight(7, 20);
	sublayout->setRowStretch(7, 1);
	sublayout->addWidget(title_IOIndex, 8, 0, 1, 3);
	sublayout->addWidget(btnIndex, 9, 0, 1, 1, Qt::AlignLeft | Qt::AlignBottom);
	sublayout->addWidget(tableIOIndex, 10, 0, 1, 3, Qt::AlignCenter);

	sublayout->setRowMinimumHeight(11, 20);
	sublayout->setRowStretch(11, 1);
	sublayout->addWidget(title_SIO, 12, 0, 1, 3);
	sublayout->addWidget(btnSIO, 13, 0, 1, 1, Qt::AlignLeft | Qt::AlignCenter);
	//sublayout->addWidget(btn4, 10, 1, 1, 1, Qt::AlignLeft | Qt::AlignCenter);
	sublayout->addWidget(combobox_SIO_device, 13, 2, 1, 1, Qt::AlignLeft | Qt::AlignCenter);

	sublayout->addWidget(tableSIO, 14, 0, 1, 3, Qt::AlignCenter);
	
	treeBrowser = new Widget_TreeBrowser(this);
	sublayout->setRowMinimumHeight(15, 30);
	sublayout->setRowMinimumHeight(16, 300);
	sublayout->addWidget(treeBrowser, 16, 0, 1, 3);


	QWidget *widget = new QWidget(this);
	widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	widget->setWindowFlags(Qt::FramelessWindowHint);
	widget->setLayout(sublayout);

	scrollarea = new QScrollArea;
	scrollarea->setBackgroundRole(QPalette::Window);
	scrollarea->setFrameStyle(QFrame::NoFrame);
	scrollarea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	scrollarea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	scrollarea->setAlignment(Qt::AlignCenter);
	scrollarea->setAutoFillBackground(true);
	scrollarea->setWidgetResizable(true);
	//scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollarea->setWidget(widget);
	

	QGridLayout *layout = new QGridLayout;
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(scrollarea,0,0);

	setLayout(layout);
}
void Hard_Board::setConnection()
{
	connect(btnIOBase, SIGNAL(clicked(bool)), this, SLOT(setIOBase()));
	connect(btnIndex, SIGNAL(clicked(bool)), this, SLOT(setIOIndex()));
	connect(combobox_SIO_device, SIGNAL(currentIndexChanged(int)), this, SLOT(changdeSIODevice(int)));

	connect(tableIOBase, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(tableIOBaseInputing(QModelIndex)));
	connect(modelIOBase, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(tableIOBaseItemChanged(QStandardItem*)));

	connect(modelIndex, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(tableIOIndexItemChanged(QStandardItem*)));
	connect(tableIOIndex, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(tableIOIndexInputing(QModelIndex)));

	connect(tableSIO, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(tableSIOInputing(QModelIndex)));
	connect(modelSIO, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(tableSIOItemChanged(QStandardItem*)));

	connect(btnSIO, SIGNAL(clicked(bool)), this, SLOT(setSuperIOAddress()));
}
void Hard_Board::initializeData()
{
	string BIOSstr;
	data.getBIOS(BIOSstr);
	biosLabel->setText(QString::fromStdString(BIOSstr));

	string Boardstr;
	data.getBoard(Boardstr);
	boardLabel->setText(QString::fromStdString(Boardstr));

	getIOBase(IOBaseaddr, 0);
	getIOIndex(IOindexaddr, IOdataaddr);
	getSIOAddress(SIOindexaddr, SIOdataaddr);

	QStandardItemModel *model = new QStandardItemModel(this);
	vector<GetData::SMBIOS_Information> x;
	data.getSMBIOS(x);
	int j = 0;
	QStringList strList;
	QStandardItem *parent = new QStandardItem(QString("SMBIOS"));
	parent->setIcon(QIcon("treeview"));
	model->setItem(0, parent);
	for (auto &i : x)
	{
		parent->setChild(j, new QStandardItem(i.title));
		strList.append(i.value);
		j++;
	}
	treeBrowser = new Widget_TreeBrowser(this, model, strList);
}
void Hard_Board::updateData()
{
	data.updateHardware();
	initializeData();
}
void Hard_Board::setIOBase()
{ 
	if (window_IOBase ==NULL)
	{
		window_IOBase = new Window_IOBase(this);
		connect(window_IOBase, SIGNAL(send_input(uint, bool)), this, SLOT(getIOBase(uint, bool)));
	}
    window_IOBase->show();
}
void Hard_Board::getIOBase(unsigned int addr, bool acpi_flag)
{
	IOBaseaddr = addr;
	unsigned int base_address = addr;
	unsigned int output = 0;
	io_base_address = base_address;
	table_changing = true;
	for (unsigned int i = 0; i < 256; i++)
	{
		if (data.readIO(base_address,output))
		{
			unsigned int row = i/16, col = i%16;
			modelIOBase->setItem(row,col, new QStandardItem(QString("%0").arg(output, 0, 16)));
			model3_list.append(QString("%0").arg(output, 0, 16));
		}
		else
		{
			QMessageBox *messagebox = new QMessageBox(this);
			messagebox->setText("read fail:getIOBase,readIO");
			messagebox->exec();
		}
		base_address++;
	}
	table_changing = false;
	btnIOBase->setText(QString("IO Base:%0").arg(addr, 0, 16));
}
void Hard_Board::tableIOBaseInputing(QModelIndex index)
{
	iobase_lastvalue = modelIOBase->data(index).toString();
	qDebug() << "last data:" << iobase_lastvalue;
}
void Hard_Board::tableIOBaseItemChanged(QStandardItem *item)
{
	if (!table_changing)
	{
		QString str_data = item->data(Qt::EditRole).toString();
		QRegExp regexp("[0-9a-fA-F]+");
		if (!regexp.exactMatch(str_data))
		{
			item->setData(QVariant(model3_list.at(item->row() * 16 + item->column())), Qt::EditRole);
		}
		else if (str_data != model3_list.at(item->row() * 16 + item->column()))
		{
			unsigned int addr = io_base_address + item->column() + item->row();
			bool ok;
			unsigned int input = str_data.toInt(&ok, 16);
			ok = data.writeIO(addr, input);
			if (!ok)
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("write fail:tableIOBaseItemChanged,writeIO");
				messagebox->exec();
				modelIOBase->setItem(item->row(), item->column(), new QStandardItem(QString("%0").arg(iobase_lastvalue, 0, 16)));
			}
			else
				model3_list.replace(item->row() * 16 + item->column(), QString("0x%0").arg(input, 0, 16));
		}
	}
}
void Hard_Board::setIOIndex()
{
	if (window_IOIndex == NULL)
	{
		window_IOIndex = new Window_IOIndex(this);
		connect(window_IOIndex, SIGNAL(send_input(uint, uint)), this, SLOT(getIOIndex(uint, uint)));
	}
    window_IOIndex->show();
}
void Hard_Board::getIOIndex(unsigned int indexaddr, unsigned int dataaddr)
{
	IOindexaddr = indexaddr;
	IOdataaddr = dataaddr;
	unsigned int output = 0;
	unsigned int addr = 0;
	index_addr = indexaddr;
	data_addr = dataaddr;
	table_changing = true;
	for (unsigned int i = 0; i < 256; i++)
	{
		if (data.writeIO(indexaddr, addr))
		{
			if (!data.readIO(dataaddr, output))
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("read fail:getIOIndex,readIO");
				messagebox->exec();
			}
			else
			{
				addr++;
				modelIndex->setItem(i/16, i%16, new QStandardItem(QString("%0").arg(output, 0, 16)));
				model1_list.append(QString("%0").arg(output, 0, 16));
			}
		}
		else {
			QMessageBox *messagebox = new QMessageBox(this);
			messagebox->setText("write fail:getIOIndex,writeIO");
			messagebox->exec();
		}
	}
	table_changing = false;
	btnIndex->setText(QString("0x%0/0x%1").arg(indexaddr, 0, 16).arg(dataaddr, 0, 16));	
}
void Hard_Board::tableIOIndexInputing(QModelIndex index)
{
	ioindex_lastvalue = modelIndex->data(index).toString();
	qDebug() << "last data:" << ioindex_lastvalue;
}
void Hard_Board::tableIOIndexItemChanged(QStandardItem *item)
{
	if (!table_changing)
	{
		QString str_data = item->data(Qt::EditRole).toString();
		QRegExp regexp("[0-9a-fA-F]+");
		if (!regexp.exactMatch(str_data))
		{
			item->setData(QVariant(model1_list.at(item->row() * 16 + item->column())), Qt::EditRole);
		}
		else if (str_data != model1_list.at(item->row() * 16 + item->column()))
		{
			unsigned int addr = item->row() * 16 + item->column();
			bool ok;
			unsigned int input = str_data.toInt(&ok, 16);
			if (data.writeIO(index_addr, addr))
			{
				if (!data.writeIO(data_addr, input))
				{
					QMessageBox *messagebox = new QMessageBox(this);
					messagebox->setText("write fail:tableIOIndexItemChanged,writeIO data");
					messagebox->exec();
				}
				else
				{
					unsigned int output;
					data.readIO(data_addr, output);
					if (output == str_data.toInt(&ok, 16))
						model1_list.replace(item->row() * 16 + item->column(), str_data);
				}

			}
			else
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("write fail:tableIOIndexItemChanged,writeIO index");
				messagebox->exec();
			}
		}
	}
}
void Hard_Board::setSuperIOAddress()
{
	if (window_SIO == NULL)
	{
		window_SIO = new Window_SIO(this);
		connect(window_SIO, SIGNAL(send_input(uint, uint)), this, SLOT(getSIOAddress(uint, uint)));
	}
    window_SIO->show();
}
void Hard_Board::getSIOAddress(unsigned int index,unsigned int data)
{
    //qDebug()<<"index:"<<index<<" data:"<<data;
}
void Hard_Board::changdeSIODevice(int index)
{
    //load information to sio table according index
}
void Hard_Board::tableSIOInputing(QModelIndex index)
{
    sio_lastvalue = modelSIO->data(index).toString();
    qDebug()<<"last data:"<<sio_lastvalue;
}
void Hard_Board::tableSIOItemChanged(QStandardItem *item)
{
    QString str_data = item->data(Qt::EditRole).toString();
    QRegExp regexp("[0-9a-fA-F]+");
    if(!regexp.exactMatch(str_data))
    {
        item->setData(QVariant(sio_lastvalue),Qt::EditRole);
    }
}
/*
void Hard_Board::setIOIndexKey()
{
    QWidget *window = new QWidget(this);

    QLineEdit *textedit = new QLineEdit(window);
    textedit->setFixedWidth(100);
    textedit->setMaximumHeight(20);

    QLabel *label = new QLabel(window);
    label->setFrameStyle(QFrame::NoFrame);
    label->setText(QString("Note: Hex number must with prefix \"0x\" or suffix \"h\". Ex 0xA7 or A8h"));

    QPushButton *btn1 = new QPushButton(window);
    btn1->setText(QString("OK"));

    QPushButton *btn2 = new QPushButton(window);
    btn2->setText(QString("Cancel"));
    connect(btn2,SIGNAL(clicked(bool)),window,SLOT(close()));

    QPushButton *btn3 = new QPushButton(window);
    btn3->setText(QString("Help"));
    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->addWidget(textedit,0,0,1,3,Qt::AlignCenter);
    layout->addWidget(label,1,0,1,3,Qt::AlignCenter);
    layout->addWidget(btn1,2,0,1,1,Qt::AlignCenter);
    layout->addWidget(btn2,2,1,1,1,Qt::AlignCenter);
    layout->addWidget(btn3,2,2,1,1,Qt::AlignCenter);


    window->setWindowFlags(Qt::Window|Qt::WindowCloseButtonHint);
    window->setLayout(layout);
    window->show();
}
*/
void Hard_Board::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}