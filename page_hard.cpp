#include "page_hard.h"
#include <QPalette>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QDir>
#include "libheaders/CPU.h"
#include "libheaders/diskdefination.h"
#include "libheaders/EDID.h"
#include "libheaders/gpu.h"
//#include "libheaders/Iusb.h"
#include "libheaders/NetworkLib.h"
#include "libheaders/smbioslib.h"
//#include "libheaders/SV-SoftWare.h"
using namespace SV_ASSIST::CPU;
using namespace SV_ASSIST::Storage;
using namespace SV_ASSIST::Display;
using namespace SV_ASSIST::DMI_SMBIOS;
using namespace SV_ASSIST::GPU;
using namespace SV_ASSIST::Net;
//using namespace SV_ASSIST::Software;
//using namespace SV_ASSIST::USB;
Page_hard::Page_hard(QWidget *parent)
{
    setFixedSize(900,594);
    setWindowFlags(Qt::FramelessWindowHint);
    QStringList stringlist;
    stringlist<<"General"<<"CPU"<<"Board"<<"Memory"<<"GFX"<<"PCI"<<"Storage"<<"Net"<<"Others";
    sideTabGroup = new Widget_sideTabGroup(0,stringlist);

    pbtnautofresh = new QPushButton("停止刷新",this);
    pbtnfresh = new QPushButton("手动刷新",this);
    pbtnoutput = new QPushButton("输出报告",this);
    pbtncompare = new QPushButton("Compare",this);
    pbtnautofresh->setFixedSize(70,25);
    pbtnfresh->setFixedSize(70,25);
    pbtnoutput->setFixedSize(70,25);
    pbtncompare->setFixedSize(70,25);
    if(autorefreshflag)
        pbtnfresh->setDisabled(true);
    connect(pbtnautofresh,SIGNAL(clicked(bool)),this,SLOT(onAutoRefresh()));
    connect(pbtnfresh,SIGNAL(clicked(bool)),this,SLOT(onManualRefresh()));
    connect(pbtnoutput,SIGNAL(clicked(bool)),this,SLOT(reportWindow()));
    connect(pbtncompare,SIGNAL(clicked(bool)),this,SLOT(Compare()));

    QGridLayout *tablayout=new QGridLayout;
    tablayout->setContentsMargins(0,0,0,0);
    tablayout->setSpacing(0);
    tablayout->setRowStretch(0,1);
    tablayout->setRowStretch(1,0);
    tablayout->setRowStretch(2,0);
    tablayout->setRowStretch(3,0);
    tablayout->setRowStretch(4,0);
    tablayout->addWidget(sideTabGroup,0,0,Qt::AlignTop|Qt::AlignLeft);
    tablayout->addWidget(pbtnautofresh,1,0,Qt::AlignCenter);
    tablayout->addWidget(pbtnfresh,2,0,Qt::AlignCenter);
    tablayout->addWidget(pbtnoutput,3,0,Qt::AlignCenter);
    tablayout->addWidget(pbtncompare,4,0,Qt::AlignCenter);
    tablayout->setRowMinimumHeight(4,20);



    hardZHXX = new Hard_ZHXX(this);
    hardBoard = new Hard_Board(this);
    hardCPU = new Hard_CPU(this);
    hardMemory = new Hard_Memory(this);
    hardGFX = new Hard_GFX(this);
    hardPCI = new Hard_PCI(this);
    hardStorage = new Hard_Storage(this);
    hardNet = new Hard_Net(this);
    hardOther = new Hard_Other(this);

    stackWidget = new QStackedWidget();
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(Qt::transparent));
    stackWidget->setPalette(palette);
    stackWidget->setAutoFillBackground(true);

    stackWidget->addWidget(hardZHXX);
    stackWidget->addWidget(hardCPU);
    stackWidget->addWidget(hardBoard);
    stackWidget->addWidget(hardMemory);
    stackWidget->addWidget(hardGFX);
    stackWidget->addWidget(hardPCI);
    stackWidget->addWidget(hardStorage);
    stackWidget->addWidget(hardNet);
    stackWidget->addWidget(hardOther);

    connect(sideTabGroup,SIGNAL(turnPage(int)),this,SLOT(turnPage(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addLayout(tablayout,0,0,Qt::AlignTop|Qt::AlignLeft);
    layout->addWidget(stackWidget,0,1,Qt::AlignTop|Qt::AlignLeft);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    setLayout(layout);

}
void Page_hard::paintEvent(QPaintEvent *event)
{

}
void Page_hard::turnPage(int index)
{
    switch(index)
    {
    case 0:
    {
        stackWidget->setCurrentWidget(hardZHXX);
        break;
    }
    case 1:
    {
        stackWidget->setCurrentWidget(hardCPU);
        break;
    }
    case 2:
    {
        stackWidget->setCurrentWidget(hardBoard);
        break;
    }
    case 3:
    {
        stackWidget->setCurrentWidget(hardMemory);
        break;
    }
    case 4:
    {
        stackWidget->setCurrentWidget(hardGFX);
        break;
    }
    case 5:
    {
        stackWidget->setCurrentWidget(hardPCI);
        break;
    }
    case 6:
    {
        stackWidget->setCurrentWidget(hardStorage);
        break;
    }
    case 7:
    {
        stackWidget->setCurrentWidget(hardNet);
        break;
    }
    case 8:
    {
        stackWidget->setCurrentWidget(hardOther);
        break;
    }
    default:
    {
        stackWidget->setCurrentWidget(hardZHXX);
        break;
    }
    }
}
void Page_hard::reportWindow()
{
    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QString("hardware report:"));
    QCheckBox *checkbox1 = new QCheckBox(this);
    checkbox1->setText(QString("clean"));
    QCheckBox *checkbox2 = new QCheckBox(this);
    checkbox2->setText(QString("specific"));

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QString("software report"));
    QCheckBox *checkbox3 = new QCheckBox(this);
    checkbox3->setText(QString("clean"));
    QCheckBox *checkbox4 = new QCheckBox(this);
    checkbox4->setText(QString("specific"));

    QLabel *label3= new QLabel(this);
    label3->setText(QString("test"));
    QCheckBox *checkbox5 = new QCheckBox(this);
    checkbox5->setText(QString("CPU"));
    QCheckBox *checkbox6 = new QCheckBox(this);
    checkbox6->setText(QString("memory"));
    QCheckBox *checkbox7 = new QCheckBox(this);
    checkbox7->setText(QString("disk"));

    QPushButton *btn = new QPushButton(this);
    btn->setText(QString("output"));

    connect(btn,SIGNAL(clicked(bool)),this,SLOT(outputReport()));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->setColumnStretch(0,0);
    layout->setColumnStretch(1,0);
    layout->setColumnStretch(2,0);
    layout->setColumnStretch(3,1);
    layout->addWidget(label1,0,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox1,0,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox2,0,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(label2,1,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox3,1,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox4,1,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(label3,2,0,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox5,2,1,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox6,2,2,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(checkbox7,2,3,1,1,Qt::AlignLeft|Qt::AlignTop);
    layout->addWidget(btn,3,0,1,4,Qt::AlignHCenter|Qt::AlignTop);

    QWidget *window = new QWidget(this);
    window->setWindowFlags(Qt::Window);
    window->setLayout(layout);
    window->setMinimumSize(200,100);
    window->show();
}
void Page_hard::onAutoRefresh()
{
    if(autorefreshflag)
    {
        pbtnautofresh->setText(QString("自动刷新"));
        autorefreshflag=false;
        pbtnfresh->setDisabled(false);
        //stop timer
    }
    else
    {
        pbtnautofresh->setText(QString("停止刷新"));
        pbtnfresh->setDisabled(true);
        autorefreshflag=true;
        //start timer
    }
    update();
}
void Page_hard::onManualRefresh()
{
    qDebug()<<"manual refresh clicked";
    //update data then display
}
void Page_hard::outputReport()
{}
void Page_hard::Compare()
{
    QString str_cpu;
    str_cpu +="[CPU]\r\n";
    str_cpu += QString().fromStdString(GetCPUName());
    str_cpu +="\r\n";
    str_cpu += QString().fromStdString(GetProcessorID());
    str_cpu +="\r\n";
    str_cpu += QString().fromStdString(GetSocketDesignation());
    str_cpu +="\r\n";
    str_cpu += QString("current clock speed:%0").arg(GetCurrentClockSpeed());
    str_cpu +="\r\n";
    str_cpu += QString("ExtClock:%0").arg(GetExtClock());
    str_cpu +="\r\n";
    str_cpu += QString("core:%0").arg(GetCore());
    str_cpu +="\r\n";
    str_cpu += QString("thread:%0").arg(GetThread());
    str_cpu +="\r\n";
    str_cpu += QString("maxclockspeed:%0").arg(GetMaxClockSpeed());
    str_cpu +="\r\n";
    str_cpu += QString("upgrademethod:%0").arg(GetUpgradeMethod());
    str_cpu +="\r\n";
    str_cpu += QString("manufacturer:%0").fromStdString(GetManufacturer());
    str_cpu +="\r\n";
    str_cpu += QString("family:%0").arg(GetFamily());
    str_cpu +="\r\n";
    str_cpu += QString("Model:%0").arg(GetModel());
    str_cpu +="\r\n";
    str_cpu += QString("Stepping:%0").arg(GetStepping());
    str_cpu +="\r\n";
    str_cpu += QString("ExtFamily:%0").arg(GetExtFamily());
    str_cpu +="\r\n";
    str_cpu += QString("ExtModel:%0").arg(GetExtModel());
    str_cpu +="\r\n";
    CPUFeature cpufeature = {};
    QString manufacturer = QString().fromStdString(GetManufacturer());
    if(manufacturer.contains("GenuineIntel"))
    {
        if(cpufeature.IntelFeature.SSE3)
            str_cpu+="SSE3 ";
        if(cpufeature.IntelFeature.PCLMULQDQ)
            str_cpu+="PCLMULQDQ ";
        if(cpufeature.IntelFeature.DTES64)
            str_cpu+="DTES64 ";
        if(cpufeature.IntelFeature.MONITOR)
            str_cpu+="MONITOE ";
        if(cpufeature.IntelFeature.DS_CPL)
            str_cpu+="DS_CPL ";
        if(cpufeature.IntelFeature.VMX)
            str_cpu+="VMX ";
        if(cpufeature.IntelFeature.SMX)
            str_cpu+="SMX ";
        if(cpufeature.IntelFeature.EIST)
            str_cpu+="EIST ";
        if(cpufeature.IntelFeature.TM2)
            str_cpu+="TM2 ";
        if(cpufeature.IntelFeature.SSSE3)
            str_cpu+="SSSE3 ";
        if(cpufeature.IntelFeature.CNXT_ID)
            str_cpu+="CNXT_ID ";
        if(cpufeature.IntelFeature.SDBG)
            str_cpu+="SDBG ";
        if(cpufeature.IntelFeature.FMA)
            str_cpu+="FMA ";
        if(cpufeature.IntelFeature.CMPXCHG16B)
            str_cpu+="CMPXCHG16B ";
        if(cpufeature.IntelFeature.xTPR_Update_Control)
            str_cpu+="xTPR_Update_Control ";
        if(cpufeature.IntelFeature.PDCM)
            str_cpu+="PDCM ";
        if(cpufeature.IntelFeature.PCID)
            str_cpu+="PCID ";
        if(cpufeature.IntelFeature.DCA)
            str_cpu+="DCA ";
        if(cpufeature.IntelFeature.SSE4_1)
            str_cpu+="SSE4_1 ";
        if(cpufeature.IntelFeature.SSE4_2)
            str_cpu+="SSE4_2 ";
        if(cpufeature.IntelFeature.x2APIC)
            str_cpu+="x2APIC ";
        if(cpufeature.IntelFeature.MOVBE)
            str_cpu+="MOVBE ";
        if(cpufeature.IntelFeature.POPCNT)
            str_cpu+="POPCNT ";
        if(cpufeature.IntelFeature.TSC_Deadline)
            str_cpu+="TSC_Deadline ";
        if(cpufeature.IntelFeature.AESNI)
            str_cpu+="AESNI ";
        if(cpufeature.IntelFeature.XSAVE)
            str_cpu+="XSAVE ";
        if(cpufeature.IntelFeature.OSXSAVE)
            str_cpu+="OSXSAVE ";
        if(cpufeature.IntelFeature.AVX)
            str_cpu+="AVX ";
        if(cpufeature.IntelFeature.F16C)
            str_cpu+="F16C ";
        if(cpufeature.IntelFeature.RDRAND)
            str_cpu+="RDRAND";
    }
    str_cpu +="\r\n";
    const Cache_info* cache = GetCache();
    for(unsigned int i = 0;i<4;i++)
    {
        Cache_info cache_temp = *(cache+i);
        if(cache_temp.Cache_type == 1)
        {
            if(cache_temp.Cache_type == 'D')
            {
                str_cpu+= "L1 Ins";
                str_cpu +="\r\n";
                str_cpu+= QString(" size:%0").arg(cache_temp.Cache_Size);
                str_cpu +="\r\n";
                str_cpu+= QString(" way:%0").arg(cache_temp.Cache_Ways);
                str_cpu +="\r\n";
                str_cpu+= QString(" line size:%0").arg(cache_temp.Cache_line_size);
                str_cpu +="\r\n";
                str_cpu+= QString(" partition:%0").arg(cache_temp.Cache_partitions);
                str_cpu +="\r\n";
                str_cpu+= QString(" set:%0").arg(cache_temp.Cache_Set);
                str_cpu +="\r\n";
            }
            else if(cache_temp.Cache_type == 'T')
            {
                str_cpu+= "L1 Data";
                str_cpu +="\r\n";
                str_cpu+= QString(" size:%0").arg(cache_temp.Cache_Size);
                str_cpu +="\r\n";
                str_cpu+= QString(" way:%0").arg(cache_temp.Cache_Ways);
                str_cpu +="\r\n";
                str_cpu+= QString(" line size:%0").arg(cache_temp.Cache_line_size);
                str_cpu +="\r\n";
                str_cpu+= QString(" partition:%0").arg(cache_temp.Cache_partitions);
                str_cpu +="\r\n";
                str_cpu+= QString(" set:%0").arg(cache_temp.Cache_Set);
                str_cpu +="\r\n";
            }
        }
        else if(cache_temp.Cache_level == 2)
        {
            str_cpu+="L2";
            str_cpu +="\r\n";
            str_cpu+= QString(" size:%0").arg(cache_temp.Cache_Size);
            str_cpu +="\r\n";
            str_cpu+= QString(" way:%0").arg(cache_temp.Cache_Ways);
            str_cpu +="\r\n";
            str_cpu+= QString(" line size:%0").arg(cache_temp.Cache_line_size);
            str_cpu +="\r\n";
            str_cpu+= QString(" partition:%0").arg(cache_temp.Cache_partitions);
            str_cpu +="\r\n";
            str_cpu+= QString(" set:%0").arg(cache_temp.Cache_Set);
            str_cpu +="\r\n";
        }
        else if(cache_temp.Cache_level == 3)
        {
            str_cpu+="L3";
            str_cpu +="\r\n";
            str_cpu+= QString(" size:%0").arg(cache_temp.Cache_Size);
            str_cpu +="\r\n";
            str_cpu+= QString(" way:%0").arg(cache_temp.Cache_Ways);
            str_cpu +="\r\n";
            str_cpu+= QString(" line size:%0").arg(cache_temp.Cache_line_size);
            str_cpu +="\r\n";
            str_cpu+= QString(" partition:%0").arg(cache_temp.Cache_partitions);
            str_cpu +="\r\n";
            str_cpu+= QString(" set:%0").arg(cache_temp.Cache_Set);
            str_cpu +="\r\n";
        }
    }
    QFile output_file("output.txt");
    if (!output_file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    QTextStream stream(&output_file);//,QIODevice::ReadWrite
    stream<<str_cpu;
    stream.flush();
    output_file.flush();
    output_file.close();
    str_cpu = "";

    updatediskinfo();
    QString str_disk;
    QDir disk_rootdir("J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/HardWare/Disk");
    if(!disk_rootdir.exists())
        qDebug()<<"disk dir not exist";
    else
    {
        QStringList dir_list = disk_rootdir.entryList(QDir::AllDirs|QDir::NoDotAndDotDot);
        for(unsigned int i=0;i<dir_list.length();i++)
        {
            QString str = "J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/HardWare/Disk/";
            str+=dir_list.at(i);
            QDir subdir;
            subdir.setPath(str);
            if(!subdir.exists())
                qDebug()<<"subdir not exist";
            else
            {
                QStringList filelist_temp = subdir.entryList(QDir::Files);
                Disk_info diskinfo_temp;
                diskinfo_temp.dir = dir_list.at(i);
                diskinfo_temp.file_list = filelist_temp;
                diskinfo_list.append(diskinfo_temp);
                qDebug()<<diskinfo_list.at(i).dir<<"\\"<<diskinfo_list.at(i).file_list;
            }
        }
    }
    str_disk+="[Storage]";
    str_disk+="\r\n";
    for(unsigned int i=0;i<diskinfo_list.length();i++)
    {
        str_disk+=QString("Disk %0:").arg(i) + diskinfo_list.at(i).dir;
        str_disk+="\r\n";
        for(unsigned int j=0;j<diskinfo_list.at(i).file_list.length();j++)
        {
            QString file_str= "J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/HardWare/Disk/" + diskinfo_list.at(i).dir + "/" + diskinfo_list.at(i).file_list.at(j);
            QFile file(file_str);
            if(!file.open(QIODevice::ReadOnly))
            {
                qDebug()<<"open disk file fail:"<<file_str;
                return;
            }
            else
            {
                QByteArray b = file.readAll();
                str_disk+=diskinfo_list.at(i).file_list.at(j)+":";
                str_disk+= QString(b)+"\r\n";
                file.flush();
                file.close();
            }
        }
    }
    if (!output_file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    str_disk+="\r\n";
    stream<<str_disk;
    stream.flush();
    output_file.flush();
    str_disk = "";
    output_file.close();
    /*
     *
    //GetEDIDNum();
    //GetEDID();
    Exec();
    QFile file("J:/00_qt_code/build-untitled-Qt_5_11_0_msvc2015_x86-Debug/debug/HardWare/DMI/smbios.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Can not open";
        return;
    }
    QTextStream in(&file);
    while(in.atEnd() == 0)
    {
       this->setText(in.readAll());
    }
    file.close();
*/
    QString str_gpu;
    str_gpu +="\r\n[GPU]";
    str_gpu += "\r\n";
    str_gpu += QString().fromStdString(GPUName());
    str_gpu += "\r\n";
    str_gpu += QString().fromStdString(GPUBIOSVersion());
    str_gpu += "\r\n";
    str_gpu += QString("temperature:%0").arg(GPUtemperature());
    str_gpu += "\r\n";
    FanTypes fantype;
    int fanspeed = GPUFans(fantype);
    str_gpu += QString("fan speed:%0").arg(fanspeed);
    str_gpu += "\r\n";
    str_gpu += QString("current clock:%0").arg(GPUCurrentClock());
    str_gpu += "\r\n";
    str_gpu += QString("memory clock:%0").arg(GPUMemoryClock());
    str_gpu += "\r\n";
    str_gpu += QString("physical memory:%0").arg(GPUPhysicalMemory());
    str_gpu += "\r\n";
    str_gpu += QString("virtual memory:%0").arg(GPUVirtualMemory());
    str_gpu += "\r\n";
    str_gpu += QString("available memory:%0").arg(GetGPUAvailableMemory());
    str_gpu += "\r\n";
    str_gpu += QString("usage:%0").arg(GetGPUUsasge());
    str_gpu += "\r\n";
    str_gpu += QString("memory control ussage:%0").arg(GetGPUMemoryControlUsasge());
    str_gpu += "\r\n";
    str_gpu += QString("video engine usage:%0").arg(GetGPUVideoEngineUsasge());
    str_gpu += "\r\n";

    if (!output_file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    stream<<str_gpu;
    stream.flush();
    output_file.flush();
    str_gpu = "";
    output_file.close();

    QString str_edid;
    SV_ASSIST::Display::Exec();
    QDir edid_dir("J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/HardWare/EDID");
    QStringList edid_file_list = edid_dir.entryList(QDir::Files);
    for(unsigned int i=0;i<edid_file_list.length();i++)
    {
        QString file_str = "J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/HardWare/EDID/" + edid_file_list.at(i);
        QFile edid_file(file_str);
        if(!edid_file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"edid.txt open fail";
            return;
        }
        else
        {
            QByteArray b = edid_file.readAll();
            str_edid+="[EDID]\r\n";
            str_edid+=QString(b);
            edid_file.flush();
            edid_file.close();
        }
    }
    if (!output_file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    stream<<str_edid;
    stream.flush();
    output_file.flush();
    str_edid = "";
    output_file.close();

    QString str_smbios;
    QFile smbios_file("J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/HardWare/DMI/smbios.txt");
    if(!smbios_file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"smbios.txt open fail";
        return;
    }
    else
    {
        QByteArray b = smbios_file.readAll();
        str_smbios+="[SMBIOS]\r\n";
        str_smbios+=QString(b);
        smbios_file.flush();
        smbios_file.close();
    }
    if (!output_file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    stream<<str_smbios;
    stream.flush();
    output_file.flush();
    str_smbios = "";
    output_file.close();

    QString str_network;
    str_network+="[Network]\r\n";
    //SV_ASSIST::Net::Exec();
    if (!output_file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    stream<<str_network;
    stream.flush();
    output_file.flush();
    str_network = "";
    output_file.close();


    //stream<<str_usb;
    //stream<<str_network;
    //stream<<str_software;

    output_file.close();
}
