#ifndef TEST_MEMORY_H
#define TEST_MEMORY_H
#include <QWidget>
#include <QDebug>
#include <QCheckBox>
#include <QLineSeries>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QChartView>
#include <QChart>
#include <QValueAxis>
#include <QtCore/qmath.h>
#include <QFont>
#include <QProcess>
#include <QMessageBox>
#include <QFile>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QScrollArea>
#include <QScrollBar>
#include "Window_memoryTest.h"
using namespace QtCharts;
class Test_Memory : public QWidget
{
    Q_OBJECT
public:
    Test_Memory(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void reset();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void begin_bw();
    void testFunction(QString para_fun);
    void ifNext(int exitCode,QProcess::ExitStatus exitStatus);
	void openBWchartWindow();

    void begin_lat();
    void test_lat(QString para_stride);
    void ifNext_lat(int exitCode,QProcess::ExitStatus exitStatus);
	void openLATchartWindow();
private:
	QLabel *label_bwtest_title = NULL;
	QLabel *label_function_title = NULL;
	QLabel *label_hyperthread_title = NULL;
	QLabel *label_lattest_title = NULL;
	QLabel *label_stride_title = NULL;
	QScrollArea *scrollarea = NULL;
    QCheckBox *checkbox_fun_ReaderSSE2;
    QCheckBox *checkbox_fun_WriterSSE2;
    QCheckBox *checkbox_fun_CopySSE;
    QCheckBox *checkbox_fun_WriterSSE2_bypass;
    QCheckBox *checkbox_fun_CopySSE_bypass;
    QCheckBox *checkbox_fun_ReaderAVX;
    QCheckBox *checkbox_fun_WriterAVX;
    QCheckBox *checkbox_fun_CopyAVX;

    QCheckBox *checkbox_hyperthread;

    QPushButton *btn_bw_begin;
	QPushButton *btn_openBWChartWindow;
	QPushButton *btn_openLATChartWindow;

	Window_memoryTest *memoryBWTestWindow = NULL;
	Window_memoryTest *memoryLATTestWindow = NULL;

	QList<QLabel*> bwResult;
	QList<QLabel*> latResult;
	QLabel *bwResult_512B_title = NULL;
	QLabel *bwResult_1KB_title = NULL;
	QLabel *bwResult_2KB_title = NULL;
	QLabel *bwResult_4KB_title = NULL;
	QLabel *bwResult_8KB_title = NULL;
	QLabel *bwResult_16KB_title = NULL;
	QLabel *bwResult_32KB_title = NULL;
	QLabel *bwResult_64KB_title = NULL;
	QLabel *bwResult_128KB_title = NULL;
	QLabel *bwResult_256KB_title = NULL;
	QLabel *bwResult_512KB_title = NULL;
	QLabel *bwResult_1MB_title = NULL;
	QLabel *bwResult_2MB_title = NULL;
	QLabel *bwResult_4MB_title = NULL;
	QLabel *bwResult_8MB_title = NULL;
	QLabel *bwResult_16MB_title = NULL;
	QLabel *bwResult_32MB_title = NULL;
	QLabel *bwResult_64MB_title = NULL;
	QLabel *bwResult_128MB_title = NULL;
	QLabel *bwResult_256MB_title = NULL;

	

	//QLabel *latResult = NULL;
	QLabel *latResult_512B_title = NULL;
	QLabel *latResult_1KB_title = NULL;
	QLabel *latResult_2KB_title = NULL;
	QLabel *latResult_4KB_title = NULL;
	QLabel *latResult_8KB_title = NULL;
	QLabel *latResult_16KB_title = NULL;
	QLabel *latResult_32KB_title = NULL;
	QLabel *latResult_64KB_title = NULL;
	QLabel *latResult_128KB_title = NULL;
	QLabel *latResult_256KB_title = NULL;
	QLabel *latResult_512KB_title = NULL;
	QLabel *latResult_1MB_title = NULL;
	QLabel *latResult_2MB_title = NULL;
	QLabel *latResult_4MB_title = NULL;
	QLabel *latResult_8MB_title = NULL;
	QLabel *latResult_16MB_title = NULL;
	QLabel *latResult_32MB_title = NULL;
	QLabel *latResult_64MB_title = NULL;
	QLabel *latResult_128MB_title = NULL;
	QLabel *latResult_256MB_title = NULL;

	

    double max_y_bw;

    QStringList testFunctionList;
    QStringList testParameter = {"1","2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288"};
    QStringList testResult;
    bool hyperthread_flag = false;
    unsigned int testFunNum = 0;
    unsigned int testedFunNum = 0;
    unsigned int testedSizeNum = 0;

    QProcess *process_bw ;
	bool beginflag1 = false;
	bool beginflag2 = false;
	QProcess *process_lat;

    QLineEdit *lineedit_stride;
    QPushButton *btn_lat_begin;

    double max_y_lat=0.0;//8
    double min_y_lat=1000.0;//8

    QStringList testLength_lat = {"1","2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288"};
    QStringList testResult_lat;
    unsigned int testedSizeNum_lat = 0;
    QString str_stride;
	QList<double> bwtestResults;
	QList<double> lattestResults;

	QString resultStyleSheet1 = QString("QLabel{background-color:rgba(130, 2, 6, 30%)}");
	QString resultStyleSheet2 = QString("QLabel{background-color:rgba(100, 2, 6, 15%)}");

	bool bw_chartWindow = false;
	bool lat_chartWindow = false;
};

#endif // TEST_MEMORY_H
