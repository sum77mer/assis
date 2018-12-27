#ifndef TEST_CPU_H
#define TEST_CPU_H
#include <QWidget>
#include <QLabel>
#include <QProcess>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>
#include <qpainter.h>
class Test_CPU : public QWidget
{
    Q_OBJECT
public:
    Test_CPU(QWidget *parent = 0);
	void initializeUI();
	void setupLayout();
	void initializeData();
	void setConnection();
	void reset();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void begin();
    void testProcessFinished(int,QProcess::ExitStatus);
private:
	QLabel *title_branch = NULL;
	QLabel *title_float = NULL;
	QLabel *title_dataStream = NULL;

	QLabel *title_cpuqueen = NULL;
	QLabel *title_julia = NULL;
	QLabel *title_mandel = NULL;
	QLabel *title_zlibCompress = NULL;
	QLabel *title_zlibUncompress = NULL;
	QLabel *title_aesDecrypto = NULL;
	QLabel *title_aesEncrypto = NULL;
	QLabel *title_sna = NULL;

	QLabel *value_cpuqueen = NULL;
	QLabel *value_julia = NULL;
	QLabel *value_mandel = NULL;
	QLabel *value_zlibCompress = NULL;
	QLabel *value_zlibUncompress = NULL;
	QLabel *value_aesDecrypto = NULL;
	QLabel *value_aesEncrypto = NULL;
	QLabel *value_sna = NULL;

    QPushButton *btn_begin;
	bool beginflag = false;
	QProcess *process;
private:
	QString resultStyleSheet1 = QString("QLabel{background-color:rgba(130, 2, 6, 30%)}");
	QString resultStyleSheet2 = QString("QLabel{background-color:rgba(100, 2, 6, 15%)}");
};

#endif // TEST_CPU_H
