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
class Test_Storage : public QWidget
{
    Q_OBJECT
public:
    Test_Storage(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void btnClicked();
    void updateStatus();
    void testFinished(int,QProcess::ExitStatus);
    void updateResult(QString str_test_item,bool rw_flag);
private:
    QComboBox *combobox_volumn_choose = new QComboBox(this);

    QPushButton *btn = new QPushButton(this);

    QCheckBox *checkbox_randomRW = new QCheckBox(this);
    QCheckBox *checkbox_4K = new QCheckBox(this);
    QCheckBox *checkbox_continuous = new QCheckBox(this);

    QLabel *label_random_result = new QLabel(this);
    QLabel *label_4K_result = new QLabel(this);
    QLabel *label_continuous_result = new QLabel(this);

    QLabel *label_random_live = new QLabel(this);
    QLabel *label_4K_live = new QLabel(this);
    QLabel *label_continuous_live = new QLabel(this);

    QTimer *timer = new QTimer(this);

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
