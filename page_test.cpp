#include "page_test.h"
#include <QPushButton>
#include <QPalette>
#include <QCheckBox>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <qtextcodec.h>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QProcess>
#include <QDateTime>
#include "getdata.h"
#include"UIconst.h"
Page_test::Page_test(double scaleX, double scaleY, QWidget *parent)
{
	this->scaleX = scaleX;
	this->scaleY = scaleY;
	setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Page_test::paintEvent(QPaintEvent *event)
{
	QRect lineRect = frame->rect();
	lineRect.setX(frame->width());
	lineRect.setWidth(1);
	QPainter painter(this);
	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(lineColor);
	painter.setBrush(brush);
	painter.setPen(Qt::NoPen);
	painter.drawRect(lineRect);
}
void Page_test::initializeUI()
{
	bottomFrame_height *= scaleX;
	appVersion = new QLabel(this);
	appVersion->setFrameStyle(QFrame::NoFrame);
	appVersion->setFont(enNormalFont);
	appVersion->setStyleSheet("QLabel{border:0px;color:rgb(100,100,100)}");
	QTextCodec *codec = QTextCodec::codecForName("GB18030");
	appVersion->setText(codec->toUnicode("主程序版本：0.0.0.0"));

	deviceLibrary_version = new QLabel(this);
	deviceLibrary_version->setFrameStyle(QFrame::NoFrame);
	deviceLibrary_version->setFont(enNormalFont);
	deviceLibrary_version->setStyleSheet("QLabel{border:0px;color:rgb(100,100,100)}");
	deviceLibrary_version->setText(codec->toUnicode("主设备库版本：0.0.0.0"));

	bottomframe = new QFrame(this);
	bottomframe->setFrameStyle(QFrame::NoFrame);
	//bottomframe->setPalette(palette);
	bottomframe->setStyleSheet(bottomframeColor);
	bottomframe->setFixedHeight(bottomFrame_height);

	frame = new QFrame(this);
	frame->setFrameStyle(QFrame::NoFrame);
	frame->setAutoFillBackground(true);
	frame->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	frame->setStyleSheet(QString("background-color:rgb(245,245,245)"));
	QStringList stringlist;
	stringlist << "CPU" << "Memory" << "Disk";
	sideTabGroup = new Widget_sideTabGroup(frame, stringlist);
	pbtnoutput = new QPushButton(codec->toUnicode("输出报告"), frame);
	pbtnoutput->setFont(enNormalFont);
	pbtnoutput->setStyleSheet(QString("QPushButton{background-origin:margin;margin:0px 0px 0px 0px;padding:3px 10px 3px 10px;background-origin:margin;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white, stop : 0.2 #cccccc, stop : 1 #aaaaaa);border-radius:2px;color:white;border:1px solid #888888}"));

	testCPU = new Test_CPU(this);
	testMemory = new Test_Memory(this);
	testStorage = new Test_Storage(this);
}
void Page_test::setupLayout()
{
	QGridLayout *tablayout = new QGridLayout;
	tablayout->setSpacing(0);
	tablayout->setContentsMargins(0, 0, 0, 0);
	tablayout->setRowStretch(0, 1);
	tablayout->setRowStretch(1, 0);
	tablayout->setRowStretch(2, 0);
	tablayout->setColumnMinimumWidth(0, 20);
	tablayout->setColumnMinimumWidth(2, 20);
	tablayout->addWidget(sideTabGroup, 0, 0, 1, 3);
	tablayout->addWidget(pbtnoutput, 1, 1);
	tablayout->setRowMinimumHeight(2, 20);

	frame->setLayout(tablayout);

	stackWidget = new QStackedWidget();
	QPalette palette;
	palette.setBrush(QPalette::Window, QBrush(Qt::transparent));
	stackWidget->setPalette(palette);
	stackWidget->setAutoFillBackground(true);

	stackWidget->addWidget(testCPU);
	stackWidget->addWidget(testMemory);
	stackWidget->addWidget(testStorage);

	QGridLayout *bottomframe_layout = new QGridLayout;
	bottomframe_layout->setVerticalSpacing(10);
	bottomframe_layout->setContentsMargins(20, 5, 20, 5);
	bottomframe_layout->addWidget(appVersion, 0, 0);
	bottomframe_layout->addWidget(deviceLibrary_version, 0, 1);
	bottomframe->setLayout(bottomframe_layout);

	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	layout->setColumnStretch(0, 0);
	layout->setColumnStretch(1, 1);
	layout->addWidget(frame, 0, 0);
	layout->addWidget(stackWidget, 0, 1);
	layout->addWidget(bottomframe, 1, 0, 1, 2);
	setLayout(layout);
}
void Page_test::setConnection()
{
	connect(pbtnoutput, SIGNAL(clicked(bool)), this, SLOT(reportWindow()));
	connect(sideTabGroup, SIGNAL(turnPage(int)), this, SLOT(turnPage(int)));
}
void Page_test::initializeData()
{}
void Page_test::turnPage(int index)
{
	switch (index)
	{
	case 0:
	{
		stackWidget->setCurrentWidget(testCPU);
		testMemory->reset();
		testStorage->reset();
		break;
	}
	case 1:
	{
		stackWidget->setCurrentWidget(testMemory);
		testCPU->reset();
		testStorage->reset();
		break;
	}
	case 2:
	{
		stackWidget->setCurrentWidget(testStorage);
		testCPU->reset();
		testMemory->reset();
		break;
	}
	default:
	{
		stackWidget->setCurrentWidget(testCPU);
		testMemory->reset();
		testStorage->reset();
		break;
	}
	}
}
void Page_test::reportWindow()
{
	QLabel *label1 = new QLabel(this);
	label1->setFrameStyle(QFrame::NoFrame);
	label1->setText(QString("Hardware report"));
	hardreport_clean = new QCheckBox(this);
	hardreport_clean->setText(QString("clean"));
	hardreport_specific = new QCheckBox(this);
	hardreport_specific->setText(QString("specific"));

	QLabel *label2 = new QLabel(this);
	label2->setFrameStyle(QFrame::NoFrame);
	label2->setText(QString("software report"));
	softreport_clean = new QCheckBox(this);
	softreport_clean->setText(QString("clean"));
	softreport_specific = new QCheckBox(this);
	softreport_specific->setText(QString("specific"));

	QLabel *label3 = new QLabel(this);
	label3->setText(QString("test"));
	reportCPUtest = new QCheckBox(this);
	reportCPUtest->setText(QString("CPU"));
	reportMemorytest = new QCheckBox(this);
	reportMemorytest->setText(QString("Memory"));
	reportDisktest = new QCheckBox(this);
	reportDisktest->setText(QString("Disk"));

	QPushButton *btn = new QPushButton(this);
	btn->setText(QString("output"));

	connect(btn, SIGNAL(clicked(bool)), this, SLOT(outputReport()));

	livemessage = new QLabel(this);
	livemessage->setFrameStyle(QFrame::NoFrame);
	livemessage->setText("default");

	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(10, 20, 10, 10);
	layout->setColumnStretch(0, 0);
	layout->setColumnStretch(1, 0);
	layout->setColumnStretch(2, 0);
	layout->setColumnStretch(3, 1);
	layout->addWidget(label1, 0, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(hardreport_clean, 0, 1, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(hardreport_specific, 0, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(label2, 1, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(softreport_clean, 1, 1, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(softreport_specific, 1, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(label3, 2, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(reportCPUtest, 2, 1, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(reportMemorytest, 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(reportDisktest, 2, 3, 1, 1, Qt::AlignLeft | Qt::AlignTop);
	layout->addWidget(btn, 3, 0, 1, 4, Qt::AlignHCenter | Qt::AlignTop);

	windowReport = new QWidget(this);
	windowReport->setWindowFlags(Qt::Window);
	windowReport->setLayout(layout);
	windowReport->setMinimumSize(200, 100);
	windowReport->show();
}
void Page_test::outputReport()
{
	if (hardreport_clean->isChecked() || hardreport_specific->isChecked() || softreport_clean->isChecked() || softreport_specific->isChecked() || reportCPUtest->isChecked() || reportMemorytest->isChecked() || reportDisktest->isChecked())
	{
		QDateTime time = QDateTime::currentDateTime();
		QFile *file = new QFile("./SVASSIST_report.txt");
		file->open(QIODevice::WriteOnly | QIODevice::Truncate);
		QTextStream  out(file);
		out.setFieldAlignment(QTextStream::AlignLeft);
		out << qSetFieldWidth(20) << left << "SV_ASSISTANT Report"
			<< qSetFieldWidth(30) << left << "v0.0.0"
			<< qSetFieldWidth(50) << right << time.toString()
			<< qSetFieldWidth(0) << "\r\n"
			<< qSetFieldWidth(100) << left << "--------------------------------------------------------------------------------------------------------"
			<< qSetFieldWidth(0) << "\r\n";
		out.flush();
		file->close();

		if (hardreport_clean->isChecked())
		{
			file->open(QIODevice::WriteOnly | QIODevice::Append);
			QTextStream  out(file);
			out << qSetFieldWidth(100) << left << "Hardware Report Clean"
				<< qSetFieldWidth(0) << "\r\n" << "--------------------------------------------------------------------------------------------------------"
				<< qSetFieldWidth(0) << "\r\n";
			GetData data;
			data.outputHardwareReportClean(out);
			file->close();
		}
		else if (hardreport_specific->isChecked())
		{
			QTextStream out(file);
			file->open(QIODevice::WriteOnly | QIODevice::Append);
			out << qSetFieldWidth(100) << left << "Hardware Report Specific"
				<< qSetFieldWidth(0) << "\r\n"
				<< "--------------------------------------------------------------------------------------------------------"
				<< qSetFieldWidth(0) << "\r\n";
			GetData data;
			data.outputHardwareReportSpecific(out);
			file->close();
		}
		if (softreport_clean->isChecked())
		{
			QTextStream out(file);
			file->open(QIODevice::WriteOnly | QIODevice::Append);
			out << qSetFieldWidth(100) << left << "Software Report Clean"
				<< qSetFieldWidth(0) << "\r\n" << "--------------------------------------------------------------------------------------------------------"
				<< qSetFieldWidth(0) << "\r\n";
			GetData data;
			data.outputSoftwareReportClean(out);
			file->close();
		}
		else if (softreport_specific->isChecked())
		{
			QTextStream out(file);
			file->open(QIODevice::WriteOnly | QIODevice::Append);
			out << qSetFieldWidth(100) << left << "Software Report Specific"
				<< qSetFieldWidth(0) << "\r\n"
				<< "--------------------------------------------------------------------------------------------------------"
				<< qSetFieldWidth(0) << "\r\n";
			GetData data;
			data.outputSoftwareReportSpecific(out);
			file->close();
		}
		if (reportCPUtest->isChecked())
		{
			QString program = "./cpu_bench.exe";
			QStringList arguments;
			arguments << "run_all";
			QProcess *process = new QProcess(this);
			process->start(program, arguments);
			QString tolive = "Running: CPUTest:";
			for (auto m : arguments)
			{
				tolive += m + " ";
			}
			livemessage->setText(tolive);
			windowReport->update();
			windowReport->repaint();
			while (!process->waitForFinished(-1))
			{
			}
			QFile *cpuresult = new QFile("./cpu_score.txt");
			cpuresult->open(QIODevice::ReadOnly);
			file->open(QIODevice::WriteOnly | QIODevice::Append);
			QTextStream  out(file);
			out << qSetFieldWidth(50) << left << "CPU Test" << right << time.toString()
				<< qSetFieldWidth(100) << left << "--------------------------------------------------------------------------------------------------------"
				<< qSetFieldWidth(0) << "\r\n";

			if (process->exitStatus() == QProcess::NormalExit)
			{
				QByteArray b = cpuresult->readAll();
				QJsonParseError *error = new QJsonParseError;
				QJsonDocument jsonfile = QJsonDocument::fromJson(b, error);
				if (error->error == QJsonParseError::NoError)
				{
					if (jsonfile.isObject())
					{
						QJsonObject jsonobject = jsonfile.object();
						QJsonValue value;
						value = jsonobject.value("queen");
						const QString str_queen = QString("%0").arg(value.toDouble());

						value = jsonobject.value("julia");
						const QString str_julia = QString("%0").arg(value.toDouble());

						value = jsonobject.value("mandel");
						const QString str_mandel = QString("%0").arg(value.toDouble());

						value = jsonobject.value("zlib_compress");
						const QString str_zlib_compress = QString("%0").arg(value.toDouble());

						value = jsonobject.value("zlib_uncompress");
						const QString str_zlib_uncompress = QString("%0").arg(value.toDouble());

						value = jsonobject.value("aes_decrypto");
						const QString str_aes_decrypto = QString("%0").arg(value.toDouble());

						value = jsonobject.value("aes_encrypto");
						const QString str_aes_encrypto = QString("%0").arg(value.toDouble());

						value = jsonobject.value("sha_256");
						const QString str_sha = QString("%0").arg(value.toDouble());

						out << qSetFieldWidth(100) << left << "Branch Prediction Test"
							<< qSetFieldWidth(0) << "\r\n"
							<< qSetFieldWidth(30) << left << "CPU Queen:"
							<< qSetFieldWidth(20) << right << str_queen + "\r\n"
							<< qSetFieldWidth(100) << left << "Floating Point Test"
							<< qSetFieldWidth(0) << "\r\n"
							<< qSetFieldWidth(30) << left << "Julia:"
							<< qSetFieldWidth(20) << right << str_julia + "\r\n"
							<< qSetFieldWidth(30) << left << "Mandel:"
							<< qSetFieldWidth(20) << right << str_mandel + "\r\n"
							<< qSetFieldWidth(100) << left << "Data Stream Test"
							<< qSetFieldWidth(0) << "\r\n"
							<< qSetFieldWidth(30) << left << "zlib Compress:"
							<< qSetFieldWidth(20) << right << str_zlib_compress + "\r\n"
							<< qSetFieldWidth(30) << left << "zlib Uncompress:"
							<< qSetFieldWidth(20) << right << str_zlib_uncompress + "\r\n"
							<< qSetFieldWidth(30) << left << "aes Decrypto:"
							<< qSetFieldWidth(20) << right << str_aes_decrypto + "\r\n"
							<< qSetFieldWidth(30) << left << "aes Encrypto:"
							<< qSetFieldWidth(20) << right << str_aes_encrypto + "\r\n"
							<< qSetFieldWidth(30) << left << "sna-256:"
							<< qSetFieldWidth(20) << right << str_sha + "\r\n";
					}
					else
					{
						out << qSetFieldWidth(100) << left << "Read CPU Test Result Error: not an object\r\n";
					}
				}
				else
				{
					out << qSetFieldWidth(100) << left << "Read CPU Test Result Error:bytearray to json fail\r\n";
				}
			}
			else
			{
				out << qSetFieldWidth(100) << left << "CPU Test Fail: " + QString("exitstatus %0").arg(process->exitStatus()) + QString(" exitcode %0\r\n").arg(process->exitCode());
			}
			out.flush();
			file->close();
		}
		if (reportMemorytest->isChecked())
		{
			QDateTime time = QDateTime::currentDateTime();
			file->open(QIODevice::WriteOnly | QIODevice::Append);
			out << qSetFieldWidth(50) << left << "Memory Test"
				<< qSetFieldWidth(0) << "\r\n"
				<< qSetFieldWidth(100) << left << "--------------------------------------------------------------------------------------------------------"
				<< qSetFieldWidth(0) << "\r\n";
			out.flush();
			file->close();
			QString program = "./mem_benchmark.exe";
			QStringList arguments;
			QStringList lengthList{ "1","8","64","512","4096","32768","524288" };
			QStringList funList = { "10","11","12","13","14","20","21","22" };
			
			for (unsigned int i = 0; i < funList.length(); i++)
			{
				time = QDateTime::currentDateTime();
				file->open(QIODevice::WriteOnly | QIODevice::Append);
				out << qSetFieldWidth(50) << left << time.toString()
					<< qSetFieldWidth(0) << "\r\n";
				out.flush();
				file->close();
				for (unsigned int j = 0; j < lengthList.length(); j++)
				{
					arguments << "bw" << lengthList.at(j) << funList.at(i) << "0";
					QProcess *process = new QProcess(this);
					process->start(program, arguments);
					QString tolive = "Running: MemoryTest:";
					for (auto m : arguments)
					{
						tolive += m + " ";
					}
					livemessage->setText(tolive);
					windowReport->update();
					windowReport->repaint();
					while (!process->waitForFinished(-1))
					{
					}
					QFile *memresult = new QFile("./mem_benchmark.txt");
					memresult->open(QIODevice::ReadOnly);
					if (process->exitStatus() == QProcess::NormalExit)
					{
						QByteArray b = memresult->readAll();
						QJsonParseError *error = new QJsonParseError;
						QJsonDocument jsonfile = QJsonDocument::fromJson(b, error);
						if (error->error == QJsonParseError::NoError)
						{
							if (jsonfile.isObject())
							{
								QJsonObject jsonobject = jsonfile.object();
								QJsonValue value;
								value = jsonobject.value("bandwidth");
								double dvalue = value.toDouble() * 100;
								unsigned int intvalue = dvalue;
								dvalue = intvalue;
								dvalue = dvalue / 100;
								file->open(QIODevice::WriteOnly | QIODevice::Append);
								out << qSetFieldWidth(10) << left << "Bandwidth"
									<< qSetFieldWidth(10) << left << "Function:"
									<< qSetFieldWidth(10) << left << funList.at(i)
									<< qSetFieldWidth(10) << left << "Length:"
									<< qSetFieldWidth(10) << left << lengthList.at(j)
									<< qSetFieldWidth(15) << left << "no hyperthread"
									<< qSetFieldWidth(10) << left << QString("%0").arg(dvalue)
									<< qSetFieldWidth(0) << "\r\n";
								out.flush();
								file->close();
							}
							else
							{
								file->open(QIODevice::WriteOnly | QIODevice::Append);
								out << qSetFieldWidth(100) << left << "Memory Test:not a json object"
									<< qSetFieldWidth(0) << "\r\n";
								out.flush();
								file->close();
							}
						}
						else
						{
							file->open(QIODevice::WriteOnly | QIODevice::Append);
							out << qSetFieldWidth(100) << left << "Memory Test:bytearray to json fail"
								<< qSetFieldWidth(0) << "\r\n";
							out.flush();
							file->close();
						}
					}
					else
					{
						file->open(QIODevice::WriteOnly | QIODevice::Append);
						out << qSetFieldWidth(20) << left << "Memory Test Fail:"
							<< qSetFieldWidth(10) << left << "bandwidth"
							<< qSetFieldWidth(10) << left << lengthList.at(j)
							<< qSetFieldWidth(10) << left << funList.at(i)
							<< qSetFieldWidth(0) << "\r\n"
							<< qSetFieldWidth(10) << left << "ExitCode:"
							<< qSetFieldWidth(20) << left << QString("exitcode %0").arg(process->exitStatus())
							<< qSetFieldWidth(10) << left << "ExitStatus:"
							<< qSetFieldWidth(20) << left << QString("%0").arg(process->exitCode())
							<< qSetFieldWidth(0) << "\r\n";
						out.flush();
						file->close();
					}
					arguments.clear();
				}
				file->open(QIODevice::WriteOnly | QIODevice::Append);
				out << qSetFieldWidth(0) << "\r\n";
				out.flush();
				file->close();
			}
			for (unsigned int i = 0; i < funList.length(); i++)
			{
				time = QDateTime::currentDateTime();
				file->open(QIODevice::WriteOnly | QIODevice::Append);
				out << qSetFieldWidth(50) << left << time.toString()
					<< qSetFieldWidth(0) << "\r\n";
				out.flush();
				file->close();
				for (unsigned int j = 0; j < lengthList.length(); j++)
				{
					arguments << "bw" << lengthList.at(j) << funList.at(i) << "1";
					QProcess *process = new QProcess(this);
					process->start(program, arguments);
					QString tolive = "Running: MemoryTest:";
					for (auto m : arguments)
					{
						tolive += m + " ";
					}
					livemessage->setText(tolive);
					windowReport->update();
					windowReport->repaint();
					while (!process->waitForFinished(-1))
					{
					}
					QFile *memresult = new QFile("./mem_benchmark.txt");
					memresult->open(QIODevice::ReadOnly);
					file->open(QIODevice::WriteOnly | QIODevice::Append);
					if (process->exitStatus() == QProcess::NormalExit)
					{
						QByteArray b = memresult->readAll();
						QJsonParseError *error = new QJsonParseError;
						QJsonDocument jsonfile = QJsonDocument::fromJson(b, error);
						if (error->error == QJsonParseError::NoError)
						{
							if (jsonfile.isObject())
							{
								QJsonObject jsonobject = jsonfile.object();
								QJsonValue value;
								value = jsonobject.value("bandwidth");
								double dvalue = value.toDouble() * 100;
								unsigned int intvalue = dvalue;
								dvalue = intvalue;
								dvalue = dvalue / 100;
								out << qSetFieldWidth(10) << left << "Bandwidth"
									<< qSetFieldWidth(10) << left << "Length:"
									<< qSetFieldWidth(10) << left << lengthList.at(j)
									<< qSetFieldWidth(10) << left << "Function:"
									<< qSetFieldWidth(10) << left << funList.at(i)
									<< qSetFieldWidth(10) << left << "hyperthread"
									<< qSetFieldWidth(10) << left << QString("%0").arg(dvalue)
									<< qSetFieldWidth(0) << "\r\n";
								out.flush();
							}
							else
							{
								out << qSetFieldWidth(100) << left << "Memory Test:not a json object"
									<< qSetFieldWidth(0) << "\r\n";
								out.flush();
							}
						}
						else
						{
							file->open(QIODevice::WriteOnly | QIODevice::Append);
							out << qSetFieldWidth(100) << left << "Memory Test:bytearray to json fail"
								<< qSetFieldWidth(0) << "\r\n";
							out.flush();
							file->close();
						}
					}
					else
					{
						file->open(QIODevice::WriteOnly | QIODevice::Append);
						out << qSetFieldWidth(20) << left << "Memory Test Fail:"
							<< qSetFieldWidth(10) << left << "bandwidth"
							<< qSetFieldWidth(10) << left << lengthList.at(j)
							<< qSetFieldWidth(10) << left << funList.at(i)
							<< qSetFieldWidth(0) << "\r\n"
							<< qSetFieldWidth(10) << left << "ExitCode:"
							<< qSetFieldWidth(20) << left << QString("exitcode %0").arg(process->exitStatus())
							<< qSetFieldWidth(10) << left << "ExitStatus:"
							<< qSetFieldWidth(20) << left << QString("%0").arg(process->exitCode())
							<< qSetFieldWidth(0) << "\r\n";
						out.flush();
						file->close();
					}
					arguments.clear();
				}
				file->open(QIODevice::WriteOnly | QIODevice::Append);
				out << qSetFieldWidth(0) << "\r\n";
				out.flush();
				file->close();
			}
			QStringList strideList;
			for (unsigned int i = 8; i <= 64; i++)
			{
				strideList << QString("%0").arg(i);
				i += 7;
			}
			for (unsigned int i = 0; i < strideList.length(); i++)
			{
				time = QDateTime::currentDateTime();
				file->open(QIODevice::WriteOnly | QIODevice::Append);
				out << qSetFieldWidth(50) << left << time.toString()
					<< qSetFieldWidth(0) << "\r\n";
				out.flush();
				file->close();
				for (unsigned int j = 0; j < lengthList.length(); j++)
				{
					arguments << "lat" << lengthList.at(j) << strideList.at(i);
					QProcess *process = new QProcess(this);
					process->start(program, arguments);
					QString tolive = "Running: MemoryTest:";
					for (auto m : arguments)
					{
						tolive += m + " ";
					}
					livemessage->setText(tolive);
					windowReport->update();
					windowReport->repaint();
					while (!process->waitForFinished(-1))
					{
					}
					QFile *memresult = new QFile("./mem_benchmark.txt");
					memresult->open(QIODevice::ReadOnly);
					file->open(QIODevice::WriteOnly | QIODevice::Append);
					if (process->exitStatus() == QProcess::NormalExit)
					{
						QByteArray b = memresult->readAll();
						QJsonParseError *error = new QJsonParseError;
						QJsonDocument jsonfile = QJsonDocument::fromJson(b, error);
						if (error->error == QJsonParseError::NoError)
						{
							if (jsonfile.isObject())
							{
								QJsonObject jsonobject = jsonfile.object();
								QJsonValue value;
								value = jsonobject.value("latency");
								//double dvalue = value.toDouble() * 100;
								//unsigned int intvalue = dvalue;
								//dvalue = intvalue;
								//dvalue = dvalue / 100;
								file->open(QIODevice::WriteOnly | QIODevice::Append);
								out << qSetFieldWidth(10) << left << "Latency"
									<< qSetFieldWidth(10) << left << "Length:"
									<< qSetFieldWidth(10) << left << lengthList.at(j)
									<< qSetFieldWidth(10) << left << "Stride:"
									<< qSetFieldWidth(10) << left << strideList.at(i)
									<< qSetFieldWidth(10) << left << QString("%0").arg(value.toDouble())
									<< qSetFieldWidth(0) << "\r\n";
								out.flush();
								file->close();
							}
							else
							{
								file->open(QIODevice::WriteOnly | QIODevice::Append);
								out << qSetFieldWidth(100) << left << "Memory Test:not a json object"
									<< qSetFieldWidth(0) << "\r\n";
								out.flush();
								file->close();
							}
						}
						else
						{
							file->open(QIODevice::WriteOnly | QIODevice::Append);
							out << qSetFieldWidth(100) << left << "Memory Test:bytearray to json fail"
								<< qSetFieldWidth(0) << "\r\n";
							out.flush();
							file->close();
						}
					}
					else
					{
						file->open(QIODevice::WriteOnly | QIODevice::Append);
						out << qSetFieldWidth(20) << left << "Memory Test Fail:"
							<< qSetFieldWidth(10) << left << "lat"
							<< qSetFieldWidth(10) << left << lengthList.at(j)
							<< qSetFieldWidth(10) << left << strideList.at(i)
							<< qSetFieldWidth(0) << "\r\n"
							<< qSetFieldWidth(10) << left << "ExitCode:"
							<< qSetFieldWidth(20) << left << QString("exitcode %0").arg(process->exitStatus())
							<< qSetFieldWidth(10) << left << "ExitStatus:"
							<< qSetFieldWidth(20) << left << QString("%0").arg(process->exitCode())
							<< qSetFieldWidth(0) << "\r\n";
						out.flush();
						file->close();
					}
					arguments.clear();
				}
				file->open(QIODevice::WriteOnly | QIODevice::Append);
				out << qSetFieldWidth(0) << "\r\n";
				out.flush();
				file->close();
			}
		}
		if (reportDisktest->isChecked())
		{
			QDateTime time = QDateTime::currentDateTime();
			file->open(QIODevice::WriteOnly | QIODevice::Append);
			out << qSetFieldWidth(50) << left << "Disk Test"
				<< qSetFieldWidth(50) << left << time.toString()
				<< qSetFieldWidth(0) << "\r\n"
				<< qSetFieldWidth(100) << left << "--------------------------------------------------------------------------------------------------------"
				<< qSetFieldWidth(0) << "\r\n";
			file->close();
			QString program = "./diskmark.exe";
			QStringList arguments;
			QStringList driveList;
			GetData data;
			data.getLogicalDrives(driveList);
			QStringList itemList = { "1","0","0","0","1","0","0","0","1" };
			QStringList resultList = { "writeiops_4k" ,"writespeed_4k" ,"readiops_4k","readspeed_4k" ,"writeiops_4k64" ,"writespeed_4k64" ,"readiops_4k64" ,"readspeed_4k64" ,"writeiops_serial" , "writespeed_serial","readiops_serial","readspeed_serial" };
			for (unsigned int i = 0; i < driveList.length(); i++)
			{
				file->open(QIODevice::WriteOnly | QIODevice::Append);
				out << qSetFieldWidth(20) << left << "Test Drive:"
					<< qSetFieldWidth(20) << left << driveList.at(i)
					<< qSetFieldWidth(0) << "\r\n";
				out.flush();
				file->close();
				for (unsigned int j = 0; j < 3; j++)
				{
					arguments << driveList.at(i) << itemList.at(j * 3) << itemList.at(j * 3 + 1) << itemList.at(j * 3 + 2);
					QProcess *process = new QProcess(this);
					process->start(program, arguments);
					QString tolive = "Running: DiskTest: ";
					for (auto m : arguments)
					{
						tolive += m + " ";
					}
					livemessage->setText(tolive);
					windowReport->update();
					windowReport->repaint();
					while (!process->waitForFinished(-1))
					{
					}
					if (process->exitStatus() == QProcess::NormalExit)
					{
						QFile *memresult = new QFile("./diskmark.txt");
						memresult->open(QIODevice::ReadOnly);
						QByteArray b = memresult->readAll();
						QJsonParseError *error = new QJsonParseError;
						QJsonDocument jsonfile = QJsonDocument::fromJson(b, error);
						if (error->error == QJsonParseError::NoError)
						{
							if (jsonfile.isObject())
							{
								QJsonObject jsonobject = jsonfile.object();
								QJsonObject::Iterator iterator = jsonobject.begin();
								QJsonValue value;
								QJsonObject jsonobject_result = iterator.value().toObject();
								time = QDateTime::currentDateTime();
								file->open(QIODevice::WriteOnly | QIODevice::Append);
								out << qSetFieldWidth(50) << left << time.toString()
									<< qSetFieldWidth(0) << "\r\n";
								for (unsigned int m = 0; m < 4; m++)
								{
									value = jsonobject_result.value(resultList.at(j * 4 + m));
									out << qSetFieldWidth(20) << left << resultList.at(j * 4 + m)
										<< ":"
										<< qSetFieldWidth(20) << left << value.toString()
										<< qSetFieldWidth(0) << "\r\n";
								}
								out << qSetFieldWidth(0) << "\r\n";
								out.flush();
								file->close();
							}
						}
					}
					else
					{
						file->open(QIODevice::WriteOnly | QIODevice::Append);
						out << "Disk Test Fail: "
							<< driveList.at(i)
							<< itemList.at(j * 3)
							<< itemList.at(j * 3 + 1)
							<< itemList.at(j * 3 + 2)
							<< QString("\r\nexitstatus %0").arg(process->exitStatus())
							<< QString(" exitcode %0").arg(process->exitCode())
							<< "\r\n";
						out.flush();
						file->close();
					}
					arguments.clear();
				}

			}
		}
		//end
		file->open(QIODevice::WriteOnly | QIODevice::Append);
		out << qSetFieldWidth(100) << left << "--------------------------------------------------------------------------------------------------------"
			<< qSetFieldWidth(0) << left << "\r\n";
		out << qSetFieldWidth(50) << left << "End of Report" << right << time.toString();
		out.flush();
		file->close();
	}
	livemessage->setText("Running: End");
	windowReport->update();
	windowReport->repaint();
	windowReport->close();
}
void Page_test::reset()
{
	sideTabGroup->reset();
	turnPage(0);
	testMemory->reset();
	testStorage->reset();
}
