#include "test_storage.h"
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QMessageBox>
Test_Storage::Test_Storage(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    combobox_volumn_choose->insertItem(0,QString("C"));
    combobox_volumn_choose->insertItem(1,QString("D"));
    combobox_volumn_choose->insertItem(2,QString("E"));
    combobox_volumn_choose->insertItem(3,QString("J"));


    btn->setText(QString("Begin"));

    connect(btn,SIGNAL(clicked(bool)),this,SLOT(btnClicked()));

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QStringLiteral("Item"));

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QStringLiteral("Result(speed/iops)"));

    QLabel *label3 = new QLabel(this);
    label3->setFrameStyle(QFrame::NoFrame);
    label3->setText(QStringLiteral("Status(speed/iops)"));

    checkbox_randomRW->setText(QStringLiteral("Random 4K Read-Write"));

    label_random_result->setFrameStyle(QFrame::NoFrame);
    label_random_result->setText(QStringLiteral("speed/Iops"));

    label_random_live->setFrameStyle(QFrame::NoFrame);
    label_random_live->setText(QStringLiteral("speed/Iops"));

    checkbox_4K->setText(QStringLiteral("4K 64 thread Read-Write"));

    label_4K_result->setFrameStyle(QFrame::NoFrame);
    label_4K_result->setText(QStringLiteral("speed/Iops"));

    label_4K_live->setFrameStyle(QFrame::NoFrame);
    label_4K_live->setText(QStringLiteral("speed/Iops"));

    checkbox_continuous->setText(QStringLiteral("Continuous Read-Write"));

    label_continuous_result->setFrameStyle(QFrame::NoFrame);
    label_continuous_result->setText(QStringLiteral("speed/Iops"));

    label_continuous_live->setFrameStyle(QFrame::NoFrame);
    label_continuous_live->setText(QStringLiteral("speed/Iops"));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);

    layout->setRowStretch(0,0);
    layout->setRowStretch(1,0);
    layout->setRowStretch(2,0);
    layout->setRowStretch(3,0);
    layout->setRowStretch(4,0);
    layout->setRowStretch(5,0);
    layout->setRowStretch(6,0);
    layout->setRowStretch(7,1);
    layout->addWidget(combobox_volumn_choose,0,0,1,1,Qt::AlignLeft);
    layout->addWidget(btn,0,1,1,1,Qt::AlignLeft);

    layout->setRowMinimumHeight(1,10);

    layout->addWidget(label1,2,0,1,1,Qt::AlignLeft);
    layout->addWidget(label2,2,1,1,1,Qt::AlignLeft);
    layout->addWidget(label3,2,2,1,1,Qt::AlignLeft);

    layout->setRowMinimumHeight(3,10);

    layout->addWidget(checkbox_randomRW,4,0,1,1,Qt::AlignLeft);
    layout->addWidget(label_random_result,4,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_random_live,4,2,1,1,Qt::AlignLeft);

    layout->addWidget(checkbox_4K,5,0,1,1,Qt::AlignLeft);
    layout->addWidget(label_4K_result,5,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_4K_live,5,2,1,1,Qt::AlignLeft);

    layout->addWidget(checkbox_continuous,6,0,1,1,Qt::AlignLeft);
    layout->addWidget(label_continuous_result,6,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_continuous_live,6,2,1,1,Qt::AlignLeft);

    setLayout(layout);
}
void Test_Storage::paintEvent(QPaintEvent *event)
{}
void Test_Storage::btnClicked()
{
    if(beginflag)
    {//user stop the test
        btn->setText(QString("begin"));
        beginflag=!beginflag;
        timer->stop();
    }
    else
    {
        if(!(checkbox_randomRW->isChecked()|checkbox_4K->isChecked()|checkbox_continuous->isChecked()))
        {
            QMessageBox *messagebox = new QMessageBox(this);
            messagebox->setText("PLease at least choose one test item");
            messagebox->exec();
        }
        else{
            btn->setText(QString("Stop"));
            label_4K_live->setText(QString("speed/iops"));
            label_4K_result->setText(QString("speed/iops"));
            label_random_live->setText(QString("speed/iops"));
            label_random_result->setText(QString("speed/iops"));
            label_continuous_live->setText(QString("speed/iops"));
            label_continuous_result->setText(QString("speed/iops"));
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

            QString volumn = combobox_volumn_choose->currentText();
            timer->setInterval(1000);
            QString program = "J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/diskmark.exe";
            QStringList parameter;
            parameter<<volumn;
            process = new QProcess(this);

            if(checkbox_randomRW->isChecked())
                parameter<<"1";
            else
                parameter<<"0";
            if(checkbox_4K->isChecked())
                parameter<<"1";
            else
                parameter<<"0";
            if(checkbox_continuous->isChecked())
                parameter<<"1";
            else
                parameter<<"0";
            process->start(program,parameter);
            connect(process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(testFinished(int,QProcess::ExitStatus)));
            timer->start();
            connect(timer,SIGNAL(timeout()),this,SLOT(updateStatus()));
            beginflag=!beginflag;
        }
    }

}
void Test_Storage::updateStatus()
{
    if(process->state()==QProcess::Running)
    {
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
                QJsonObject::Iterator iterator = jsonobject.begin();
                iterator++;
                QJsonValue value;
                QJsonObject jsonobject_status = iterator.value().toObject();
                double temp_readspeed = 0,temp_readiops = 0;
                double temp_writespeed = 0,temp_writeiops = 0;
                QString str_updateresult_item = "";
                bool flag_rw = false;//true = read, false = write
                if(checkbox_randomRW->isChecked())
                {
                    value = jsonobject_status.value("readiops_4k");
                    if(!value.isNull())
                        temp_readiops = value.toDouble();
                    value = jsonobject_status.value("readspeed_4k");
                    if(!value.isNull())
                        temp_readspeed = value.toDouble();
                    value = jsonobject_status.value("writeiops_4k");
                    if(!value.isNull())
                        temp_writeiops = value.toDouble();
                    value = jsonobject_status.value("writespeed_4k");
                    if(!value.isNull())
                        temp_writespeed = value.toDouble();
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
                    label_random_live->setText(QString("%0/%1  %2/%3").arg(readspeed_4k).arg(readiops_4k).arg(writespeed_4k).arg(writeiops_4k));
                }
                if(checkbox_4K->isChecked())
                {
                    value = jsonobject_status.value("readiops_4k64");
                    if(!value.isNull())
                        temp_readiops = value.toDouble();
                    value = jsonobject_status.value("readspeed_4k64");
                    if(!value.isNull())
                        temp_readspeed = value.toDouble();
                    value = jsonobject_status.value("writeiops_4k64");
                    if(!value.isNull())
                        temp_writeiops = value.toDouble();
                    value = jsonobject_status.value("writespeed_4k64");
                    if(!value.isNull())
                        temp_writespeed = value.toDouble();
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
                    label_4K_live->setText(QString("%0/%1  %2/%3").arg(readspeed_4k64).arg(readiops_4k64).arg(writespeed_4k64).arg(writeiops_4k64));

                }
                if(checkbox_continuous->isChecked())
                {
                    value = jsonobject_status.value("readiops_serial");
                    if(!value.isNull())
                        temp_readiops = value.toDouble();
                    value = jsonobject_status.value("readspeed_serial");
                    if(!value.isNull())
                        temp_readspeed = value.toDouble();
                    value = jsonobject_status.value("writeiops_serial");
                    if(!value.isNull())
                        temp_writeiops = value.toDouble();
                    value = jsonobject_status.value("writespeed_serial");
                    if(!value.isNull())
                        temp_writespeed = value.toDouble();
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
                    label_continuous_live->setText(QString("%0/%1  %2/%3").arg(readspeed_serial).arg(readiops_serial).arg(writespeed_serial).arg(writeiops_serial));
                }
                update();
                if(!str_updateresult_item.isEmpty())
                    updateResult(str_updateresult_item,flag_rw);
            }
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("test fail"));
        messagebox->exec();
    }
}
void Test_Storage::updateResult(QString str_test_item,bool rw_flag)
{
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
            QJsonObject::Iterator iterator = jsonobject.begin();
            QJsonValue value;
            QJsonObject jsonobject_result = iterator.value().toObject();
            if(str_test_item==checkbox_randomRW->text())
            {
                if(rw_flag)
                {
                    value = jsonobject_result.value("readiops_4k");
                    readiops_4k_result = value.toDouble();
                    value = jsonobject_result.value("readspeed_4k");
                    readspeed_4k_result = value.toDouble();
                }
                else
                {
                    value = jsonobject_result.value("writeiops_4k");
                    writeiops_4k_result = value.toDouble();
                    value = jsonobject_result.value("writespeed_4k");
                    writespeed_4k_result = value.toDouble();
                }
                label_random_result->setText(QString("%0/%1 %2/%3").arg(readspeed_4k_result).arg(readiops_4k_result).arg(writespeed_4k_result).arg(writeiops_4k_result));
            }
            if(str_test_item==checkbox_4K->text())
            {
                if(rw_flag)
                {
                    value = jsonobject_result.value("readiops_4k64");
                    readiops_4k64_result = value.toDouble();
                    value = jsonobject_result.value("readspeed_4k64");
                    readspeed_4k64_result = value.toDouble();
                }
                else
                {
                    value = jsonobject_result.value("writeiops_4k64");
                    writeiops_4k64_result = value.toDouble();
                    value = jsonobject_result.value("writespeed_4k64");
                    writespeed_4k64_result = value.toDouble();
                }
                label_4K_result->setText(QString("%0/%1 %2/%3").arg(readspeed_4k64_result).arg(readiops_4k64_result).arg(writespeed_4k64_result).arg(writeiops_4k64_result));
            }
            if(str_test_item==checkbox_continuous->text())
            {
                if(rw_flag)
                {
                    value = jsonobject_result.value("readiops_serial");
                    readiops_serial_result = value.toDouble();
                    value = jsonobject_result.value("readspeed_serial");
                    readspeed_serial_result = value.toDouble();
                }
                else
                {
                    value = jsonobject_result.value("writeiops_serial");
                    writeiops_serial_result = value.toDouble();
                    value = jsonobject_result.value("writespeed_serial");
                    writespeed_serial_result = value.toDouble();
                }
                label_continuous_result->setText(QString("%0/%1 %2/%3").arg(readspeed_serial_result).arg(readiops_serial_result).arg(writespeed_serial_result).arg(writeiops_serial_result));
            }
            update();
        }
    }
}
void Test_Storage::testFinished(int, QProcess::ExitStatus exitStatus)
{
    timer->stop();
    btn->setText(QString("Begin"));
    btn->setEnabled(true);
    beginflag = !beginflag;
    if(exitStatus==QProcess::NormalExit)
    {
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
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("test fail"));
        messagebox->exec();
    }
}
