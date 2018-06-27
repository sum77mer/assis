#include "hard_storage.h"

#include "widget_treebrowser.h"
Hard_Storage::Hard_Storage(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QStringLiteral("product:"));
    QLabel *clabel1 = new QLabel(this);
    clabel1->setFrameStyle(QFrame::NoFrame);
    clabel1->setText(QStringLiteral("xxxxxxx"));

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QStringLiteral("Firmware:"));
    QLabel *clabel2 = new QLabel(this);
    clabel2->setFrameStyle(QFrame::NoFrame);
    clabel2->setText(QStringLiteral("xxxx"));

    QLabel *label3 = new QLabel(this);
    label3->setFrameStyle(QFrame::NoFrame);
    label3->setText(QStringLiteral("Product:"));
    QLabel *clabel3 = new QLabel(this);
    clabel3->setFrameStyle(QFrame::NoFrame);
    clabel3->setText(QStringLiteral("xxxxxxx"));

    QLabel *label4 = new QLabel(this);
    label4->setFrameStyle(QFrame::NoFrame);
    label4->setText(QStringLiteral("Firmware:"));
    QLabel *clabel4 = new QLabel(this);
    clabel4->setFrameStyle(QFrame::NoFrame);
    clabel4->setText(QStringLiteral("xxxx"));


    QLabel *label5 = new QLabel(this);
    label5->setFrameStyle(QFrame::NoFrame);
    label5->setText(QStringLiteral("Product:"));
    QLabel *clabel5 = new QLabel(this);
    clabel5->setFrameStyle(QFrame::NoFrame);
    clabel5->setText(QStringLiteral("xxxxxxx"));

    QLabel *label6 = new QLabel(this);
    label6->setFrameStyle(QFrame::NoFrame);
    label6->setText(QStringLiteral("Firmware:"));
    QLabel *clabel6 = new QLabel(this);
    clabel6->setFrameStyle(QFrame::NoFrame);
    clabel6->setText(QStringLiteral("xxxx"));

    QLabel *label7 = new QLabel(this);
    label7->setFrameStyle(QFrame::NoFrame);
    label7->setText(QStringLiteral("select:"));

    QComboBox *combobox = new QComboBox(this);
    combobox->insertItem(0,QString("disk 1"));
    combobox->insertItem(1,QString("disk 2"));
    combobox->insertItem(2,QString("disk 3"));

    connect(combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeIdentifyDisk(int)));

    QTableView *tableview1 = new QTableView(this);
    tableview1->setEditTriggers(QAbstractItemView::DoubleClicked);
    tableview1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableview1->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    for(unsigned int i=0;i<16;++i)
    {
        model1->setHorizontalHeaderItem(i,new QStandardItem(QString("%0").arg(i)));
    }
    for(unsigned int i=0;i<16;i++)
    {
        for(unsigned int j=0;j<16;j++)
        {
            model1->setItem(i,j,new QStandardItem("0x1"));
        }
    }
    tableview1->setModel(model1);
    tableview1->setEditTriggers(QAbstractItemView::DoubleClicked);
    connect(tableview1,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(identifyTableInputing(QModelIndex)));
    connect(model1,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(identifyTableItemChanged(QStandardItem*)));
    combobox_RWdisk = new QComboBox(this);
    combobox_RWdisk->insertItem(0,QString("disk1"));
    combobox_RWdisk->insertItem(1,QString("disk2"));
    combobox_RWdisk->insertItem(2,QString("disk3"));
    combobox_RWdisk->insertItem(3,QString("disk4"));

    QLabel *label8 = new QLabel(this);
    label8->setFrameStyle(QFrame::NoFrame);
    label8->setText(QStringLiteral("LBA"));

    lineedit_lba = new QLineEdit(this);
    lineedit_lba->setText(QStringLiteral(""));
    //clabel8->setMinimumWidth(50);
    //clabel8->setMaximumHeight(20);

    QPushButton *btn_ok = new QPushButton(this);
    btn_ok->setText("OK");

    connect(btn_ok,SIGNAL(clicked(bool)),this,SLOT(setRWAddress()));


    tableview2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableview2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    for(unsigned int i=0;i<16;++i)
    {
        model2->setHorizontalHeaderItem(i,new QStandardItem(QString("%0").arg(i)));
    }
    for(unsigned int i=0;i<16;i++)
    {
        for(unsigned int j=0;j<16;j++)
        {
            model2->setItem(i,j,new QStandardItem("0x1"));
        }
    }
    tableview2->setEditTriggers(QAbstractItemView::DoubleClicked);
    tableview2->setModel(model2);
    connect(tableview2,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(rwTableInputing(QModelIndex)));
    connect(model2,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(rwTableItemChanged(QStandardItem*)));

    QLabel *label9 = new QLabel(this);
    label9->setFrameStyle(QFrame::NoFrame);
    label9->setText(QStringLiteral("USB"));

    QLabel *label10 = new QLabel(this);
    label10->setFrameStyle(QFrame::NoFrame);
    label10->setText(QStringLiteral("Version A08"));

    QLabel *label11 = new QLabel(this);
    label11->setFrameStyle(QFrame::NoFrame);
    label11->setText(QStringLiteral("Date 04/16/2014"));

    QStandardItemModel *model = new QStandardItemModel(this);
    QStandardItem *parentItem = model->invisibleRootItem();
    for(int i = 0;i<4;++i)
    {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        parentItem->appendRow(item);
        parentItem = item;
    }
    for(int i = 1;i<10;++i)
    {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        model->setItem(i,0,item);
    }
    Widget_TreeBrowser *treebrowser = new Widget_TreeBrowser(this,model,700,594);

    QGridLayout *sublayout = new QGridLayout;
    sublayout->setContentsMargins(20,10,10,10);
    sublayout->setColumnStretch(0,0);
    sublayout->setColumnStretch(1,0);
    sublayout->setColumnStretch(2,0);
    sublayout->setColumnStretch(3,1);
    sublayout->addWidget(label1,0,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(clabel1,0,1,1,3,Qt::AlignLeft);
    sublayout->addWidget(label2,1,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(clabel2,1,1,1,3,Qt::AlignLeft);
    sublayout->addWidget(label3,2,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(clabel3,2,1,1,3,Qt::AlignLeft);
    sublayout->addWidget(label4,3,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(clabel4,3,1,1,3,Qt::AlignLeft);
    sublayout->addWidget(label5,4,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(clabel5,4,1,1,3,Qt::AlignLeft);
    sublayout->addWidget(label6,5,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(clabel6,5,1,1,3,Qt::AlignLeft);

    sublayout->setRowMinimumHeight(6,20);
    sublayout->addWidget(label7,7,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(combobox,7,1,1,2,Qt::AlignLeft);


    sublayout->addWidget(tableview1,8,0,1,4,Qt::AlignCenter);

    sublayout->setRowMinimumHeight(9,20);
    sublayout->addWidget(combobox_RWdisk,10,0,1,1,Qt::AlignLeft);
    sublayout->addWidget(label8,10,1,1,1,Qt::AlignLeft);
    sublayout->addWidget(lineedit_lba,10,2,1,2,Qt::AlignLeft);
    sublayout->addWidget(btn_ok,10,4,1,1,Qt::AlignLeft);

    sublayout->addWidget(tableview2,11,0,1,4,Qt::AlignCenter);

    sublayout->setRowMinimumHeight(12,20);
    sublayout->addWidget(label9,13,0,1,3,Qt::AlignLeft);
    sublayout->addWidget(label10,14,0,1,3,Qt::AlignLeft);
    sublayout->addWidget(label11,15,0,1,3,Qt::AlignLeft);

    sublayout->setRowMinimumHeight(16,20);
    sublayout->addWidget(treebrowser,17,0,1,4,Qt::AlignCenter);


    QWidget *widget = new QWidget(this);
    widget->setWindowFlags(Qt::FramelessWindowHint);
    widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    widget->setLayout(sublayout);

    QScrollArea *scrollarea = new QScrollArea;
    scrollarea->setBackgroundRole(QPalette::Window);
    scrollarea->setFrameStyle(QFrame::NoFrame);
    scrollarea->setAlignment(Qt::AlignCenter);
    scrollarea->setWidget(widget);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(scrollarea);

    setLayout(layout);
}
void Hard_Storage::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("Storage"));
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
