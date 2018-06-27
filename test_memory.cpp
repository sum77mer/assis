#include "test_memory.h"
#include<windows.h>
Test_Memory::Test_Memory(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QLabel *label_bwtest_title = new QLabel(this);
    label_bwtest_title->setFrameStyle(QFrame::NoFrame);
    label_bwtest_title->setText(QString("BrandWidth Test"));
    QFont title_font("Arial",12,QFont::Bold);
    label_bwtest_title->setFont(title_font);

    QLabel *label_function_title = new QLabel(this);
    label_function_title->setFrameStyle(QFrame::NoFrame);
    label_function_title->setText(QString("Test Function:"));

    checkbox_fun_ReaderSSE2 = new QCheckBox(this);
    checkbox_fun_WriterSSE2  = new QCheckBox(this);
    checkbox_fun_CopySSE = new QCheckBox(this);
    checkbox_fun_WriterSSE2_bypass = new QCheckBox(this);
    checkbox_fun_CopySSE_bypass = new QCheckBox(this);
    checkbox_fun_ReaderAVX = new QCheckBox(this);
    checkbox_fun_WriterAVX = new QCheckBox(this);
    checkbox_fun_CopyAVX = new QCheckBox(this);

    checkbox_fun_ReaderSSE2->setText(QString("ReaderSSE2"));
    checkbox_fun_WriterSSE2->setText(QString("WriterSSE2"));
    checkbox_fun_CopySSE->setText(QString("CopySSE"));
    checkbox_fun_WriterSSE2_bypass->setText(QString("WriterSSE2 bypass"));
    checkbox_fun_CopySSE_bypass->setText(QString("CopySSE bypass"));
    checkbox_fun_ReaderAVX->setText(QString("ReaderAVX"));
    checkbox_fun_WriterAVX->setText(QString("WriterAVX"));
    checkbox_fun_CopyAVX->setText(QString("CopyAVX"));

    QLabel *label_hyperthread_title = new QLabel(this);
    label_hyperthread_title->setFrameStyle(QFrame::NoFrame);
    label_hyperthread_title->setText(QString("Hyperthread:"));

    checkbox_hyperthread = new QCheckBox(this);
    checkbox_hyperthread->setText(QString("HyperThread"));

    btn_bw_begin = new QPushButton(this);
    btn_bw_begin->setText(QString("Begin"));

    connect(btn_bw_begin,SIGNAL(clicked(bool)),this,SLOT(begin_bw()));

    /*
    series_bw->append(1,3.0124);
    series_bw->append(2,5.0124);
    series_bw->append(3,13.0124);
    series_bw->append(4,30.0124);
    series_bw->append(5,3.0124);
    series_bw->append(6,13.0124);
    series_bw->append(7,15.0124);
    series_bw->append(8,17.0124);
    series_bw->append(9,4.0124);
    series_bw->append(10,3.0124);
    series_bw->append(11,3.0124);
    series_bw->append(12,3.0124);
    series_bw->append(13,23.0124);
    series_bw->append(14,3.0124);
    series_bw->append(15,3.0124);
    series_bw->append(16,13.0124);
    series_bw->append(17,3.0124);
    series_bw->append(18,10.0124);
    series_bw->append(19,3.0124);
*/


    axisX_bw = new QValueAxis;
    const unsigned int min = 512;
    const unsigned int max = 256*qPow(2,20);
    const unsigned int base = 2;
    axisX_bw->setRange(0,qLn(max/min)/qLn(base));
    axisX_bw->setTickCount(20);
    axisX_bw->setLabelFormat("2^%u");

    axisY_bw = new QValueAxis;
    axisY_bw->setRange(0,300);

    chart_bw = new QChart();
    //chart_bw->addSeries(series_bw);
    chart_bw->setAxisX(axisX_bw);
    chart_bw->setAxisY(axisY_bw);

    QLabel *label_bwchart = new QLabel(this);
    label_bwchart->setText(QString("512B*"));
    label_bwchart->setFrameStyle(QFrame::NoFrame);

    chartview_bw = new QChartView(this);
    chartview_bw->setFixedSize(1300,400);
    chartview_bw->setChart(chart_bw);

    //latency test


    QLabel *label_lattest_title = new QLabel(this);
    label_lattest_title->setFrameStyle(QFrame::NoFrame);
    label_lattest_title->setText(QStringLiteral("Latency Test"));
    label_lattest_title->setFont(title_font);

    QLabel *label_stride_title = new QLabel(this);
    label_stride_title->setFrameStyle(QFrame::NoFrame);
    label_stride_title->setText(QStringLiteral("stride"));

    lineedit_stride = new QLineEdit(this);
    lineedit_stride->setText(QStringLiteral(""));
    lineedit_stride->setMinimumWidth(50);
    lineedit_stride->setMaximumHeight(20);

    btn_lat_begin = new QPushButton(this);
    btn_lat_begin->setText(QString("Begin"));

    connect(btn_lat_begin,SIGNAL(clicked(bool)),this,SLOT(begin_lat()));

    axisX_lat = new QValueAxis;
    const unsigned int min_lat = 512;
    const unsigned int max_lat = 256*qPow(2,20);
    const unsigned int base_lat = 2;
    axisX_lat->setRange(0,qLn(max_lat/min_lat)/qLn(base_lat));
    axisX_lat->setTickCount(20);
    axisX_lat->setLabelFormat("2^%u");

    axisY_lat = new QValueAxis;
    axisY_lat->setRange(0.0,1000.0);
    axisY_lat->setLabelFormat("%lfe-10");

    chart_lat = new QChart();
    chart_lat->setAxisX(axisX_lat);
    chart_lat->setAxisY(axisY_lat);

    QLabel *label_latchart = new QLabel(this);
    label_latchart->setText(QString("512B*"));
    label_latchart->setFrameStyle(QFrame::NoFrame);

    QChartView *chartview_lat = new QChartView(this);
    chartview_lat->setFixedSize(1300,800);
    chartview_lat->setChart(chart_lat);

    QWidget *widget = new QWidget(this);
    widget->setWindowFlags(Qt::FramelessWindowHint);
    widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QGridLayout *sublayout = new QGridLayout;
    sublayout->setContentsMargins(0,0,0,0);
    sublayout->setSpacing(0);

    sublayout->setContentsMargins(10,20,20,10);//row: col:
    //row1
    sublayout->addWidget(label_bwtest_title,0,1,1,1,Qt::AlignLeft);
    //row2
    //row3
    sublayout->addWidget(label_function_title,2,1,1,1,Qt::AlignLeft);
    sublayout->addWidget(checkbox_fun_ReaderSSE2,2,2,1,1,Qt::AlignLeft);
    sublayout->addWidget(checkbox_fun_WriterSSE2,2,3,1,1,Qt::AlignLeft);
    sublayout->addWidget(checkbox_fun_CopySSE,2,4,1,1,Qt::AlignLeft);
    sublayout->addWidget(checkbox_fun_WriterSSE2_bypass,2,5,1,1,Qt::AlignLeft);
    //row4
    sublayout->addWidget(checkbox_fun_CopySSE_bypass,3,2,1,1,Qt::AlignLeft);
    sublayout->addWidget(checkbox_fun_ReaderAVX,3,3,1,1,Qt::AlignLeft);
    sublayout->addWidget(checkbox_fun_WriterAVX,3,4,1,1,Qt::AlignLeft);
    sublayout->addWidget(checkbox_fun_CopyAVX,3,5,1,1,Qt::AlignLeft);
    //row5
    sublayout->addWidget(label_hyperthread_title,4,1,1,1,Qt::AlignLeft);
    sublayout->addWidget(checkbox_hyperthread,4,2,1,1,Qt::AlignLeft);
    //row6
    sublayout->addWidget(btn_bw_begin,5,1,1,1,Qt::AlignLeft);
    //row7
    sublayout->addWidget(label_bwchart,6,1,1,1,Qt::AlignRight|Qt::AlignBottom);
    sublayout->addWidget(chartview_bw,6,2,1,7,Qt::AlignLeft|Qt::AlignBottom);
    //row8
    //row9
    sublayout->addWidget(label_lattest_title,8,1,1,1,Qt::AlignLeft);
    //row10
    //row11
    sublayout->addWidget(label_stride_title,10,1,1,1,Qt::AlignLeft);
    sublayout->addWidget(lineedit_stride,10,2,1,2,Qt::AlignLeft);
    sublayout->addWidget(btn_lat_begin,10,4,1,1,Qt::AlignLeft);
    //row12
    sublayout->addWidget(label_latchart,11,1,1,1,Qt::AlignRight|Qt::AlignBottom);
    sublayout->addWidget(chartview_lat,11,2,1,6,Qt::AlignLeft|Qt::AlignBottom);

    sublayout->setColumnStretch(0,0);
    sublayout->setColumnStretch(1,0);
    sublayout->setColumnStretch(2,0);
    sublayout->setColumnStretch(3,0);
    sublayout->setColumnStretch(4,0);
    sublayout->setColumnStretch(5,0);
    sublayout->setColumnStretch(6,0);
    sublayout->setColumnStretch(7,0);
    widget->setLayout(sublayout);


    QScrollArea *scrollarea = new QScrollArea;
    scrollarea->setAlignment(Qt::AlignCenter);
    scrollarea->setBackgroundRole(QPalette::Window);
    scrollarea->setFrameStyle(QFrame::NoFrame);
    scrollarea->setWidget(widget);
    scrollarea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(scrollarea);
    setLayout(layout);
}
void Test_Memory::paintEvent(QPaintEvent *event)
{}
void Test_Memory::begin_bw()
{
    chart_bw->removeAllSeries();
    testFunctionList.clear();
    testedFunNum = 0;
    if(checkbox_fun_ReaderSSE2->isChecked())
    {
        testFunctionList<<"10";
        testFunNum++;
    }
    if(checkbox_fun_WriterSSE2->isChecked())
    {
        testFunctionList<<"11";
        testFunNum++;
    }
    if(checkbox_fun_CopySSE->isChecked())
    {
        testFunctionList<<"12";
        testFunNum++;
    }
    if(checkbox_fun_WriterSSE2_bypass->isChecked())
    {
        testFunctionList<<"13";
        testFunNum++;
    }
    if(checkbox_fun_CopySSE_bypass->isChecked())
    {
        testFunctionList<<"14";
        testFunNum++;
    }
    if(checkbox_fun_ReaderAVX->isChecked())
    {
        testFunctionList<<"20";
        testFunNum++;
    }
    if(checkbox_fun_WriterAVX->isChecked())
    {
        testFunctionList<<"21";
        testFunNum++;
    }
    if(checkbox_fun_CopyAVX->isChecked())
    {
        testFunctionList<<"22";
        testFunNum++;
    }
    if(checkbox_hyperthread->isChecked())
    {
        hyperthread_flag = true;
    }
    if(!testFunctionList.isEmpty())
    {
        testFunction(testFunctionList.at(0));
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("please choose at least one function"));
        messagebox->exec();
    }
}
void Test_Memory::testFunction(QString para_fun)
{
    /*
     *
    char szCommandLine[]="mem_benchmark.exe bw 1 10 0";
  //  string cmd_arg = "run_all";
     //   char szCommandLine[256] = "cpu_bench.exe ";
     //   strcat_s(szCommandLine,cmd_arg.data());
        WCHAR wzprocessname[256],wzCommandLine[256];
        memset(wzCommandLine, 0, sizeof(wzCommandLine));
        MultiByteToWideChar(CP_ACP, 0, szCommandLine, strlen(szCommandLine) + 1, wzCommandLine,sizeof(wzCommandLine) / sizeof(wzCommandLine[0]));

    STARTUPINFO si={sizeof(si)};
    PROCESS_INFORMATION pi;
    si.dwFlags=STARTF_USESHOWWINDOW;//指定wShowWindow成员有效
    si.wShowWindow=TRUE;//此成员设为TRUE的话则显示新建进程的主窗口
    BOOL bRet=CreateProcess(
    NULL,//不在此指定可执行文件的文件名
    wzCommandLine,//命令行参数
    NULL,//默认进程安全性
    NULL,//默认进程安全性
    FALSE,//指定当前进程内句柄不可以被子进程继承
    CREATE_NEW_CONSOLE,//为新进程创建一个新的控制台窗口
    NULL,//使用本进程的环境变量
    NULL,//使用本进程的驱动器和目录
    &si,
    &pi);
    if(bRet)
    {
    //不使用的句柄最好关掉
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    printf("新进程的ID号：%d\n",pi.dwProcessId);
    printf("新进程的主线程ID号：%d\n",pi.dwThreadId);
    }
    Sleep(500);
*/

    btn_bw_begin->setText(QString("running"));
    btn_bw_begin->setEnabled(false);
    QString program = "J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/mem_benchmark.exe";
    QStringList parameter;
    parameter<<"bw"<<testParameter.at(testedSizeNum)<<para_fun<<QString("%0").arg(hyperthread_flag);
    process_bw = new QProcess(this);
    process_bw->start(program,parameter);

    connect(process_bw,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(ifNext(int,QProcess::ExitStatus)));
}
void Test_Memory::ifNext(int exitCode,QProcess::ExitStatus exitStatus)
{
    if(exitStatus == QProcess::NormalExit)
    {
        //QByteArray x = process->readAllStandardOutput();
        QFile *file = new QFile("J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/mem_benchmark.txt");
        file->open(QIODevice::ReadOnly);
        QByteArray b= file->readAll();
        QJsonParseError *error=new QJsonParseError;
        QJsonDocument jsonfile = QJsonDocument::fromJson(b,error);
        if(error->error==QJsonParseError::NoError)
        {
            if(jsonfile.isObject())
            {
                if(testedSizeNum!=0)
                    chart_bw->removeSeries(series_remove);
                QJsonObject jsonobject = jsonfile.object();
                QJsonValue value;
                value = jsonobject.value("bandwidth");
                if(max_y_bw<value.toDouble())
                {
                    max_y_bw = value.toDouble();
                    axisY_bw->setRange(0,max_y_bw+20);
                }
                testResult<<QString("%0").arg(value.toDouble());
                testedSizeNum++;
                QLineSeries *series = new QLineSeries();
                series->setPointsVisible(true);
                series->setPointLabelsVisible(true);
                series->setPointLabelsClipping(false);
                series->setPointLabelsFormat("[@yPoint G/s]");
                for(unsigned int i=0;i<testedSizeNum;i++)
                {
                    series->append(i,QString(testResult.at(i)).toDouble());
                }

                chart_bw->addSeries(series);
                series->attachAxis(axisX_bw);
                series->attachAxis(axisY_bw);
                series_remove = series;
                update();
                if(testedSizeNum==20)
                {
                    testedFunNum++;
                    testedSizeNum=0;
                    testResult.clear();
                    /*
                    if(testedFunNum==0)
                    {

                    }
                    else
                    {
                        QLineSeries *series = new QLineSeries();
                        series->setPointsVisible(true);
                        series->setPointLabelsVisible(true);
                        series->setPointLabelsClipping(false);
                        for(unsigned int i=0;i<20;i++)
                        {
                            series->append(i,200);
                        }
                        testedFunNum++;
                        testedSizeNum=0;
                        chart_bw->addSeries(series);
                        testResult.clear();
                        update();
                    }
*/

                }
            }
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("test fail"));
        messagebox->exec();
    }
    if(testFunctionList.length()>testedFunNum)
    {
        testFunction(testFunctionList.at(testedFunNum));
    }
    else
    {
        btn_bw_begin->setEnabled(true);
        btn_bw_begin->setText(QString("Begin"));
    }
}
void Test_Memory::begin_lat()
{
    axisY_lat->setRange(min_y_lat,max_y_lat);
    testedSizeNum_lat = 0;
    chart_lat->removeAllSeries();
    str_stride = lineedit_stride->text();
    unsigned int i = str_stride.toInt();
    QRegExp regexp("[0-9]+");
    if(regexp.exactMatch(str_stride)&&(i>=8)&&(i<=64))
    {
        btn_lat_begin->setEnabled(false);
        btn_lat_begin->setText(QString("running"));
        test_lat(str_stride);
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("invalid input(8-64)"));
        messagebox->exec();
    }
}
void Test_Memory::test_lat(QString para_stride)
{
    QString program = "J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/mem_benchmark.exe";
    QStringList parameter;
    parameter<<"lat"<<testLength_lat.at(testedSizeNum_lat)<<para_stride;
    QProcess *process_lat;
    process_lat = new QProcess(this);
    process_lat->start(program,parameter);
    connect(process_lat,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(ifNext_lat(int,QProcess::ExitStatus)));
}
void Test_Memory::ifNext_lat(int exitCode, QProcess::ExitStatus exitStatus)
{
    if(exitStatus == QProcess::NormalExit)
    {
        QFile *file = new QFile("J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/mem_benchmark.txt");
        file->open(QIODevice::ReadOnly);
        QByteArray b= file->readAll();
        QJsonParseError *error=new QJsonParseError;
        QJsonDocument jsonfile = QJsonDocument::fromJson(b,error);
        if(error->error==QJsonParseError::NoError)
        {
            if(jsonfile.isObject())
            {
                if(testedSizeNum_lat!=0)
                    chart_lat->removeSeries(series_remove_lat);
                QJsonObject jsonobject = jsonfile.object();
                QJsonValue value;
                value = jsonobject.value("latency");
                unsigned int i = 0;
                double point_value= value.toDouble();
                while(!qFloor(point_value))
                {
                    point_value = point_value*10;
                    i++;
                }
                if(i<10)
                    point_value = point_value*qPow(10,10-i);

                if(max_y_lat<point_value)
                {
                    max_y_lat = point_value*1.02;
                }
                if(min_y_lat>point_value)
                {
                    min_y_lat = point_value-point_value*0.4;
                }
                axisY_lat->setRange(min_y_lat,max_y_lat);

                testResult_lat<<QString("%0").arg(point_value);
                testedSizeNum_lat++;
                QLineSeries *series = new QLineSeries();
                series->setPointsVisible(true);
                series->setPointLabelsVisible(true);
                series->setPointLabelsClipping(false);
                series->setPointLabelsFormat("[@yPoint ns]");
                for(unsigned int i=0;i<testedSizeNum_lat;i++)
                {
                    double point = QString(testResult_lat.at(i)).toDouble();
                    series->append(i,point);
                }
                chart_lat->addSeries(series);
                series->attachAxis(axisX_lat);
                series->attachAxis(axisY_lat);
                series_remove_lat = series;
                update();
                if(testedSizeNum_lat==20)
                {
                    testedSizeNum=0;

                    testResult_lat.clear();
                }
            }
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("test fail"));
        messagebox->exec();
    }
    if(testedSizeNum_lat<testLength_lat.length())
    {
        test_lat(str_stride);
    }
    else
    {
        btn_lat_begin->setEnabled(true);
        btn_lat_begin->setText(QString("Begin"));
    }
}
