#ifndef HARD_GFX_H
#define HARD_GFX_H
#include <QWidget>
#include <QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include "getdata.h"
class Hard_GFX : public QWidget
{
    Q_OBJECT
public:
    Hard_GFX(QWidget *parent=0);
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

	QLabel *title_gpuName = NULL;
	QLabel *value_gpuName = NULL;

	QLabel *title_BIOSVersion = NULL;
	QLabel *value_BIOSVersion = NULL;

	QLabel *title_gpuDriverVersion = NULL;
	QLabel *value_gpuDriverVersion = NULL;

	QLabel *title_gpuBranchVersion = NULL;
	QLabel *value_gpuBranchVersion = NULL;

	QLabel *title_temprature = NULL;
	QLabel *value_temperature = NULL;

	QLabel *title_gpuClock = NULL;
	QLabel *value_gpuClock = NULL;

	QLabel *title_gpuMemoryClock = NULL;
	QLabel *value_gpuMemoryClock = NULL;

	QLabel *title_gpuUsage = NULL;
	QLabel *value_gpuUsage = NULL;

	QLabel *title_gpuFans = NULL;
	QLabel *value_gpuFans = NULL;

	QLabel *title_monitorName = NULL;
	QLabel *value_monitorName = NULL;

	QLabel *title_monitorSerialNum = NULL;
	QLabel *value_monitorSerialNum = NULL;

	QLabel *title_monitorManufacture = NULL;
	QLabel *value_monitorManufacture = NULL;

	QLabel *title_monitorDate = NULL;
	QLabel *value_monitorDate = NULL;

	QLabel *value_EDID = NULL;
private:
	GetData data;
};

#endif // HARD_GFX_H
