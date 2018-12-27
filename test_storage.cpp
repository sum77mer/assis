#include "test_storage.h"
#include "UIdata.h"
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QMessageBox>
#include "getdata.h"
Test_Storage::Test_Storage(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Test_Storage::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	int rowHeight = checkbox_4K->height();
	/*
	QBrush brush;
	brush.setColor(QColor(120, 194, 196, 150));
	brush.setStyle(Qt::SolidPattern);
	painter.setBrush(brush);
	*/
	//painter.setPen(Qt::NoPen);
	QRect rect = label_random_read->geometry();
	rect.setY(checkbox_randomRW->y());
	rect.setHeight(rowHeight);
	painter.drawRect(rect);

	rect = label_random_write->geometry();
	rect.setY(checkbox_randomRW->y());
	rect.setHeight(rowHeight);
	painter.drawRect(rect);

	rect = label_4K_read->geometry();
	rect.setY(checkbox_4K->y());
	rect.setHeight(rowHeight);
	painter.drawRect(rect);

	rect = label_4K_write->geometry();
	rect.setY(checkbox_4K->y());
	rect.setHeight(rowHeight);
	painter.drawRect(rect);

	rect = label_continuous_read->geometry();
	rect.setY(checkbox_continuous->y());
	rect.setHeight(rowHeight);
	painter.drawRect(rect);

	rect = label_continuous_write->geometry();
	rect.setY(checkbox_continuous->y());
	rect.setHeight(rowHeight);
	painter.drawRect(rect);
}
void Test_Storage::initializeUI()
{
	combobox_volumn_choose->setFont(*normalFont);
	GetData data;
	QStringList slist;
	data.getLogicalDrives(slist);
	for (auto i : slist)
	{
		combobox_volumn_choose->insertItem(0, i);
	}

	btn->setFont(*normalFont);
	btn->setMinimumHeight(btn->sizeHint().height() * 2);
	btn->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
	btn->setText(QString("Run"));

	
	title_item = new QLabel(this);
	title_item->setFrameStyle(QFrame::NoFrame);
	title_item->setFont(*title_font);
	title_item->setAlignment(Qt::AlignCenter);
	title_item->setText(QStringLiteral("Item"));

	title_read = new QLabel(this);
	title_read->setFrameStyle(QFrame::NoFrame);
	title_read->setFont(*title_font);
	title_read->setAlignment(Qt::AlignCenter);
	title_read->setText(QStringLiteral("Read"));

	title_write = new QLabel(this);
	title_write->setFrameStyle(QFrame::NoFrame);
	title_write->setAlignment(Qt::AlignCenter);
	title_write->setFont(*title_font);
	title_write->setText(QStringLiteral("Write"));

	checkbox_randomRW->setText(QStringLiteral("4K"));
	checkbox_randomRW->setFont(*normalFont);
	checkbox_randomRW->setMinimumHeight(checkbox_randomRW->sizeHint().height() * 2);
	checkbox_randomRW->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
	
	label_random_read->setFrameStyle(QFrame::NoFrame);
	label_random_read->setFont(*normalFont);
	label_random_read->setAlignment(Qt::AlignCenter);
	label_random_read->setText(QStringLiteral("speed"));

	label_random_write->setFrameStyle(QFrame::NoFrame);
	label_random_write->setFont(*normalFont);
	label_random_write->setAlignment(Qt::AlignCenter);
	label_random_write->setText(QStringLiteral("speed"));

	checkbox_4K->setFont(*normalFont);
	checkbox_4K->setMinimumHeight(checkbox_4K->sizeHint().height() * 2);
	checkbox_4K->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
	checkbox_4K->setText(QStringLiteral("4K-64Thrd"));
	
	label_4K_read->setFrameStyle(QFrame::NoFrame);
	label_4K_read->setFont(*normalFont);
	label_4K_read->setAlignment(Qt::AlignCenter);
	label_4K_read->setText(QStringLiteral("speed"));

	label_4K_write->setFrameStyle(QFrame::NoFrame);
	label_4K_write->setFont(*normalFont);
	label_4K_write->setAlignment(Qt::AlignCenter);
	label_4K_write->setText(QStringLiteral("speed"));

	checkbox_continuous->setFont(*normalFont);
	checkbox_continuous->setText(QStringLiteral("Seq"));
	checkbox_continuous->setMinimumHeight(checkbox_continuous->sizeHint().height() * 2);
	checkbox_continuous->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
	
	label_continuous_read->setFrameStyle(QFrame::NoFrame);
	label_continuous_read->setFont(*normalFont);
	label_continuous_read->setAlignment(Qt::AlignCenter);
	label_continuous_read->setText(QStringLiteral("speed"));


	label_continuous_write->setFrameStyle(QFrame::NoFrame);
	label_continuous_write->setFont(*normalFont);
	label_continuous_write->setAlignment(Qt::AlignCenter);
	label_continuous_write->setText(QStringLiteral("speed"));

}
void Test_Storage::setupLayout()
{
	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(10, 20, 10, 10);

	layout->setRowStretch(0, 0);
	layout->setRowStretch(1, 0);
	layout->setRowStretch(2, 0);
	layout->setRowStretch(3, 0);
	layout->setRowStretch(4, 0);
	layout->setRowStretch(5, 0);
	layout->setRowStretch(6, 0);
	layout->setRowStretch(7, 1);

	layout->setColumnStretch(0, 1);
	layout->setColumnStretch(1, 1);
	layout->setColumnStretch(2, 1);

	layout->addWidget(btn, 0, 0);
	layout->addWidget(combobox_volumn_choose, 0, 1);

	layout->setRowMinimumHeight(1, 10);

	layout->addWidget(title_item, 2, 0);
	layout->addWidget(title_read, 2, 1);
	layout->addWidget(title_write, 2, 2);

	layout->setRowMinimumHeight(3, 10);

	layout->addWidget(checkbox_randomRW, 4, 0);
	layout->addWidget(label_random_read, 4, 1);
	layout->addWidget(label_random_write, 4, 2);

	layout->addWidget(checkbox_4K, 5, 0);
	layout->addWidget(label_4K_read, 5, 1);
	layout->addWidget(label_4K_write, 5, 2);

	layout->addWidget(checkbox_continuous, 6, 0);
	layout->addWidget(label_continuous_read, 6, 1);
	layout->addWidget(label_continuous_write, 6, 2);

	setLayout(layout);
}
void Test_Storage::setConnection()
{
	connect(btn, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
	connect(checkbox_4K, SIGNAL(clicked(bool)), this, SLOT(test4K64()));
	connect(checkbox_randomRW, SIGNAL(clicked(bool)), this, SLOT(testRandom4k()));
	connect(checkbox_continuous, SIGNAL(clicked(bool)), this, SLOT(testContinuous()));

}
void Test_Storage::initializeData()
{}
void Test_Storage::btnClicked()
{
    if(btn->text() == "Stop")
    {//user stop the test
        btn->setText(QString("Run"));
		btn->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
        beginflag=false;
		testrandomFlag = false;
		testthreadFlag = false;
		testcontinuousFlag = false;
		process->kill();
        timer->stop();
    }
    else
    {
		btn->setText(QString("Stop"));
		btn->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #afafaf, stop : 0.7 #afafaf,stop : 1 #afafaf);border-radius:4px;color:black;border:2px solid #999999}"));
		testrandomFlag = true;
		testthreadFlag = true;
		testcontinuousFlag = true;
		beginflag = true;
		label_4K_read->setText(QString("speed"));
		label_4K_write->setText(QString("speed"));
		label_random_read->setText(QString("speed"));
		label_random_write->setText(QString("speed"));
		label_continuous_read->setText(QString("speed"));
		label_continuous_write->setText(QString("speed"));
		readiops_4k = 0;
		readspeed_4k = 0;
		writeiops_4k = 0;
		writespeed_4k = 0;
		readiops_4k64 = 0;
		readspeed_4k64 = 0;
		writeiops_4k64 = 0;
		writespeed_4k64 = 0;
		readiops_serial = 0;
		readspeed_serial = 0;
		writeiops_serial = 0;
		writespeed_serial = 0;

		readiops_4k_result = 0;
		readspeed_4k_result = 0;
		writeiops_4k_result = 0;
		writespeed_4k_result = 0;
		readiops_4k64_result = 0;
		readspeed_4k64_result = 0;
		writeiops_4k64_result = 0;
		writespeed_4k64_result = 0;
		readiops_serial_result = 0;
		readspeed_serial_result = 0;
		writeiops_serial_result = 0;
		writespeed_serial_result = 0;
		testRandom4k();
		testItemNum = 3;
    }
}
void Test_Storage::testRandom4k()
{
	if (checkbox_randomRW->text() == "Stop")
	{//user stop the test
		checkbox_randomRW->setText(QString("4K"));
		checkbox_randomRW->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
		//beginflag = false;
		testrandomFlag = false;
		testedrandomFlag = true;
		process->kill();
		timer->stop();
	}
	else
	{
		checkbox_randomRW->setText(QString("Stop"));
		checkbox_randomRW->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #afafaf, stop : 0.7 #afafaf,stop : 1 #afafaf);border-radius:4px;color:black;border:2px solid #999999}"));
		//beginflag = true;
		testrandomFlag = true;
		testedrandomFlag = false;
		label_random_read->setText(QString("speed"));
		label_random_write->setText(QString("speed"));
		readiops_4k = 0;
		readspeed_4k = 0;
		writeiops_4k = 0;
		writespeed_4k = 0;

		readiops_4k_result = 0;
		readspeed_4k_result = 0;
		writeiops_4k_result = 0;
		writespeed_4k_result = 0;


		QString volumn = combobox_volumn_choose->currentText();
		volumn = volumn.at(0);
		timer->setInterval(1000);
		QString program = "./diskmark.exe";
		//QString program = "./debug/diskmark.exe";
		QStringList parameter;
		parameter << volumn;
		process = new QProcess(this);
		parameter << "1";
		parameter << "0";
		parameter << "0";
		process->start(program, parameter);
		connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(testFinished(int, QProcess::ExitStatus)));
		timer->start();
		connect(timer, SIGNAL(timeout()), this, SLOT(updateStatus()));
	}
}
void Test_Storage::test4K64()
{
	if (checkbox_4K->text() == "Stop")
	{//user stop the test
		checkbox_4K->setText(QString("4K-64Thrd"));
		checkbox_4K->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
		//beginflag = false;
		testthreadFlag = false;
		testedthreadFlag = true;
		process->kill();
		timer->stop();
	}
	else
	{
		checkbox_4K->setText(QString("Stop"));
		checkbox_4K->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #afafaf, stop : 0.7 #afafaf,stop : 1 #afafaf);border-radius:4px;color:black;border:2px solid #999999}"));
		//beginflag = true;
		testthreadFlag = true;
		testedthreadFlag = false;
		label_4K_read->setText(QString("speed"));
		label_4K_write->setText(QString("speed"));

		readiops_4k64 = 0;
		readspeed_4k64 = 0;
		writeiops_4k64 = 0;
		writespeed_4k64 = 0;

		readiops_4k64_result = 0;
		readspeed_4k64_result = 0;
		writeiops_4k64_result = 0;
		writespeed_4k64_result = 0;

		QString volumn = combobox_volumn_choose->currentText();
		volumn = volumn.at(0);
		timer->setInterval(1000);
		QString program = "./diskmark.exe";
		//QString program = "./debug/diskmark.exe";
		QStringList parameter;
		parameter << volumn;
		process = new QProcess(this);
		parameter << "0";
		parameter << "1";
		parameter << "0";

		process->start(program, parameter);
		connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(testFinished(int, QProcess::ExitStatus)));
		timer->start();
		connect(timer, SIGNAL(timeout()), this, SLOT(updateStatus()));	
	}
}
void Test_Storage::testContinuous()
{
	if (checkbox_continuous->text() == "Stop")
	{//user stop the test
		checkbox_continuous->setText(QString("Seq"));
		checkbox_continuous->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
		//beginflag = false;
		testcontinuousFlag = false;
		testedcontinuousFlag = true;
		process->kill();
		timer->stop();
	}
	else
	{
		checkbox_continuous->setText(QString("Stop"));
		checkbox_continuous->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #afafaf, stop : 0.7 #afafaf,stop : 1 #afafaf);border-radius:4px;color:black;border:2px solid #999999}"));
		//beginflag = true;
		testcontinuousFlag = true;
		testedcontinuousFlag = false;
		label_continuous_read->setText(QString("speed"));
		label_continuous_write->setText(QString("speed"));

		readiops_serial = 0;
		readspeed_serial = 0;
		writeiops_serial = 0;
		writespeed_serial = 0;

		readiops_serial_result = 0;
		readspeed_serial_result = 0;
		writeiops_serial_result = 0;
		writespeed_serial_result = 0;

		QString volumn = combobox_volumn_choose->currentText();
		timer->setInterval(1000);
		QString program = "./diskmark.exe";
		//QString program = "./debug/diskmark.exe";
		QStringList parameter;
		parameter << volumn;
		process = new QProcess(this);
		parameter << "0";
		parameter << "0";
		parameter << "1";
		process->start(program, parameter);
		connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(testFinished(int, QProcess::ExitStatus)));
		timer->start();
		connect(timer, SIGNAL(timeout()), this, SLOT(updateStatus()));
	}
}
void Test_Storage::updateStatus()
{
    if(process->state()==QProcess::Running)
    {
        QFile *file = new QFile("./diskmark.txt");
		if (!file->open(QIODevice::ReadOnly))
		{
			QMessageBox *messagebox = new QMessageBox(this);
			messagebox->setText(QString("can't open diskmark.txt"));
			messagebox->exec();
		}
        QByteArray b= file->readAll();
        QJsonParseError *error=new QJsonParseError;
        QJsonDocument jsonfile = QJsonDocument::fromJson(b,error);
        if(error->error==QJsonParseError::NoError)
        {
            if(jsonfile.isObject())
            {
                QJsonObject jsonobject = jsonfile.object();
                QJsonObject::Iterator iterator = jsonobject.begin();
                iterator++;
                QJsonValue value;
                QJsonObject jsonobject_status = iterator.value().toObject();
                double temp_readspeed = 0,temp_readiops = 0;
                double temp_writespeed = 0,temp_writeiops = 0;
                QString str_updateresult_item = "";
                bool flag_rw = false;//true = read, false = write
                if(testrandomFlag)
                {
                    value = jsonobject_status.value("readiops_4k");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						readiops_4k = string.toDouble();
                    value = jsonobject_status.value("readspeed_4k");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						readspeed_4k = string.toDouble();
                    value = jsonobject_status.value("writeiops_4k");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						writeiops_4k = string.toDouble();
                    value = jsonobject_status.value("writespeed_4k");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						writespeed_4k = string.toDouble();
					/*
					if(temp_readiops||temp_readspeed||temp_writeiops||temp_writespeed)//
                    {
                        if(temp_readiops)
                            readiops_4k = temp_readiops;
                        if(temp_readspeed)
                            readspeed_4k = temp_readspeed;
                        if(temp_writespeed)
                            writespeed_4k = temp_writespeed;
                        if(temp_writeiops)
                            writeiops_4k = temp_writeiops;
                        if((!writespeed_4k_result)&&(!writeiops_4k_result)&&(writeiops_4k||writespeed_4k))//
                        {
                            str_updateresult_item = checkbox_randomRW->text();
                            flag_rw = false;
                        }
                        if((!readspeed_4k_result)&&(!readiops_4k_result)&&(readiops_4k||readspeed_4k))
                        {
                            str_updateresult_item = checkbox_randomRW->text();
                            flag_rw = true;
                        }
                    }
                    else
                    {
                        if(readiops_4k||readspeed_4k||writeiops_4k||writeiops_4k)
                        {
                            if((!writespeed_4k_result)&&(!writeiops_4k_result)&&(writeiops_4k||writespeed_4k))
                            {
                                str_updateresult_item = checkbox_randomRW->text();
                                flag_rw = false;
                            }
                            if((!readspeed_4k_result)&&(!readiops_4k_result)&&(readiops_4k||readspeed_4k))
                            {
                                str_updateresult_item = checkbox_randomRW->text();
                                flag_rw = true;
                            }
                        }
                    }
					*/
					if(writespeed_4k|| writeiops_4k)
						label_random_write->setText(QString("%0MB/S").arg(writespeed_4k));
					if(readspeed_4k|| readiops_4k)
						label_random_read->setText(QString("%0MB/S").arg(readspeed_4k));
                }
                if(testthreadFlag)
                {
                    value = jsonobject_status.value("readiops_4k64");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						readiops_4k64 = string.toDouble();
                    value = jsonobject_status.value("readspeed_4k64");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						readspeed_4k64 = string.toDouble();
                    value = jsonobject_status.value("writeiops_4k64");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						writeiops_4k64 = string.toDouble();
                    value = jsonobject_status.value("writespeed_4k64");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						writespeed_4k64 = string.toDouble();
					/*
					if(temp_readiops||temp_readspeed||temp_writeiops||temp_writespeed)
                    {
                        if(temp_readiops)
                            readiops_4k64 = temp_readiops;
                        if(temp_readspeed)
                            readspeed_4k64 = temp_readspeed;
                        if(temp_writeiops)
                            writeiops_4k64 = temp_writeiops;
                        if(temp_writespeed)
                            writespeed_4k64 = temp_writespeed;
                        if((!writeiops_4k64_result)&&(!writespeed_4k64_result)&&(writeiops_4k64||writespeed_4k64))
                        {
                            str_updateresult_item = checkbox_4K->text();
                            flag_rw = false;
                        }
                        if((!readiops_4k64_result)&&(!readspeed_4k64_result)&&(readiops_4k64||readspeed_4k64))
                        {
                            str_updateresult_item = checkbox_4K->text();
                            flag_rw = true;
                        }
                    }
                    else
                    {
                        if(readiops_4k64||readspeed_4k64||writeiops_4k64||writespeed_4k64)
                        {

                            if((!writespeed_4k64_result)&&(!writeiops_4k64_result)&&(writeiops_4k64||writespeed_4k64))
                            {
                                str_updateresult_item = checkbox_4K->text();
                                flag_rw = false;
                            }
                            if((!readiops_4k64_result)&&(!readspeed_4k64_result)&&(readiops_4k64||readspeed_4k64))
                            {
                                str_updateresult_item = checkbox_4K->text();
                                flag_rw = true;
                            }
                        }
                    }
					*/
                    if(readiops_4k64|| readspeed_4k64)
						label_4K_read->setText(QString("%0MB/S").arg(readspeed_4k64));
					if(writespeed_4k64|| writeiops_4k64)
						label_4K_write->setText(QString("%0MB/S").arg(writespeed_4k64));

                }
                if(testcontinuousFlag)
                {
                    value = jsonobject_status.value("readiops_serial");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						readiops_serial = string.toDouble();
                    value = jsonobject_status.value("readspeed_serial");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						readspeed_serial = string.toDouble();
                    value = jsonobject_status.value("writeiops_serial");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						writeiops_serial = string.toDouble();
                    value = jsonobject_status.value("writespeed_serial");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    if(!value.isNull())
						writespeed_serial = string.toDouble();
					/*
					if(temp_readiops||temp_readspeed||temp_writeiops||temp_writespeed)
                    {
                        if(temp_readiops)
                            readiops_serial = temp_readiops;
                        if(temp_readspeed)
                            readspeed_serial = temp_readspeed;
                        if(temp_writeiops)
                            writeiops_serial = temp_writeiops;
                        if(temp_writespeed)
                            writespeed_serial = temp_writespeed;
                        if((!writespeed_serial_result)&&(!writeiops_serial_result)&&(writeiops_serial||writespeed_serial))
                        {
                            str_updateresult_item = checkbox_continuous->text();
                            flag_rw = false;
                        }
                        if((!readiops_serial_result)&&(!readspeed_serial_result)&&(readiops_serial||readspeed_serial))
                        {
                            str_updateresult_item = checkbox_continuous->text();
                            flag_rw = true;
                        }
                    }
                    else
                    {
                        if(readspeed_serial||readiops_serial||writeiops_serial||writespeed_serial)
                        {

                            if((!writeiops_serial_result)&&(!writespeed_serial_result)&&(writeiops_serial||writespeed_serial))
                            {
                                str_updateresult_item = checkbox_continuous->text();
                                flag_rw = false;
                            }
                            if((!readiops_serial_result)&&(!readspeed_serial_result)&&(readspeed_serial||readiops_serial))
                            {
                                str_updateresult_item = checkbox_continuous->text();
                                flag_rw = true;
                            }
                        }
                    }
					*/
                    if(readspeed_serial|| readiops_serial)
						label_continuous_read->setText(QString("%0MB/S").arg(readspeed_serial));
					if(writespeed_serial|| writeiops_serial)
						label_continuous_write->setText(QString("%0MB/S").arg(writespeed_serial));
                }
                update();
                //if(!str_updateresult_item.isEmpty())
                    //updateResult(str_updateresult_item,flag_rw);
            }
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("test fail:updateStatus processStatus:%0").arg(process->state()));
        messagebox->exec();
    }
}
void Test_Storage::updateResult(QString str_test_item,bool rw_flag)
{
    QFile *file = new QFile("./diskmark.txt");
	if (!file->open(QIODevice::ReadOnly))
	{
		QMessageBox *messagebox = new QMessageBox(this);
		messagebox->setText(QString("can't open diskmark.txt"));
		messagebox->exec();
	}
    QByteArray b= file->readAll();
    QJsonParseError *error=new QJsonParseError;
    QJsonDocument jsonfile = QJsonDocument::fromJson(b,error);
    if(error->error==QJsonParseError::NoError)
    {
        if(jsonfile.isObject())
        {
            QJsonObject jsonobject = jsonfile.object();
            QJsonObject::Iterator iterator = jsonobject.begin();
            QJsonValue value;
            QJsonObject jsonobject_result = iterator.value().toObject();
            if(str_test_item==checkbox_randomRW->text())
            {
                if(rw_flag)
                {
                    value = jsonobject_result.value("readiops_4k");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length-1, 1);
					readiops_4k_result = string.toDouble();
                    value = jsonobject_result.value("readspeed_4k");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    readspeed_4k_result = string.toDouble();
                }
                else
                {
                    value = jsonobject_result.value("writeiops_4k");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    writeiops_4k_result = string.toDouble();
                    value = jsonobject_result.value("writespeed_4k");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    writespeed_4k_result = string.toDouble();
                }
                label_random_read->setText(QString("%0MB/S").arg(readspeed_4k_result));
				label_random_write->setText(QString("%0MB/S").arg(writespeed_4k_result));
            }
            if(str_test_item==checkbox_4K->text())
            {
                if(rw_flag)
                {
                    value = jsonobject_result.value("readiops_4k64");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    readiops_4k64_result = string.toDouble();
                    value = jsonobject_result.value("readspeed_4k64");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    readspeed_4k64_result = string.toDouble();
                }
                else
                {
                    value = jsonobject_result.value("writeiops_4k64");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    writeiops_4k64_result = string.toDouble();
                    value = jsonobject_result.value("writespeed_4k64");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    writespeed_4k64_result = string.toDouble();
                }
                label_4K_read->setText(QString("%0MB/S").arg(readspeed_4k64_result));
				label_4K_write->setText(QString("%0MB/S").arg(writespeed_4k64_result));
            }
            if(str_test_item==checkbox_continuous->text())
            {
                if(rw_flag)
                {
                    value = jsonobject_result.value("readiops_serial");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    readiops_serial_result = string.toDouble();
                    value = jsonobject_result.value("readspeed_serial");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    readspeed_serial_result = string.toDouble();
                }
                else
                {
                    value = jsonobject_result.value("writeiops_serial");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    writeiops_serial_result = string.toDouble();
                    value = jsonobject_result.value("writespeed_serial");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
                    writespeed_serial_result = string.toDouble();
                }
                label_continuous_read->setText(QString("%0MB/S").arg(readspeed_serial_result));
				label_continuous_write->setText(QString("%0MB/S").arg(writespeed_serial_result));
            }
            update();
        }
    }
	else
	{
		QMessageBox *messagebox = new QMessageBox(this);
		messagebox->setText(QString("updateResult(JsonParseError)"));
		messagebox->exec();
	}
}
void Test_Storage::testFinished(int, QProcess::ExitStatus exitStatus)
{
    if(exitStatus==QProcess::NormalExit)
    {
		timer->stop();
		QFile *file = new QFile("./diskmark.txt");
		if (!file->open(QIODevice::ReadOnly))
		{
			QMessageBox *messagebox = new QMessageBox(this);
			messagebox->setText(QString("can't open diskmark.txt"));
			messagebox->exec();
		}
		QByteArray b = file->readAll();
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
				if (testrandomFlag)
				{
					value = jsonobject_result.value("readiops_4k");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					readiops_4k_result = string.toDouble();
					value = jsonobject_result.value("readspeed_4k");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					readspeed_4k_result = string.toDouble();
					value = jsonobject_result.value("writeiops_4k");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					writeiops_4k_result = string.toDouble();
					value = jsonobject_result.value("writespeed_4k");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					writespeed_4k_result = string.toDouble();
					label_random_read->setText(QString("%0MB/S").arg(readspeed_4k_result));
					label_random_write->setText(QString("%0MB/S").arg(writespeed_4k_result));
					testrandomFlag = false;
					testedrandomFlag = true;
					testedItemNum++;
					checkbox_randomRW->setText(QString("4K"));
					checkbox_randomRW->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
				}
				else if (testthreadFlag)
				{
					value = jsonobject_result.value("readiops_4k64");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					readiops_4k64_result = string.toDouble();
					value = jsonobject_result.value("readspeed_4k64");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					readspeed_4k64_result = string.toDouble();

					value = jsonobject_result.value("writeiops_4k64");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					writeiops_4k64_result = string.toDouble();
					value = jsonobject_result.value("writespeed_4k64");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					writespeed_4k64_result = string.toDouble();

					label_4K_read->setText(QString("%0MB/S").arg(readspeed_4k64_result));
					label_4K_write->setText(QString("%0MB/S").arg(writespeed_4k64_result));

					testthreadFlag = false;
					testedthreadFlag = true;
					testedItemNum++;

					checkbox_4K->setText(QString("4K-64Thrd")); 
					checkbox_4K->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
				}
				else if (testcontinuousFlag)
				{
					value = jsonobject_result.value("readiops_serial");
					QString string = value.toString();
					auto length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					readiops_serial_result = string.toDouble();
					value = jsonobject_result.value("readspeed_serial");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					readspeed_serial_result = string.toDouble();

					value = jsonobject_result.value("writeiops_serial");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					writeiops_serial_result = string.toDouble();
					value = jsonobject_result.value("writespeed_serial");
					string.clear();
					string = value.toString();
					length = string.length();
					string.remove(0, 1);
					string.remove(length - 1, 1);
					writespeed_serial_result = string.toDouble();

					label_continuous_read->setText(QString("%0MB/S").arg(readspeed_serial_result));
					label_continuous_write->setText(QString("%0MB/S").arg(writespeed_serial_result));

					testcontinuousFlag = false;
					testedcontinuousFlag = true;
					testedItemNum++;

					checkbox_continuous->setText(QString("Seq"));
					checkbox_continuous->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
				}
				if (testItemNum == testedItemNum)
				{
					beginflag = false;
					testedItemNum = 0;
					btn->setText(QString("Run"));
					btn->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
				}
				else if (testedItemNum < testItemNum)
				{
					if (!testedrandomFlag)
						testRandom4k();
					else if (!testedthreadFlag)
						test4K64();
					else if (!testedcontinuousFlag)
						testContinuous();
				}
			}
		}
        /*
        QFile *file = new QFile("J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/diskmark.txt");
        file->open(QIODevice::ReadOnly);
        QByteArray b= file->readAll();
        QJsonParseError *error=new QJsonParseError;
        QJsonDocument jsonfile = QJsonDocument::fromJson(b,error);
        if(error->error==QJsonParseError::NoError)
        {
            if(jsonfile.isObject())
            {
                QJsonObject jsonobject = jsonfile.object();
                qDebug()<<"jsonfile array?"<<jsonfile.isArray();
                QJsonObject::Iterator iterator = jsonobject.begin();
                QJsonValue value;
                QJsonObject jsonobject_result = iterator.value().toObject();
                if(checkbox_randomRW->isChecked())
                {
                    value = jsonobject_result.value("readiops_4k");
                    readiops_4k = value.toDouble();
                    value = jsonobject_result.value("readspeed_4k");
                    readspeed_4k = value.toDouble();
                    value = jsonobject_result.value("writeiops_4k");
                    writeiops_4k = value.toDouble();
                    value = jsonobject_result.value("writespeed_4k");
                    writespeed_4k = value.toDouble();
                    label_random_result->setText(QString("%0/%1 %2/%3").arg(readspeed_4k).arg(readiops_4k).arg(writespeed_4k).arg(writeiops_4k));
                }
                if(checkbox_4K->isChecked())
                {
                    value = jsonobject_result.value("readiops_4k64");
                    readiops_4k64 = value.toDouble();
                    value = jsonobject_result.value("readspeed_4k64");
                    readspeed_4k64 = value.toDouble();
                    value = jsonobject_result.value("writeiops_4k64");
                    writeiops_4k64 = value.toDouble();
                    value = jsonobject_result.value("writespeed_4k64");
                    writespeed_4k64 = value.toDouble();
                    label_4K_result->setText(QString("%0/%1 %2/%3").arg(readspeed_4k64).arg(readiops_4k64).arg(writespeed_4k64).arg(writeiops_4k64));
                }
                if(checkbox_continuous->isChecked())
                {
                    value = jsonobject_result.value("readiops_serial");
                    readiops_serial = value.toDouble();
                    value = jsonobject_result.value("readspeed_serial");
                    readspeed_serial = value.toDouble();
                    value = jsonobject_result.value("writeiops_serial");
                    writeiops_serial = value.toDouble();
                    value = jsonobject_result.value("writespeed_serial");
                    writespeed_serial = value.toDouble();
                    label_continuous_result->setText(QString("%0/%1 %2/%3").arg(readspeed_serial).arg(readiops_serial).arg(writespeed_serial).arg(writeiops_serial));
                }
                update();
            }
        }
*/
    }
    else
    {
		if (btn->text() == "Stop" && (testedItemNum<testItemNum))
		{
			testedItemNum++;
			if (!testedrandomFlag)
				testRandom4k();
			else if (!testedthreadFlag)
				test4K64();
			else if (!testedcontinuousFlag)
				testContinuous();
		}
		else
		{
			checkbox_randomRW->setText(QString("4K"));
			checkbox_randomRW->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
			checkbox_4K->setText(QString("4K-64Thrd"));
			checkbox_4K->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
			checkbox_continuous->setText(QString("Seq"));
			checkbox_continuous->setStyleSheet(QString("QPushButton{padding:3px 4px 3px 4px;background: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 white,stop:0.4 #9FEEEA, stop : 0.7 #9FEEEA,stop : 1 #9FEEEA);border-radius:4px;color:black;border:2px solid #6DDEE5}"));
		}
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("test fail:testFinished process unormal exit exitStatus:%1").arg(exitStatus));
        messagebox->exec();
    }
	update();
}
void Test_Storage::reset() {

}