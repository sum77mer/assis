#ifndef HARD_STORAGE_H
#define HARD_STORAGE_H
#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QBrush>
#include <QScrollArea>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>
#include <QTextEdit>
#include <QLineEdit>
#include <QRegExp>
#include <QPushButton>
#include <QDebug>
class Hard_Storage : public QWidget
{
    Q_OBJECT
public:
    Hard_Storage(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void changeIdentifyDisk(int index);
    void setRWAddress();
    void identifyTableInputing(QModelIndex);
    void identifyTableItemChanged(QStandardItem*);
    void rwTableInputing(QModelIndex);
    void rwTableItemChanged(QStandardItem*);
private:
    QTableView *tableview2 = new QTableView(this);

    QString identify_lastValue;
    QStandardItemModel *model1 = new QStandardItemModel();
    QString rw_lastValue;
    QStandardItemModel *model2 = new QStandardItemModel();

    QComboBox *combobox_RWdisk;
    QLineEdit *lineedit_lba;
};

#endif // HARD_STORAGE_H
