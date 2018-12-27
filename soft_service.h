#ifndef SOFT_SERVICE_H
#define SOFT_SERVICE_H
#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include "getdata.h"
class soft_service : public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event);
public:
	void reset();
    soft_service(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void updateData();
private:
	QScrollArea *scrollarea = NULL;
	QLabel *title = NULL;
	QLabel *value = NULL;
private:
	GetData data;
};

#endif // SOFT_SERVICE_H
