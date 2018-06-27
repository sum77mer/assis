#ifndef HARD_BOARD_H
#define HARD_BOARD_H
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPainter>
#include <QLabel>
#include <QGridLayout>
#include <QDesktopServices>
#include <QUrl>
#include <QMouseEvent>
#include <QGroupBox>
#include <QScrollArea>
#include <QPushButton>
#include <QTableView>
#include <QHeaderView>
#include <QModelIndex>
#include <QComboBox>
#include <QSizePolicy>
#include "widget_treebrowser.h"
#include <QTextEdit>
#include <QCheckBox>
#include <QLineEdit>
#include <QRegExp>
#include <QVariant>
#include <QMessageBox>
#include "window_iobase.h"
#include "window_ioindex.h"
#include "window_sio.h"
#include "libheaders/smbioslib.h"
#include "smbiostextbrowser.h"
#include "smbiostreewidget.h"
using namespace SV_ASSIST::DMI_SMBIOS;
class Hard_Board : public QWidget
{
    Q_OBJECT
public:
    Hard_Board(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void setIOBase();
    void getIOBase(unsigned int addr,bool acpi_flag);

    void setIOIndex();
    void getIOIndex(unsigned int index, unsigned int data);

    //void setIOIndexKey();
    void setSuperIOAddress();
    void getSIOAddress(unsigned int index,unsigned int data);
    void changdeSIODevice(int index);

    void tableIOBaseInputing(QModelIndex);
    void tableIOBaseItemChanged(QStandardItem*);
    void tableIOIndexInputing(QModelIndex);
    void tableIOIndexItemChanged(QStandardItem*);
    void tableSIOInputing(QModelIndex);
    void tableSIOItemChanged(QStandardItem*);
private:
    QLabel *boardLabel;
    QLabel *chipsetLabel;
    QLabel *biosLabel;

    QComboBox *combobox_SIO_device;

    QStandardItemModel *model3 = new QStandardItemModel();//iobase
    QStandardItemModel *model1 = new QStandardItemModel();//ioindex
    QStandardItemModel *model2 = new QStandardItemModel();//sio
    QString iobase_lastvalue;
    QString ioindex_lastvalue;
    QString sio_lastvalue;

    Window_IOBase *window_IOBase;
    Window_IOIndex *window_IOIndex;
    Window_SIO *window_SIO;
};

#endif // HARD_BOARD_H
