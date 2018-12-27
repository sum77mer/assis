#ifndef SOFT_ZHXX_H
#define SOFT_ZHXX_H
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include "getdata.h"
class Soft_ZHXX : public QWidget
{
    Q_OBJECT
public:
    Soft_ZHXX(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void reset();
	void updateData();
protected:
    void paintEvent(QPaintEvent *event);
private:
	QScrollArea *scrollarea = NULL;
	QLabel *title_general = NULL;
	QLabel *value = NULL;
private:
	GetData data;
};

#endif // SOFT_ZHXX_H
