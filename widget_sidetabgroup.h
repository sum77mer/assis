#ifndef WIDGET_SIDETABGROUP_H
#define WIDGET_SIDETABGROUP_H
#include <QWidget>
#include <QGridLayout>
#include <QSignalMapper>
#include "widget_sidetab.h"
#include <QDebug>
class Widget_sideTabGroup : public QWidget
{
    Q_OBJECT
public:
    Widget_sideTabGroup(QWidget *parent=0,QStringList string_list={"undefined","undefined"});
signals:
    void turnPage(int index);
private slots:
    void childChoosed(QString index);
protected:
    void paintEvent(QPaintEvent *event);
private:
    QGridLayout *layout=new QGridLayout;
    int tabSpacing;
    unsigned int childNum=0;
    QList<Widget_sideTab *> btnList;
    QStringList stringList;
};

#endif // WIDGET_SIDETABGROUP_H
