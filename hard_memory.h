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
#include <QEvent>
#include <QScrollBar>
#include "window_memoryaddress.h"
#include "getdata.h"
class Hard_Memory : public QWidget
{
    Q_OBJECT
public:
    Hard_Memory(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void updateData();
	void reset();
private slots:
    void setAddress();
    void getMemoryAddress(unsigned int addr);
    void tableInputing(QModelIndex);
    void tableItemChanged(QStandardItem*);
	
protected:
    void paintEvent(QPaintEvent *event);

private:
	/*
	QLabel *title_modelType = NULL;
	QLabel *value_modelType = NULL;

	QLabel *title_modelSize = NULL;
	QLabel *value_modelSize = NULL;

	QLabel *title_channel = NULL;
	QLabel *value_channel = NULL;

	QLabel *title_frequency = NULL;
	QLabel *value_frequency = NULL;

	QLabel *title_memoryFre = NULL;
	QLabel *value_memoryFre = NULL;

	QLabel *title_CASDelay = NULL;
	QLabel *value_CASDelay = NULL;

	QLabel *title_RASprecharge = NULL;
	QLabel *value_RASprecharge = NULL;

	QLabel *title_rowRefreshCycleTime = NULL;
	QLabel *value_rowRefreshCycleTime = NULL;

	QLabel *title_frontBusMemory = NULL;
	QLabel *value_frontBusMemory = NULL;

	QLabel *title_rasTOcas = NULL;
	QLabel *value_rasTOcas = NULL;

	QLabel *title_cycle = NULL;
	QLabel *value_cycle = NULL;

	QLabel *title_voltage = NULL;
	QLabel *value_voltage = NULL;
	*/
	QLabel *label = NULL;
    QStandardItemModel *model = new QStandardItemModel();
    QString lastvalue;
	bool table_changing = false;
	QList<QString> model_list;
	unsigned int begin_addr = 0x100;

	QPushButton *setAddr;
	QTableView *tableviewRW = NULL;
    Window_memoryAddress *window_memoryAddress = NULL;
	QScrollArea *scrollarea = NULL;
private:
	GetData data;
};

#endif // HARD_MEMORY_H
