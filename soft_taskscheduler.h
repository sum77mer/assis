#ifndef SOFT_TASKSCHEDULER_H
#define SOFT_TASKSCHEDULER_H
#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include "getdata.h"
class soft_taskscheduler : public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event);
public:
    soft_taskscheduler(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void reset();
	void updateData();
private:
	QScrollArea *scrollarea = NULL;
	QLabel *title = NULL;
	QLabel *folderValue = NULL;
	QLabel *runningValue = NULL;
private:
	GetData data;
};

#endif // SOFT_TASKSCHEDULER_H
