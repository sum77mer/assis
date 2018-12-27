#include "hard_storage.h"
#include "usbtreewidget.h"
#include "usbtestbrowser.h"
#include "widget_treebrowser.h"
#include "UIdata.h"

Hard_Storage::Hard_Storage(QWidget *parent)
{
	setFont(*normalFont);
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Hard_Storage::paintEvent(QPaintEvent *event)
{
}
void Hard_Storage::initializeUI()
{
	title_select = new QLabel(this);
	title_select->setFrameStyle(QFrame::NoFrame);
	title_select->setText(QStringLiteral("select:"));

	selectDisk_RW = new QComboBox(this);
	selectDisk_RW->insertItem(0, QString("disk 1"));
	selectDisk_RW->insertItem(1, QString("disk 2"));
	selectDisk_RW->insertItem(2, QString("disk 3"));

	tableview_identify = new QTableView(this);
	tableview_identify->setEditTriggers(QAbstractItemView::DoubleClicked);
	tableview_identify->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	tableview_identify->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tableview_identify->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	for (unsigned int i = 0; i<16; ++i)
	{
		model1->setHorizontalHeaderItem(i, new QStandardItem(QString("%0").arg(i)));
	}
	for (unsigned int i = 0; i<16; i++)
	{
		for (unsigned int j = 0; j<16; j++)
		{
			model1->setItem(i, j, new QStandardItem("0x1"));
		}
	}
	tableview_identify->setModel(model1);
	tableview_identify->setMinimumHeight(tableview_identify->rowHeight(0) * 17);
	combobox_RWdisk = new QComboBox(this);
	combobox_RWdisk->insertItem(0, QString("disk1"));
	combobox_RWdisk->insertItem(1, QString("disk2"));
	combobox_RWdisk->insertItem(2, QString("disk3"));
	combobox_RWdisk->insertItem(3, QString("disk4"));

	title_LBA = new QLabel(this);
	title_LBA->setFrameStyle(QFrame::NoFrame);
	title_LBA->setText(QStringLiteral("LBA"));

	lineedit_lba = new QLineEdit(this);
	lineedit_lba->setText(QStringLiteral(""));
	btn_RWok = new QPushButton(this);
	btn_RWok->setText("OK");

	tableviewRW = new QTableView(this);
	tableviewRW->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	tableviewRW->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tableviewRW->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	for (unsigned int i = 0; i<16; ++i)
	{
		model2->setHorizontalHeaderItem(i, new QStandardItem(QString("%0").arg(i)));
	}
	for (unsigned int i = 0; i<16; i++)
	{
		for (unsigned int j = 0; j<16; j++)
		{
			model2->setItem(i, j, new QStandardItem("0x1"));
		}
	}
	tableviewRW->setModel(model2);
	tableviewRW->setEditTriggers(QAbstractItemView::DoubleClicked);
	tableviewRW->setMinimumHeight(tableviewRW->rowHeight(0) * 17);
	titleUSB = new QLabel(this);
	titleUSB->setFrameStyle(QFrame::NoFrame);
	titleUSB->setText(QStringLiteral("USB"));

	valueVersion = new QLabel(this);
	valueVersion->setFrameStyle(QFrame::NoFrame);
	valueVersion->setText(QStringLiteral("Version A08"));

	valueDate = new QLabel(this);
	valueDate->setFrameStyle(QFrame::NoFrame);
	valueDate->setText(QStringLiteral("Date 04/16/2014"));

	QStandardItemModel *model = new QStandardItemModel(this);
	QStandardItem *parentItem = model->invisibleRootItem();
	for (int i = 0; i<4; ++i)
	{
		QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
		parentItem->appendRow(item);
		parentItem = item;
	}
	for (int i = 1; i<10; ++i)
	{
		QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
		model->setItem(i, 0, item);
	}
}
void Hard_Storage::setupLayout()
{
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(0, 10, 10, 10);
	sublayout->setColumnStretch(0, 0);
	sublayout->setColumnStretch(1, 1);
	sublayout->setColumnStretch(2, 1);
	sublayout->setColumnStretch(3, 1);
	sublayout->setColumnStretch(4, 1);
	sublayout->setColumnStretch(5, 1);
	sublayout->setColumnStretch(6, 1);
	sublayout->setColumnStretch(7, 1);
	sublayout->setColumnStretch(8, 1);
	sublayout->setColumnStretch(9, 1);
	sublayout->setColumnStretch(10, 1);
	sublayout->setColumnStretch(11, 0);
	sublayout->addWidget(value_disk, 0, 0, 1, 10);
	sublayout->setRowMinimumHeight(6, 20);
	sublayout->addWidget(title_select, 7, 1, 1, 1, Qt::AlignRight);
	sublayout->addWidget(selectDisk_RW, 7, 2, 1, 2, Qt::AlignLeft);

	sublayout->addWidget(tableview_identify, 8, 1, 1, 10, Qt::AlignCenter);

	sublayout->setRowMinimumHeight(9, 20);
	sublayout->addWidget(combobox_RWdisk, 10, 1, 1, 1, Qt::AlignRight);
	sublayout->addWidget(title_LBA, 10, 2, 1, 1, Qt::AlignRight);
	sublayout->addWidget(lineedit_lba, 10, 3, 1, 2, Qt::AlignLeft);
	sublayout->addWidget(btn_RWok, 10, 6, 1, 1, Qt::AlignRight);

	sublayout->addWidget(tableviewRW, 11, 1, 1, 10, Qt::AlignCenter);//

	sublayout->setRowMinimumHeight(12, 20);
	sublayout->addWidget(titleUSB, 13, 0, 1, 3, Qt::AlignLeft);
	sublayout->addWidget(valueVersion, 14, 0, 1, 3, Qt::AlignLeft);
	sublayout->addWidget(valueDate, 15, 0, 1, 3, Qt::AlignLeft);
	usbtestbrowser *a = new usbtestbrowser(this);
	usbtreewidget *b = new usbtreewidget(this);
	connect(b, SIGNAL(sendUsbInfo(QString)), a, SLOT(ReviceUsbInfo(QString)));
	sublayout->addWidget(b, 16, 1, 1, 3);
	sublayout->addWidget(a, 16, 4, 1, 7);
	sublayout->setRowMinimumHeight(16, 300);
	sublayout->setRowMinimumHeight(17, 20);

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

	setLayout(layout);
}
void Hard_Storage::setConnection()
{
	connect(combobox_RWdisk, SIGNAL(currentIndexChanged(int)), this, SLOT(changeIdentifyDisk(int)));

	connect(tableviewRW, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(identifyTableInputing(QModelIndex)));
	connect(model1, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(identifyTableItemChanged(QStandardItem*)));
	connect(btn_RWok, SIGNAL(clicked(bool)), this, SLOT(setRWAddress()));
	connect(tableviewRW, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(rwTableInputing(QModelIndex)));
	connect(model2, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(rwTableItemChanged(QStandardItem*)));
}
void Hard_Storage::initializeData()
{
	QString str_disk;
	vector<GetData::Disk_Information> x;
	data.getStorage(x);
	for (auto &i : x)
	{
		str_disk += "Model:" + QString::fromStdWString(i.Model) + "\r\n";
		str_disk += "NvCache Size:" + QString::fromStdWString(i.LogicalDrive) + "\r\n";
		str_disk += "Total Disk Size:" + QString::fromStdWString(i.TotalDiskSize) + "\r\n";
		str_disk += "Interface:" + QString::fromStdWString(i.Interface) + "\r\n";
		str_disk += "Serial Number:" + QString::fromStdWString(i.SerialNumber) + "\r\n";
		str_disk += "Fireware Rev:" + QString::fromStdWString(i.FirmwareRev) + "\r\n";
		str_disk += "Power On Hours:" + QString::fromStdWString(i.PowerOnHours) + "\r\n";
		str_disk += "Power On Count:" + QString::fromStdWString(i.PowerOnCount) + "\r\n";
		str_disk += "Temperature:" + QString::fromStdWString(i.Temperature);
		str_disk += "Nominal Media Rotation Rate:" + QString::fromStdWString(i.NominalMediaRotationRate) + "\r\n";
		str_disk += "Buffer Size:" + QString::fromStdWString(i.BufferSize) + "\r\n";

		str_disk += "Host Writes:" + QString::fromStdWString(i.HostWrites) + "\r\n";
		str_disk += "Host Reads:" + QString::fromStdWString(i.HostReads) + "\r\n";
		str_disk += "GBytes Erased:" + QString::fromStdWString(i.GBytesErased) + "\r\n";
		str_disk += "Nand Writes:" + QString::fromStdWString(i.NandWrites) + "\r\n";
		str_disk += "Enclosure:" + QString::fromStdWString(i.Enclosure) + "\r\n";
		str_disk += "Device Nominal Form Factor:" + QString::fromStdWString(i.DeviceNominalFormFactor) + "\r\n";
		str_disk += "Feature:" + QString::fromStdWString(i.Feature) + "\r\n";
		str_disk += "Disk State:" + QString::fromStdWString(i.DiskState) + "\r\n";
		str_disk += "\r\n";
	}
	value_disk = new QLabel(this);
	value_disk->setFrameStyle(QFrame::NoFrame);
	value_disk->setText(str_disk);
}
void Hard_Storage::updateData()
{
	data.updateHardware();
	initializeData();
}
void Hard_Storage::changeIdentifyDisk(int index)
{
    qDebug()<<"identify disk choose:"<<index;
}
void Hard_Storage::setRWAddress()
{
    qDebug()<<"RW disk:"<<combobox_RWdisk->currentIndex();
    QString str_lba = lineedit_lba->text();
    qDebug()<<"lba:"<<str_lba;
}
void Hard_Storage::identifyTableInputing(QModelIndex index)
{
    identify_lastValue = model1->data(index).toString();
}
void Hard_Storage::identifyTableItemChanged(QStandardItem *item)
{
    QString str_data = item->data(Qt::EditRole).toString();
    QRegExp regexp("[0-9a-fA-F]+");
    if(!regexp.exactMatch(str_data))
    {
        item->setData(QVariant(identify_lastValue),Qt::EditRole);
    }
}
void Hard_Storage::rwTableInputing(QModelIndex index)
{
    //qDebug()<<"activated";
    rw_lastValue = model2->data(index).toString();
}
void Hard_Storage::rwTableItemChanged(QStandardItem *item)
{
    QString str_data = item->data(Qt::EditRole).toString();
    QRegExp regexp("[0-9a-fA-F]+");
    if(!regexp.exactMatch(str_data))
    {
        item->setData(QVariant(rw_lastValue),Qt::EditRole);
    }
}
void Hard_Storage::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}