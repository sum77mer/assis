#ifndef HARD_PCI_H
#define HARD_PCI_H
#include <QWidget>
#include <QPainter>
#include <QScrollArea>
#include <QGridLayout>
#include <QTreeWidget>
#include <QComboBox>
#include <QLabel>
#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>
#include <QDebug>
class Hard_PCI : public QWidget
{
    Q_OBJECT
public:
    Hard_PCI(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void changeDevice(int index);
    void tableInputing(QModelIndex);
    void tableItemChanged(QStandardItem*);
private:
    QStandardItemModel *model = new QStandardItemModel();
    QString lastValue;
    QComboBox *combobox_device;
};

#endif // HARD_PCI_H
