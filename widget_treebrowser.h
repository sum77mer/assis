#ifndef WIDGET_TREEBROWSER_H
#define WIDGET_TREEBROWSER_H
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTreeView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QStringList>
#include <QString>
#include <QDebug>

class Widget_TreeBrowser : public QWidget
{
    Q_OBJECT
public:
    Widget_TreeBrowser(QWidget *parent = 0,QStandardItemModel *model = 0,int width = 300,int height = 500);
    void updateData(QStandardItemModel *model = 0);
protected slots:
    void changeText(QModelIndex index);
private:
    unsigned int txtbrowserwidth;
    unsigned int txtbrowserheight;
    unsigned int treewidth;
    unsigned int treeheight;
    QStringList stringlist;
    QLabel *label;
    QString string;
    QStandardItemModel *modelData;
};

#endif // WIDGET_TREEBROWSER_H
