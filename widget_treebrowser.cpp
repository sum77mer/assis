#include "widget_treebrowser.h"

Widget_TreeBrowser::Widget_TreeBrowser(QWidget *parent,QStandardItemModel *model,int width,int height)
{
    setFixedSize(width,height);
    setWindowFlags(Qt::FramelessWindowHint);

    modelData = model;
    int rowcount=model->rowCount();
    for(int i=0;i<rowcount;i++)
    {
        QStandardItem *item = model->item(i,0);
        //if()
        //{}
        stringlist.append(item->text());
    }
    QTreeView *treeview = new QTreeView(this);
    treeview->setModel(model);
    treeview->setHeaderHidden(true);
    treeview->setMinimumSize(width*0.35,height);
    treeview->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    connect(treeview,SIGNAL(clicked(QModelIndex)),this,SLOT(changeText(QModelIndex)));

    label = new QLabel(this);
    label->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label->setMinimumSize(width*0.6,height);
    label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    label->setText(QStringLiteral(""));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->setColumnStretch(0,1);
    layout->setColumnStretch(1,0);
    layout->setColumnMinimumWidth(1,width*0.03);
    layout->setColumnStretch(2,2);
    layout->addWidget(treeview,0,0,1,1,Qt::AlignRight|Qt::AlignTop);
    layout->addWidget(label,0,2,1,1,Qt::AlignLeft|Qt::AlignTop);

    setLayout(layout);

}
void Widget_TreeBrowser::updateData(QStandardItemModel *model)
{}
void Widget_TreeBrowser::changeText(QModelIndex index)
{
    unsigned int num=0;
    num=index.row();
    const QString str=stringlist.at(num);
    label->setText(str);
    label->update();
}

