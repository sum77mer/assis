#ifndef PAGE_SOFT_H
#define PAGE_SOFT_H
#include <QWidget>
#include <QDebug>
#include "widget_sidetabgroup.h"
#include "soft_zhxx.h"
#include "soft_config.h"
#include "soft_autoboot.h"
#include "soft_service.h"
#include "soft_taskscheduler.h"
#include "soft_transmission.h"
#include <QStackedWidget>
#include <QTimer>
class Page_soft : public QWidget
{
    Q_OBJECT
public:
    Page_soft(double scaleX, double scaleY, QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void reset();
protected:
    void paintEvent(QPaintEvent *event);
private:
	void updatePage();
private slots:
    void turnPage(int index);
    void reportWindow();
    void onAutoRefresh();
    void onManualRefresh();
    void outputReport();
private:
	QFrame *frame = NULL;
    Widget_sideTabGroup *sideTabGroup;
    QStackedWidget *stackWidget;
    Soft_ZHXX *softZHXX;
    Soft_Config *softConfig;
    soft_autoboot *softAutoBoot;
    soft_service *softService;
    soft_taskscheduler *softTaskScheduler;
    soft_transmission *softTranmission;

	QLabel *appVersion = NULL;
	QLabel *deviceLibrary_version = NULL;

    QPushButton *pbtnautofresh;
    QPushButton *pbtnfresh;
    QPushButton *pbtnoutput;

	QWidget *windowReport = NULL;
	QLabel *livemessage = NULL;
	QCheckBox *hardreport_clean = NULL;
	QCheckBox *hardreport_specific = NULL;
	QCheckBox *softreport_clean = NULL;
	QCheckBox *softreport_specific = NULL;
	QCheckBox *testCPU = NULL;
	QCheckBox *testMemory = NULL;
	QCheckBox *testDisk = NULL;

	QColor lineColor = QColor(200, 200, 200);//darkgray
	QColor frameColor = QColor(240, 240, 240);

	double scaleX;
	double scaleY;
	QFrame *bottomframe = NULL;
	int bottomFrame_height = 28;
	QColor bottomlineColor = QColor(255, 0, 0);
	QString bottomframeColor = QString("QFrame{background-color:rgb(245,245,245);border-top-color:rgb(200,200,200);border-width:1px;border-color:rgb(200,200,200);border-style:solid}");

	QTimer *timer = new QTimer(this);
	bool autorefreshflag = true;
};

#endif // PAGE_SOFT_H
