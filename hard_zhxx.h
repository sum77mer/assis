#ifndef HARD_ZHXX_H
#define HARD_ZHXX_H
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QFormLayout>
#include <QScrollArea>
#include <QScrollBar>
#include<QString>
#include "getdata.h"
class Hard_ZHXX : public QWidget
{
    Q_OBJECT
public:
    Hard_ZHXX(QWidget *parent=0);
	void initializeUI();
	void setCPU(QString s);
	void setGPU(QString s);
	void setMemory(QString s);
	void setBoard(QString s);
	void setDisk(QString s);
	void initializeData();
	void setupLayout();
	void setConnection();
	void updateData();
	void reset();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
	QScrollArea *scrollarea = NULL;

	QLabel *title_generalInformation = NULL;

	QLabel *title_cpu = NULL;
	QLabel *value_cpu = NULL;
	QLabel *title_gpu = NULL;
	QLabel *value_gpu = NULL;
	QLabel *title_memory = NULL;
	QLabel *value_memory = NULL;
	QLabel *title_board = NULL;
	QLabel *value_board = NULL;
	QLabel *title_disk = NULL;
	QLabel *value_disk = NULL;

    QLabel *picLabel;
private:
	//GetData data;
	const QString titleString = QStringLiteral("Ӳ������");
	const QString titleCPUString = QStringLiteral("CPU");
	const QString titleGPUString = QStringLiteral("GPU");
	const QString titleMemoryString = QStringLiteral("Memory");
	const QString titleBoardString = QStringLiteral("Board");
	const QString titleDiskString = QStringLiteral("Disk");
	QString valueCPUString;
	QString valueGPUString;
	QString valueMemoryString;
	QString valueBoardString;
	QString valueDiskString;

};

#endif // HARD_ZHXX_H
