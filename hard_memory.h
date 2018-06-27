#ifndef HARD_MEMORY_H
#define HARD_MEMORY_H
#include <QWidget>
#include <QPainter>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QScrollArea>
#include <QTextEdit>
#include <QLineEdit>
#include <QRegExp>
#include <QDebug>
#include "window_memoryaddress.h"
class Hard_Memory : public QWidget
{
    Q_OBJECT
public:
    Hard_Memory(QWidget *parent=0);
private slots:
    void setAddress();
    void getMemoryAddress(unsigned int addr);
    void tableInputing(QModelIndex);
    void tableItemChanged(QStandardItem*);
protected:
    void paintEvent(QPaintEvent *event);

private:
    QStandardItemModel *model = new QStandardItemModel();
    QString lastvalue;

    Window_memoryAddress *window_memoryAddress;
};

#endif // HARD_MEMORY_H
