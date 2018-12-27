#ifndef HARD_CPU_H
#define HARD_CPU_H
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QPainter>
#include <QTabWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QComboBox>
#include <QTimer>
#include <QList>
#include <QHeaderView>
#include <QRegExp>
#include <QMessageBox>
#include "getData.h"

class Hard_CPU : public QWidget
{
    Q_OBJECT
public:
    Hard_CPU(QWidget *parent=0);
	void updateData();
	void reset();
private slots:
    void cpuChoose(int index);
    void cpuidRead();
    void cpuidtableHeaderChoosed(int index);
    void cpuidtableFix();
    void cpuidtableDelete();
    void msrtableHeaderChoosed(int index);
    void msrCpuChoose();
    void msrRead();
    void msrWrite();
    void msrtablefix();
    void msrtabledelete();
protected:
    void paintEvent(QPaintEvent *event);
	void initializeUI();
	void setupLayout();
	void initializeData();
	void setConnection();

private:
	GetData data;
	GetData::CPU_Information *cpuInfo;
	unsigned int cpuid_default_eax = 0x80000002;
	unsigned int cpuid_default_ecx = 0;
	unsigned int msr_default_ecx = 0x250;

	QTabWidget *tabwidget = NULL;
	QWidget *pagecpu = NULL;
	QWidget *pagemsr = NULL;
	QWidget *pagecpuid = NULL;
	QWidget *pagecache = NULL;
	//page1 CPU
	QLabel *title_cpuManufacture = NULL;
	QLabel *value_cpuManufacture = NULL;

	QLabel *title_codeName = NULL;
	QLabel *value_codeName = NULL;

	QLabel *title_socketDesignation = NULL;
	QLabel *value_socketDesignation = NULL;

	QLabel *title_family = NULL;
	QLabel *value_family = NULL;

	QLabel *title_model = NULL;
	QLabel *value_model = NULL;

	QLabel *title_stepping = NULL;
	QLabel *value_stepping = NULL;

	QLabel *title_extFamily = NULL;
	QLabel *value_extFamily = NULL;

	QLabel *title_extModel = NULL;
	QLabel *value_extModel = NULL;

	QLabel *title_revision = NULL;
	QLabel *value_revision = NULL;

	QLabel *title_technology = NULL;
	QLabel *value_technology = NULL;

	QLabel *title_cpuName = NULL;
	QLabel *value_cpuName = NULL;

	QLabel *title_instructionSets = NULL;
	QLabel *value_instructionSets = NULL;

	QLabel *title_southbridge = NULL;
	QLabel *value_southbridge = NULL;

	QLabel *title_maxTDP = NULL;
	QLabel *value_maxTDP = NULL;

	QLabel *title_packageTemperature = NULL;
	QLabel *value_packageTemperature = NULL;

	QLabel *title_temperature = NULL;
	QLabel *value_temperature = NULL;

	QLabel *title_coreSpeed = NULL;
	QLabel *value_coreSpeed = NULL;

	QLabel *title_multiplier = NULL;
	QLabel *value_multiplier = NULL;

	QLabel *title_extSpeed = NULL;
	QLabel *value_extSpeed = NULL;

	QLabel *title_maxSpeed = NULL;
	QLabel *value_maxSpeed = NULL;

	QLabel *title_L1D = NULL;
	QLabel *value_L1Dsize = NULL;
	QLabel *value_L1Dway = NULL;

	QLabel *title_L1I = NULL;
	QLabel *value_L1Isize = NULL;
	QLabel *value_L1Iway = NULL;

	QLabel *title_L2 = NULL;
	QLabel *value_L2size = NULL;
	QLabel *value_L2way = NULL;

	QLabel *title_L3 = NULL;
	QLabel *value_L3size = NULL;
	QLabel *value_L3way = NULL;

	QLabel *title_cpuSelected = NULL;
	QComboBox *value_cpuSelected = NULL;
	
	QLabel *title_cores = NULL;
	QLabel *value_cores = NULL;

	QLabel *title_threads = NULL;
	QLabel *value_threads = NULL;

	//page2 Cache
	QLabel *title_L1D_page2 = NULL;
	QLabel *value_L1D_size_page2 = NULL;
	QLabel *value_L1D_ways_page2 = NULL;
	QLabel *title_L1D_descriptor = NULL;
	QLabel *value_L1D_descriptor = NULL;

	QLabel *title_L1I_page2 = NULL;
	QLabel *value_L1I_size_page2 = NULL;
	QLabel *value_L1I_ways_page2 = NULL;
	QLabel *title_L1I_descriptor = NULL;
	QLabel *value_L1I_descriptor = NULL;

	QLabel *title_L2_page2 = NULL;
	QLabel *value_L2_size_page2 = NULL;
	QLabel *value_L2_ways_page2 = NULL;
	QLabel *title_L2_descriptor = NULL;
	QLabel *value_L2_descriptor = NULL;

	QLabel *title_L3_page2 = NULL;
	QLabel *value_L3_size_page2 = NULL;
	QLabel *value_L3_ways_page2 = NULL;
	QLabel *title_L3_descriptor = NULL;
	QLabel *value_L3_descriptor = NULL;

    //page 3 CPUID
	QCheckBox *cpuid_checkCPU1 = NULL;
	QCheckBox *cpuid_checkCPU2 = NULL;
	QCheckBox *cpuid_checkCPU3 = NULL;
	QCheckBox *cpuid_checkCPU4 = NULL;

	QLabel *title_cpuid_inputEAX = NULL;
	QLabel *title_cpuid_inputECX = NULL;
	QLabel *title_cpuid_outputEAX = NULL;
	QLabel *title_cpuid_outputEBX = NULL;
	QLabel *title_cpuid_outputECX = NULL;
	QLabel *title_cpuid_outputEDX = NULL;

	QLineEdit *cpuid_input_eax = NULL;
	QLineEdit *cpuid_input_ecx = NULL;
	QLineEdit *cpuid_output_eax = NULL;
	QLineEdit *cpuid_output_ebx = NULL;
	QLineEdit *cpuid_output_ecx = NULL;
	QLineEdit *cpuid_output_edx = NULL;

	QPushButton *cpuid_readBtn = NULL;
	QPushButton *cpuid_fixBtn = NULL;
	QPushButton *cpuid_deleteBtn = NULL;

	QTableView *cpuid_table = NULL;

    QStandardItemModel *cpuidmodel = new QStandardItemModel();
    int removecpuidRow = 0;

    //page4 MSR
    QCheckBox *msr_checkCPU1 = NULL;
	QCheckBox *msr_checkCPU2 = NULL;
	QCheckBox *msr_checkCPU3 = NULL;
	QCheckBox *msr_checkCPU4 = NULL;

	QLabel *title_msrECX = NULL;
	QLabel *title_msrEAX = NULL;
	QLabel *title_msrEDX = NULL;

    QLineEdit *msr_ecx = NULL;
    QLineEdit *msr_eax = NULL;
    QLineEdit *msr_edx = NULL;

	QPushButton *msr_readBtn = NULL;
	QPushButton *msr_writeBtn = NULL;
	QPushButton *msr_fixBtn = NULL;
	QPushButton *msr_deleteBtn = NULL;

	QTableView *msr_table = NULL;

    QStandardItemModel *msrmodel = new QStandardItemModel();
    int removemsrRow = 0;
};

#endif // HARD_CPU_H
