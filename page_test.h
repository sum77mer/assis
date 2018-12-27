#ifndef PAGE_TEST_H
#define PAGE_TEST_H
#include <QWidget>
#include <QDebug>
#include "widget_sidetabgroup.h"
#include "test_cpu.h"
#include "test_memory.h"
#include "test_storage.h"
#include <QStackedWidget>
class Page_test : public QWidget
{
    Q_OBJECT
public:
    Page_test(double scaleX,double scaleY, QWidget *parent=0);
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
    void outputReport();
private:
	QLabel *appVersion = NULL;
	QLabel *deviceLibrary_version = NULL;
	QFrame *frame = NULL;
    Widget_sideTabGroup *sideTabGroup;
    QStackedWidget *stackWidget;
    Test_CPU *testCPU;
    Test_Memory *testMemory;
    Test_Storage *testStorage;

    QPushButton *pbtnoutput;

	QWidget *windowReport = NULL;
	QLabel *livemessage = NULL;
	QCheckBox *hardreport_clean = NULL;
	QCheckBox *hardreport_specific = NULL;
	QCheckBox *softreport_clean = NULL;
	QCheckBox *softreport_specific = NULL;
	QCheckBox *reportCPUtest = NULL;
	QCheckBox *reportMemorytest = NULL;
	QCheckBox *reportDisktest = NULL;

	QColor lineColor = QColor(200, 200, 200);//darkgray
	QColor frameColor = QColor(240, 240, 240);//lightgray
	double scaleX;
	double scaleY;
	QFrame *bottomframe = NULL;
	int bottomFrame_height = 28;
	QColor bottomlineColor = QColor(255, 0, 0);
	QString bottomframeColor = QString("QFrame{background-color:rgb(245,245,245);border-top-color:rgb(200,200,200);border-width:1px;border-color:rgb(200,200,200);border-style:solid}");
};

#endif // PAGE_TEST_H
