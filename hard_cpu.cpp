#include "hard_cpu.h"
Hard_CPU::Hard_CPU(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);
//page1 cpu content


    QString processorID = QString().fromStdString(GetProcessorID());
    socketdesignation_info = QString().fromStdString(GetSocketDesignation());

    unsigned int core = GetCore();
    unsigned int thread = GetThread();
    unsigned int upgrademethod = GetUpgradeMethod();

    qDebug()<<"processorID:"<<processorID
         <<" core:"<<core
        <<" thread:"<<thread
       <<" upgrademethod:"<<upgrademethod;

    manufacturer_info = QString().fromStdString(GetManufacturer());
    family_info = GetFamily();
    model_info = GetModel();
    stepping_info = GetStepping();
    extfamily_info = GetExtFamily();
    extmodel_info = GetExtModel();
    cpuname_info = QString().fromStdString(GetCPUName());
    cpufeature_info = GetFeature();

    currentclockspeed_info = GetCurrentClockSpeed();
    extclock_info = GetExtClock();
    multiplier = currentclockspeed_info/extclock_info;
    maxclockspeed_info = GetMaxClockSpeed();

    core_info = GetCore();
    thread_info = GetThread();

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QString("Manufacturer"));

    label_cpu_name->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_cpu_name->setText(manufacturer_info);
    label_cpu_name->setFixedSize(50,20);

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QString("Code Name"));

    label_cpu_code_name->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_cpu_code_name->setText(QString("default"));
    label_cpu_code_name->setFixedSize(50,20);

    QLabel *label3 = new QLabel(this);
    label3->setFrameStyle(QFrame::NoFrame);
    label3->setText(QString("Socket Designation"));

    label_max_TDP->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_max_TDP->setText(socketdesignation_info);
    label_max_TDP->setFixedSize(50,20);

    //QLabel *label4 = new QLabel(this);
    //label4->setFrameStyle(QFrame::NoFrame);
    //label4->setText(QString("Package"));

    //label_package->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    //label_package->setText(QStringLiteral("xxxxx"));
    //label_package->setFixedSize(50,20);

    //QLabel *label5 = new QLabel(this);
    //label5->setFrameStyle(QFrame::NoFrame);
    //label5->setText(QString("Technology"));

    //label_technology->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    //label_technology->setText(QStringLiteral("default"));
    //label_technology->setFixedSize(50,20);

    //QLabel *label6 = new QLabel(this);
    //label6->setFrameStyle(QFrame::NoFrame);
    //label6->setText(QString("Core VID"));

    //label_core_VID->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    //label_core_VID->setText(QStringLiteral("default"));
    //label_core_VID->setFixedSize(50,20);

    QLabel *label7 = new QLabel(this);
    label7->setFrameStyle(QFrame::NoFrame);
    label7->setText(QString("Family"));

    label_family->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_family->setText(QString("%0").arg(family_info));
    label_family->setFixedSize(50,20);

    QLabel *label8 = new QLabel(this);
    label8->setFrameStyle(QFrame::NoFrame);
    label8->setText(QString("Model"));

    label_model->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_model->setText(QString("%0").arg(model_info));
    label_model->setFixedSize(50,20);

    QLabel *label9 = new QLabel(this);
    label9->setFrameStyle(QFrame::NoFrame);
    label9->setText(QString("Stepping"));

    label_stepping->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_stepping->setText(QString("%0").arg(stepping_info));
    label_stepping->setFixedSize(50,20);

    QLabel *label10 = new QLabel(this);
    label10->setFrameStyle(QFrame::NoFrame);
    label10->setText(QString("Ext Family"));

    label_ext_family->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_ext_family->setText(QString("%0").arg(extfamily_info));
    label_ext_family->setFixedSize(50,20);

    QLabel *label11 = new QLabel(this);
    label11->setFrameStyle(QFrame::NoFrame);
    label11->setText(QString("Ext Model"));

    label_ext_model->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_ext_model->setText(QString("%0").arg(extmodel_info));
    label_ext_model->setFixedSize(50,20);

    QLabel *label12 = new QLabel(this);
    label12->setFrameStyle(QFrame::NoFrame);
    label12->setText(QString("Revision"));

    label_revision->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_revision->setText(QString("default"));//QString("%0").arg(revision_info)
    label_revision->setFixedSize(50,20);

    QLabel *label13 = new QLabel(this);
    label13->setFrameStyle(QFrame::NoFrame);
    label13->setText(QString("Specification"));
    QLineEdit *lineedit1 = new QLineEdit(this);
    lineedit1->setReadOnly(true);
    lineedit1->setFrame(false);
    label_specification->setBuddy(lineedit1);
    label_specification->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_specification->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    label_specification->setMaximumHeight(30);
    label_specification->setMinimumWidth(300);
    label_specification->setText(cpuname_info);
/*
    switch(manufacturer_info)
    {
    case:
    {
        break;
    }
    case:
    {
        break;
    }
    case:
    {
        break;
    }
    default:
    {
        break;
    }
    }
*/
    if(manufacturer_info.contains("GenuineIntel"))
    {
        if(cpufeature_info.IntelFeature.SSE3)
            instructionset_info+="SSE3 ";
        if(cpufeature_info.IntelFeature.PCLMULQDQ)
            instructionset_info+="PCLMULQDQ ";
        if(cpufeature_info.IntelFeature.DTES64)
            instructionset_info+="DTES64 ";
        if(cpufeature_info.IntelFeature.MONITOR)
            instructionset_info+="MONITOE ";
        if(cpufeature_info.IntelFeature.DS_CPL)
            instructionset_info+="DS_CPL ";
        if(cpufeature_info.IntelFeature.VMX)
            instructionset_info+="VMX ";
        if(cpufeature_info.IntelFeature.SMX)
            instructionset_info+="SMX ";
        if(cpufeature_info.IntelFeature.EIST)
            instructionset_info+="EIST ";
        if(cpufeature_info.IntelFeature.TM2)
            instructionset_info+="TM2 ";
        if(cpufeature_info.IntelFeature.SSSE3)
            instructionset_info+="SSSE3 ";
        if(cpufeature_info.IntelFeature.CNXT_ID)
            instructionset_info+="CNXT_ID ";
        if(cpufeature_info.IntelFeature.SDBG)
            instructionset_info+="SDBG ";
        if(cpufeature_info.IntelFeature.FMA)
            instructionset_info+="FMA ";
        if(cpufeature_info.IntelFeature.CMPXCHG16B)
            instructionset_info+="CMPXCHG16B ";
        if(cpufeature_info.IntelFeature.xTPR_Update_Control)
            instructionset_info+="xTPR_Update_Control ";
        if(cpufeature_info.IntelFeature.PDCM)
            instructionset_info+="PDCM ";
        if(cpufeature_info.IntelFeature.PCID)
            instructionset_info+="PCID ";
        if(cpufeature_info.IntelFeature.DCA)
            instructionset_info+="DCA ";
        if(cpufeature_info.IntelFeature.SSE4_1)
            instructionset_info+="SSE4_1 ";
        if(cpufeature_info.IntelFeature.SSE4_2)
            instructionset_info+="SSE4_2 ";
        if(cpufeature_info.IntelFeature.x2APIC)
            instructionset_info+="x2APIC ";
        if(cpufeature_info.IntelFeature.MOVBE)
            instructionset_info+="MOVBE ";
        if(cpufeature_info.IntelFeature.POPCNT)
            instructionset_info+="POPCNT ";
        if(cpufeature_info.IntelFeature.TSC_Deadline)
            instructionset_info+="TSC_Deadline ";
        if(cpufeature_info.IntelFeature.AESNI)
            instructionset_info+="AESNI ";
        if(cpufeature_info.IntelFeature.XSAVE)
            instructionset_info+="XSAVE ";
        if(cpufeature_info.IntelFeature.OSXSAVE)
            instructionset_info+="OSXSAVE ";
        if(cpufeature_info.IntelFeature.AVX)
            instructionset_info+="AVX ";
        if(cpufeature_info.IntelFeature.F16C)
            instructionset_info+="F16C ";
        if(cpufeature_info.IntelFeature.RDRAND)
            instructionset_info+="RDRAND";
    }
    else if(manufacturer_info =="")
    {}
    else if(manufacturer_info =="")
    {}


    QLabel *label14 = new QLabel(this);
    label14->setFrameStyle(QFrame::NoFrame);
    label14->setText(QString("Instructions"));
    label14->adjustSize();
    label_instructions->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_instructions->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    label_instructions->setReadOnly(true);
    label_instructions->setText(instructionset_info);


    //content  clock
    QLabel *label15 = new QLabel(this);
    label15->setFrameStyle(QFrame::NoFrame);
    label15->setText(QString("Core Speed"));
    label_core_speed->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_core_speed->setText(QString("%0").arg(currentclockspeed_info));
    label_core_speed->setFixedSize(50,20);

    QLabel *label16 = new QLabel(this);
    label16->setFrameStyle(QFrame::NoFrame);
    label16->setText(QString("Multiplier"));
    label_multiplier->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_multiplier->setText(QString("%0").arg(multiplier));//QString("%0").arg(currentclockspeed_info/extclock_info)
    label_multiplier->setFixedSize(50,20);

    QLabel *label17 = new QLabel(this);
    label17->setFrameStyle(QFrame::NoFrame);
    label17->setText(QString("Ext Speed"));
    label_bus_speed->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_bus_speed->setText(QString("%0").arg(extclock_info));
    label_bus_speed->setFixedSize(50,20);

    QLabel *label18 = new QLabel(this);
    label18->setFrameStyle(QFrame::NoFrame);
    label18->setText(QString("Max speed"));
    label_rated_FSB->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_rated_FSB->setText(QString("%0").arg(maxclockspeed_info));
    label_rated_FSB->setFixedSize(50,20);

    //content cache
    for(unsigned int i=0;i<4;i++)
    {
        Cache_info cache_temp = *(cache_info+i);
        if(cache_temp.Cache_level == 1)
        {
            if(cache_temp.Cache_type == 'D')
            {
                cache1D = cache_temp;
            }
            else if(cache_temp.Cache_type == 'T')
            {
                cache1I = cache_temp;
            }
        }
        else if(cache_temp.Cache_level == 2)
        {
            cache2 = cache_temp;
        }
        else if(cache_temp.Cache_level == 3)
        {
            cache3 = cache_temp;
        }
    }
    cache1I.Cache_Size = cache1I.Cache_Size/1024;
    cache1D.Cache_Size = cache1D.Cache_Size/1024;
    cache2.Cache_Size = cache2.Cache_Size/1024;
    cache3.Cache_Size = cache3.Cache_Size/1024/1024;
    QLabel *label19 = new QLabel(this);
    label19->setFrameStyle(QFrame::NoFrame);
    label19->setText(QString("L1 Data"));

    label_L1_data_size1->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_data_size1->setText(QString("%0KB").arg(cache1D.Cache_Size));//QString("%0").arg(cache_info->Cache_Size)
    label_L1_data_size1->setFixedSize(50,20);


    label_L1_data_way->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_data_way->setText(QString("%0-way").arg(cache1D.Cache_Ways));//QString("%0").arg(cache_info->Cache_Ways)
    label_L1_data_way->setFixedSize(50,20);

    QLabel *label20 = new QLabel(this);
    label20->setFrameStyle(QFrame::NoFrame);
    label20->setText(QStringLiteral("L1 Instruction"));


    label_L1_inst_size1->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_inst_size1->setText(QString("%0KB").arg(cache1I.Cache_Size));
    label_L1_inst_size1->setFixedSize(50,20);


    label_L1_inst_way->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_inst_way->setText(QString("%0-way").arg(cache1I.Cache_Ways));
    label_L1_inst_way->setFixedSize(50,20);

    QLabel *label21 = new QLabel(this);
    label21->setFrameStyle(QFrame::NoFrame);
    label21->setText(QStringLiteral("L2"));

    label_L2_size1->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L2_size1->setText(QString("%0MB").arg(cache2.Cache_Size));
    label_L2_size1->setFixedSize(50,20);


    label_L2_way->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L2_way->setText(QString("%0-way").arg(cache2.Cache_Ways));
    label_L2_way->setFixedSize(50,20);

    QLabel *label22 = new QLabel(this);
    label22->setFrameStyle(QFrame::NoFrame);
    label22->setText(QStringLiteral("L3"));

    label_L3_size1->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L3_size1->setText(QString("%0MB").arg(cache3.Cache_Size));
    label_L3_size1->setFixedSize(50,20);

    label_L3_way->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L3_way->setText(QString("%0-way").arg(cache3.Cache_Ways));
    label_L3_way->setFixedSize(50,20);

    //content choosed
    QLabel *label23 = new QLabel(this);
    label23->setFrameStyle(QFrame::NoFrame);
    label23->setText(QStringLiteral("selected"));

    /*
    for(unsigned int i=1;i<=core_info;i++)
    {
        cpuNum_list<<QString("CPU%0").arg(i);
    }
    QComboBox *combobox = new QComboBox(this);
    for(unsigned int i = 0;i<cpuNum_list.length();i++)
        combobox->insertItem(i,cpuNum_list.at(i));
*/
    QComboBox *combobox = new QComboBox(this);
    combobox->insertItem(0,QString("CPU1"));

    QLabel *label24 = new QLabel(this);
    label24->setFrameStyle(QFrame::NoFrame);
    label24->setText(QStringLiteral("Cores"));
    //const unsigned int cores = GetCore();
    label_cores->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_cores->setText(QString("%0").arg(core_info));
    label_cores->setFixedSize(50,20);

    QLabel *label25 = new QLabel(this);
    label25->setFrameStyle(QFrame::NoFrame);
    label25->setText(QStringLiteral("Threads"));
    //const unsigned int value_threads = GetThread();
    label_threads->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_threads->setText(QString("%0").arg(thread_info));
    label_threads->setFixedSize(50,20);

    connect(combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(cpuChoose(int)));

    QGridLayout *cpugrouplayout = new QGridLayout;
    cpugrouplayout->setContentsMargins(20,10,0,10);
    cpugrouplayout->setSpacing(5);
    cpugrouplayout->setColumnStretch(0,0);
    cpugrouplayout->setColumnStretch(1,100);
    cpugrouplayout->setColumnStretch(2,0);
    cpugrouplayout->setColumnStretch(3,100);
    cpugrouplayout->setColumnStretch(4,0);
    cpugrouplayout->setColumnStretch(5,100);
    cpugrouplayout->setRowStretch(0,10);
    cpugrouplayout->setRowStretch(1,0);
    cpugrouplayout->setRowStretch(2,0);
    cpugrouplayout->setRowStretch(3,0);
    cpugrouplayout->setRowStretch(4,0);
    cpugrouplayout->setRowStretch(5,0);
    cpugrouplayout->addWidget(label1,0,0,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_cpu_name,0,1,1,1,Qt::AlignLeft);
    cpugrouplayout->addWidget(label2,0,2,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_cpu_code_name,0,3,1,1,Qt::AlignLeft);
    cpugrouplayout->addWidget(label3,0,4,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_max_TDP,0,5,1,1,Qt::AlignLeft);

    //cpugrouplayout->addWidget(label4,1,0,1,1,Qt::AlignCenter);
    //cpugrouplayout->addWidget(label_package,1,1,1,1,Qt::AlignLeft);
    //cpugrouplayout->addWidget(label5,1,2,1,1,Qt::AlignCenter);
    //cpugrouplayout->addWidget(label_technology,1,3,1,1,Qt::AlignLeft);
    //cpugrouplayout->addWidget(label6,1,4,1,1,Qt::AlignCenter);
    //cpugrouplayout->addWidget(label_core_VID,1,5,1,1,Qt::AlignLeft);

    cpugrouplayout->addWidget(label7,2,0,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_family,2,1,1,1,Qt::AlignLeft);
    cpugrouplayout->addWidget(label8,2,2,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_model,2,3,1,1,Qt::AlignLeft);
    cpugrouplayout->addWidget(label9,2,4,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_stepping,2,5,1,1,Qt::AlignLeft);

    cpugrouplayout->addWidget(label10,3,0,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_ext_family,3,1,1,1,Qt::AlignLeft);
    cpugrouplayout->addWidget(label11,3,2,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_ext_model,3,3,1,1,Qt::AlignLeft);
    cpugrouplayout->addWidget(label12,3,4,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_revision,3,5,1,1,Qt::AlignLeft);

    cpugrouplayout->addWidget(label13,4,0,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_specification,4,1,1,6,Qt::AlignLeft);

    cpugrouplayout->addWidget(label14,5,0,1,1,Qt::AlignCenter);
    cpugrouplayout->addWidget(label_instructions,5,1,1,6,Qt::AlignLeft);

    QGridLayout *clockgrouplayout = new QGridLayout;
    clockgrouplayout->setContentsMargins(20,10,20,10);
    clockgrouplayout->setColumnStretch(0,5);
    clockgrouplayout->setColumnStretch(1,10);
    clockgrouplayout->addWidget(label15,0,0,1,1,Qt::AlignCenter);
    clockgrouplayout->addWidget(label_core_speed,0,1,1,1,Qt::AlignLeft);
    clockgrouplayout->addWidget(label16,1,0,1,1,Qt::AlignCenter);
    clockgrouplayout->addWidget(label_multiplier,1,1,1,1,Qt::AlignLeft);
    clockgrouplayout->addWidget(label17,2,0,1,1,Qt::AlignCenter);
    clockgrouplayout->addWidget(label_bus_speed,2,1,1,1,Qt::AlignLeft);
    clockgrouplayout->addWidget(label18,3,0,1,1,Qt::AlignCenter);
    clockgrouplayout->addWidget(label_rated_FSB,3,1,1,1,Qt::AlignLeft);

    QGridLayout *cachegrouplayout = new QGridLayout;
    cachegrouplayout->setContentsMargins(50,10,20,10);
    cachegrouplayout->setColumnStretch(0,0);
    cachegrouplayout->setColumnStretch(1,0);
    cachegrouplayout->setColumnStretch(2,100);
    cachegrouplayout->addWidget(label19,0,0,1,1,Qt::AlignCenter);
    cachegrouplayout->addWidget(label_L1_data_size1,0,1,1,1,Qt::AlignLeft);
    cachegrouplayout->addWidget(label_L1_data_way,0,2,1,1,Qt::AlignLeft);

    cachegrouplayout->addWidget(label20,1,0,1,1,Qt::AlignCenter);
    cachegrouplayout->addWidget(label_L1_inst_size1,1,1,1,1,Qt::AlignLeft);
    cachegrouplayout->addWidget(label_L1_inst_way,1,2,1,1,Qt::AlignLeft);

    cachegrouplayout->addWidget(label21,2,0,1,1,Qt::AlignCenter);
    cachegrouplayout->addWidget(label_L2_size1,2,1,1,1,Qt::AlignLeft);
    cachegrouplayout->addWidget(label_L2_way,2,2,1,1,Qt::AlignLeft);

    cachegrouplayout->addWidget(label22,3,0,1,1,Qt::AlignCenter);
    cachegrouplayout->addWidget(label_L3_size1,3,1,1,1,Qt::AlignLeft);
    cachegrouplayout->addWidget(label_L3_way,3,2,1,1,Qt::AlignLeft);

    QGridLayout *choosedgrouplayout = new QGridLayout;
    choosedgrouplayout->setContentsMargins(20,10,300,10);
    choosedgrouplayout->setColumnStretch(0,0);
    choosedgrouplayout->setColumnStretch(1,100);
    choosedgrouplayout->setColumnStretch(2,0);
    choosedgrouplayout->setColumnStretch(3,100);
    choosedgrouplayout->setColumnStretch(4,0);
    choosedgrouplayout->setColumnStretch(5,100);
    choosedgrouplayout->addWidget(label23,0,0,Qt::AlignCenter);
    choosedgrouplayout->addWidget(combobox,0,1,Qt::AlignLeft);
    choosedgrouplayout->addWidget(label24,0,2,Qt::AlignCenter);
    choosedgrouplayout->addWidget(label_cores,0,3,Qt::AlignLeft);
    choosedgrouplayout->addWidget(label25,0,4,Qt::AlignCenter);
    choosedgrouplayout->addWidget(label_threads,0,5,Qt::AlignLeft);

    //groupbox
    QGroupBox *cpugroup = new QGroupBox(tr("CPU"));
    QGroupBox *clockgroup = new QGroupBox(tr("CLOCK"));
    QGroupBox *cachegroup = new QGroupBox(tr("Cache"));
    QGroupBox *choosegroup = new QGroupBox(tr("Choosed"));

    cpugroup->setLayout(cpugrouplayout);
    cpugroup->setMinimumWidth(760);
    cpugroup->setMaximumHeight(300);
    cpugroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);

    clockgroup->setLayout(clockgrouplayout);
    clockgroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    clockgroup->setMinimumWidth(300);
    clockgroup->setMaximumHeight(200);

    cachegroup->setLayout(cachegrouplayout);
    cachegroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    cachegroup->setMinimumWidth(400);
    cachegroup->setMaximumHeight(200);

    choosegroup->setLayout(choosedgrouplayout);
    choosegroup->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    choosegroup->setMinimumWidth(760);
    choosegroup->setMaximumHeight(100);
//page2 cache content
    QLabel *label26 = new QLabel(this);
    label26->setFrameStyle(QFrame::NoFrame);
    label26->setText(QStringLiteral("Size"));
    label_L1_data_size2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_data_size2->setText(QString("%0KB").arg(cache1D.Cache_Size));
    label_L1_data_size2->setMaximumHeight(20);
    label_L1_data_way2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_data_way2->setText(QString("x%0").arg(core_info));
    label_L1_data_way2->setMaximumHeight(20);

    QLabel *label27 = new QLabel(this);
    label27->setFrameStyle(QFrame::NoFrame);
    label27->setText(QStringLiteral("Descriptor"));
    label_L1_data_description->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_data_description->setText(QString("%0-ways set associative, %1-byte line size").arg(cache1D.Cache_Ways).arg(cache1D.Cache_line_size));
    label_L1_data_description->setMaximumHeight(20);

    QLabel *label28 = new QLabel(this);
    label28->setFrameStyle(QFrame::NoFrame);
    label28->setText(QStringLiteral("Size"));
    label_L1_inst_size2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_inst_size2->setText(QString("%0KB").arg(cache1I.Cache_Size));
    label_L1_inst_size2->setMaximumHeight(20);
    label_L1_inst_way2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_inst_way2->setText(QString("x%0").arg(core_info));
    label_L1_inst_way2->setMaximumHeight(20);
    QLabel *label29 = new QLabel(this);
    label29->setFrameStyle(QFrame::NoFrame);
    label29->setText(QStringLiteral("Descriptor"));
    label_L1_inst_description->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L1_inst_description->setText(QString("%0-ways set associative, %1-byte line size").arg(cache1I.Cache_Ways).arg(cache1I.Cache_line_size));
    label_L1_inst_description->setMaximumHeight(20);

    QLabel *label30 = new QLabel(this);
    label30->setFrameStyle(QFrame::NoFrame);
    label30->setText(QStringLiteral("Size"));
    label_L2_size2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L2_size2->setText(QString("%0KB").arg(cache2.Cache_Size));
    label_L2_size2->setMaximumHeight(20);
    label_L2_way2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L2_way2->setText(QString("x%0").arg(core_info));
    label_L2_way2->setMaximumHeight(20);

    QLabel *label31 = new QLabel(this);
    label31->setFrameStyle(QFrame::NoFrame);
    label31->setText(QStringLiteral("Descriptor"));
    label_L2_description->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L2_description->setText(QString("%0-ways set associative, %1-byte line size").arg(cache2.Cache_Ways).arg(cache2.Cache_line_size));
    label_L2_description->setMaximumHeight(20);

    QLabel *label32 = new QLabel(this);
    label32->setFrameStyle(QFrame::NoFrame);
    label32->setText(QStringLiteral("Size"));
    label_L3_size2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L3_size2->setText(QString("%0MB").arg(cache3.Cache_Size));
    label_L3_size2->setMaximumHeight(20);
    label_L3_way2->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L3_way2->setText(QString("x%0").arg(core_info));
    label_L3_way2->setMaximumHeight(20);

    QLabel *label33 = new QLabel(this);
    label33->setFrameStyle(QFrame::NoFrame);
    label33->setText(QStringLiteral("Descriptor"));
    label_L3_description->setFrameStyle(QFrame::WinPanel|QFrame::Sunken);
    label_L3_description->setText(QString("%0-ways set associative, %1-byte line size").arg(cache3.Cache_Ways).arg(cache3.Cache_line_size));
    label_L3_description->setMaximumHeight(20);

    QGridLayout *firdatagrouplayout = new QGridLayout;
    firdatagrouplayout->setContentsMargins(100,20,20,20);
    firdatagrouplayout->setVerticalSpacing(5);
    firdatagrouplayout->setHorizontalSpacing(5);
    firdatagrouplayout->setColumnStretch(0,0);
    firdatagrouplayout->setColumnStretch(1,0);
    firdatagrouplayout->setColumnStretch(2,100);
    firdatagrouplayout->addWidget(label26,0,0,1,1,Qt::AlignCenter);
    firdatagrouplayout->addWidget(label_L1_data_size2,0,1,1,1,Qt::AlignLeft);
    firdatagrouplayout->addWidget(label_L1_data_way2,0,2,1,1,Qt::AlignLeft);
    firdatagrouplayout->addWidget(label27,1,0,1,1,Qt::AlignCenter);
    firdatagrouplayout->addWidget(label_L1_data_description,1,1,1,2,Qt::AlignLeft);
    QGridLayout *firinstgrouplayout = new QGridLayout;
    firinstgrouplayout->setContentsMargins(100,20,20,20);
    firinstgrouplayout->setVerticalSpacing(5);
    firinstgrouplayout->setColumnStretch(0,0);
    firinstgrouplayout->setColumnStretch(1,0);
    firinstgrouplayout->setColumnStretch(2,100);
    firinstgrouplayout->addWidget(label28,0,0,1,1,Qt::AlignCenter);
    firinstgrouplayout->addWidget(label_L1_inst_size2,0,1,1,1,Qt::AlignLeft);
    firinstgrouplayout->addWidget(label_L1_inst_way2,0,2,1,1,Qt::AlignLeft);
    firinstgrouplayout->addWidget(label29,1,0,1,1,Qt::AlignCenter);
    firinstgrouplayout->addWidget(label_L1_inst_description,1,1,1,2,Qt::AlignLeft);
    QGridLayout *secgrouplayout = new QGridLayout;
    secgrouplayout->setContentsMargins(100,20,20,20);
    secgrouplayout->setVerticalSpacing(5);
    secgrouplayout->setColumnStretch(0,0);
    secgrouplayout->setColumnStretch(1,0);
    secgrouplayout->setColumnStretch(2,100);
    secgrouplayout->addWidget(label30,0,0,1,1,Qt::AlignCenter);
    secgrouplayout->addWidget(label_L2_size2,0,1,1,1,Qt::AlignLeft);
    secgrouplayout->addWidget(label_L2_way2,0,2,1,1,Qt::AlignLeft);
    secgrouplayout->addWidget(label31,1,0,1,1,Qt::AlignCenter);
    secgrouplayout->addWidget(label_L2_description,1,1,1,2,Qt::AlignLeft);
    QGridLayout *thirgrouplayout = new QGridLayout;
    thirgrouplayout->setContentsMargins(100,20,20,20);
    thirgrouplayout->setVerticalSpacing(5);
    thirgrouplayout->setColumnStretch(0,0);
    thirgrouplayout->setColumnStretch(1,0);
    thirgrouplayout->setColumnStretch(2,100);
    thirgrouplayout->addWidget(label32,0,0,1,1,Qt::AlignCenter);
    thirgrouplayout->addWidget(label_L3_size2,0,1,1,1,Qt::AlignLeft);
    thirgrouplayout->addWidget(label_L3_way2,0,2,1,1,Qt::AlignLeft);
    thirgrouplayout->addWidget(label33,1,0,1,1,Qt::AlignCenter);
    thirgrouplayout->addWidget(label_L3_description,1,1,1,2,Qt::AlignLeft);

    QGroupBox *firdatacachegroup = new QGroupBox(tr("L1 D-Cache"));
    QGroupBox *firinstcachegroup = new QGroupBox(tr("L1 I-Cache"));
    QGroupBox *seccachegroup = new QGroupBox(tr("L2 Cache"));
    QGroupBox *thircachegroup = new QGroupBox(tr("L3 Cache"));
    firdatacachegroup->setMinimumWidth(760);
    firinstcachegroup->setMinimumWidth(760);
    seccachegroup->setMinimumWidth(760);
    thircachegroup->setMinimumWidth(760);
    firdatacachegroup->setLayout(firdatagrouplayout);
    firinstcachegroup->setLayout(firinstgrouplayout);
    seccachegroup->setLayout(secgrouplayout);
    thircachegroup->setLayout(thirgrouplayout);

//page3 content
    checkbox_cpuid_cpu1->setText(QString("CPU1"));
    checkbox_cpuid_cpu2->setText(QString("CPU2"));
    checkbox_cpuid_cpu3->setText(QString("CPU3"));
    checkbox_cpuid_cpu4->setText(QString("CPU4"));

    QLabel *label34 = new QLabel(this);
    label34->setFrameStyle(QFrame::NoFrame);
    label34->setText(QStringLiteral("EAX: 0x"));
    //QLineEdit *clabel34 = new QLineEdit(this);
    lineedit_cpuid_input_eax->setText(QStringLiteral(""));
    lineedit_cpuid_input_eax->setMaximumHeight(20);
    lineedit_cpuid_input_eax->setMinimumWidth(50);

    QLabel *label35 = new QLabel(this);
    label35->setFrameStyle(QFrame::NoFrame);
    label35->setText(QStringLiteral("ECX: 0x"));
   // QLineEdit *clabel35 = new QLineEdit(this);
    lineedit_cpuid_input_ecx->setText(QStringLiteral(""));
    lineedit_cpuid_input_ecx->setMaximumHeight(20);
    lineedit_cpuid_input_ecx->setMinimumWidth(50);

    QLabel *label36 = new QLabel(this);
    label36->setFrameStyle(QFrame::NoFrame);
    label36->setText(QStringLiteral("EAX: 0x"));
    //QLineEdit *clabel36 = new QLineEdit(this);
    lineedit_cpuid_output_eax->setText(QStringLiteral(""));
    lineedit_cpuid_output_eax->setMaximumHeight(20);
    lineedit_cpuid_output_eax->setMinimumWidth(50);

    QLabel *label37 = new QLabel(this);
    label37->setFrameStyle(QFrame::NoFrame);
    label37->setText(QStringLiteral("EBX: 0x"));
    //QLineEdit *clabel37 = new QLineEdit(this);
    lineedit_cpuid_output_ebx->setText(QStringLiteral(""));
    lineedit_cpuid_output_ebx->setMaximumHeight(20);
    lineedit_cpuid_output_ebx->setMinimumWidth(50);

    QLabel *label38 = new QLabel(this);
    label38->setFrameStyle(QFrame::NoFrame);
    label38->setText(QStringLiteral("ECX: 0x"));
    //QLineEdit *clabel38 = new QLineEdit(this);
    lineedit_cpuid_output_ecx->setText(QStringLiteral(""));
    lineedit_cpuid_output_ecx->setMaximumHeight(20);
    lineedit_cpuid_output_ecx->setMinimumWidth(50);

    QLabel *label39 = new QLabel(this);
    label39->setFrameStyle(QFrame::NoFrame);
    label39->setText(QStringLiteral("EDX: 0x"));
    //QLineEdit *clabel39 = new QLineEdit(this);
    lineedit_cpuid_output_edx->setText(QStringLiteral(""));
    lineedit_cpuid_output_edx->setMaximumHeight(20);
    lineedit_cpuid_output_edx->setMinimumWidth(50);

    QPushButton *btnread = new QPushButton(this);
    btnread->setText(QString("Read"));

    connect(btnread,SIGNAL(clicked(bool)),this,SLOT(cpuidRead()));

    QPushButton *btnfix1 = new QPushButton(this);
    btnfix1->setText(QString("Fix"));

    QPushButton *btndelete1 = new QPushButton(this);
    btndelete1->setText(QString("Delete"));

    QTableView *tableview = new QTableView(this);
    tableview->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableview->setEditTriggers(QAbstractItemView::NoEditTriggers);

    cpuidmodel->setHorizontalHeaderItem(0,new QStandardItem("Address"));
    cpuidmodel->setHorizontalHeaderItem(1,new QStandardItem("CPU1"));
    cpuidmodel->setHorizontalHeaderItem(2,new QStandardItem("CPU2"));
    cpuidmodel->setHorizontalHeaderItem(3,new QStandardItem("CPU3"));
    cpuidmodel->setHorizontalHeaderItem(4,new QStandardItem("CPU4"));
    cpuidmodel->setItem(0,0,new QStandardItem("address"));
    cpuidmodel->setItem(0,1,new QStandardItem("data1"));
    cpuidmodel->setItem(0,2,new QStandardItem("data1"));
    cpuidmodel->setItem(0,3,new QStandardItem("data1"));
    cpuidmodel->setItem(0,4,new QStandardItem("data1"));
    cpuidmodel->setItem(1,0,new QStandardItem("address"));
    cpuidmodel->setItem(1,1,new QStandardItem("data1"));
    cpuidmodel->setItem(1,2,new QStandardItem("data1"));
    cpuidmodel->setItem(1,3,new QStandardItem("data1"));
    cpuidmodel->setItem(1,4,new QStandardItem("data1"));
    tableview->setModel(cpuidmodel);
    connect(btnfix1,SIGNAL(clicked(bool)),this,SLOT(cpuidtableFix()));
    connect(btndelete1,SIGNAL(clicked(bool)),this,SLOT(cpuidtableDelete()));
    connect(tableview->verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(cpuidtableHeaderChoosed(int)));
//page4 content
    QCheckBox *checkbox6 = new QCheckBox(this);
    QCheckBox *checkbox7 = new QCheckBox(this);
    QCheckBox *checkbox8 = new QCheckBox(this);
    QCheckBox *checkbox9 = new QCheckBox(this);
    QCheckBox *checkbox10 = new QCheckBox(this);
    checkbox_msr_cpu1->setText(QString("CPU1"));
    checkbox_msr_cpu2->setText(QString("CPU2"));
    checkbox_msr_cpu3->setText(QString("CPU3"));
    checkbox_msr_cpu4->setText(QString("CPU4"));

    QLabel *label40 = new QLabel(this);
    label40->setFrameStyle(QFrame::NoFrame);
    label40->setText(QStringLiteral("ECX: 0x"));
    //QLineEdit *clabel40 = new QLineEdit(this);
    lineedit_msr_ecx->setText(QStringLiteral(""));
    lineedit_msr_ecx->setMinimumWidth(50);
    lineedit_msr_ecx->setMaximumHeight(20);

    QLabel *label41 = new QLabel(this);
    label41->setFrameStyle(QFrame::NoFrame);
    label41->setText(QStringLiteral("EAX: 0x"));
    //QLineEdit *clabel41 = new QLineEdit(this);
    lineedit_msr_eax->setText(QStringLiteral(""));
    lineedit_msr_eax->setMaximumHeight(20);
    lineedit_msr_eax->setMinimumWidth(50);

    QLabel *label42 = new QLabel(this);
    label42->setFrameStyle(QFrame::NoFrame);
    label42->setText(QStringLiteral("EDX: 0x"));
    //QLineEdit *clabel42 = new QLineEdit(this);
    lineedit_msr_edx->setText(QStringLiteral(""));
    lineedit_msr_edx->setMaximumHeight(20);
    lineedit_msr_edx->setMinimumWidth(50);


    QPushButton *btnread2 = new QPushButton(this);
    btnread2->setText(QString("Read"));

    connect(btnread2,SIGNAL(clicked(bool)),this,SLOT(msrRead()));

    QPushButton *btnwrite2 = new QPushButton(this);
    btnwrite2->setText(QString("Write"));

    connect(btnwrite2,SIGNAL(clicked(bool)),this,SLOT(msrWrite()));

    QPushButton *btnfix = new QPushButton(this);
    btnfix->setText(QString("Fix"));
    QPushButton *btndele = new QPushButton(this);
    btndele->setText(QString("Delete"));

    QTableView *tableview2 = new QTableView(this);
    tableview2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tableview2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableview2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    msrmodel->setHorizontalHeaderItem(0,new QStandardItem("Address"));
    msrmodel->setHorizontalHeaderItem(1,new QStandardItem("CPU1"));
    msrmodel->setHorizontalHeaderItem(2,new QStandardItem("CPU2"));
    msrmodel->setHorizontalHeaderItem(3,new QStandardItem("CPU3"));
    msrmodel->setHorizontalHeaderItem(4,new QStandardItem("CPU4"));
    msrmodel->setItem(0,0,new QStandardItem("address"));
    msrmodel->setItem(0,1,new QStandardItem("data1"));
    msrmodel->setItem(0,2,new QStandardItem("data1"));
    msrmodel->setItem(0,3,new QStandardItem("data1"));
    msrmodel->setItem(0,4,new QStandardItem("data1"));
    msrmodel->setItem(1,0,new QStandardItem("address"));
    msrmodel->setItem(1,1,new QStandardItem("data1"));
    msrmodel->setItem(1,2,new QStandardItem("data1"));
    msrmodel->setItem(1,3,new QStandardItem("data1"));
    msrmodel->setItem(1,4,new QStandardItem("data1"));
    tableview2->setModel(msrmodel);

    connect(btnfix,SIGNAL(clicked(bool)),this,SLOT(msrtablefix()));
    connect(btndele,SIGNAL(clicked(bool)),this,SLOT(msrtabledelete()));
    connect(tableview2->verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(msrtableHeaderChoosed(int)));

    //4  page
    QWidget *pagecpu = new QWidget();
    QWidget *pagecache = new QWidget();
    QWidget *pagecpuid = new QWidget();
    QWidget *pagemsr = new QWidget();

    QGridLayout *page1layout = new QGridLayout;
    QGridLayout *page2layout = new QGridLayout;
    QGridLayout *page3layout = new QGridLayout;
    QGridLayout *page4layout = new QGridLayout;
    page1layout->setContentsMargins(10,10,10,10);
    page1layout->setColumnStretch(0,0);
    page1layout->setColumnStretch(1,100);

    //page1layout->setRowStretch(0,0);
    //page1layout->setRowStretch(1,2);
    //page1layout->setRowStretch(2,1);
    page1layout->setSpacing(5);
    page1layout->setColumnStretch(0,1);
    page1layout->setColumnStretch(1,0);
    page1layout->setColumnStretch(2,0);
    page1layout->setColumnStretch(3,1);
    page1layout->addWidget(cpugroup,0,1,
                           1,2,Qt::AlignCenter);
    page1layout->addWidget(clockgroup,1,1,
                           1,1,Qt::AlignLeft);
    page1layout->addWidget(cachegroup,1,2,
                           1,1,Qt::AlignRight);
    page1layout->addWidget(choosegroup,2,1,
                           1,2,Qt::AlignCenter);

    page2layout->setContentsMargins(10,10,10,10);
    page2layout->addWidget(firdatacachegroup,0,0,1,1,Qt::AlignLeft);
    page2layout->addWidget(firinstcachegroup,1,0,1,1,Qt::AlignLeft);
    page2layout->addWidget(seccachegroup,2,0,1,1,Qt::AlignLeft);
    page2layout->addWidget(thircachegroup,3,0,1,1,Qt::AlignLeft);

    page3layout->setContentsMargins(100,20,100,0);
    //page3layout->setVerticalSpacing(5);
    //page3layout->setHorizontalSpacing(5);
    page3layout->setColumnStretch(0,20);
    page3layout->setColumnStretch(1,0);
    page3layout->setColumnStretch(2,0);
    page3layout->setColumnStretch(3,0);
    page3layout->setColumnStretch(4,0);
    page3layout->setColumnStretch(5,0);
    page3layout->setColumnStretch(6,20);
    //page3layout->setColumnMinimumWidth(1,5);
    //page3layout->setColumnMinimumWidth(5,5);
    page3layout->setRowStretch(0,2);
    page3layout->setRowStretch(1,0);
    page3layout->setRowStretch(2,0);
    page3layout->setRowStretch(3,0);
    page3layout->setRowStretch(4,2);
    page3layout->setRowStretch(5,10);

    page3layout->addWidget(checkbox_cpuid_cpu1,0,1,1,1,Qt::AlignHCenter|Qt::AlignTop);
    page3layout->addWidget(checkbox_cpuid_cpu2,0,2,1,1,Qt::AlignHCenter|Qt::AlignTop);
    page3layout->addWidget(checkbox_cpuid_cpu3,0,3,1,1,Qt::AlignHCenter|Qt::AlignTop);
    page3layout->addWidget(checkbox_cpuid_cpu4,0,4,1,1,Qt::AlignHCenter|Qt::AlignTop);

    page3layout->addWidget(label34,1,0,
                           1,1,Qt::AlignRight);
    page3layout->addWidget(lineedit_cpuid_input_eax,1,1,
                           1,2,Qt::AlignLeft);
    page3layout->addWidget(label35,1,4,
                           1,1,Qt::AlignRight);
    page3layout->addWidget(lineedit_cpuid_input_ecx,1,5,
                           1,2,Qt::AlignLeft);
    page3layout->addWidget(label36,2,0,
                           1,1,Qt::AlignRight);
    page3layout->addWidget(lineedit_cpuid_output_eax,2,1,
                           1,2,Qt::AlignLeft);
    page3layout->addWidget(label37,2,4,
                           1,1,Qt::AlignRight);
    page3layout->addWidget(lineedit_cpuid_output_ebx,2,5,
                           1,2,Qt::AlignLeft);
    page3layout->addWidget(label38,3,0,
                           1,1,Qt::AlignRight);
    page3layout->addWidget(lineedit_cpuid_output_ecx,3,1,
                           1,2,Qt::AlignLeft);
    page3layout->addWidget(label39,3,4,
                           1,1,Qt::AlignRight);
    page3layout->addWidget(lineedit_cpuid_output_edx,3,5,
                           1,2,Qt::AlignLeft);
    page3layout->addWidget(btnread,4,1,
                           1,1,Qt::AlignCenter);
    page3layout->addWidget(btnfix1,4,4,
                           1,1,Qt::AlignCenter);
    page3layout->addWidget(btndelete1,4,5,
                           1,1,Qt::AlignCenter);
    page3layout->addWidget(tableview,5,0,
                           1,7,Qt::AlignCenter);

    page4layout->setContentsMargins(0,20,0,0);
    page4layout->setVerticalSpacing(5);
    page4layout->setHorizontalSpacing(5);
    page4layout->setRowStretch(0,1);
    page4layout->setRowStretch(1,0);
    page4layout->setRowStretch(2,0);
    page4layout->setRowStretch(3,0);
    page4layout->setRowStretch(4,1);
    page4layout->setRowStretch(5,10);
    page4layout->setColumnStretch(0,10);
    page4layout->setColumnStretch(1,0);
    page4layout->setColumnStretch(2,0);
    page4layout->setColumnStretch(3,0);
    page4layout->setColumnStretch(4,0);
    page4layout->setColumnStretch(5,0);
    page4layout->setColumnStretch(6,10);
    page4layout->addWidget(checkbox_msr_cpu1,0,1,1,1,Qt::AlignHCenter|Qt::AlignTop);
    page4layout->addWidget(checkbox_msr_cpu2,0,2,1,1,Qt::AlignHCenter|Qt::AlignTop);
    page4layout->addWidget(checkbox_msr_cpu3,0,3,1,1,Qt::AlignHCenter|Qt::AlignTop);
    page4layout->addWidget(checkbox_msr_cpu4,0,4,1,1,Qt::AlignHCenter|Qt::AlignTop);

    page4layout->addWidget(label40,1,2,1,1,Qt::AlignRight|Qt::AlignTop);
    page4layout->addWidget(lineedit_msr_ecx,1,3,1,2,Qt::AlignLeft|Qt::AlignTop);
    page4layout->addWidget(label41,2,2,1,1,Qt::AlignRight|Qt::AlignTop);
    page4layout->addWidget(lineedit_msr_eax,2,3,1,2,Qt::AlignLeft|Qt::AlignTop);
    page4layout->addWidget(label42,3,2,1,1,Qt::AlignRight|Qt::AlignTop);
    page4layout->addWidget(lineedit_msr_edx,3,3,1,2,Qt::AlignLeft|Qt::AlignTop);

    page4layout->addWidget(btnread2,4,1,1,1,Qt::AlignHCenter|Qt::AlignBottom);
    page4layout->addWidget(btnwrite2,4,2,1,1,Qt::AlignHCenter|Qt::AlignBottom);
    page4layout->addWidget(btnfix,4,3,1,1,Qt::AlignHCenter|Qt::AlignBottom);
    page4layout->addWidget(btndele,4,5,1,1,Qt::AlignHCenter|Qt::AlignBottom);

    page4layout->addWidget(tableview2,5,0,1,7,Qt::AlignCenter);

    //pagecpu->setMinimumHeight(560);
    //pagecache->setMinimumHeight(560);
    //pagecpuid->setMinimumHeight(560);
    //pagemsr->setMinimumHeight(560);
    pagecpu->setMaximumSize(800,594);
    pagecache->setMaximumSize(800,594);
    pagecpuid->setMaximumSize(800,594);
    pagemsr->setMaximumSize(800,594);
    pagecpu->setLayout(page1layout);
    pagecache->setLayout(page2layout);
    pagecpuid->setLayout(page3layout);
    pagemsr->setLayout(page4layout);

    pagecpu->setWindowFlags(Qt::FramelessWindowHint);
    pagecache->setWindowFlags(Qt::FramelessWindowHint);
    pagecpuid->setWindowFlags(Qt::FramelessWindowHint);
    pagemsr->setWindowFlags(Qt::FramelessWindowHint);

    //tabwidget
    QTabWidget *tabwidget = new QTabWidget(this);
    //tabwidget->setBackgroundRole(QPalette::Dark);
    tabwidget->addTab(pagecpu,QString("CPU"));
    tabwidget->addTab(pagecache,QString("Cache"));
    tabwidget->addTab(pagecpuid,QString("CPUID"));
    tabwidget->addTab(pagemsr,QString("MSR"));
    //root layout
    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(tabwidget);//,0,0,Qt::AlignCenter

    setLayout(layout);
}
void Hard_CPU::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawText(this->rect(),Qt::AlignCenter,tr("cpu"));
}

void Hard_CPU::cpuChoose(int index)
{
    switch (index)
    {
    case 0:
    {
        label_cores->setText(QString("case 0"));
        label_threads->setText(QString("case 0"));
        break;
    }
    case 1:
    {
        label_cores->setText(QString("case 1"));
        label_threads->setText(QString("case 1"));
        break;
    }
    case 2:
    {
        label_cores->setText(QString("case 2"));
        label_threads->setText(QString("case 2"));
        break;
    }
    case 3:
    {
        label_cores->setText(QString("case 3"));
        label_threads->setText(QString("case 3"));
        break;
    }
    default:
    {
        label_cores->setText(QString("default"));
        label_threads->setText(QString("default"));
        break;
    }
    }
    update();
}
void Hard_CPU::cpuidRead()
{
    QString str_eax = lineedit_cpuid_input_eax->text();
    QString str_ecx = lineedit_cpuid_input_ecx->text();
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_eax)&&regexp.exactMatch(str_ecx))
    {
        unsigned int multicheck_flag = 0;
        if(checkbox_cpuid_cpu1->isChecked())
        {
            multicheck_flag = multicheck_flag|0x1;
        }
        if(checkbox_cpuid_cpu2->isChecked())
        {
            multicheck_flag = multicheck_flag|0x2;
        }
        if(checkbox_cpuid_cpu3->isChecked())
        {
            multicheck_flag = multicheck_flag|0x4;
        }
        if(checkbox_cpuid_cpu4->isChecked())
        {
            multicheck_flag = multicheck_flag|0x8;
        }
        switch (multicheck_flag)
        {
        case 0x1:
        {
            break;
        }
        case 0x2:
        {
            break;
        }
        case 0x4:
        {
            break;
        }
        case 0x8:
        {
            break;
        }
        default:
        {
            QMessageBox *messagebox = new QMessageBox(this);
            messagebox->setText("Please choose one CPU");
            messagebox->exec();
            break;
        }
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText("invalid input");
        messagebox->exec();
    }
    //qDebug()<<"cpuid read clicked";
}
void Hard_CPU::cpuidtableHeaderChoosed(int index)
{
    removecpuidRow = index;
}
void Hard_CPU::cpuidtableFix()
{
    QList <QStandardItem *> list;
    list<<new QStandardItem("address")<<new QStandardItem("xxxx")<<new QStandardItem("xxxx")<<new QStandardItem("xxxx")<<new QStandardItem("xxxx");
    cpuidmodel->appendRow(list);
}
void Hard_CPU::cpuidtableDelete()
{
    cpuidmodel->removeRow(removecpuidRow);
    update();
}
void Hard_CPU::msrCpuChoose()
{}
void Hard_CPU::msrRead()
{
    QString str_ecx = lineedit_msr_ecx->text();
    QString str_eax = lineedit_msr_eax->text();
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_eax)&&regexp.exactMatch(str_ecx))
    {
        unsigned int multicheck_flag = 0;
        if(checkbox_msr_cpu1->isChecked())
        {
            multicheck_flag = multicheck_flag|0x1;
        }
        if(checkbox_msr_cpu2->isChecked())
        {
            multicheck_flag = multicheck_flag|0x2;
        }
        if(checkbox_msr_cpu3->isChecked())
        {
            multicheck_flag = multicheck_flag|0x4;
        }
        if(checkbox_msr_cpu4->isChecked())
        {
            multicheck_flag = multicheck_flag|0x8;
        }
        switch (multicheck_flag)
        {
        case 0x1:
        {
            lineedit_msr_edx->setText(QString("cpu1 read"));
            break;
        }
        case 0x2:
        {
            lineedit_msr_edx->setText(QString("cpu2 read"));
            break;
        }
        case 0x4:
        {
            lineedit_msr_edx->setText(QString("cpu3 read"));
            break;
        }
        case 0x8:
        {
            lineedit_msr_edx->setText(QString("cpu4 read"));
            break;
        }
        default:
        {
            QMessageBox *messagebox = new QMessageBox(this);
            messagebox->setText("Please choose one CPU");
            messagebox->exec();
            break;
        }
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText("invalid input");
        messagebox->exec();
    }
}
void Hard_CPU::msrWrite()
{
    QString str_ecx = lineedit_msr_ecx->text();
    QString str_eax = lineedit_msr_eax->text();
    QString str_edx = lineedit_msr_edx->text();
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_eax)&&regexp.exactMatch(str_ecx)&&regexp.exactMatch(str_edx))
    {
        unsigned int multicheck_flag = 0;
        if(checkbox_msr_cpu1->isChecked())
        {
            multicheck_flag = multicheck_flag|0x1;
        }
        if(checkbox_msr_cpu2->isChecked())
        {
            multicheck_flag = multicheck_flag|0x2;
        }
        if(checkbox_msr_cpu3->isChecked())
        {
            multicheck_flag = multicheck_flag|0x4;
        }
        if(checkbox_msr_cpu4->isChecked())
        {
            multicheck_flag = multicheck_flag|0x8;
        }
        switch (multicheck_flag)
        {
        case 0x1:
        {
            lineedit_msr_edx->setText(QString("cpu1 write"));
            break;
        }
        case 0x2:
        {
            lineedit_msr_edx->setText(QString("cpu2 write"));
            break;
        }
        case 0x4:
        {
            lineedit_msr_edx->setText(QString("cpu3 write"));
            break;
        }
        case 0x8:
        {
            lineedit_msr_edx->setText(QString("cpu4 write"));
            break;
        }
        default:
        {
            QMessageBox *messagebox = new QMessageBox(this);
            messagebox->setText("Please choose one CPU");
            messagebox->exec();
            break;
        }
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText("invalid input");
        messagebox->exec();
    }
}
void Hard_CPU::msrtablefix()
{
    QList <QStandardItem *> list;
    list<<new QStandardItem("address")<<new QStandardItem("xxxx")<<new QStandardItem("xxxx")<<new QStandardItem("xxxx")<<new QStandardItem("xxxx");
    msrmodel->appendRow(list);
}
void Hard_CPU::msrtableHeaderChoosed(int index)
{
    //msrmodel->removeRow(index);
    removemsrRow = index;
}
void Hard_CPU::msrtabledelete()
{
    if(removemsrRow!=999)
    {
        msrmodel->removeRow(removemsrRow);
        removemsrRow = 999;
    }
    update();
}
