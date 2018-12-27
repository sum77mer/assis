#pragma once

#include <QWidget>
#include <qvalueaxis.h>
#include <QLineEdit>
#include <QChartView>
#include <QChart>
#include <qlineseries.h>
#include <QStringList>
#include <QLabel>
#include <qmath.h>
#include <QGridLayout>
#include <qsizepolicy.h>
#include <qstring.h>
using namespace QtCharts;
class Window_memoryTest : public QWidget
{
	Q_OBJECT
public:
	Window_memoryTest(QWidget *parent = 0,QString ytitle = "default",int width = 1300,int height = 800);
	~Window_memoryTest();
	void initializeChart();//parameter
	void clearChart();
	void drawSeries(QList<double>,bool);//parameter
	void clearSeries();//parameter
public:
	QValueAxis *axisX = NULL;
	QValueAxis *axisY = NULL;
	QChart *chart = NULL;
	QChartView *chartview = NULL;
	QLineSeries *seriesDrawingNow = NULL;

	QList<QLineSeries*> seriesList;

	double maxY = 0;
private:
};
