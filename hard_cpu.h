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
#include "libheaders/CPU.h"
using namespace SV_ASSIST::CPU;
class Hard_CPU : public QWidget
{
    Q_OBJECT
public:
    Hard_CPU(QWidget *parent=0);
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

private:

    char processorID_info[1024] = {};

    QString manufacturer_info;
    QString socketdesignation_info;
    short family_info = 0;
    short model_info = 0;
    short stepping_info = 0;
    short extfamily_info = 0;
    short extmodel_info = 0;
    unsigned int revision_info = 0;
    QString cpuname_info;

    unsigned int currentclockspeed_info = 0;
    unsigned int extclock_info = 0;
    unsigned int multiplier = 0;
    unsigned int maxclockspeed_info = 0;

    unsigned int core_info = 0;
    unsigned int thread_info = 0;
    QStringList cpuNum_list;

    CPUFeature cpufeature_info = {};
    QString instructionset_info = "";
    const Cache_info* cache_info = GetCache();
    Cache_info cache1I;
    Cache_info cache1D;
    Cache_info cache2;
    Cache_info cache3;

    QLabel *label_cpu_name =  new QLabel(this);
    QLabel *label_cpu_code_name = new QLabel(this);
    QLabel *label_max_TDP = new QLabel(this);
    //QLabel *label_package = new QLabel(this);
    //QLabel *label_technology = new QLabel(this);
    //QLabel *label_core_VID = new QLabel(this);
    QLabel *label_specification = new QLabel(this);
    QLabel *label_family = new QLabel(this);
    QLabel *label_model = new QLabel(this);
    QLabel *label_stepping = new QLabel(this);
    QLabel *label_ext_family = new QLabel(this);
    QLabel *label_ext_model = new QLabel(this);
    QLabel *label_revision = new QLabel(this);
    QTextEdit *label_instructions = new QTextEdit(this);

    QLabel *label_core_speed = new QLabel(this);
    QLabel *label_multiplier = new QLabel(this);
    QLabel *label_bus_speed = new QLabel(this);
    QLabel *label_rated_FSB = new QLabel(this);

    QLabel *label_L1_data_size1 = new QLabel(this);
    QLabel *label_L1_data_way = new QLabel(this);
    QLabel *label_L1_inst_size1 = new QLabel(this);
    QLabel *label_L1_inst_way = new QLabel(this);
    QLabel *label_L2_size1 = new QLabel(this);
    QLabel *label_L2_way = new QLabel(this);
    QLabel *label_L3_size1 = new QLabel(this);
    QLabel *label_L3_way = new QLabel(this);

    QLabel *label_cores =  new QLabel(this);
    QLabel *label_threads = new QLabel(this);

    QLabel *label_L1_data_size2 = new QLabel(this);
    QLabel *label_L1_data_way2 = new QLabel(this);
    QLabel *label_L1_data_description = new QLabel(this);
    QLabel *label_L1_inst_size2 = new QLabel(this);
    QLabel *label_L1_inst_way2 = new QLabel(this);
    QLabel *label_L1_inst_description = new QLabel(this);
    QLabel *label_L2_size2 = new QLabel(this);
    QLabel *label_L2_way2 = new QLabel(this);
    QLabel *label_L2_description = new QLabel(this);
    QLabel *label_L3_size2 = new QLabel(this);
    QLabel *label_L3_way2 = new QLabel(this);
    QLabel *label_L3_description = new QLabel(this);

    //page 3 cpuid
    QLineEdit *lineedit_cpuid_input_eax = new QLineEdit(this);
    QLineEdit *lineedit_cpuid_input_ecx = new QLineEdit(this);
    QLineEdit *lineedit_cpuid_output_eax = new QLineEdit(this);
    QLineEdit *lineedit_cpuid_output_ebx = new QLineEdit(this);
    QLineEdit *lineedit_cpuid_output_ecx = new QLineEdit(this);
    QLineEdit *lineedit_cpuid_output_edx = new QLineEdit(this);

    QCheckBox *checkbox_cpuid_cpu1 = new QCheckBox(this);
    QCheckBox *checkbox_cpuid_cpu2 = new QCheckBox(this);
    QCheckBox *checkbox_cpuid_cpu3 = new QCheckBox(this);
    QCheckBox *checkbox_cpuid_cpu4 = new QCheckBox(this);
    QStandardItemModel *cpuidmodel = new QStandardItemModel();
    int removecpuidRow = 0;

    //page4 msr
    QCheckBox *checkbox_msr_cpu1 = new QCheckBox(this);
    QCheckBox *checkbox_msr_cpu2 = new QCheckBox(this);
    QCheckBox *checkbox_msr_cpu3 = new QCheckBox(this);
    QCheckBox *checkbox_msr_cpu4 = new QCheckBox(this);

    QLineEdit *lineedit_msr_ecx = new QLineEdit(this);
    QLineEdit *lineedit_msr_eax = new QLineEdit(this);
    QLineEdit *lineedit_msr_edx = new QLineEdit(this);

    QStandardItemModel *msrmodel = new QStandardItemModel();
    int removemsrRow = 0;
};

#endif // HARD_CPU_H
