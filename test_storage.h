#ifndef TEST_STORAGE_H
#define TEST_STORAGE_H
#include <QWidget>
#include <QDebug>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QProcess>
#include <QRegExp>
#include <QMessageBox>
#include <QFile>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QPainter>
#include <QPalette>
class Test_Storage : public QWidget
{
    Q_OBJECT
public:
    Test_Storage(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void reset();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void btnClicked();
    void updateStatus();
    void testFinished(int,QProcess::ExitStatus);
    void updateResult(QString str_test_item,bool rw_flag);
	void testRandom4k();
	void test4K64();
	void testContinuous();
private:
	QLabel *title_item = NULL;
	QLabel *title_read = NULL;
	QLabel *title_write = NULL;
    QComboBox *combobox_volumn_choose = new QComboBox(this);

    QPushButton *btn = new QPushButton(this);

    QPushButton *checkbox_randomRW = new QPushButton(this);
	QPushButton *checkbox_4K = new QPushButton(this);
	QPushButton *checkbox_continuous = new QPushButton(this);

    QLabel *label_random_read = new QLabel(this);
	QLabel *label_random_write = new QLabel(this);
    QLabel *label_4K_read = new QLabel(this);
	QLabel *label_4K_write = new QLabel(this);
    QLabel *label_continuous_read = new QLabel(this);
	QLabel *label_continuous_write = new QLabel(this);


    QTimer *timer = new QTimer(this);
	bool testrandomFlag = false;
	bool testedrandomFlag = false;
	bool testthreadFlag = false;
	bool testedthreadFlag = false;
	bool testcontinuousFlag = false;
	bool testedcontinuousFlag = false;
	unsigned int testItemNum = 0;
	unsigned int testedItemNum = 0;

    bool beginflag = false;
    QProcess *process;

    double readiops_4k=0;
    double readiops_4k64=0;
    double readiops_serial=0;
    double readspeed_4k=0;
    double readspeed_4k64=0;
    double readspeed_serial=0;
    double writeiops_4k=0;
    double writeiops_4k64=0;
    double writeiops_serial=0;
    double writespeed_4k=0;
    double writespeed_4k64=0;
    double writespeed_serial=0;

    double readiops_4k_result=0;
    double readiops_4k64_result=0;
    double readiops_serial_result=0;
    double readspeed_4k_result=0;
    double readspeed_4k64_result=0;
    double readspeed_serial_result=0;
    double writeiops_4k_result=0;
    double writeiops_4k64_result=0;
    double writeiops_serial_result=0;
    double writespeed_4k_result=0;
    double writespeed_4k64_result=0;
    double writespeed_serial_result=0;
};

#endif // TEST_STORAGE_H
