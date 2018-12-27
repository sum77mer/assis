#ifndef SOFT_TRANSMISSION_H
#define SOFT_TRANSMISSION_H
#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include "getdata.h"
class soft_transmission : public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event);
public:
    soft_transmission(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void reset();
	void updateData();
private:
	QScrollArea *scrollarea = NULL;
	QLabel *title = NULL;
	QLabel *tcpValue = NULL;
	QLabel *udpValue = NULL;
private:
	GetData data;
};

#endif // SOFT_TRANSMISSION_H
