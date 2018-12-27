#include "Window_memoryTest.h"

Window_memoryTest::Window_memoryTest(QWidget *parent,QString ytitle,int width,int height)
	: QWidget(parent)
{
	setWindowFlags(Qt::Window|Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint);
	initializeChart();
	QFont title_font("Arial", 15, QFont::Normal);
	QFont item_font("Arial", 12, QFont::Normal);
	axisX = new QValueAxis;
	const unsigned int min = 512;
	const unsigned int max = 256 * qPow(2, 20);
	const unsigned int base = 2;
	axisX->setRange(0, qLn(max / min) / qLn(base));
	axisX->setTickCount(20);
	axisX->setLabelsFont(item_font);
	axisX->setTitleFont(title_font);
	axisX->setTitleVisible(true);
	axisX->setTitleText(QString("Length(*512KB)"));
	axisX->setLabelFormat("2^%u");

	axisY = new QValueAxis;
	axisY->setLabelsFont(item_font);
	axisY->setTitleVisible(true);
	axisY->setTitleText(ytitle);//
	axisY->setTitleFont(title_font);
	axisY->setRange(0, 300);

	chart = new QChart();
	//chart_bw->addSeries(series_bw);
	chart->setMargins(QMargins(50, 50, 50, 50));
	chart->setWindowTitle(QString("BandWidth Test"));
	chart->setAutoFillBackground(true);
	chart->setBackgroundVisible(true);
	chart->setAxisX(axisX);
	chart->setAxisY(axisY);

	//QLabel *label_chart = new QLabel(this);
	//label_chart->setText(QString("512B*"));
	//label_chart->setFrameStyle(QFrame::NoFrame);

	chartview = new QChartView(this);
	//chartview->setFixedSize(1300, 400);
	//chartview->setSizePolicy(QSizePolicy::GrowFlag);
	chartview->setMinimumSize(width, height);
	
	chartview->setChart(chart);

	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(chartview, 0, 0, 1, 1);

	this->setLayout(layout);
	//connect(this, SIGNAL(close()), this, SLOT());
	
}

Window_memoryTest::~Window_memoryTest()
{
}
void Window_memoryTest::initializeChart()
{
	

	
}
void Window_memoryTest::clearChart()
{
	chart->removeAllSeries();
}
void Window_memoryTest::clearSeries()
{
}
void Window_memoryTest::drawSeries(QList<double> testResult,bool newflag)
{
	if (testResult.length() > 1)
		chart->removeSeries(seriesDrawingNow);
	seriesDrawingNow = new QLineSeries(this);
	if (maxY<testResult.at(testResult.length()-1) )
	{
		maxY = testResult.at(testResult.length() - 1);
		axisY->setRange(0, maxY + 100);
	}
	QFont item_font("Arial", 12, QFont::Normal);
	seriesDrawingNow->setPointsVisible(true);
	seriesDrawingNow->setPointLabelsVisible(true);
	seriesDrawingNow->setPointLabelsClipping(false);
	seriesDrawingNow->setPointLabelsFont(item_font);
	seriesDrawingNow->setPointLabelsFormat("[@yPoint G/s]");
	for (unsigned int i = 0; i < testResult.length(); i++)
	{
		seriesDrawingNow->append(i, testResult.at(i));
	}
	
	chart->addSeries(seriesDrawingNow);
	seriesDrawingNow->attachAxis(axisX);
	seriesDrawingNow->attachAxis(axisY);
	
	update();
	if (testResult.length() == 20)
	{
		seriesList.append(seriesDrawingNow);
		//delete seriesDrawingNow;
		//seriesDrawingNow = NULL;
	}	
}
