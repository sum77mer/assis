#ifndef TEST_CPU_H
#define TEST_CPU_H
#include <QWidget>
#include <QLabel>
#include <QProcess>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>
class Test_CPU : public QWidget
{
    Q_OBJECT
public:
    Test_CPU(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void begin();
    void testProcessFinished(int,QProcess::ExitStatus);
private:
    QLabel *label_cpuqueen = new QLabel(this);
    QLabel *label_julia = new QLabel(this);
    QLabel *label_mandel = new QLabel(this);
    QLabel *label_zlib_compress = new QLabel(this);
    QLabel *label_zlib_uncompress = new QLabel(this);
    QLabel *label_aes_decrypto = new QLabel(this);
    QLabel *label_aes_encrypto = new QLabel(this);
    QLabel *label_sna = new QLabel(this);

    QPushButton *btn_begin;
};

#endif // TEST_CPU_H
