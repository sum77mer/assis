#include "widget_treebrowser.h"

Widget_TreeBrowser::Widget_TreeBrowser(QWidget *parent,QStandardItemModel *model,const QStringList &valueList)
{
    setWindowFlags(Qt::FramelessWindowHint);
	stringlist = valueList;
    modelData = model;
    int rowcount=model->rowCount();
    for(int i=0;i<rowcount;i++)
    {
        QStandardItem *item = model->item(i,0);
        //stringlist.append(item->text());
    }
    QTreeView *treeview = new QTreeView(this);
    treeview->setModel(model);
    treeview->setHeaderHidden(true);
    treeview->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    connect(treeview,SIGNAL(clicked(QModelIndex)),this,SLOT(changeText(QModelIndex)));


    label = new QTextEdit(this);
	label->setReadOnly(true);
    label->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    label->setText(QStringLiteral(""));


    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->setColumnStretch(0,1);
    layout->setColumnStretch(1,0);
    layout->setColumnMinimumWidth(1,5);
    layout->setColumnStretch(2,1);
    layout->addWidget(treeview,0,0);
    layout->addWidget(label,0,2);

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

