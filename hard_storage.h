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
#include <QScrollBar>
#include "getdata.h"
class Hard_Storage : public QWidget
{
    Q_OBJECT
public:
    Hard_Storage(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void updateData();
	void reset();
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
	QScrollArea *scrollarea = NULL;

	QLabel *value_disk = NULL;
	QLabel *title_select = NULL;
	QComboBox *selectDisk_RW = NULL;
	QTableView * tableview_identify = NULL;
	QStandardItemModel *model1 = new QStandardItemModel();

	QLabel *title_LBA = NULL;
	QComboBox *combobox_RWdisk;
	QLineEdit *lineedit_lba = NULL;
	QPushButton *btn_RWok = NULL;
    QTableView *tableviewRW = NULL;
	QStandardItemModel *model2 = new QStandardItemModel();
	QLabel *titleUSB = NULL;
	QLabel *valueVersion = NULL;
	QLabel *valueDate = NULL;

    QString identify_lastValue;
    
    QString rw_lastValue;
private:
	GetData data;
};

#endif // HARD_STORAGE_H
