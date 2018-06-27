#include "hard_memory.h"

Hard_Memory::Hard_Memory(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QStringLiteral("类型"));
    QLabel *clabel1 = new QLabel(this);
    clabel1->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel1->setText(QStringLiteral(""));
    clabel1->setMaximumHeight(20);
    clabel1->setMinimumWidth(50);

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QStringLiteral("大小"));
    QLabel *clabel2 = new QLabel(this);
    clabel2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel2->setText(QStringLiteral(""));
    clabel2->setMaximumHeight(20);
    clabel2->setMinimumWidth(50);

    QLabel *label3 = new QLabel(this);
    label3->setFrameStyle(QFrame::NoFrame);
    label3->setText(QStringLiteral("channel"));
    QLabel *clabel3 = new QLabel(this);
    clabel3->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel3->setText(QStringLiteral(""));
    clabel3->setMaximumHeight(20);
    clabel3->setMinimumWidth(50);

    QLabel *label4 = new QLabel(this);
    label4->setFrameStyle(QFrame::NoFrame);
    label4->setText(QStringLiteral("frequency"));
    QLabel *clabel4 = new QLabel(this);
    clabel4->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel4->setText(QStringLiteral(""));
    clabel4->setMaximumHeight(20);
    clabel4->setMinimumWidth(50);

    QLabel *label5 = new QLabel(this);
    label5->setFrameStyle(QFrame::NoFrame);
    label5->setText(QStringLiteral("memory frequency"));
    QLabel *clabel5 = new QLabel(this);
    clabel5->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel5->setText(QStringLiteral(""));
    clabel5->setMaximumHeight(20);
    clabel5->setMinimumWidth(50);

    QLabel *label6 = new QLabel(this);
    label6->setFrameStyle(QFrame::NoFrame);
    label6->setText(QStringLiteral("CAS delay"));
    QLabel *clabel6 = new QLabel(this);
    clabel6->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel6->setText(QStringLiteral(""));
    clabel6->setMaximumHeight(20);
    clabel6->setMinimumWidth(50);

    QLabel *label7 = new QLabel(this);
    label7->setFrameStyle(QFrame::NoFrame);
    label7->setText(QStringLiteral("RAS precharge"));
    QLabel *clabel7 = new QLabel(this);
    clabel7->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel7->setText(QStringLiteral(""));
    clabel7->setMaximumHeight(20);
    clabel7->setMinimumWidth(50);

    QLabel *label8 = new QLabel(this);
    label8->setFrameStyle(QFrame::NoFrame);
    label8->setText(QStringLiteral("Row Refresh Cycle Time"));
    QLabel *clabel8 = new QLabel(this);
    clabel8->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel8->setText(QStringLiteral(""));
    clabel8->setMaximumHeight(20);
    clabel8->setMinimumWidth(50);

    QLabel *label9 = new QLabel(this);
    label9->setFrameStyle(QFrame::NoFrame);
    label9->setText(QStringLiteral("front bus：memory"));
    QLabel *clabel9 = new QLabel(this);
    clabel9->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel9->setText(QStringLiteral(""));
    clabel9->setMaximumHeight(20);
    clabel9->setMinimumWidth(50);

    QLabel *label10 = new QLabel(this);
    label10->setFrameStyle(QFrame::NoFrame);
    label10->setText(QStringLiteral("RAS to CAS"));
    QLabel *clabel10 = new QLabel(this);
    clabel10->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel10->setText(QStringLiteral(""));
    clabel10->setMaximumHeight(20);
    clabel10->setMinimumWidth(50);

    QLabel *label11 = new QLabel(this);
    label11->setFrameStyle(QFrame::NoFrame);
    label11->setText(QStringLiteral("cycle"));
    QLabel *clabel11 = new QLabel(this);
    clabel11->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel11->setText(QStringLiteral(""));
    clabel11->setMaximumHeight(20);
    clabel11->setMinimumWidth(50);

    QLabel *label12 = new QLabel(this);
    label12->setFrameStyle(QFrame::NoFrame);
    label12->setText(QStringLiteral("zhilingbilv"));
    QLabel *clabel12 = new QLabel(this);
    clabel12->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    clabel12->setText(QStringLiteral(""));
    clabel12->setMaximumHeight(20);
    clabel12->setMinimumWidth(50);

    QGridLayout *group1layout = new QGridLayout;
    group1layout->setContentsMargins(20,10,20,10);
    group1layout->setColumnStretch(0,0);
    group1layout->setColumnStretch(1,2);
    group1layout->setColumnStretch(2,0);
    group1layout->setColumnStretch(3,2);
    group1layout->setColumnStretch(4,0);
    group1layout->setColumnStretch(5,2);
    group1layout->setColumnStretch(6,0);
    group1layout->setColumnStretch(7,2);
    group1layout->addWidget(label1,0,0,Qt::AlignLeft);
    group1layout->addWidget(clabel1,0,1,Qt::AlignLeft);
    group1layout->addWidget(label2,0,2,Qt::AlignLeft);
    group1layout->addWidget(clabel2,0,3,Qt::AlignLeft);
    group1layout->addWidget(label3,0,4,Qt::AlignLeft);
    group1layout->addWidget(clabel3,0,5,Qt::AlignLeft);
    group1layout->addWidget(label4,0,6,Qt::AlignLeft);
    group1layout->addWidget(clabel4,0,7,Qt::AlignLeft);
    QGridLayout *group2layout = new QGridLayout;
    group2layout->setContentsMargins(20,10,20,10);
    group2layout->setColumnStretch(0,0);
    group2layout->setColumnStretch(1,2);
    group2layout->setColumnStretch(2,0);
    group2layout->setColumnStretch(3,2);
    group2layout->setColumnStretch(4,0);
    group2layout->setColumnStretch(5,2);
    group2layout->setColumnStretch(6,0);
    group2layout->setColumnStretch(7,2);
    group2layout->addWidget(label5,0,0,Qt::AlignLeft);
    group2layout->addWidget(clabel5,0,1,Qt::AlignLeft);
    group2layout->addWidget(label6,0,2,Qt::AlignLeft);
    group2layout->addWidget(clabel6,0,3,Qt::AlignLeft);
    group2layout->addWidget(label7,0,4,Qt::AlignLeft);
    group2layout->addWidget(clabel7,0,5,Qt::AlignLeft);
    group2layout->addWidget(label8,0,6,Qt::AlignLeft);
    group2layout->addWidget(clabel8,0,7,Qt::AlignLeft);
    group2layout->addWidget(label9,1,0,Qt::AlignLeft);
    group2layout->addWidget(clabel9,1,1,Qt::AlignLeft);
    group2layout->addWidget(label10,1,2,Qt::AlignLeft);
    group2layout->addWidget(clabel10,1,3,Qt::AlignLeft);
    group2layout->addWidget(label11,1,4,Qt::AlignLeft);
    group2layout->addWidget(clabel11,1,5,Qt::AlignLeft);
    group2layout->addWidget(label12,1,6,Qt::AlignLeft);
    group2layout->addWidget(clabel12,1,7,Qt::AlignLeft);

    QGroupBox *groupbox1 = new QGroupBox(tr("常规"));
    groupbox1->setLayout(group1layout);
    groupbox1->setMinimumWidth(750);
    QGroupBox *groupbox2 = new QGroupBox(tr("时序"));
    groupbox2->setLayout(group2layout);
    groupbox2->setMinimumWidth(750);

    QPushButton *btn = new QPushButton(this);
    btn->setText(QString("Addr=0x0000000000"));
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(setAddress()));

    QTableView *tableview = new QTableView(this);
    tableview->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    for(unsigned int i=0;i<16;++i)
    {
        //model1->setHeaderData(i,Qt::Horizontal,QObject::tr("a"));
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
    tableview->setEditTriggers(QAbstractItemView::DoubleClicked);
    connect(tableview,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(tableInputing(QModelIndex)));
    connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(tableItemChanged(QStandardItem*)));

    QGridLayout *sublayout = new QGridLayout;
    sublayout->setContentsMargins(10,10,10,10);
    sublayout->setSpacing(5);
    sublayout->setRowStretch(0,0);
    sublayout->setRowStretch(1,0);
    sublayout->setRowStretch(2,0);
    sublayout->setRowMinimumHeight(2,20);
    sublayout->setRowStretch(3,0);
    sublayout->setRowStretch(4,0);
    sublayout->addWidget(groupbox1,0,0,Qt::AlignCenter);
    sublayout->addWidget(groupbox2,1,0,Qt::AlignCenter);
    sublayout->addWidget(btn,3,0,Qt::AlignLeft|Qt::AlignBottom);
    sublayout->addWidget(tableview,4,0,Qt::AlignCenter);

    QWidget *widget = new QWidget(this);
    widget->setWindowFlags(Qt::FramelessWindowHint);
    widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    widget->setLayout(sublayout);

    QScrollArea *scrollarea = new QScrollArea;
    scrollarea->setBackgroundRole(QPalette::Window);
    scrollarea->setFrameStyle(QFrame::NoFrame);
    scrollarea->setWidget(widget);

    QGridLayout *layout = new QGridLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(scrollarea);

    setLayout(layout);
}
void Hard_Memory::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("Memory"));
}
void Hard_Memory::setAddress()
{
    window_memoryAddress  = new Window_memoryAddress(this);
    connect(window_memoryAddress,SIGNAL(send_input(uint)),this,SLOT(getMemoryAddress(uint)));
    window_memoryAddress->show();
}
void Hard_Memory::getMemoryAddress(unsigned int addr)
{
    qDebug()<<"address:"<<addr;
}
void Hard_Memory::tableInputing(QModelIndex index)
{
    lastvalue = model->data(index).toString();
}
void Hard_Memory::tableItemChanged(QStandardItem *item)
{
    QString str_data = item->data(Qt::EditRole).toString();
    QRegExp regexp("[0-9a-fA-F]+");
    if(!regexp.exactMatch(str_data))
    {
        item->setData(QVariant(lastvalue),Qt::EditRole);
    }
}
