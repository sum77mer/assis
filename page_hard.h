#ifndef PAGE_HARD_H
#define PAGE_HARD_H
#include <QWidget>
#include <QDebug>
#include "widget_sidetabgroup.h"
#include <QStackedWidget>
#include "hard_zhxx.h"
#include "hard_board.h"
#include "hard_cpu.h"
#include "hard_memory.h"
#include "hard_pci.h"
#include "hard_storage.h"
#include "hard_gfx.h"
#include "hard_net.h"
#include "hard_other.h"
#include <QPushButton>
#include <QList>
#include <QProcess>
class Page_hard : public QWidget
{
    Q_OBJECT
public:
    Page_hard(double scaleX, double scaleY, QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void reset();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void turnPage(int index);
    void reportWindow();
    void onAutoRefresh();
    void onManualRefresh();
    void onoutputReportBtn();
    void Compare();
	void updatePage();
	void outputReport();
	void updateLive(QString s);
private:
	QWidget *windowOutputReport = NULL;
	QLabel *livemessage = NULL;
	QCheckBox *hardreport_clean = NULL;
	QCheckBox *hardreport_specific = NULL;
	QCheckBox *softreport_clean = NULL;
	QCheckBox *softreport_specific = NULL;
	QCheckBox *testCPU = NULL;
	QCheckBox *testMemory = NULL;
	QCheckBox *testDisk = NULL;
	QFrame *frame = NULL;
    Widget_sideTabGroup *sideTabGroup;
    QStackedWidget *stackWidget;
    Hard_ZHXX *hardZHXX;
    Hard_Board *hardBoard;
    Hard_CPU *hardCPU;
    Hard_Memory *hardMemory;
    Hard_GFX *hardGFX;
    Hard_PCI *hardPCI;
    Hard_Storage *hardStorage;
    Hard_Net *hardNet;
    Hard_Other *hardOther;

	QLabel *appVersion = NULL;
	QLabel *deviceLibrary_version = NULL;

    QPushButton *pbtnautofresh;
    QPushButton *pbtnfresh;
    QPushButton *pbtnoutput;
    QPushButton *pbtncompare;
    bool autorefreshflag=true;

    struct Disk_info{
        QString dir;
        QStringList file_list;
    };
    QList<Disk_info> diskinfo_list;
	struct PCI_info {
		unsigned long bus;
		unsigned long dev;
		unsigned long fun;
		unsigned long address;
	};
	QList<PCI_info> pciinfo_list;

	QColor lineColor = QColor(200, 200, 200);//darkgray
	QString frameColor = QString("background-color:rgb(245,245,245)");

	double scaleX;
	double scaleY;

	QFrame *bottomframe = NULL;
	int bottomFrame_height = 28;
	QColor bottomlineColor = QColor(255, 0, 0);
	QString bottomframeColor = QString("QFrame{background-color:rgb(245,245,245);border-top-color:rgb(200,200,200);border-width:1px;border-color:rgb(200,200,200);border-style:solid}");

	QTimer *timer = new QTimer(this);
};

#endif // PAGE_HARD_H
