#include "hard_pci.h"
#include "UIdata.h"
#include <qmessagebox.h>
#include <qdebug.h>
#include"UIconst.h"
Hard_PCI::Hard_PCI(QWidget *parent)
{
	setFont(enNormalFont);
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Hard_PCI::paintEvent(QPaintEvent *event)
{
}
void Hard_PCI::initializeUI()
{
	pciTree = new QTreeWidget();
	pciTree->setColumnCount(1);
	pciTree->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	pciTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//pciTree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	pciTree->setHeaderHidden(true);

	select_device = new QComboBox(this);
	
	table_configSpace = new QTableView(this);
	table_configSpace->setEditTriggers(QAbstractItemView::DoubleClicked);
	table_configSpace->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	table_configSpace->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	table_configSpace->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

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
	table_configSpace->setModel(model);
	table_configSpace->setMinimumHeight(table_configSpace->rowHeight(0) * 17);

	value_descriptor = new QLabel(this);
	value_descriptor->setFrameStyle(QFrame::NoFrame);
	value_descriptor->setText(QString("default"));
}
void Hard_PCI::setupLayout()
{
	QWidget *widget = new QWidget(this);
	widget->setWindowFlags(Qt::FramelessWindowHint);
	widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setContentsMargins(0, 0, 0, 0);
	sublayout->setSpacing(0);
	sublayout->setContentsMargins(10, 20, 10, 10);
	sublayout->setSpacing(5);
	sublayout->setRowMinimumHeight(1, 20);
	sublayout->setRowStretch(0, 0);
	sublayout->setRowStretch(1, 0);
	sublayout->setRowStretch(2, 0);
	sublayout->setRowStretch(3, 0);
	sublayout->setColumnMinimumWidth(1, 10);
	sublayout->setColumnStretch(0, 0);
	sublayout->setColumnStretch(1, 0);
	sublayout->setColumnStretch(2, 0);

	
	sublayout->setRowMinimumHeight(0, 200);
	sublayout->addWidget(pciTree, 0, 0, 1, 3);
	sublayout->addWidget(select_device, 2, 0, 1, 2, Qt::AlignBottom | Qt::AlignLeft);
	sublayout->addWidget(table_configSpace, 3, 0, 1, 1, Qt::AlignLeft);
	sublayout->addWidget(value_descriptor, 3, 2, 1, 1, Qt::AlignLeft);
	widget->setLayout(sublayout);

	scrollarea = new QScrollArea;
	scrollarea->setAlignment(Qt::AlignCenter);
	scrollarea->setBackgroundRole(QPalette::Window);
	scrollarea->setFrameStyle(QFrame::NoFrame);
	scrollarea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	scrollarea->setWidget(widget);
	scrollarea->setWidgetResizable(true);
	scrollarea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


	QGridLayout *layout = new QGridLayout;
	//layout->setContentsMargins(0,0,0,0);
	//layout->setRowStretch(0,1);
	//layout->setColumnStretch(0,1);
	layout->addWidget(scrollarea);
	//layout->addWidget(treewidget);

	setLayout(layout);
}
void Hard_PCI::setConnection()
{
	connect(table_configSpace, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(tableInputing(QModelIndex)));
	connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(tableItemChanged(QStandardItem*)));
	connect(select_device, SIGNAL(currentIndexChanged(int)), this, SLOT(changeDevice(int)));
}
void Hard_PCI::initializeData()
{
	pciInfo.clear();
	data.getPCI(pciInfo);
	QList<QTreeWidgetItem *> items;
	pci_list.clear();
	pciTree->clear();
	for (auto i : pciInfo)
	{
		items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("Bus: %0  Dev: %1  Fun: %2").arg(i.bus, 16).arg(i.dev, 16).arg(i.fun, 16))));
		pci_list << QString("Bus: %0  Dev: %1  Fun: %2").arg(i.bus, 16).arg(i.dev, 16).arg(i.fun, 16);
	}
	pciTree->insertTopLevelItems(0, items);
	if (pciInfo.begin() != pciInfo.end())
	{
		QString des;
		data.getPCIdescription(pciInfo.at(0).bus, pciInfo.at(0).dev, pciInfo.at(0).fun, des);
		value_descriptor->setText(des);
	}
	for (unsigned int i = 0; i<pci_list.length(); i++)
	{
		pcimodel->setItem(i, new QStandardItem(pci_list.at(i)));
	}
	select_device->setModel(pcimodel);
	select_device->setCurrentIndex(currentIndex);
}
void Hard_PCI::updateData()
{
	data.updateHardware();
	initializeData();
}
void Hard_PCI::changeDevice(int index)
{
	currentIndex = index;
	table_changing = true;
	int cfgSpace[256];
	if(data.getPCIconfig(pciInfo.at(index).bus, pciInfo.at(index).dev, pciInfo.at(index).fun, cfgSpace))
		for (unsigned int i = 0; i < 256; i++)
		{
			model->setItem(i / 16, i % 16, new QStandardItem(QString("%0").arg(cfgSpace[i], 0, 16)));
			pci_cfg_now << QString("%0").arg(cfgSpace[i], 0, 16);
		}
	else
	{
		QMessageBox *messagebox = new QMessageBox(this);
		messagebox->setText("read fail:changeDevice,getPCIconfig");
		messagebox->exec();
	}
	table_changing = false;
	QString des;
	data.getPCIdescription(pciInfo.at(index).bus, pciInfo.at(index).dev, pciInfo.at(index).fun, des);
	value_descriptor->setText(des);
}
void Hard_PCI::tableInputing(QModelIndex index)
{
    lastValue = model->data(index).toString();
}
void Hard_PCI::tableItemChanged(QStandardItem *item)
{
	if (!table_changing)
	{
		QString str_data = item->data(Qt::EditRole).toString();
		QRegExp regexp("[0-9a-fA-F]+");
		if (!regexp.exactMatch(str_data))
		{
			item->setData(QVariant(lastValue), Qt::EditRole);
		}
		else if (str_data != pci_cfg_now.at(item->row() * 16 + item->column()))
		{
			bool ok;
			unsigned int input = str_data.toInt(&ok, 16);
			unsigned int index = item->row() * 16 + item->column();
			if(data.writePCIconfig(pciInfo.at(item->row() * 16 + item->column()).bus, pciInfo.at(item->row() * 16 + item->column()).dev, pciInfo.at(item->row() * 16 + item->column()).fun, index, input))
				pci_cfg_now.replace(index, str_data);
			else
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("write fail:tableItemChanged");
				messagebox->exec();
				model->setItem(item->row(), item->column(), new QStandardItem(QString("%0").arg(lastValue, 0, 16)));
			}
		}
	} 	
}
void Hard_PCI::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}