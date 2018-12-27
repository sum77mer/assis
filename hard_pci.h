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
#include <QScrollBar>
#include "getdata.h"
class Hard_PCI : public QWidget
{
    Q_OBJECT
public:
    Hard_PCI(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void updateData();
	void reset();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void changeDevice(int index);
    void tableInputing(QModelIndex);
    void tableItemChanged(QStandardItem*);
private:
	QScrollArea *scrollarea = NULL;

	QTreeWidget *pciTree = NULL;
	QComboBox *select_device = NULL;
	QTableView *table_configSpace = NULL;
	QLabel *value_descriptor = NULL;
	
    QStandardItemModel *model = new QStandardItemModel();
    QString lastValue;
	QStandardItemModel *pcimodel = new QStandardItemModel();
	int currentIndex = 0;
    
	QList<QString> pci_list;
	bool table_changing = false;
	QStringList pci_cfg_now;
private:
	GetData data;
	vector<GetData::PCI_Information> pciInfo;
};

#endif // HARD_PCI_H
