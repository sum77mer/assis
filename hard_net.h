#ifndef HARD_NET_H
#define HARD_NET_H
#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include"getdata.h"
class Hard_Net : public QWidget
{
    Q_OBJECT
public:
    Hard_Net(QWidget *parent=0);
	void initializeUI();
	void initializeData();
	void setupLayout();
	void setConnection();
	void updateData();
	void reset();
protected:
    void paintEvent(QPaintEvent *event);

private:
	QScrollArea *scrollarea = NULL;
	QLabel *value_net = NULL;
private:
	GetData data;

};

#endif // HARD_NET_H
