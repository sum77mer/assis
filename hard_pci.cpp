#include "hard_pci.h"

Hard_PCI::Hard_PCI(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QWidget *widget = new QWidget(this);
    widget->setWindowFlags(Qt::FramelessWindowHint);
    widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QGridLayout *sublayout = new QGridLayout;
    sublayout->setContentsMargins(0,0,0,0);
    sublayout->setSpacing(0);
    //tree view
    QTreeWidget *treewidget = new QTreeWidget();
    treewidget->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    for(int i=0;i<10;++i)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("item:%1").arg(i)));
        item->addChild(new QTreeWidgetItem((QTreeWidget*)0,QStringList(QString("item:0"))));
        items.append(item);
    }
    treewidget->insertTopLevelItems(0,items);
    treewidget->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    //treewidget->setFrameStyle(QFrame::NoFrame);
    treewidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    treewidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    treewidget->setHeaderHidden(true);
    //treewidget->setMinimumWidth(700);

    combobox_device = new QComboBox(this);
    combobox_device->insertItem(0,QString("Bus 0 Dev 1 Intel Storage xxxx"));
    combobox_device->insertItem(1,QString("Bus 1 Dev 1 Intel Storage xxxx"));
    combobox_device->insertItem(2,QString("Bus 2 Dev 1 Intel Storage xxxx"));
    combobox_device->insertItem(3,QString("Bus 3 Dev 1 Intel Storage xxxx"));
    combobox_device->insertItem(4,QString("Bus 4 Dev 1 Intel Storage xxxx"));

    connect(combobox_device,SIGNAL(currentIndexChanged(int)),this,SLOT(changeDevice(int)));

    QTableView *tableview = new QTableView(this);
    tableview->setEditTriggers(QAbstractItemView::DoubleClicked);
    tableview->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    for(unsigned int i=0;i<16;++i)
    {
        model->setHorizontalHeaderItem(i,new QStandardItem(QString("%0").arg(i)));
    }
    for(unsigned int i=0;i<16;i++)
    {
        for(unsigned int j=0;j<16;j++)
        {
            model->setItem(i,j,new QStandardItem("0x1"));
        }
    }
    tableview->setModel(model);
    connect(tableview,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(tableInputing(QModelIndex)));
    connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(tableItemChanged(QStandardItem*)));

    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::NoFrame);
    label->setText(QStringLiteral("xxxxxxxxx\n"
                                  "xxxxxxxxx\n"
                                  "xxxxxxxxx\n"
                                  "xxxxxxxxx\n"
                                  "xxxxxxxxx\n"
                                  "xxxxxxxxx\n"
                                  "xxxxxxxxx\n"
                                  "xxxxxxxxx\n"
                                  "xxxxxxxxx\n"
                                  "xxxxxxxxx\n"));

    sublayout->setContentsMargins(10,20,10,10);
    sublayout->setSpacing(5);
    sublayout->setRowMinimumHeight(1,20);
    sublayout->setRowStretch(0,0);
    sublayout->setRowStretch(1,0);
    sublayout->setRowStretch(2,0);
    sublayout->setRowStretch(3,0);
    sublayout->setColumnMinimumWidth(1,10);
    sublayout->setColumnStretch(0,0);
    sublayout->setColumnStretch(1,0);
    sublayout->setColumnStretch(2,0);
    sublayout->addWidget(treewidget,0,0,1,3,Qt::AlignCenter);
    sublayout->addWidget(combobox_device,2,0,1,2,Qt::AlignBottom|Qt::AlignLeft);
    sublayout->addWidget(tableview,3,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(label,3,2,1,1,Qt::AlignLeft);
    widget->setLayout(sublayout);

    QScrollArea *scrollarea = new QScrollArea;
    scrollarea->setAlignment(Qt::AlignCenter);
    scrollarea->setBackgroundRole(QPalette::Window);
    scrollarea->setFrameStyle(QFrame::NoFrame);
    scrollarea->setWidget(widget);
    scrollarea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    QGridLayout *layout = new QGridLayout;
    //layout->setContentsMargins(0,0,0,0);
    //layout->setRowStretch(0,1);
    //layout->setColumnStretch(0,1);
    layout->addWidget(scrollarea);
    //layout->addWidget(treewidget);

    setLayout(layout);
}
void Hard_PCI::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("pci"));
}
void Hard_PCI::changeDevice(int index)
{
    qDebug()<<"pci device index:"<<index;
}
void Hard_PCI::tableInputing(QModelIndex index)
{
    lastValue = model->data(index).toString();
}
void Hard_PCI::tableItemChanged(QStandardItem *item)
{
    QString str_data = item->data(Qt::EditRole).toString();
    QRegExp regexp("[0-9a-fA-F]+");
    if(!regexp.exactMatch(str_data))
    {
        item->setData(QVariant(lastValue),Qt::EditRole);
    }
}
