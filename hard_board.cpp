#include "hard_board.h"
#include "smbiostextbrowser.h"
#include "smbiostreewidget.h"
Hard_Board::Hard_Board(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    //window_IOBase->close();
    Updatesmbios();
    boardLabel = new QLabel(this);
    chipsetLabel = new QLabel(this);
    biosLabel = new QLabel(this);
    boardLabel->setFrameStyle(QFrame::NoFrame);
    boardLabel->setText(QStringLiteral("Manufacturer:******\n"
                                       "Product:******\n"
                                       "Type:******"));
    boardLabel->setAlignment(Qt::AlignLeft);
    chipsetLabel->setFrameStyle(QFrame::NoFrame);
    chipsetLabel->setText(QStringLiteral("Chipset Model:******"));
    chipsetLabel->setAlignment(Qt::AlignLeft);
    biosLabel->setFrameStyle(QFrame::NoFrame);
    biosLabel->setText(QStringLiteral("Vender:******\n"
                                      "Version:******\n"
                                      "Date:*******"));
    biosLabel->setAlignment(Qt::AlignLeft);

    QGridLayout *layout1 = new QGridLayout;
    layout1->setContentsMargins(20,10,0,10);
    layout1->addWidget(boardLabel);
    QGridLayout *layout2 = new QGridLayout;
    layout2->setContentsMargins(20,10,0,10);
    layout2->addWidget(chipsetLabel);
    QGridLayout *layout3 = new QGridLayout;
    layout3->setContentsMargins(20,10,0,10);
    layout3->addWidget(biosLabel);

    QGroupBox *boardgroup = new QGroupBox(tr("Board"));
    QGroupBox *chipsetgroup = new QGroupBox(tr("Chipset"));
    QGroupBox *biosgroup = new QGroupBox(tr("BIOS"));
    boardgroup->setLayout(layout1);
    boardgroup->setMinimumWidth(700);
    chipsetgroup->setLayout(layout2);
    chipsetgroup->setMinimumWidth(700);
    biosgroup->setLayout(layout3);
    biosgroup->setMinimumWidth(700);

    //io base
    QPushButton *btn5 = new QPushButton(this);
    btn5->setText(QString("IO Base:FFFFF"));
    connect(btn5,SIGNAL(clicked(bool)),this,SLOT(setIOBase()));
    QTableView *tableview3 = new QTableView(this);
    tableview3->setEditTriggers(QAbstractItemView::DoubleClicked);
    tableview3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableview3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    for(unsigned int i=0;i<16;++i)
    {
        model3->setHorizontalHeaderItem(i,new QStandardItem(QString("%0").arg(i)));
    }
    for(unsigned int i=0;i<16;i++)
    {
        for(unsigned int j=0;j<16;j++)
        {
            model3->setItem(i,j,new QStandardItem("1"));
            model3->setSortRole(Qt::EditRole);
        }
    }

    tableview3->setModel(model3);
    connect(tableview3,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(tableIOBaseInputing(QModelIndex)));
    connect(model3,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(tableIOBaseItemChanged(QStandardItem*)));
    //io index
    QPushButton *btn1 = new QPushButton(this);
    btn1->setText(QString("0x77/0x80"));
    connect(btn1,SIGNAL(clicked(bool)),this,SLOT(setIOIndex()));
    QPushButton *btn2 = new QPushButton(this);
    btn2->setText(QString("key"));
    //connect(btn2,SIGNAL(clicked(bool)),this,SLOT(setIOIndexKey()));

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
            model1->setSortRole(Qt::EditRole);
        }
    }
    connect(tableview1,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(tableIOIndexInputing(QModelIndex)));
    connect(model1,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(tableIOIndexItemChanged(QStandardItem*)));

    tableview1->setModel(model1);

    //super io
    QPushButton *btn3 = new QPushButton(this);
    btn3->setText(QString("IO Ports"));
    connect(btn3,SIGNAL(clicked(bool)),this,SLOT(setSuperIOAddress()));
    QPushButton *btn4 = new QPushButton(this);
    btn4->setText(QString("key"));
    //connect(btn4,SIGNAL(clicked(bool)),this,SLOT(setSuperIOKey()));
    combobox_SIO_device = new QComboBox(this);
    combobox_SIO_device->insertItem(0,QString("logical device xxxxxxxx"));
    combobox_SIO_device->insertItem(1,QString("logical device xxxxxxxx"));
    combobox_SIO_device->insertItem(2,QString("logical device xxxxxxxx"));

    connect(combobox_SIO_device,SIGNAL(currentIndexChanged(int)),this,SLOT(changdeSIODevice(int)));

    QTableView *tableview2 = new QTableView(this);
    tableview2->setEditTriggers(QAbstractItemView::DoubleClicked);
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
            model2->setSortRole(Qt::EditRole);
        }
    }
    connect(tableview2,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(tableSIOInputing(QModelIndex)));
    connect(model2,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(tableSIOItemChanged(QStandardItem*)));
    tableview2->setModel(model2);
/*
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
    Widget_TreeBrowser *treebrowser = new Widget_TreeBrowser(this,model,700,500);
*/
    smbiostextbrowser *browser = new smbiostextbrowser(this);
    smbiostreewidget *tree = new smbiostreewidget(this);
    tree->UpdateData();
    connect(tree,SIGNAL(SMBIOSReady(bool)),browser,SLOT(ReciveSMBIOSReady(bool)));
    connect(tree,SIGNAL(itemClicked(QTreeWidgetItem*,int)),browser,SLOT(ReciveSMBIOSloc(QTreeWidgetItem*,int)));
    tree->setMinimumHeight(300);
    browser->setMinimumHeight(300);
    //browser->ReciveSMBIOSloc(tree,0);

    QGridLayout *sublayout = new QGridLayout;
    sublayout->setColumnStretch(0,0);
    sublayout->setColumnStretch(1,0);
    sublayout->setColumnStretch(2,10);
    //sublayout->setColumnStretch(3,10);
    sublayout->setRowStretch(0,0);
    sublayout->setRowStretch(1,0);
    sublayout->setRowStretch(2,0);
    sublayout->setRowMinimumHeight(3,20);
    sublayout->setRowStretch(3,0);
    sublayout->setRowStretch(4,0);
    sublayout->setRowStretch(5,0);
    sublayout->setRowMinimumHeight(6,20);
    sublayout->setRowStretch(6,0);
    sublayout->setRowStretch(7,0);
    sublayout->setRowStretch(8,0);
    sublayout->setRowMinimumHeight(9,20);
    sublayout->setRowStretch(9,0);
    sublayout->setRowStretch(10,0);
    sublayout->setRowStretch(11,0);
    sublayout->setRowStretch(12,0);
    sublayout->setRowStretch(13,0);
    sublayout->setRowMinimumHeight(12,20);
    sublayout->addWidget(boardgroup,0,0,1,3,Qt::AlignCenter);

    sublayout->addWidget(chipsetgroup,1,0,1,3,Qt::AlignCenter);

    sublayout->addWidget(biosgroup,2,0,1,3,Qt::AlignCenter);

    sublayout->addWidget(btn5,4,0,1,1,Qt::AlignLeft|Qt::AlignBottom);
    sublayout->addWidget(tableview3,5,0,1,3,Qt::AlignCenter);

    sublayout->addWidget(btn1,7,0,1,1,Qt::AlignLeft|Qt::AlignBottom);
    sublayout->addWidget(btn2,7,1,1,1,Qt::AlignLeft|Qt::AlignBottom);

    sublayout->addWidget(tableview1,8,0,1,3,Qt::AlignCenter);

    sublayout->addWidget(btn3,10,0,1,1,Qt::AlignLeft|Qt::AlignCenter);
    sublayout->addWidget(btn4,10,1,1,1,Qt::AlignLeft|Qt::AlignCenter);
    sublayout->addWidget(combobox_SIO_device,10,2,1,1,Qt::AlignLeft|Qt::AlignCenter);

    sublayout->addWidget(tableview2,11,0,1,3,Qt::AlignCenter);

    sublayout->addWidget(tree,13,0,1,1,Qt::AlignCenter);
    sublayout->addWidget(browser,13,1,1,1,Qt::AlignCenter);


    QWidget *widget = new QWidget(this);
    //widget->setFixedSize(500,594);
    widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    widget->setWindowFlags(Qt::FramelessWindowHint);
    widget->setLayout(sublayout);

    QScrollArea *scrollarea = new QScrollArea;
    scrollarea->setBackgroundRole(QPalette::Window);
    scrollarea->setFrameStyle(QFrame::NoFrame);
    scrollarea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scrollarea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollarea->setWidget(widget);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(scrollarea);

    setLayout(layout);

}
void Hard_Board::paintEvent(QPaintEvent *event)
{

}
void Hard_Board::setIOBase()
{
    window_IOBase = new Window_IOBase(this);
    connect(window_IOBase,SIGNAL(send_input(uint,bool)),this,SLOT(getIOBase(uint,bool)));
    window_IOBase->show();
}
void Hard_Board::getIOBase(unsigned int addr, bool acpi_flag)
{
    qDebug()<<"addr:"<<addr<<" flag:"<<acpi_flag;
}
void Hard_Board::setIOIndex()
{
    window_IOIndex = new Window_IOIndex(this);
    connect(window_IOIndex,SIGNAL(send_input(uint,uint)),this,SLOT(getIOIndex(uint,uint)));
    window_IOIndex->show();
}
void Hard_Board::getIOIndex(unsigned int index, unsigned int data)
{
    qDebug()<<"index:"<<index<<" data:"<<data;
}

void Hard_Board::setSuperIOAddress()
{
    window_SIO = new Window_SIO(this);
    connect(window_SIO,SIGNAL(send_input(uint,uint)),this,SLOT(getSIOAddress(uint,uint)));
    window_SIO->show();
}
void Hard_Board::getSIOAddress(unsigned int index,unsigned int data)
{
    qDebug()<<"index:"<<index<<" data:"<<data;
}
void Hard_Board::changdeSIODevice(int index)
{
    //load information to sio table according index
}
void Hard_Board::tableIOBaseInputing(QModelIndex index)
{
    iobase_lastvalue = model3->data(index).toString();
    qDebug()<<"last data:"<<iobase_lastvalue;
}
void Hard_Board::tableIOBaseItemChanged(QStandardItem *item)
{
    QString str_data = item->data(Qt::EditRole).toString();
    QRegExp regexp("[0-9a-fA-F]+");
    if(!regexp.exactMatch(str_data))
    {
        item->setData(QVariant(iobase_lastvalue),Qt::EditRole);
    }
}
void Hard_Board::tableIOIndexInputing(QModelIndex index)
{
    ioindex_lastvalue = model1->data(index).toString();
    qDebug()<<"last data:"<<ioindex_lastvalue;
}
void Hard_Board::tableIOIndexItemChanged(QStandardItem *item)
{
    QString str_data = item->data(Qt::EditRole).toString();
    QRegExp regexp("[0-9a-fA-F]+");
    if(!regexp.exactMatch(str_data))
    {
        item->setData(QVariant(ioindex_lastvalue),Qt::EditRole);
    }
}
void Hard_Board::tableSIOInputing(QModelIndex index)
{
    sio_lastvalue = model2->data(index).toString();
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
