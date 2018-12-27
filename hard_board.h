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
#include <QScrollBar>
#include "window_iobase.h"
#include "window_ioindex.h"
#include "window_sio.h"
#include "getData.h"
class Hard_Board : public QWidget
{
    Q_OBJECT
public:
    Hard_Board(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void updateData();
	void reset();
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
	QScrollArea *scrollarea = NULL;
	QLabel *boardLabel = NULL;
	QLabel *chipsetLabel = NULL;
    QLabel *biosLabel = NULL;

	QLabel *title_IOBase = NULL;
	QPushButton *btnIOBase = NULL;
	QTableView *tableIOBase = NULL;
	QStandardItemModel *modelIOBase = new QStandardItemModel();//iobase

	QLabel *title_IOIndex = NULL;
	QPushButton *btnIndex = NULL;
	QPushButton *btnIndexKey = NULL;
	QTableView *tableIOIndex = NULL;
	QStandardItemModel *modelIndex = new QStandardItemModel();//ioindex

	QLabel *title_SIO = NULL;
	QPushButton *btnSIO = NULL;
	QPushButton *btnSIOKey = NULL;
    QComboBox *combobox_SIO_device = NULL;
	QStandardItemModel *modelSIO = new QStandardItemModel();//sio
	QTableView *tableSIO = NULL;

	Widget_TreeBrowser *treeBrowser = NULL;
    
	QList<QString> model3_list;
	QList<QString> model2_list;
	QList<QString> model1_list;
    QString iobase_lastvalue;
    QString ioindex_lastvalue;
    QString sio_lastvalue;
	bool table_changing = false;
	unsigned int index_addr;
	unsigned int data_addr;

    Window_IOBase *window_IOBase = NULL;
    Window_IOIndex *window_IOIndex = NULL;
    Window_SIO *window_SIO = NULL;

	unsigned int io_base_address;
	unsigned int io_index;
	unsigned int io_data;
	unsigned int sio_index;
	unsigned int sio_data;
private:
	GetData data;
	unsigned int IOBaseaddr = 0x2e;
	unsigned int IOindexaddr = 0x2e;
	unsigned int IOdataaddr = 0x2f;
	unsigned int SIOindexaddr = 0x2e;
	unsigned int SIOdataaddr = 0x2f;
};

#endif // HARD_BOARD_H
