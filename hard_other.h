#ifndef HARD_OTHER_H
#define HARD_OTHER_H
#include <QWidget>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include "getdata.h"
class Hard_Other : public QWidget
{
    Q_OBJECT
public:
    Hard_Other(QWidget *parent=0);
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

	QLabel *value_audio = NULL;
	GetData data;
};

#endif // HARD_OTHER_H
