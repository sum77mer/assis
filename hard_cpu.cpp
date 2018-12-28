#include "hard_cpu.h"
#include <QTextCodec>
#include"UIconst.h"
Hard_CPU::Hard_CPU(QWidget *parent)
{
	initializeUI();
	setupLayout();
	initializeData();
	setConnection();
}

void Hard_CPU::initializeUI()
{
	setWindowFlags(Qt::FramelessWindowHint);

	title_cpuManufacture = new QLabel(this);
	title_cpuManufacture->setFrameStyle(QFrame::NoFrame);
	title_cpuManufacture->setText(QString("Manufacturer"));
	value_cpuManufacture = new QLabel(this);
	value_cpuManufacture->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_cpuManufacture->setMinimumHeight(value_cpuManufacture->sizeHint().height()+6);
	value_cpuManufacture->setMinimumWidth(value_cpuManufacture->sizeHint().width() + 10);
	value_cpuManufacture->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	value_cpuManufacture->setText(QString("default"));


	title_codeName = new QLabel(this);
	title_codeName->setFrameStyle(QFrame::NoFrame);
	title_codeName->setText(QString("Code Name"));
	value_codeName = new QLabel(this);
	value_codeName->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_codeName->setMinimumHeight(value_codeName->sizeHint().height() + 6);
	value_codeName->setMinimumWidth(value_codeName->sizeHint().width() + 10);
	value_codeName->setText(QString("default"));

	title_socketDesignation = new QLabel(this);
	title_socketDesignation->setFrameStyle(QFrame::NoFrame);
	title_socketDesignation->setText(QString("Socket Designation"));
	value_socketDesignation = new QLabel(this);
	value_socketDesignation->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_socketDesignation->setMinimumHeight(value_socketDesignation->sizeHint().height() + 6);
	value_socketDesignation->setMinimumWidth(value_socketDesignation->sizeHint().width() + 10);
	value_socketDesignation->setText(QString("default"));

	title_family = new QLabel(this);
	title_family->setFrameStyle(QFrame::NoFrame);
	title_family->setText(QString("Family"));
	value_family = new QLabel(this);
	value_family->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_family->setMinimumHeight(value_family->sizeHint().height() + 6);
	value_family->setMinimumWidth(value_family->sizeHint().width() + 10);
	value_family->setText(QString("default"));

	title_model = new QLabel(this);
	title_model->setFrameStyle(QFrame::NoFrame);
	title_model->setText(QString("Model"));
	value_model = new QLabel(this);
	value_model->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_model->setMinimumHeight(value_model->sizeHint().height() + 6);
	value_model->setMinimumWidth(value_model->sizeHint().width() + 10);
	value_model->setText(QString("default"));

	title_stepping = new QLabel(this);
	title_stepping->setFrameStyle(QFrame::NoFrame);
	title_stepping->setText(QString("Stepping"));
	value_stepping = new QLabel(this);
	value_stepping->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_stepping->setMinimumHeight(value_stepping->sizeHint().height() + 6);
	value_stepping->setMinimumWidth(value_stepping->sizeHint().width() + 10);
	value_stepping->setText(QString("default"));

	title_extFamily = new QLabel(this);
	title_extFamily->setFrameStyle(QFrame::NoFrame);
	title_extFamily->setText(QString("Ext Family"));
	value_extFamily = new QLabel(this);
	value_extFamily->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_extFamily->setMinimumHeight(value_extFamily->sizeHint().height() + 6);
	value_extFamily->setMinimumWidth(value_extFamily->sizeHint().width() + 10);
	value_extFamily->setText(QString("default"));

	title_extModel = new QLabel(this);
	title_extModel->setFrameStyle(QFrame::NoFrame);
	title_extModel->setText(QString("Ext Model"));
	value_extModel = new QLabel(this);
	value_extModel->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_extModel->setMinimumHeight(value_extModel->sizeHint().height() + 6);
	value_extModel->setMinimumWidth(value_extModel->sizeHint().width() + 10);
	value_extModel->setText(QString("default"));

	title_revision = new QLabel(this);
	title_revision->setFrameStyle(QFrame::NoFrame);
	title_revision->setText(QString("Revision"));
	value_revision = new QLabel(this);
	value_revision->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_revision->setMinimumHeight(value_revision->sizeHint().height() + 6);
	value_revision->setMinimumWidth(value_revision->sizeHint().width() + 10);
	value_revision->setText(QString("default"));

	title_technology = new QLabel(this);
	title_technology->setFrameStyle(QFrame::NoFrame);
	title_technology->setText(QString("Technology"));
	value_technology = new QLabel(this);
	value_technology->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_technology->setMinimumHeight(value_technology->sizeHint().height() + 6);
	value_technology->setMinimumWidth(value_technology->sizeHint().width() + 10);
	value_technology->setText(QString("default"));

	title_cpuName = new QLabel(this);
	title_cpuName->setFrameStyle(QFrame::NoFrame);
	title_cpuName->setText(QString("CPU Name"));

	value_cpuName = new QLabel(this);
	QLineEdit *lineedit = new QLineEdit(this);
	lineedit->setReadOnly(true);
	lineedit->setFrame(false);
	value_cpuName->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_cpuName->setMinimumHeight(value_cpuName->sizeHint().height() + 6);
	value_cpuName->setMinimumWidth(value_cpuName->sizeHint().width() + 10);
	value_cpuName->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	value_cpuName->setBuddy(lineedit);
	value_cpuName->setText(QString("default"));

	title_instructionSets = new QLabel(this);
	title_instructionSets->setFrameStyle(QFrame::NoFrame);
	title_instructionSets->setText(QString("Instructions"));
	value_instructionSets = new QLabel(this);
	value_instructionSets->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_instructionSets->setMinimumHeight(value_instructionSets->sizeHint().height() + 6);
	value_instructionSets->setMinimumWidth(value_instructionSets->sizeHint().width() + 10);
	//value_instructionSets->setReadOnly(true);
	value_instructionSets->setWordWrap(true);
	value_instructionSets->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	value_instructionSets->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	value_instructionSets->setText(QString("default"));

	title_southbridge = new QLabel(this);
	title_southbridge->setFrameStyle(QFrame::NoFrame);
	title_southbridge->setText(QString("SouthBridge"));
	value_southbridge = new QLabel(this);
	value_southbridge->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_southbridge->setMinimumHeight(value_southbridge->sizeHint().height() + 6);
	value_southbridge->setMinimumWidth(value_southbridge->sizeHint().width() + 10);
	value_southbridge->setText(QString("default"));

	title_maxTDP = new QLabel(this);
	title_maxTDP->setFrameStyle(QFrame::NoFrame);
	title_maxTDP->setText(QString("TDP"));
	value_maxTDP = new QLabel(this);
	value_maxTDP->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_maxTDP->setMinimumHeight(value_maxTDP->sizeHint().height() + 6);
	value_maxTDP->setMinimumWidth(value_maxTDP->sizeHint().width() + 10);
	value_maxTDP->setText(QString("default"));

	title_temperature = new QLabel(this);
	title_temperature->setFrameStyle(QFrame::NoFrame);
	title_temperature->setText(QString("Temperature"));
	value_temperature = new QLabel(this);
	value_temperature->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_temperature->setMinimumHeight(value_temperature->sizeHint().height() + 6);
	value_temperature->setMinimumWidth(value_temperature->sizeHint().width() + 10);
	value_temperature->setText(QString("default"));

	title_packageTemperature = new QLabel(this);
	title_packageTemperature->setFrameStyle(QFrame::NoFrame);
	title_packageTemperature->setText(QString("Package Temperature"));
	value_packageTemperature = new QLabel(this);
	value_packageTemperature->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_packageTemperature->setMinimumHeight(value_packageTemperature->sizeHint().height() + 6);
	value_packageTemperature->setMinimumWidth(value_packageTemperature->sizeHint().width() + 10);
	value_packageTemperature->setText(QString("default"));


	title_coreSpeed = new QLabel(this);
	title_coreSpeed->setFrameStyle(QFrame::NoFrame);
	title_coreSpeed->setText(QString("Core Speed"));
	value_coreSpeed = new QLabel(this);
	value_coreSpeed->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_coreSpeed->setMinimumHeight(value_coreSpeed->sizeHint().height() + 6);
	value_coreSpeed->setMinimumWidth(value_coreSpeed->sizeHint().width() + 10);
	value_coreSpeed->setText(QString("default"));

	title_multiplier = new QLabel(this);
	title_multiplier->setFrameStyle(QFrame::NoFrame);
	title_multiplier->setText(QString("Multiplier"));
	value_multiplier = new QLabel(this);
	value_multiplier->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_multiplier->setMinimumHeight(value_multiplier->sizeHint().height() + 6);
	value_multiplier->setMinimumWidth(value_multiplier->sizeHint().width() + 10);
	value_multiplier->setText(QString("default"));

	title_extSpeed = new QLabel(this);
	title_extSpeed->setFrameStyle(QFrame::NoFrame);
	title_extSpeed->setText(QString("Bus Speed"));
	value_extSpeed = new QLabel(this);
	value_extSpeed->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_extSpeed->setMinimumHeight(value_extSpeed->sizeHint().height() + 6);
	value_extSpeed->setMinimumWidth(value_extSpeed->sizeHint().width() + 10);
	value_extSpeed->setText(QString("default"));

	title_maxSpeed = new QLabel(this);
	title_maxSpeed->setFrameStyle(QFrame::NoFrame);
	title_maxSpeed->setText(QString("Max Speed"));
	value_maxSpeed = new QLabel(this);
	value_maxSpeed->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_maxSpeed->setMinimumHeight(value_maxSpeed->sizeHint().height() + 6);
	value_maxSpeed->setMinimumWidth(value_maxSpeed->sizeHint().width() + 10);
	value_maxSpeed->setText(QString("default"));

	title_L1D = new QLabel(this);
	title_L1D->setFrameStyle(QFrame::NoFrame);
	title_L1D->setText(QString("L1 Data"));
	value_L1Dsize = new QLabel(this);
	value_L1Dsize->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1Dsize->setMinimumHeight(value_L1Dsize->sizeHint().height() + 6);
	value_L1Dsize->setMinimumWidth(value_L1Dsize->sizeHint().width() + 10);
	value_L1Dsize->setText(QString("default"));
	value_L1Dway = new QLabel(this);
	value_L1Dway->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1Dway->setMinimumHeight(value_L1Dway->sizeHint().height() + 6);
	value_L1Dway->setMinimumWidth(value_L1Dway->sizeHint().width() + 10);
	value_L1Dway->setText(QString("default"));

	title_L1I = new QLabel(this);
	title_L1I->setFrameStyle(QFrame::NoFrame);
	title_L1I->setText(QString("L1 Instruction"));
	value_L1Isize = new QLabel(this);
	value_L1Isize->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1Isize->setMinimumHeight(value_L1Isize->sizeHint().height() + 6);
	value_L1Isize->setMinimumWidth(value_L1Isize->sizeHint().width() + 10);
	value_L1Isize->setText(QString("default"));
	value_L1Iway = new QLabel(this);
	value_L1Iway->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1Iway->setMinimumHeight(value_L1Iway->sizeHint().height() + 6);
	value_L1Iway->setMinimumWidth(value_L1Iway->sizeHint().width() + 10);
	value_L1Iway->setText(QString("default"));

	title_L2 = new QLabel(this);
	title_L2->setFrameStyle(QFrame::NoFrame);
	title_L2->setText(QString("L2"));
	value_L2size = new QLabel(this);
	value_L2size->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L2size->setMinimumHeight(value_L2size->sizeHint().height() + 6);
	value_L2size->setMinimumWidth(value_L2size->sizeHint().width() + 10);
	value_L2size->setText(QString("default"));
	value_L2way = new QLabel(this);
	value_L2way->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L2way->setMinimumHeight(value_L2way->sizeHint().height() + 6);
	value_L2way->setMinimumWidth(value_L2way->sizeHint().width() + 10);
	value_L2way->setText(QString("default"));

	title_L3 = new QLabel(this);
	title_L3->setFrameStyle(QFrame::NoFrame);
	title_L3->setText(QString("L3"));
	value_L3size = new QLabel(this);
	value_L3size->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L3size->setMinimumHeight(value_L3size->sizeHint().height() + 6);
	value_L3size->setMinimumWidth(value_L3size->sizeHint().width() + 10);
	value_L3size->setText(QString("default"));
	value_L3way = new QLabel(this);
	value_L3way->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L3way->setMinimumHeight(value_L3way->sizeHint().height() + 6);
	value_L3way->setMinimumWidth(value_L3way->sizeHint().width() + 10);
	value_L3way->setText(QString("default"));

	title_cpuSelected = new QLabel(this);
	title_cpuSelected->setFrameStyle(QFrame::NoFrame);
	title_cpuSelected->setText(QString("Selected"));
	value_cpuSelected = new QComboBox(this);
	value_cpuSelected->insertItem(0, QString("default"));

	title_cores = new QLabel(this);
	title_cores->setFrameStyle(QFrame::NoFrame);
	title_cores->setText(QString("Cores"));
	value_cores = new QLabel(this);
	value_cores->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_cores->setMinimumHeight(value_cores->sizeHint().height() + 6);
	value_cores->setMinimumWidth(value_cores->sizeHint().width() + 10);
	value_cores->setText(QString("default"));

	title_threads = new QLabel(this);
	title_threads->setFrameStyle(QFrame::NoFrame);
	title_threads->setText(QString("Threads"));
	value_threads = new QLabel(this);
	value_threads->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_threads->setMinimumHeight(value_threads->sizeHint().height() + 6);
	value_threads->setMinimumWidth(value_threads->sizeHint().width() + 10);
	value_threads->setText(QString("default"));

	//page2
	title_L1D_page2 = new QLabel(this);
	title_L1D_page2->setFrameStyle(QFrame::NoFrame);
	title_L1D_page2->setText(QString("Size"));
	value_L1D_size_page2 = new QLabel(this);
	value_L1D_size_page2->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1D_size_page2->setMinimumHeight(value_L1D_size_page2->sizeHint().height() + 6);
	value_L1D_size_page2->setMinimumWidth(value_L1D_size_page2->sizeHint().width() + 10);
	value_L1D_size_page2->setText(QString("default"));
	value_L1D_ways_page2 = new QLabel(this);
	value_L1D_ways_page2->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1D_ways_page2->setMinimumHeight(value_L1D_ways_page2->sizeHint().height() + 6);
	value_L1D_ways_page2->setMinimumWidth(value_L1D_ways_page2->sizeHint().width() + 10);
	value_L1D_ways_page2->setText(QString("default"));
	title_L1D_descriptor = new QLabel(this);
	title_L1D_descriptor->setFrameStyle(QFrame::NoFrame);
	title_L1D_descriptor->setText(QString("Descriptor"));
	value_L1D_descriptor = new QLabel(this);
	value_L1D_descriptor->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1D_descriptor->setMinimumHeight(value_L1D_descriptor->sizeHint().height() + 6);
	value_L1D_descriptor->setMinimumWidth(value_L1D_descriptor->sizeHint().width() + 10);
	value_L1D_descriptor->setText(QString("default"));

	title_L1I_page2 = new QLabel(this);
	title_L1I_page2->setFrameStyle(QFrame::NoFrame);
	title_L1I_page2->setText(QString("Size"));
	value_L1I_size_page2 = new QLabel(this);
	value_L1I_size_page2->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1I_size_page2->setMinimumHeight(value_L1I_size_page2->sizeHint().height() + 6);
	value_L1I_size_page2->setMinimumWidth(value_L1I_size_page2->sizeHint().width() + 10);
	value_L1I_size_page2->setText(QString("default"));
	value_L1I_ways_page2 = new QLabel(this);
	value_L1I_ways_page2->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1I_ways_page2->setMinimumHeight(value_L1I_ways_page2->sizeHint().height() + 6);
	value_L1I_ways_page2->setMinimumWidth(value_L1I_ways_page2->sizeHint().width() + 10);
	value_L1I_ways_page2->setText(QString("default"));
	title_L1I_descriptor = new QLabel(this);
	title_L1I_descriptor->setFrameStyle(QFrame::NoFrame);
	title_L1I_descriptor->setText(QString("Descriptor"));
	value_L1I_descriptor = new QLabel(this);
	value_L1I_descriptor->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L1I_descriptor->setMinimumHeight(value_L1I_descriptor->sizeHint().height() + 6);
	value_L1I_descriptor->setMinimumWidth(value_L1I_descriptor->sizeHint().width() + 10);
	value_L1I_descriptor->setText(QString("default"));

	title_L2_page2 = new QLabel(this);
	title_L2_page2->setFrameStyle(QFrame::NoFrame);
	title_L2_page2->setText(QString("Size"));
	value_L2_size_page2 = new QLabel(this);
	value_L2_size_page2->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L2_size_page2->setMinimumHeight(value_L2_size_page2->sizeHint().height() + 6);
	value_L2_size_page2->setMinimumWidth(value_L2_size_page2->sizeHint().width() + 10);
	value_L2_size_page2->setText(QString("default"));
	value_L2_ways_page2 = new QLabel(this);
	value_L2_ways_page2->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L2_ways_page2->setMinimumHeight(value_L2_ways_page2->sizeHint().height() + 6);
	value_L2_ways_page2->setMinimumWidth(value_L2_ways_page2->sizeHint().width() + 10);
	value_L2_ways_page2->setText(QString("default"));
	title_L2_descriptor = new QLabel(this);
	title_L2_descriptor->setFrameStyle(QFrame::NoFrame);
	title_L2_descriptor->setText(QString("Descriptor"));
	value_L2_descriptor = new QLabel(this);
	value_L2_descriptor->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L2_descriptor->setMinimumHeight(value_L2_descriptor->sizeHint().height() + 6);
	value_L2_descriptor->setMinimumWidth(value_L2_descriptor->sizeHint().width() + 10);
	value_L2_descriptor->setText(QString("default"));

	title_L3_page2 = new QLabel(this);
	title_L3_page2->setFrameStyle(QFrame::NoFrame);
	title_L3_page2->setText(QString("Size"));
	value_L3_size_page2 = new QLabel(this);
	value_L3_size_page2->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L3_size_page2->setMinimumHeight(value_L3_size_page2->sizeHint().height() + 6);
	value_L3_size_page2->setMinimumWidth(value_L3_size_page2->sizeHint().width() + 10);
	value_L3_size_page2->setText(QString("default"));
	value_L3_ways_page2 = new QLabel(this);
	value_L3_ways_page2->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L3_ways_page2->setMinimumHeight(value_L3_ways_page2->sizeHint().height() + 6);
	value_L3_ways_page2->setMinimumWidth(value_L3_ways_page2->sizeHint().width() + 10);
	value_L3_ways_page2->setText(QString("default"));
	title_L3_descriptor = new QLabel(this);
	title_L3_descriptor->setFrameStyle(QFrame::NoFrame);
	title_L3_descriptor->setText(QString("Descriptor"));
	value_L3_descriptor = new QLabel(this);
	value_L3_descriptor->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
	value_L3_descriptor->setMinimumHeight(value_L3_descriptor->sizeHint().height() + 6);
	value_L3_descriptor->setMinimumWidth(value_L3_descriptor->sizeHint().width() + 10);
	value_L3_descriptor->setText(QString("default"));

	//page3
	cpuid_checkCPU1 = new QCheckBox(this);
	cpuid_checkCPU1->setText(QString("CPU1"));
	cpuid_checkCPU2 = new QCheckBox(this);
	cpuid_checkCPU2->setText(QString("CPU2"));
	cpuid_checkCPU3 = new QCheckBox(this);
	cpuid_checkCPU3->setText(QString("CPU3"));
	cpuid_checkCPU4 = new QCheckBox(this);
	cpuid_checkCPU4->setText(QString("CPU4"));

	title_cpuid_inputEAX = new QLabel(this);
	title_cpuid_inputEAX->setFrameStyle(QFrame::NoFrame);
	title_cpuid_inputEAX->setText(QString("EAX: 0x"));
	title_cpuid_inputECX = new QLabel(this);
	title_cpuid_inputECX->setFrameStyle(QFrame::NoFrame);
	title_cpuid_inputECX->setText(QString("ECX: 0x"));
	title_cpuid_outputEAX = new QLabel(this);
	title_cpuid_outputEAX->setFrameStyle(QFrame::NoFrame);
	title_cpuid_outputEAX->setText(QString("EAX: 0x"));
	title_cpuid_outputEBX = new QLabel(this);
	title_cpuid_outputEBX->setFrameStyle(QFrame::NoFrame);
	title_cpuid_outputEBX->setText(QString("EBX: 0x"));
	title_cpuid_outputECX = new QLabel(this);
	title_cpuid_outputECX->setFrameStyle(QFrame::NoFrame);
	title_cpuid_outputECX->setText(QString("ECX: 0x"));
	title_cpuid_outputEDX = new QLabel(this);
	title_cpuid_outputEDX->setFrameStyle(QFrame::NoFrame);
	title_cpuid_outputEDX->setText(QString("EDX: 0x"));

	cpuid_input_eax = new QLineEdit(this);
	cpuid_input_eax->setMaximumHeight(20);
	cpuid_input_eax->setMinimumWidth(50);
	cpuid_input_ecx = new QLineEdit(this);
	cpuid_input_ecx->setMaximumHeight(20);
	cpuid_input_ecx->setMinimumWidth(50);
	cpuid_output_eax = new QLineEdit(this);
	cpuid_output_eax->setMaximumHeight(20);
	cpuid_output_eax->setMinimumWidth(50);
	cpuid_output_ebx = new QLineEdit(this);
	cpuid_output_ebx->setMaximumHeight(20);
	cpuid_output_ebx->setMinimumWidth(50);
	cpuid_output_ecx = new QLineEdit(this);
	cpuid_output_ecx->setMaximumHeight(20);
	cpuid_output_ecx->setMinimumWidth(50);
	cpuid_output_edx = new QLineEdit(this);
	cpuid_output_edx->setMaximumHeight(20);
	cpuid_output_edx->setMinimumWidth(50);

	//page4
	msr_checkCPU1 = new QCheckBox(this);
	msr_checkCPU1->setText(QString("CPU1"));
	msr_checkCPU2 = new QCheckBox(this);
	msr_checkCPU2->setText(QString("CPU2"));
	msr_checkCPU3 = new QCheckBox(this);
	msr_checkCPU3->setText(QString("CPU3"));
	msr_checkCPU4 = new QCheckBox(this);
	msr_checkCPU4->setText(QString("CPU4"));

	title_msrECX = new QLabel(this);
	title_msrECX->setFrameStyle(QFrame::NoFrame);
	title_msrECX->setText(QString("ECX: 0x"));
	title_msrEAX = new QLabel(this);
	title_msrEAX->setFrameStyle(QFrame::NoFrame);
	title_msrEAX->setText(QString("EAX: 0x"));
	title_msrEDX = new QLabel(this);
	title_msrEDX->setFrameStyle(QFrame::NoFrame);
	title_msrEDX->setText(QString("EDX: 0x"));

	cpuid_readBtn = new QPushButton(this);
	cpuid_readBtn->setText(QString("Read"));

	cpuid_fixBtn = new QPushButton(this);
	cpuid_fixBtn->setText(QString("Fix"));

	cpuid_deleteBtn = new QPushButton(this);
	cpuid_deleteBtn->setText(QString("Delete"));

	cpuid_table = new QTableView(this);
	cpuid_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	cpuid_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	cpuid_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

	msr_ecx = new QLineEdit(this);
	msr_ecx->setMaximumHeight(20);
	msr_ecx->setMinimumWidth(50);
	msr_eax = new QLineEdit(this);
	msr_eax->setMaximumHeight(20);
	msr_eax->setMinimumWidth(50);
	msr_edx = new QLineEdit(this);
	msr_edx->setMaximumHeight(20);
	msr_edx->setMinimumWidth(50);

	msr_readBtn = new QPushButton(this);
	msr_readBtn->setText(QString("Read"));
	msr_writeBtn = new QPushButton(this);
	msr_writeBtn->setText(QString("Write"));
	msr_fixBtn = new QPushButton(this);
	msr_fixBtn->setText(QString("Fix"));
	msr_deleteBtn = new QPushButton(this);
	msr_deleteBtn->setText(QString("Delete"));

	msr_table = new QTableView(this);
	msr_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
	msr_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	msr_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void Hard_CPU::setupLayout()
{
//*********************       Page1 CPU      ******************************
	QGridLayout *cpugrouplayout = new QGridLayout;
	cpugrouplayout->setContentsMargins(30, 10, 30, 10);
	cpugrouplayout->setHorizontalSpacing(5);
	cpugrouplayout->setVerticalSpacing(5);
	cpugrouplayout->setRowStretch(0, 0);
	cpugrouplayout->setRowStretch(1, 0);
	cpugrouplayout->setRowStretch(2, 0);
	cpugrouplayout->setRowStretch(3, 0);
	cpugrouplayout->setRowStretch(4, 1);
	cpugrouplayout->addWidget(title_cpuName, 0, 0, 1, 1);
	cpugrouplayout->addWidget(value_cpuName, 0, 1, 1, 3);
	cpugrouplayout->addWidget(title_cpuManufacture, 0, 4, 1, 1);
	cpugrouplayout->addWidget(value_cpuManufacture, 0, 5, 1, 1);
	cpugrouplayout->addWidget(title_codeName, 0, 6, 1, 1);
	cpugrouplayout->addWidget(value_codeName, 0, 7, 1, 1);

	cpugrouplayout->addWidget(title_packageTemperature, 1, 0, 1, 1);
	cpugrouplayout->addWidget(value_packageTemperature, 1, 1, 1, 1);
	cpugrouplayout->addWidget(title_temperature, 1, 2, 1, 1);
	cpugrouplayout->addWidget(value_temperature, 1, 3, 1, 1);
	cpugrouplayout->addWidget(title_technology, 1, 6, 1, 1);
	cpugrouplayout->addWidget(value_technology, 1, 7, 1, 1);
	cpugrouplayout->addWidget(title_maxTDP, 1, 4, 1, 1);
	cpugrouplayout->addWidget(value_maxTDP, 1, 5, 1, 1);
	

	cpugrouplayout->addWidget(title_southbridge, 2, 0, 1, 1);
	cpugrouplayout->addWidget(value_southbridge, 2, 1, 1, 1);
	cpugrouplayout->addWidget(title_family, 2, 2, 1, 1);
	cpugrouplayout->addWidget(value_family, 2, 3, 1, 1);
	cpugrouplayout->addWidget(title_model, 2, 4, 1, 1);
	cpugrouplayout->addWidget(value_model, 2, 5, 1, 1);
	cpugrouplayout->addWidget(title_stepping, 2, 6, 1, 1);
	cpugrouplayout->addWidget(value_stepping, 2, 7, 1, 1);

	cpugrouplayout->addWidget(title_socketDesignation, 3, 0, 1, 1);
	cpugrouplayout->addWidget(value_socketDesignation, 3, 1, 1, 1);
	cpugrouplayout->addWidget(title_extFamily, 3, 2, 1, 1);
	cpugrouplayout->addWidget(value_extFamily, 3, 3, 1, 1);
	cpugrouplayout->addWidget(title_extModel, 3, 4, 1, 1);
	cpugrouplayout->addWidget(value_extModel, 3, 5, 1, 1);
	cpugrouplayout->addWidget(title_revision, 3, 6, 1, 1);
	cpugrouplayout->addWidget(value_revision, 3, 7, 1, 1);

	cpugrouplayout->addWidget(title_instructionSets, 4, 0, 1, 1);
	cpugrouplayout->addWidget(value_instructionSets, 4, 1, 1, 7);

	QGridLayout *clockgrouplayout = new QGridLayout;
	clockgrouplayout->setContentsMargins(30, 10, 30, 10);
	clockgrouplayout->setColumnStretch(0, 5);
	clockgrouplayout->setColumnStretch(1, 10);
	clockgrouplayout->setRowStretch(0, 2);
	clockgrouplayout->setRowStretch(1, 8);
	clockgrouplayout->setRowStretch(2, 8);
	clockgrouplayout->setRowStretch(3, 8);
	clockgrouplayout->setRowStretch(4, 8);
	clockgrouplayout->setRowStretch(5, 2);
	clockgrouplayout->addWidget(title_coreSpeed, 1, 0, 1, 1);
	clockgrouplayout->addWidget(value_coreSpeed, 1, 1, 1, 1);
	clockgrouplayout->addWidget(title_multiplier, 2, 0, 1, 1);
	clockgrouplayout->addWidget(value_multiplier, 2, 1, 1, 1);
	clockgrouplayout->addWidget(title_extSpeed, 3, 0, 1, 1);
	clockgrouplayout->addWidget(value_extSpeed, 3, 1, 1, 1);
	clockgrouplayout->addWidget(title_maxSpeed, 4, 0, 1, 1);
	clockgrouplayout->addWidget(value_maxSpeed, 4, 1, 1, 1);

	QGridLayout *cachegrouplayout = new QGridLayout;
	cachegrouplayout->setContentsMargins(30, 10, 30, 10);
	cachegrouplayout->setColumnStretch(0, 0);
	cachegrouplayout->setColumnStretch(1, 0);
	cachegrouplayout->setColumnStretch(2, 100);
	cachegrouplayout->setRowStretch(0, 2);
	cachegrouplayout->setRowStretch(1, 8);
	cachegrouplayout->setRowStretch(2, 8);
	cachegrouplayout->setRowStretch(3, 8);
	cachegrouplayout->setRowStretch(4, 8);
	cachegrouplayout->setRowStretch(5, 2);
	cachegrouplayout->addWidget(title_L1D, 1, 0, 1, 1);
	cachegrouplayout->addWidget(value_L1Dsize, 1, 1, 1, 1);
	cachegrouplayout->addWidget(value_L1Dway, 1, 2, 1, 1);

	cachegrouplayout->addWidget(title_L1I, 2, 0, 1, 1);
	cachegrouplayout->addWidget(value_L1Isize, 2, 1, 1, 1);
	cachegrouplayout->addWidget(value_L1Iway, 2, 2, 1, 1);

	cachegrouplayout->addWidget(title_L2, 3, 0, 1, 1);
	cachegrouplayout->addWidget(value_L2size, 3, 1, 1, 1);
	cachegrouplayout->addWidget(value_L2way, 3, 2, 1, 1);

	cachegrouplayout->addWidget(title_L3, 4, 0, 1, 1);
	cachegrouplayout->addWidget(value_L3size, 4, 1, 1, 1);
	cachegrouplayout->addWidget(value_L3way, 4, 2, 1, 1);

	QGridLayout *choosedgrouplayout = new QGridLayout;
	choosedgrouplayout->setContentsMargins(30, 10, 30, 10);
	choosedgrouplayout->setColumnStretch(0, 0);
	choosedgrouplayout->setColumnStretch(1, 100);
	choosedgrouplayout->setColumnStretch(2, 0);
	choosedgrouplayout->setColumnStretch(3, 100);
	choosedgrouplayout->setColumnStretch(4, 0);
	choosedgrouplayout->setColumnStretch(5, 100);
	choosedgrouplayout->addWidget(title_cpuSelected, 0, 0);
	choosedgrouplayout->addWidget(value_cpuSelected, 0, 1);
	choosedgrouplayout->addWidget(title_cores, 0, 2);
	choosedgrouplayout->addWidget(value_cores, 0, 3);
	choosedgrouplayout->addWidget(title_threads, 0, 4);
	choosedgrouplayout->addWidget(value_threads, 0, 5);

	//groupbox
	QGroupBox *cpugroup = new QGroupBox(tr("CPU"));
	QGroupBox *clockgroup = new QGroupBox(tr("CLOCK"));
	QGroupBox *cachegroup = new QGroupBox(tr("Cache"));
	QGroupBox *choosegroup = new QGroupBox(tr("Choosed"));

	cpugroup->setLayout(cpugrouplayout);
	cpugroup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	clockgroup->setLayout(clockgrouplayout);
	clockgroup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	cachegroup->setLayout(cachegrouplayout);
	cachegroup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	choosegroup->setLayout(choosedgrouplayout);
	choosegroup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QGridLayout *page1layout = new QGridLayout;
	page1layout->setContentsMargins(10, 10, 10, 10);
	page1layout->setRowStretch(0, 7);
	page1layout->setRowStretch(1, 4);
	page1layout->setRowStretch(2, 1);
	page1layout->setVerticalSpacing(5);
	page1layout->setHorizontalSpacing(10);

	page1layout->addWidget(cpugroup, 0, 0,
		1, 2);
	page1layout->addWidget(clockgroup, 1, 0,
		1, 1);
	page1layout->addWidget(cachegroup, 1, 1,
		1, 1);
	page1layout->addWidget(choosegroup, 2, 0,
		1, 2);
	pagecpu = new QWidget();
	pagecpu->setLayout(page1layout);
	pagecpu->setWindowFlags(Qt::FramelessWindowHint);
//**********************************          Page2 Cache       *************************************
	QGridLayout *firdatagrouplayout = new QGridLayout;
	firdatagrouplayout->setContentsMargins(20, 20, 20, 20);
	firdatagrouplayout->setVerticalSpacing(5);
	firdatagrouplayout->setHorizontalSpacing(5);
	firdatagrouplayout->setRowStretch(0, 2);
	firdatagrouplayout->setRowStretch(1, 8);
	firdatagrouplayout->setRowStretch(2, 8);
	firdatagrouplayout->setRowStretch(3, 2);
	firdatagrouplayout->setColumnStretch(0, 0);
	firdatagrouplayout->setColumnStretch(1, 0);
	firdatagrouplayout->setColumnStretch(2, 100);
	firdatagrouplayout->addWidget(title_L1D_page2, 1, 0, 1, 1);
	firdatagrouplayout->addWidget(value_L1D_size_page2, 1, 1, 1, 1);
	firdatagrouplayout->addWidget(value_L1D_ways_page2, 1, 2, 1, 1);
	firdatagrouplayout->addWidget(title_L1D_descriptor, 2, 0, 1, 1);
	firdatagrouplayout->addWidget(value_L1D_descriptor, 2, 1, 1, 2);
	QGridLayout *firinstgrouplayout = new QGridLayout;
	firinstgrouplayout->setContentsMargins(20, 20, 20, 20);
	firinstgrouplayout->setVerticalSpacing(5);
	firinstgrouplayout->setRowStretch(0, 2);
	firinstgrouplayout->setRowStretch(1, 8);
	firinstgrouplayout->setRowStretch(2, 8);
	firinstgrouplayout->setRowStretch(3, 2);
	firinstgrouplayout->setColumnStretch(0, 0);
	firinstgrouplayout->setColumnStretch(1, 0);
	firinstgrouplayout->setColumnStretch(2, 100);
	firinstgrouplayout->addWidget(title_L1I_page2, 1, 0, 1, 1);
	firinstgrouplayout->addWidget(value_L1I_size_page2, 1, 1, 1, 1);
	firinstgrouplayout->addWidget(value_L1I_ways_page2, 1, 2, 1, 1);
	firinstgrouplayout->addWidget(title_L1I_descriptor, 2, 0, 1, 1);
	firinstgrouplayout->addWidget(value_L1I_descriptor, 2, 1, 1, 2);
	QGridLayout *secgrouplayout = new QGridLayout;
	secgrouplayout->setContentsMargins(20, 20, 20, 20);
	secgrouplayout->setVerticalSpacing(5);
	secgrouplayout->setRowStretch(0, 2);
	secgrouplayout->setRowStretch(1, 8);
	secgrouplayout->setRowStretch(2, 8);
	secgrouplayout->setRowStretch(3, 2);
	secgrouplayout->setColumnStretch(0, 0);
	secgrouplayout->setColumnStretch(1, 0);
	secgrouplayout->setColumnStretch(2, 100);
	secgrouplayout->addWidget(title_L2_page2, 1, 0, 1, 1);
	secgrouplayout->addWidget(value_L2_size_page2, 1, 1, 1, 1);
	secgrouplayout->addWidget(value_L2_ways_page2, 1, 2, 1, 1);
	secgrouplayout->addWidget(title_L2_descriptor, 2, 0, 1, 1);
	secgrouplayout->addWidget(value_L2_descriptor, 2, 1, 1, 2);
	QGridLayout *thirgrouplayout = new QGridLayout;
	thirgrouplayout->setContentsMargins(20, 20, 20, 20);
	thirgrouplayout->setVerticalSpacing(5);
	thirgrouplayout->setRowStretch(0, 2);
	thirgrouplayout->setRowStretch(1, 8);
	thirgrouplayout->setRowStretch(2, 8);
	thirgrouplayout->setRowStretch(3, 2);
	thirgrouplayout->setColumnStretch(0, 0);
	thirgrouplayout->setColumnStretch(1, 0);
	thirgrouplayout->setColumnStretch(2, 100);
	thirgrouplayout->addWidget(title_L3_page2, 1, 0, 1, 1);
	thirgrouplayout->addWidget(value_L3_size_page2, 1, 1, 1, 1);
	thirgrouplayout->addWidget(value_L3_ways_page2, 1, 2, 1, 1);
	thirgrouplayout->addWidget(title_L3_descriptor, 2, 0, 1, 1);
	thirgrouplayout->addWidget(value_L3_descriptor, 2, 1, 1, 2);

	QGroupBox *firdatacachegroup = new QGroupBox(tr("L1 D-Cache"));
	QGroupBox *firinstcachegroup = new QGroupBox(tr("L1 I-Cache"));
	QGroupBox *seccachegroup = new QGroupBox(tr("L2 Cache"));
	QGroupBox *thircachegroup = new QGroupBox(tr("L3 Cache"));
	//firdatacachegroup->setMinimumWidth(760);
	//firinstcachegroup->setMinimumWidth(760);
	//seccachegroup->setMinimumWidth(760);
	//thircachegroup->setMinimumWidth(760);
	firdatacachegroup->setLayout(firdatagrouplayout);
	firinstcachegroup->setLayout(firinstgrouplayout);
	seccachegroup->setLayout(secgrouplayout);
	thircachegroup->setLayout(thirgrouplayout);

	QGridLayout *page2layout = new QGridLayout;
	page2layout->setContentsMargins(10, 10, 10, 10);
	page2layout->addWidget(firdatacachegroup, 0, 0, 1, 1);
	page2layout->addWidget(firinstcachegroup, 1, 0, 1, 1);
	page2layout->addWidget(seccachegroup, 2, 0, 1, 1);
	page2layout->addWidget(thircachegroup, 3, 0, 1, 1);
	pagecache = new QWidget();
	pagecache->setLayout(page2layout);
	pagecache->setWindowFlags(Qt::FramelessWindowHint);
//*********************************       Page3 CPUID             ***************************************
	QGridLayout *page3layout = new QGridLayout;
	page3layout->setContentsMargins(100, 20, 100, 0);
	page3layout->setColumnStretch(0, 20);
	page3layout->setColumnStretch(1, 0);
	page3layout->setColumnStretch(2, 0);
	page3layout->setColumnStretch(3, 0);
	page3layout->setColumnStretch(4, 0);
	page3layout->setColumnStretch(5, 0);
	page3layout->setColumnStretch(6, 20);
	page3layout->setRowStretch(0, 2);
	page3layout->setRowStretch(1, 0);
	page3layout->setRowStretch(2, 0);
	page3layout->setRowStretch(3, 0);
	page3layout->setRowStretch(4, 2);
	page3layout->setRowStretch(5, 10);

	page3layout->addWidget(cpuid_checkCPU1, 0, 1, 1, 1, Qt::AlignHCenter | Qt::AlignTop);
	page3layout->addWidget(cpuid_checkCPU2, 0, 2, 1, 1, Qt::AlignHCenter | Qt::AlignTop);
	page3layout->addWidget(cpuid_checkCPU3, 0, 3, 1, 1, Qt::AlignHCenter | Qt::AlignTop);
	page3layout->addWidget(cpuid_checkCPU4, 0, 4, 1, 1, Qt::AlignHCenter | Qt::AlignTop);

	page3layout->addWidget(title_cpuid_inputEAX, 1, 0,
		1, 1, Qt::AlignRight);
	page3layout->addWidget(cpuid_input_eax, 1, 1,
		1, 2, Qt::AlignLeft);
	page3layout->addWidget(title_cpuid_inputECX, 1, 4,
		1, 1, Qt::AlignRight);
	page3layout->addWidget(cpuid_input_ecx, 1, 5,
		1, 2, Qt::AlignLeft);
	page3layout->addWidget(title_cpuid_outputEAX, 2, 0,
		1, 1, Qt::AlignRight);
	page3layout->addWidget(cpuid_output_eax, 2, 1,
		1, 2, Qt::AlignLeft);
	page3layout->addWidget(title_cpuid_outputEBX, 2, 4,
		1, 1, Qt::AlignRight);
	page3layout->addWidget(cpuid_output_ebx, 2, 5,
		1, 2, Qt::AlignLeft);
	page3layout->addWidget(title_cpuid_outputECX, 3, 0,
		1, 1, Qt::AlignRight);
	page3layout->addWidget(cpuid_output_ecx, 3, 1,
		1, 2, Qt::AlignLeft);
	page3layout->addWidget(title_cpuid_outputEDX, 3, 4,
		1, 1, Qt::AlignRight);
	page3layout->addWidget(cpuid_output_edx, 3, 5,
		1, 2, Qt::AlignLeft);
	page3layout->addWidget(cpuid_readBtn, 4, 1,
		1, 1, Qt::AlignCenter);
	page3layout->addWidget(cpuid_fixBtn, 4, 4,
		1, 1, Qt::AlignCenter);
	page3layout->addWidget(cpuid_deleteBtn, 4, 5,
		1, 1, Qt::AlignCenter);
	page3layout->addWidget(cpuid_table, 5, 0,
		1, 7,Qt::AlignCenter);
	pagecpuid = new QWidget();
	pagecpuid->setLayout(page3layout);
	pagecpuid->setWindowFlags(Qt::FramelessWindowHint);
	
//*****************************            Page4 MSR             **************************************
	QGridLayout *page4layout = new QGridLayout;
	
	page4layout->setContentsMargins(0, 20, 0, 0);
	page4layout->setVerticalSpacing(5);
	page4layout->setHorizontalSpacing(5);
	page4layout->setRowStretch(0, 1);
	page4layout->setRowStretch(1, 0);
	page4layout->setRowStretch(2, 0);
	page4layout->setRowStretch(3, 0);
	page4layout->setRowStretch(4, 1);
	page4layout->setRowStretch(5, 10);
	page4layout->setColumnStretch(0, 10);
	page4layout->setColumnStretch(1, 0);
	page4layout->setColumnStretch(2, 0);
	page4layout->setColumnStretch(3, 0);
	page4layout->setColumnStretch(4, 0);
	page4layout->setColumnStretch(5, 0);
	page4layout->setColumnStretch(6, 10);
	page4layout->addWidget(msr_checkCPU1, 0, 1, 1, 1, Qt::AlignHCenter | Qt::AlignTop);
	page4layout->addWidget(msr_checkCPU2, 0, 2, 1, 1, Qt::AlignHCenter | Qt::AlignTop);
	page4layout->addWidget(msr_checkCPU3, 0, 3, 1, 1, Qt::AlignHCenter | Qt::AlignTop);
	page4layout->addWidget(msr_checkCPU4, 0, 4, 1, 1, Qt::AlignHCenter | Qt::AlignTop);

	page4layout->addWidget(title_msrEAX, 1, 2, 1, 1, Qt::AlignRight | Qt::AlignTop);
	page4layout->addWidget(msr_eax, 1, 3, 1, 2, Qt::AlignLeft | Qt::AlignTop);
	page4layout->addWidget(title_msrECX, 2, 2, 1, 1, Qt::AlignRight | Qt::AlignTop);
	page4layout->addWidget(msr_ecx, 2, 3, 1, 2, Qt::AlignLeft | Qt::AlignTop);
	page4layout->addWidget(title_msrEDX, 3, 2, 1, 1, Qt::AlignRight | Qt::AlignTop);
	page4layout->addWidget(msr_edx, 3, 3, 1, 2, Qt::AlignLeft | Qt::AlignTop);

	page4layout->addWidget(msr_readBtn, 4, 1, 1, 1, Qt::AlignHCenter | Qt::AlignBottom);
	page4layout->addWidget(msr_writeBtn, 4, 2, 1, 1, Qt::AlignHCenter | Qt::AlignBottom);
	page4layout->addWidget(msr_fixBtn, 4, 3, 1, 1, Qt::AlignHCenter | Qt::AlignBottom);
	page4layout->addWidget(msr_deleteBtn, 4, 5, 1, 1, Qt::AlignHCenter | Qt::AlignBottom);

	page4layout->addWidget(msr_table, 5, 0, 1, 7, Qt::AlignCenter);
	pagemsr = new QWidget();
	pagemsr->setLayout(page4layout);
	pagemsr->setWindowFlags(Qt::FramelessWindowHint);
//****************************           tabwidget           ***************************************
	tabwidget = new QTabWidget(this);
	tabwidget->setFont(enNormalFont);
	tabwidget->setStyleSheet(QString("QTabBar::tab{background:transparent;border:1px solid #333333;border-bottom:none;color:#BBBBBB;padding-left:5px;padding-right:30px;padding-top:5px;padding-bottom:5px}QTabBar::tab:hover{background-color:#777777;border:1px solid #444444;border-bottom:none;}QTabBar::tab:selected{background-color:#111111;border:1px solid #333333;border-top:2px solid rgb(150,150,150);border-right:2px solid rgb(150,150,150);border-bottom:none;color:white}QTabWidget::pane{border-color:rgb(200,200,200);border-style:solid;border-width:1px}"));
	tabwidget->addTab(pagecpu, QString("CPU"));
	tabwidget->addTab(pagecache, QString("Cache"));
	tabwidget->addTab(pagecpuid, QString("CPUID"));
	tabwidget->addTab(pagemsr, QString("MSR"));
//****************************            root window layout   ****************************************
	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(tabwidget);
	setLayout(layout);
}
void Hard_CPU::initializeData()
{
	GetData::CPU_Information *cpu_temp = new GetData::CPU_Information;
	data.getCPU(cpu_temp);
	cpuInfo = cpu_temp;

	value_cpuManufacture->setText(QString::fromStdString(cpuInfo->manufacture));
	value_codeName->setText(QString::fromStdString(cpuInfo->codeName));
	value_socketDesignation->setText(QString::fromStdString(cpuInfo->socketDescription));
	value_family->setText(QString("%0").arg(cpuInfo->family));
	value_model->setText(QString("%0").arg(cpuInfo->model));
	value_stepping->setText(QString("%0").arg(cpuInfo->stepping));
	value_extFamily->setText(QString("%0").arg(cpuInfo->extFamily));
	value_extModel->setText(QString("%0").arg(cpuInfo->extModel));
	value_revision->setText(QString("%0").arg(cpuInfo->revision));
	value_technology->setText(QString("%0nm").arg(cpuInfo->technology));
	value_cpuName->setText(QString::fromStdString(cpuInfo->cpuName));//
	value_instructionSets->setText(QString::fromStdString(cpuInfo->instructionSets));//
	value_southbridge->setText(QString::fromStdString(cpuInfo->southbridgeName));
	value_maxTDP->setText(QString("%0 W").arg(cpuInfo->maxTDP));
	QTextCodec *codec = QTextCodec::codecForName("GB18030");
	QString str = QString("%0").arg(cpuInfo->packageTemperature);
	str += codec->toUnicode("¡æ");
	value_packageTemperature->setText(str);
	str = QString("%0").arg(cpuInfo->temperature[0]);
	str+= codec->toUnicode("¡æ");
	value_temperature->setText(str);

	value_coreSpeed->setText(QString("%0 GHz").arg(cpuInfo->coreSpeed));
	value_multiplier->setText(QString("%0").arg(cpuInfo->multiplier));
	value_extSpeed->setText(QString("%0 MHz").arg(cpuInfo->extSpeed));
	value_maxSpeed->setText(QString("%0 GHz").arg(cpuInfo->maxSpeed));

	value_L1Dsize->setText(QString("%0 KB").arg(cpuInfo->cache[0].size));
	value_L1Dway->setText(QString("%0 - ways").arg(cpuInfo->cache[0].way));
	value_L1Isize->setText(QString("%0 KB").arg(cpuInfo->cache[1].size));
	value_L1Iway->setText(QString("%0 - ways").arg(cpuInfo->cache[1].way));
	value_L2size->setText(QString("%0 KB").arg(cpuInfo->cache[2].size));
	value_L2way->setText(QString("%0 - ways").arg(cpuInfo->cache[2].way));
	value_L3size->setText(QString("%0 MB").arg(cpuInfo->cache[3].size));
	value_L3way->setText(QString("%0 - ways").arg(cpuInfo->cache[3].way));

	value_cores->setText(QString("%0").arg(cpuInfo->coreNum));
	value_threads->setText(QString("%0").arg(cpuInfo->threadNum));

	value_L1D_size_page2->setText(QString("%0KB").arg(cpuInfo->cache[0].size));
	value_L1D_ways_page2->setText(QString("x%0").arg(cpuInfo->coreNum));
	value_L1D_descriptor->setText(QString("%0-ways set associative, %1-byte line size").arg(cpuInfo->cache[0].way).arg(cpuInfo->cache[0].lineSize));

	value_L1I_size_page2->setText(QString("%0KB").arg(cpuInfo->cache[1].size));
	value_L1I_ways_page2->setText(QString("x%0").arg(cpuInfo->coreNum));
	value_L1I_descriptor->setText(QString("%0-ways set associative, %1-byte line size").arg(cpuInfo->cache[1].way).arg(cpuInfo->cache[1].lineSize));

	value_L2_size_page2->setText(QString("%0KB").arg(cpuInfo->cache[2].size));
	value_L2_ways_page2->setText(QString("x%0").arg(cpuInfo->coreNum));//
	value_L2_descriptor->setText(QString("%0-ways set associative, %1-byte line size").arg(cpuInfo->cache[2].way).arg(cpuInfo->cache[2].lineSize));

	value_L3_size_page2->setText(QString("%0MB").arg(cpuInfo->cache[3].size));
	value_L3_ways_page2->setText(QString("x%0").arg(cpuInfo->coreNum));
	value_L3_descriptor->setText(QString("%0-ways set associative, %1-byte line size").arg(cpuInfo->cache[3].way).arg(cpuInfo->cache[3].lineSize));

	//recode
	cpuidmodel->setHorizontalHeaderItem(0, new QStandardItem("Address"));
	cpuidmodel->setHorizontalHeaderItem(1, new QStandardItem("EAX"));
	cpuidmodel->setHorizontalHeaderItem(2, new QStandardItem("EBX"));
	cpuidmodel->setHorizontalHeaderItem(3, new QStandardItem("ECX"));
	cpuidmodel->setHorizontalHeaderItem(4, new QStandardItem("EDX"));
	
	QString title = "EAX:0x" + QString("%0").arg(cpuid_default_eax,0,16) + "-ECX:0x" + QString("%0").arg(cpuid_default_ecx,0,16);
	bool ok;
	long long cpuideax = cpuid_default_eax, cpuidecx = cpuid_default_ecx;
	long long cpuidebx = 0, cpuidedx = 0;
	data.readCPUID(cpuideax, cpuidebx, cpuidecx, cpuidedx);
	cpuidmodel->setItem(0, 0,new QStandardItem(title));
	cpuidmodel->setItem(0, 1, new QStandardItem(QString("0x%0").arg(cpuideax, 0, 16)));
	cpuidmodel->setItem(0, 2, new QStandardItem(QString("0x%0").arg(cpuidebx, 0, 16)));
	cpuidmodel->setItem(0, 3, new QStandardItem(QString("0x%0").arg(cpuidecx, 0, 16)));
	cpuidmodel->setItem(0, 4, new QStandardItem(QString("0x%0").arg(cpuidedx, 0, 16)));
	cpuid_table->setModel(cpuidmodel);

	//recode
	msrmodel->setHorizontalHeaderItem(0, new QStandardItem("Address"));
	msrmodel->setHorizontalHeaderItem(1, new QStandardItem("CPU1"));
	msrmodel->setHorizontalHeaderItem(2, new QStandardItem("CPU2"));
	msrmodel->setHorizontalHeaderItem(3, new QStandardItem("CPU3"));
	msrmodel->setHorizontalHeaderItem(4, new QStandardItem("CPU4"));
	/*
	int ecx = msr_default_ecx, eax1, edx1, eax2, edx2, eax3, edx3, eax4, edx4;
	ok = data.readMsrTx(ecx, 1, eax1, edx1);
	ok &= data.readMsrTx(ecx, 2, eax2, edx2);
	ok &= data.readMsrTx(ecx, 4, eax3, edx3);
	ok &= data.readMsrTx(ecx, 8, eax4, edx4);
	if (ok)
	{
		msrmodel->setItem(0,0,new QStandardItem(QString("0x%0").arg(ecx, 0, 16)));
		msrmodel->setItem(0,1,new QStandardItem(QString("0x%0%1").arg(edx1, 0, 16).arg(eax1, 0, 16)));
		msrmodel->setItem(0,2,new QStandardItem(QString("0x%0%1").arg(edx2, 0, 16).arg(eax2, 0, 16)));
		msrmodel->setItem(0,3,new QStandardItem(QString("0x%0%1").arg(edx3, 0, 16).arg(eax3, 0, 16)));
		msrmodel->setItem(0,4,new QStandardItem(QString("0x%0%1").arg(edx4, 0, 16).arg(eax4, 0, 16)));
	}
	else
	{
		QMessageBox *messagebox = new QMessageBox(this);
		messagebox->setText("read fail:msr table default");
		messagebox->exec();
	}
	*/
	
	msr_table->setModel(msrmodel);
	update();
}
void Hard_CPU::updateData()
{
	data.updateHardware();
	initializeData();
}
void Hard_CPU::setConnection()
{
	connect(value_cpuSelected, SIGNAL(currentIndexChanged(int)), this, SLOT(cpuChoose(int)));
	connect(cpuid_readBtn, SIGNAL(clicked(bool)), this, SLOT(cpuidRead()));
	connect(cpuid_fixBtn, SIGNAL(clicked(bool)), this, SLOT(cpuidtableFix()));
	connect(cpuid_deleteBtn, SIGNAL(clicked(bool)), this, SLOT(cpuidtableDelete()));
	connect(cpuid_table->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(cpuidtableHeaderChoosed(int)));

	connect(msr_fixBtn, SIGNAL(clicked(bool)), this, SLOT(msrtablefix()));
	connect(msr_readBtn, SIGNAL(clicked(bool)), this, SLOT(msrRead()));
	connect(msr_writeBtn, SIGNAL(clicked(bool)), this, SLOT(msrWrite()));
	connect(msr_deleteBtn, SIGNAL(clicked(bool)), this, SLOT(msrtabledelete()));
	connect(msr_table->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(msrtableHeaderChoosed(int)));
}
void Hard_CPU::paintEvent(QPaintEvent *event)
{
}

void Hard_CPU::cpuChoose(int index)
{
    switch (index)
    {
    case 0:
    {
		value_cores->setText(QString("case 0"));
		value_threads->setText(QString("case 0"));
        break;
    }
    case 1:
    {
		value_cores->setText(QString("case 1"));
		value_threads->setText(QString("case 1"));
        break;
    }
    case 2:
    {
		value_cores->setText(QString("case 2"));
		value_threads->setText(QString("case 2"));
        break;
    }
    case 3:
    {
		value_cores->setText(QString("case 3"));
		value_threads->setText(QString("case 3"));
        break;
    }
    default:
    {
		value_cores->setText(QString("default"));
		value_threads->setText(QString("default"));
        break;
    }
    }
    update();
}
void Hard_CPU::cpuidRead()
{
    QString str_eax = cpuid_input_eax->text();
    QString str_ecx = cpuid_input_ecx->text();
	bool ok;
	long long eax = str_eax.toLongLong(&ok, 16);
	long long ecx = str_ecx.toLong(&ok, 16);
	long long ebx = 0, edx = 0;
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_eax)&&regexp.exactMatch(str_ecx))
    {
        unsigned int multicheck_flag = 0;
        if(cpuid_checkCPU1->isChecked())
        {
            multicheck_flag = multicheck_flag|0x1;
        }
        if(cpuid_checkCPU2->isChecked())
        {
            multicheck_flag = multicheck_flag|0x2;
        }
        if(cpuid_checkCPU3->isChecked())
        {
            multicheck_flag = multicheck_flag|0x4;
        }
        if(cpuid_checkCPU4->isChecked())
        {
            multicheck_flag = multicheck_flag|0x8;
        }
        switch (multicheck_flag)
        {
        case 0x1:
        {
			data.readCPUID(eax,ebx,ecx,edx);
            break;
        }
        case 0x2:
        {
			data.readCPUID(eax, ebx, ecx, edx);
            break;
        }
        case 0x4:
        {
			data.readCPUID(eax, ebx, ecx, edx);
            break;
        }
        case 0x8:
        {
			data.readCPUID(eax, ebx, ecx, edx);
            break;
        }
        default:
        {
            QMessageBox *messagebox = new QMessageBox(this);
            messagebox->setText("CPUID:Please choose one CPU");
            messagebox->exec();
            break;
        }
        }
		cpuid_output_eax->setText(QString("%0").arg(eax,0,16));
		cpuid_output_ebx->setText(QString("%0").arg(ebx,0,16));
		cpuid_output_ecx->setText(QString("%0").arg(ecx,0,16));
		cpuid_output_edx->setText(QString("%0").arg(edx,0,16));
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText("CPUID:invalid input");
        messagebox->exec();
    }
}
void Hard_CPU::cpuidtableHeaderChoosed(int index)
{
    removecpuidRow = index;
}
void Hard_CPU::cpuidtableFix()
{
    QList <QStandardItem *> list;
	QString str_eax = cpuid_input_eax->text();
	QString str_ecx = cpuid_input_ecx->text();
	QString title = "EAX:0x" + str_eax + "-ECX:0x" + str_ecx;
	bool ok;
	long long eax = str_eax.toLongLong(&ok, 16);
	long long ecx = str_ecx.toLong(&ok, 16);
	long long ebx = 0, edx = 0;
	QRegExp regexp("[0-9a-fA-F]+");
	if (regexp.exactMatch(str_eax) && regexp.exactMatch(str_ecx))
	{
		data.readCPUID(eax, ebx, ecx, edx);
		list << new QStandardItem(title) << new QStandardItem(QString("0x%0").arg(eax,0,16)) << new QStandardItem(QString("0x%0").arg(ebx, 0, 16)) << new QStandardItem(QString("0x%0").arg(ecx, 0, 16)) << new QStandardItem(QString("0x%0").arg(edx, 0, 16));
		cpuidmodel->appendRow(list);
	}
	else
	{
		QMessageBox *messagebox = new QMessageBox(this);
		messagebox->setText("CPUID:invalid input");
		messagebox->exec();
	}
    
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
	 QString str_ecx = msr_ecx->text();
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_ecx))
    {
        unsigned int multicheck_flag = 0;
        if(msr_checkCPU1->isChecked())
        {
            multicheck_flag = multicheck_flag|0x1;
        }
        if(msr_checkCPU2->isChecked())
        {
            multicheck_flag = multicheck_flag|0x2;
        }
        if(msr_checkCPU3->isChecked())
        {
            multicheck_flag = multicheck_flag|0x4;
        }
        if(msr_checkCPU4->isChecked())
        {
            multicheck_flag = multicheck_flag|0x8;
        }
        switch (multicheck_flag)
        {
        case 0x1:
        {
			bool ok;
			int ecx = str_ecx.toInt(&ok, 16);
			int eax, edx;
			if (data.readMsrTx(ecx, 1, eax, edx))
			{
				msr_edx->setText(QString("%0").arg(edx, 0, 16));
				msr_eax->setText(QString("%0").arg(eax, 0, 16));
			}
			else
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("read fail:msrread");
				messagebox->exec();
			}
            break;
        }
        case 0x2:
        {
			bool ok;
			int ecx = str_ecx.toInt(&ok, 16);
			int eax, edx;
			if (data.readMsrTx(ecx, 1, eax, edx))
			{
				msr_edx->setText(QString("%0").arg(edx, 0, 16));
				msr_eax->setText(QString("%0").arg(eax, 0, 16));
			}
			else
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("read fail:msrread");
				messagebox->exec();
			}
            break;
        }
        case 0x4:
        {		
			bool ok;
			int ecx = str_ecx.toInt(&ok, 16);
			int eax, edx;
			if (data.readMsrTx(ecx, 1, eax, edx))
			{
				msr_edx->setText(QString("%0").arg(edx, 0, 16));
				msr_eax->setText(QString("%0").arg(eax, 0, 16));
			}
			else
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("read fail:msrread");
				messagebox->exec();
			}
            break;
        }
        case 0x8:
        {
			bool ok;
			int ecx = str_ecx.toInt(&ok, 16);
			int eax, edx;
			if (data.readMsrTx(ecx, 1, eax, edx))
			{
				msr_edx->setText(QString("%0").arg(edx, 0, 16));
				msr_eax->setText(QString("%0").arg(eax, 0, 16));
			}
			else
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("read fail:msrread");
				messagebox->exec();
			}
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
	QString str_ecx = msr_ecx->text();
    QString str_eax = msr_eax->text();
    QString str_edx = msr_edx->text();

	bool ok;
	int ecx = str_ecx.toInt(&ok, 16);
	int eax = str_eax.toInt(&ok, 16);
	int edx = str_edx.toInt(&ok, 16);
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_eax)&&regexp.exactMatch(str_ecx)&&regexp.exactMatch(str_edx))
    {
        unsigned int multicheck_flag = 0;
        if(msr_checkCPU1->isChecked())
        {
            multicheck_flag = multicheck_flag|0x1;
        }
        if(msr_checkCPU2->isChecked())
        {
            multicheck_flag = multicheck_flag|0x2;
        }
        if(msr_checkCPU3->isChecked())
        {
            multicheck_flag = multicheck_flag|0x4;
        }
        if(msr_checkCPU4->isChecked())
        {
            multicheck_flag = multicheck_flag|0x8;
        }
        switch (multicheck_flag)
        {
        case 0x1:
        {
			if(!data.writeMsrTx(ecx,1,eax,edx))
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("write fail:msrwrite");
				messagebox->exec();
			}	
            break;
        }
        case 0x2:
        {
			if (!data.writeMsrTx(ecx, 2, eax, edx))
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("write fail:msrwrite");
				messagebox->exec();
			}
            break;
        }
        case 0x4:
        {
			if (!data.writeMsrTx(ecx, 4, eax, edx))
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("write fail:msrwrite");
				messagebox->exec();
			}
            break;
        }
        case 0x8:
        {
			if (!data.writeMsrTx(ecx, 8, eax, edx))
			{
				QMessageBox *messagebox = new QMessageBox(this);
				messagebox->setText("write fail:msrwrite");
				messagebox->exec();
			}
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
	QString str_index = msr_ecx->text();
	bool ok;
	int ecx = str_index.toInt(&ok, 16),eax1,edx1, eax2, edx2, eax3, edx3, eax4, edx4;
	ok = data.readMsrTx(ecx, 1, eax1,edx1);
	ok &= data.readMsrTx(ecx, 2, eax2, edx2);
	ok &= data.readMsrTx(ecx, 4, eax3, edx3);
	ok &= data.readMsrTx(ecx, 8, eax4, edx4);
	if (ok)
	{
		list << new QStandardItem(QString("0x%0").arg(ecx, 0, 16)) << new QStandardItem(QString("0x%0%1").arg(edx1, 0, 16).arg(eax1,0,16)) << new QStandardItem(QString("0x%0%1").arg(edx2, 0, 16).arg(eax2, 0, 16)) << new QStandardItem(QString("0x%0%1").arg(edx3, 0, 16).arg(eax3, 0, 16)) << new QStandardItem(QString("0x%0%1").arg(edx4, 0, 16).arg(eax4, 0, 16));
		msrmodel->appendRow(list);
	}
	else
	{
		QMessageBox *messagebox = new QMessageBox(this);
		messagebox->setText("read fail:msrtablefix");
		messagebox->exec();
	}
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
void Hard_CPU::reset()
{
	tabwidget->setCurrentWidget(pagecpu);
}