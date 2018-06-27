#ifndef TEST_MEMORY_H
#define TEST_MEMORY_H
#include <QWidget>
#include <QDebug>
#include <QCheckBox>
#include <QLineSeries>
#include <QCheckBox>
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
using namespace QtCharts;
class Test_Memory : public QWidget
{
    Q_OBJECT
public:
    Test_Memory(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void begin_bw();
    void testFunction(QString para_fun);
    void ifNext(int exitCode,QProcess::ExitStatus exitStatus);

    void begin_lat();
    void test_lat(QString para_stride);
    void ifNext_lat(int exitCode,QProcess::ExitStatus exitStatus);
private:
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

    QValueAxis *axisX_bw;
    QValueAxis *axisY_bw;
    double max_y_bw;
    QChart *chart_bw;
    QChartView *chartview_bw;
    QLineSeries *series_remove;

    QStringList testFunctionList;
    QStringList testParameter = {"1","2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288"};
    QStringList testResult;
    bool hyperthread_flag = false;
    unsigned int testFunNum = 0;
    unsigned int testedFunNum = 0;
    unsigned int testedSizeNum = 0;

    QProcess *process_bw ;


    QLineEdit *lineedit_stride;
    QPushButton *btn_lat_begin;

    QValueAxis *axisX_lat;
    QValueAxis *axisY_lat;
    double max_y_lat=0.0;//8
    double min_y_lat=1000.0;//8
    QChart *chart_lat;
    QLineSeries *series_remove_lat;

    QStringList testLength_lat = {"1","2","4","8","16","32","64","128","256","512","1024","2048","4096","8192","16384","32768","65536","131072","262144","524288"};
    QStringList testResult_lat;
    unsigned int testedSizeNum_lat = 0;
    QString str_stride;
};

#endif // TEST_MEMORY_H
