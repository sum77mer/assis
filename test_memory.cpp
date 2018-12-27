#include "test_memory.h"
#include "UIdata.h"
Test_Memory::Test_Memory(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
	initializeUI();
	setupLayout();
	setConnection();
	initializeData();  
}
void Test_Memory::paintEvent(QPaintEvent *event)
{}
void Test_Memory::initializeUI()
{
	QLabel *bwResult_512B_value = NULL;
	QLabel *bwResult_1KB_value = NULL;
	QLabel *bwResult_2KB_value = NULL;
	QLabel *bwResult_4KB_value = NULL;
	QLabel *bwResult_8KB_value = NULL;
	QLabel *bwResult_16KB_value = NULL;
	QLabel *bwResult_32KB_value = NULL;
	QLabel *bwResult_64KB_value = NULL;
	QLabel *bwResult_128KB_value = NULL;
	QLabel *bwResult_256KB_value = NULL;
	QLabel *bwResult_512KB_value = NULL;
	QLabel *bwResult_1MB_value = NULL;
	QLabel *bwResult_2MB_value = NULL;
	QLabel *bwResult_4MB_value = NULL;
	QLabel *bwResult_8MB_value = NULL;
	QLabel *bwResult_16MB_value = NULL;
	QLabel *bwResult_32MB_value = NULL;
	QLabel *bwResult_64MB_value = NULL;
	QLabel *bwResult_128MB_value = NULL;
	QLabel *bwResult_256MB_value = NULL;


	QLabel *latResult_512B_value = NULL;
	QLabel *latResult_1KB_value = NULL;
	QLabel *latResult_2KB_value = NULL;
	QLabel *latResult_4KB_value = NULL;
	QLabel *latResult_8KB_value = NULL;
	QLabel *latResult_16KB_value = NULL;
	QLabel *latResult_32KB_value = NULL;
	QLabel *latResult_64KB_value = NULL;
	QLabel *latResult_128KB_value = NULL;
	QLabel *latResult_256KB_value = NULL;
	QLabel *latResult_512KB_value = NULL;
	QLabel *latResult_1MB_value = NULL;
	QLabel *latResult_2MB_value = NULL;
	QLabel *latResult_4MB_value = NULL;
	QLabel *latResult_8MB_value = NULL;
	QLabel *latResult_16MB_value = NULL;
	QLabel *latResult_32MB_value = NULL;
	QLabel *latResult_64MB_value = NULL;
	QLabel *latResult_128MB_value = NULL;
	QLabel *latResult_256MB_value = NULL;

	label_bwtest_title = new QLabel(this);
	label_bwtest_title->setFrameStyle(QFrame::NoFrame);
	label_bwtest_title->setFont(*title_font);
	label_bwtest_title->setAlignment(Qt::AlignLeft);
	label_bwtest_title->setText(QString("BrandWidth Test"));

	label_function_title = new QLabel(this);
	label_function_title->setFrameStyle(QFrame::NoFrame);
	label_function_title->setFont(*normalFont);
	label_function_title->setText(QString("Test Function:"));

	checkbox_fun_ReaderSSE2 = new QCheckBox(this);
	checkbox_fun_ReaderSSE2->setFont(*normalFont);

	checkbox_fun_WriterSSE2 = new QCheckBox(this);
	checkbox_fun_WriterSSE2->setFont(*normalFont);
	checkbox_fun_CopySSE = new QCheckBox(this);
	checkbox_fun_CopySSE->setFont(*normalFont);
	checkbox_fun_WriterSSE2_bypass = new QCheckBox(this);
	checkbox_fun_WriterSSE2_bypass->setFont(*normalFont);
	checkbox_fun_CopySSE_bypass = new QCheckBox(this);
	checkbox_fun_CopySSE_bypass->setFont(*normalFont);
	checkbox_fun_ReaderAVX = new QCheckBox(this);
	checkbox_fun_ReaderAVX->setFont(*normalFont);
	checkbox_fun_WriterAVX = new QCheckBox(this);
	checkbox_fun_WriterAVX->setFont(*normalFont);
	checkbox_fun_CopyAVX = new QCheckBox(this);
	checkbox_fun_CopyAVX->setFont(*normalFont);

	checkbox_fun_ReaderSSE2->setText(QString("ReaderSSE2"));
	checkbox_fun_WriterSSE2->setText(QString("WriterSSE2"));
	checkbox_fun_CopySSE->setText(QString("CopySSE"));
	checkbox_fun_WriterSSE2_bypass->setText(QString("WriterSSE2 bypass"));
	checkbox_fun_CopySSE_bypass->setText(QString("CopySSE bypass"));
	checkbox_fun_ReaderAVX->setText(QString("ReaderAVX"));
	checkbox_fun_WriterAVX->setText(QString("WriterAVX"));
	checkbox_fun_CopyAVX->setText(QString("CopyAVX"));

	label_hyperthread_title = new QLabel(this);
	label_hyperthread_title->setFrameStyle(QFrame::NoFrame);
	label_hyperthread_title->setFont(*normalFont);
	label_hyperthread_title->setText(QString("Hyperthread:"));

	checkbox_hyperthread = new QCheckBox(this);
	checkbox_hyperthread->setFont(*normalFont);
	checkbox_hyperthread->setText(QString("HyperThread"));

	btn_bw_begin = new QPushButton(this);
	btn_bw_begin->setFont(*normalFont);
	btn_bw_begin->setText(QString("Run"));

	bwResult_512B_title = new QLabel(this);
	bwResult_512B_title->setFrameStyle(QFrame::NoFrame);
	bwResult_512B_title->setAlignment(Qt::AlignLeft);
	bwResult_512B_title->setStyleSheet(resultStyleSheet1);
	bwResult_512B_title->setFont(*normalFont);
	bwResult_512B_title->setText(QString("512B"));

	bwResult_1KB_title = new QLabel(this);
	bwResult_1KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_1KB_title->setAlignment(Qt::AlignLeft);
	bwResult_1KB_title->setStyleSheet(resultStyleSheet2);
	bwResult_1KB_title->setFont(*normalFont);
	bwResult_1KB_title->setText(QString("1KB"));

	bwResult_2KB_title = new QLabel(this);
	bwResult_2KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_2KB_title->setAlignment(Qt::AlignLeft);
	bwResult_2KB_title->setStyleSheet(resultStyleSheet1);
	bwResult_2KB_title->setFont(*normalFont);
	bwResult_2KB_title->setText(QString("2KB"));

	bwResult_4KB_title = new QLabel(this);
	bwResult_4KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_4KB_title->setAlignment(Qt::AlignLeft);
	bwResult_4KB_title->setStyleSheet(resultStyleSheet2);
	bwResult_4KB_title->setFont(*normalFont);
	bwResult_4KB_title->setText(QString("4KB"));

	bwResult_8KB_title = new QLabel(this);
	bwResult_8KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_8KB_title->setAlignment(Qt::AlignLeft);
	bwResult_8KB_title->setStyleSheet(resultStyleSheet1);
	bwResult_8KB_title->setFont(*normalFont);
	bwResult_8KB_title->setText(QString("8KB"));

	bwResult_16KB_title = new QLabel(this);
	bwResult_16KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_16KB_title->setAlignment(Qt::AlignLeft);
	bwResult_16KB_title->setStyleSheet(resultStyleSheet2);
	bwResult_16KB_title->setFont(*normalFont);
	bwResult_16KB_title->setText(QString("16KB"));

	bwResult_32KB_title = new QLabel(this);
	bwResult_32KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_32KB_title->setAlignment(Qt::AlignLeft);
	bwResult_32KB_title->setStyleSheet(resultStyleSheet1);
	bwResult_32KB_title->setFont(*normalFont);
	bwResult_32KB_title->setText(QString("32KB"));

	bwResult_64KB_title = new QLabel(this);
	bwResult_64KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_64KB_title->setAlignment(Qt::AlignLeft);
	bwResult_64KB_title->setStyleSheet(resultStyleSheet2);
	bwResult_64KB_title->setFont(*normalFont);
	bwResult_64KB_title->setText(QString("64KB"));

	bwResult_128KB_title = new QLabel(this);
	bwResult_128KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_128KB_title->setAlignment(Qt::AlignLeft);
	bwResult_128KB_title->setStyleSheet(resultStyleSheet1);
	bwResult_128KB_title->setFont(*normalFont);
	bwResult_128KB_title->setText(QString("128KB"));

	bwResult_256KB_title = new QLabel(this);
	bwResult_256KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_256KB_title->setAlignment(Qt::AlignLeft);
	bwResult_256KB_title->setStyleSheet(resultStyleSheet2);
	bwResult_256KB_title->setFont(*normalFont);
	bwResult_256KB_title->setText(QString("256KB"));

	bwResult_512KB_title = new QLabel(this);
	bwResult_512KB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_512KB_title->setAlignment(Qt::AlignLeft);
	bwResult_512KB_title->setStyleSheet(resultStyleSheet1);
	bwResult_512KB_title->setFont(*normalFont);
	bwResult_512KB_title->setText(QString("512KB"));

	bwResult_1MB_title = new QLabel(this);
	bwResult_1MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_1MB_title->setAlignment(Qt::AlignLeft);
	bwResult_1MB_title->setStyleSheet(resultStyleSheet2);
	bwResult_1MB_title->setFont(*normalFont);
	bwResult_1MB_title->setText(QString("1MB"));

	bwResult_2MB_title = new QLabel(this);
	bwResult_2MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_2MB_title->setAlignment(Qt::AlignLeft);
	bwResult_2MB_title->setStyleSheet(resultStyleSheet1);
	bwResult_2MB_title->setFont(*normalFont);
	bwResult_2MB_title->setText(QString("2MB"));

	bwResult_4MB_title = new QLabel(this);
	bwResult_4MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_4MB_title->setAlignment(Qt::AlignLeft);
	bwResult_4MB_title->setStyleSheet(resultStyleSheet2);
	bwResult_4MB_title->setFont(*normalFont);
	bwResult_4MB_title->setText(QString("4MB"));

	bwResult_8MB_title = new QLabel(this);
	bwResult_8MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_8MB_title->setAlignment(Qt::AlignLeft);
	bwResult_8MB_title->setStyleSheet(resultStyleSheet1);
	bwResult_8MB_title->setFont(*normalFont);
	bwResult_8MB_title->setText(QString("8MB"));

	bwResult_16MB_title = new QLabel(this);
	bwResult_16MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_16MB_title->setAlignment(Qt::AlignLeft);
	bwResult_16MB_title->setStyleSheet(resultStyleSheet2);
	bwResult_16MB_title->setFont(*normalFont);
	bwResult_16MB_title->setText(QString("16MB"));

	bwResult_32MB_title = new QLabel(this);
	bwResult_32MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_32MB_title->setAlignment(Qt::AlignLeft);
	bwResult_32MB_title->setStyleSheet(resultStyleSheet1);
	bwResult_32MB_title->setFont(*normalFont);
	bwResult_32MB_title->setText(QString("32MB"));

	bwResult_64MB_title = new QLabel(this);
	bwResult_64MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_64MB_title->setAlignment(Qt::AlignLeft);
	bwResult_64MB_title->setStyleSheet(resultStyleSheet2);
	bwResult_64MB_title->setFont(*normalFont);
	bwResult_64MB_title->setText(QString("64MB"));

	bwResult_128MB_title = new QLabel(this);
	bwResult_128MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_128MB_title->setAlignment(Qt::AlignLeft);
	bwResult_128MB_title->setStyleSheet(resultStyleSheet1);
	bwResult_128MB_title->setFont(*normalFont);
	bwResult_128MB_title->setText(QString("128MB"));

	bwResult_256MB_title = new QLabel(this);
	bwResult_256MB_title->setFrameStyle(QFrame::NoFrame);
	bwResult_256MB_title->setAlignment(Qt::AlignLeft);
	bwResult_256MB_title->setStyleSheet(resultStyleSheet2);
	bwResult_256MB_title->setFont(*normalFont);
	bwResult_256MB_title->setText(QString("256MB"));

	bwResult_512B_value = new QLabel(this);
	bwResult_512B_value->setFrameStyle(QFrame::NoFrame);
	bwResult_512B_value->setAlignment(Qt::AlignRight);
	bwResult_512B_value->setStyleSheet(resultStyleSheet1);
	bwResult_512B_value->setFont(*normalFont);
	bwResult_512B_value->setText(QString("default"));

	bwResult_1KB_value = new QLabel(this);
	bwResult_1KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_1KB_value->setAlignment(Qt::AlignRight);
	bwResult_1KB_value->setStyleSheet(resultStyleSheet2);
	bwResult_1KB_value->setFont(*normalFont);
	bwResult_1KB_value->setText(QString("default"));

	bwResult_2KB_value = new QLabel(this);
	bwResult_2KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_2KB_value->setAlignment(Qt::AlignRight);
	bwResult_2KB_value->setStyleSheet(resultStyleSheet1);
	bwResult_2KB_value->setFont(*normalFont);
	bwResult_2KB_value->setText(QString("default"));

	bwResult_4KB_value = new QLabel(this);
	bwResult_4KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_4KB_value->setAlignment(Qt::AlignRight);
	bwResult_4KB_value->setStyleSheet(resultStyleSheet2);
	bwResult_4KB_value->setFont(*normalFont);
	bwResult_4KB_value->setText(QString("default"));

	bwResult_8KB_value = new QLabel(this);
	bwResult_8KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_8KB_value->setAlignment(Qt::AlignRight);
	bwResult_8KB_value->setStyleSheet(resultStyleSheet1);
	bwResult_8KB_value->setFont(*normalFont);
	bwResult_8KB_value->setText(QString("default"));

	bwResult_16KB_value = new QLabel(this);
	bwResult_16KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_16KB_value->setAlignment(Qt::AlignRight);
	bwResult_16KB_value->setStyleSheet(resultStyleSheet2);
	bwResult_16KB_value->setFont(*normalFont);
	bwResult_16KB_value->setText(QString("default"));

	bwResult_32KB_value = new QLabel(this);
	bwResult_32KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_32KB_value->setAlignment(Qt::AlignRight);
	bwResult_32KB_value->setStyleSheet(resultStyleSheet1);
	bwResult_32KB_value->setFont(*normalFont);
	bwResult_32KB_value->setText(QString("default"));

	bwResult_64KB_value = new QLabel(this);
	bwResult_64KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_64KB_value->setAlignment(Qt::AlignRight);
	bwResult_64KB_value->setStyleSheet(resultStyleSheet2);
	bwResult_64KB_value->setFont(*normalFont);
	bwResult_64KB_value->setText(QString("default"));

	bwResult_128KB_value = new QLabel(this);
	bwResult_128KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_128KB_value->setAlignment(Qt::AlignRight);
	bwResult_128KB_value->setStyleSheet(resultStyleSheet1);
	bwResult_128KB_value->setFont(*normalFont);
	bwResult_128KB_value->setText(QString("default"));

	bwResult_256KB_value = new QLabel(this);
	bwResult_256KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_256KB_value->setAlignment(Qt::AlignRight);
	bwResult_256KB_value->setStyleSheet(resultStyleSheet2);
	bwResult_256KB_value->setFont(*normalFont);
	bwResult_256KB_value->setText(QString("default"));

	bwResult_512KB_value = new QLabel(this);
	bwResult_512KB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_512KB_value->setAlignment(Qt::AlignRight);
	bwResult_512KB_value->setStyleSheet(resultStyleSheet1);
	bwResult_512KB_value->setFont(*normalFont);
	bwResult_512KB_value->setText(QString("default"));

	bwResult_1MB_value = new QLabel(this);
	bwResult_1MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_1MB_value->setAlignment(Qt::AlignRight);
	bwResult_1MB_value->setStyleSheet(resultStyleSheet2);
	bwResult_1MB_value->setFont(*normalFont);
	bwResult_1MB_value->setText(QString("default"));

	bwResult_2MB_value = new QLabel(this);
	bwResult_2MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_2MB_value->setAlignment(Qt::AlignRight);
	bwResult_2MB_value->setStyleSheet(resultStyleSheet1);
	bwResult_2MB_value->setFont(*normalFont);
	bwResult_2MB_value->setText(QString("default"));

	bwResult_4MB_value = new QLabel(this);
	bwResult_4MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_4MB_value->setAlignment(Qt::AlignRight);
	bwResult_4MB_value->setStyleSheet(resultStyleSheet2);
	bwResult_4MB_value->setFont(*normalFont);
	bwResult_4MB_value->setText(QString("default"));

	bwResult_8MB_value = new QLabel(this);
	bwResult_8MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_8MB_value->setAlignment(Qt::AlignRight);
	bwResult_8MB_value->setStyleSheet(resultStyleSheet1);
	bwResult_8MB_value->setFont(*normalFont);
	bwResult_8MB_value->setText(QString("default"));

	bwResult_16MB_value = new QLabel(this);
	bwResult_16MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_16MB_value->setAlignment(Qt::AlignRight);
	bwResult_16MB_value->setStyleSheet(resultStyleSheet2);
	bwResult_16MB_value->setFont(*normalFont);
	bwResult_16MB_value->setText(QString("default"));

	bwResult_32MB_value = new QLabel(this);
	bwResult_32MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_32MB_value->setAlignment(Qt::AlignRight);
	bwResult_32MB_value->setStyleSheet(resultStyleSheet1);
	bwResult_32MB_value->setFont(*normalFont);
	bwResult_32MB_value->setText(QString("default"));

	bwResult_64MB_value = new QLabel(this);
	bwResult_64MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_64MB_value->setAlignment(Qt::AlignRight);
	bwResult_64MB_value->setStyleSheet(resultStyleSheet2);
	bwResult_64MB_value->setFont(*normalFont);
	bwResult_64MB_value->setText(QString("default"));

	bwResult_128MB_value = new QLabel(this);
	bwResult_128MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_128MB_value->setAlignment(Qt::AlignRight);
	bwResult_128MB_value->setStyleSheet(resultStyleSheet1);
	bwResult_128MB_value->setFont(*normalFont);
	bwResult_128MB_value->setText(QString("default"));

	bwResult_256MB_value = new QLabel(this);
	bwResult_256MB_value->setFrameStyle(QFrame::NoFrame);
	bwResult_256MB_value->setAlignment(Qt::AlignRight);
	bwResult_256MB_value->setStyleSheet(resultStyleSheet2);
	bwResult_256MB_value->setFont(*normalFont);
	bwResult_256MB_value->setText(QString("default"));
	//****************************************************************

	latResult_512B_title = new QLabel(this);
	latResult_512B_title->setFrameStyle(QFrame::NoFrame);
	latResult_512B_title->setAlignment(Qt::AlignLeft);
	latResult_512B_title->setStyleSheet(resultStyleSheet2);
	latResult_512B_title->setFont(*normalFont);
	latResult_512B_title->setText(QString("512B"));

	latResult_1KB_title = new QLabel(this);
	latResult_1KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_1KB_title->setAlignment(Qt::AlignLeft);
	latResult_1KB_title->setStyleSheet(resultStyleSheet1);
	latResult_1KB_title->setFont(*normalFont);
	latResult_1KB_title->setText(QString("1KB"));

	latResult_2KB_title = new QLabel(this);
	latResult_2KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_2KB_title->setAlignment(Qt::AlignLeft);
	latResult_2KB_title->setStyleSheet(resultStyleSheet2);
	latResult_2KB_title->setFont(*normalFont);
	latResult_2KB_title->setText(QString("2KB"));

	latResult_4KB_title = new QLabel(this);
	latResult_4KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_4KB_title->setAlignment(Qt::AlignLeft);
	latResult_4KB_title->setStyleSheet(resultStyleSheet1);
	latResult_4KB_title->setFont(*normalFont);
	latResult_4KB_title->setText(QString("4KB"));

	latResult_8KB_title = new QLabel(this);
	latResult_8KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_8KB_title->setAlignment(Qt::AlignLeft);
	latResult_8KB_title->setStyleSheet(resultStyleSheet2);
	latResult_8KB_title->setFont(*normalFont);
	latResult_8KB_title->setText(QString("8KB"));

	latResult_16KB_title = new QLabel(this);
	latResult_16KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_16KB_title->setAlignment(Qt::AlignLeft);
	latResult_16KB_title->setStyleSheet(resultStyleSheet1);
	latResult_16KB_title->setFont(*normalFont);
	latResult_16KB_title->setText(QString("16KB"));

	latResult_32KB_title = new QLabel(this);
	latResult_32KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_32KB_title->setAlignment(Qt::AlignLeft);
	latResult_32KB_title->setStyleSheet(resultStyleSheet2);
	latResult_32KB_title->setFont(*normalFont);
	latResult_32KB_title->setText(QString("32KB"));

	latResult_64KB_title = new QLabel(this);
	latResult_64KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_64KB_title->setAlignment(Qt::AlignLeft);
	latResult_64KB_title->setStyleSheet(resultStyleSheet1);
	latResult_64KB_title->setFont(*normalFont);
	latResult_64KB_title->setText(QString("64KB"));

	latResult_128KB_title = new QLabel(this);
	latResult_128KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_128KB_title->setAlignment(Qt::AlignLeft);
	latResult_128KB_title->setStyleSheet(resultStyleSheet2);
	latResult_128KB_title->setFont(*normalFont);
	latResult_128KB_title->setText(QString("128KB"));

	latResult_256KB_title = new QLabel(this);
	latResult_256KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_256KB_title->setAlignment(Qt::AlignLeft);
	latResult_256KB_title->setStyleSheet(resultStyleSheet1);
	latResult_256KB_title->setFont(*normalFont);
	latResult_256KB_title->setText(QString("256KB"));

	latResult_512KB_title = new QLabel(this);
	latResult_512KB_title->setFrameStyle(QFrame::NoFrame);
	latResult_512KB_title->setAlignment(Qt::AlignLeft);
	latResult_512KB_title->setStyleSheet(resultStyleSheet2);
	latResult_512KB_title->setFont(*normalFont);
	latResult_512KB_title->setText(QString("512KB"));

	latResult_1MB_title = new QLabel(this);
	latResult_1MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_1MB_title->setAlignment(Qt::AlignLeft);
	latResult_1MB_title->setStyleSheet(resultStyleSheet1);
	latResult_1MB_title->setFont(*normalFont);
	latResult_1MB_title->setText(QString("1MB"));

	latResult_2MB_title = new QLabel(this);
	latResult_2MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_2MB_title->setAlignment(Qt::AlignLeft);
	latResult_2MB_title->setStyleSheet(resultStyleSheet2);
	latResult_2MB_title->setFont(*normalFont);
	latResult_2MB_title->setText(QString("2MB"));

	latResult_4MB_title = new QLabel(this);
	latResult_4MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_4MB_title->setAlignment(Qt::AlignLeft);
	latResult_4MB_title->setStyleSheet(resultStyleSheet1);
	latResult_4MB_title->setFont(*normalFont);
	latResult_4MB_title->setText(QString("4MB"));

	latResult_8MB_title = new QLabel(this);
	latResult_8MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_8MB_title->setAlignment(Qt::AlignLeft);
	latResult_8MB_title->setStyleSheet(resultStyleSheet2);
	latResult_8MB_title->setFont(*normalFont);
	latResult_8MB_title->setText(QString("8MB"));

	latResult_16MB_title = new QLabel(this);
	latResult_16MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_16MB_title->setAlignment(Qt::AlignLeft);
	latResult_16MB_title->setStyleSheet(resultStyleSheet1);
	latResult_16MB_title->setFont(*normalFont);
	latResult_16MB_title->setText(QString("16MB"));

	latResult_32MB_title = new QLabel(this);
	latResult_32MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_32MB_title->setAlignment(Qt::AlignLeft);
	latResult_32MB_title->setStyleSheet(resultStyleSheet2);
	latResult_32MB_title->setFont(*normalFont);
	latResult_32MB_title->setText(QString("32MB"));

	latResult_64MB_title = new QLabel(this);
	latResult_64MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_64MB_title->setAlignment(Qt::AlignLeft);
	latResult_64MB_title->setStyleSheet(resultStyleSheet1);
	latResult_64MB_title->setFont(*normalFont);
	latResult_64MB_title->setText(QString("64MB"));

	latResult_128MB_title = new QLabel(this);
	latResult_128MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_128MB_title->setAlignment(Qt::AlignLeft);
	latResult_128MB_title->setStyleSheet(resultStyleSheet2);
	latResult_128MB_title->setFont(*normalFont);
	latResult_128MB_title->setText(QString("128MB"));

	latResult_256MB_title = new QLabel(this);
	latResult_256MB_title->setFrameStyle(QFrame::NoFrame);
	latResult_256MB_title->setAlignment(Qt::AlignLeft);
	latResult_256MB_title->setStyleSheet(resultStyleSheet1);
	latResult_256MB_title->setFont(*normalFont);
	latResult_256MB_title->setText(QString("256MB"));

	latResult_512B_value = new QLabel(this);
	latResult_512B_value->setFrameStyle(QFrame::NoFrame);
	latResult_512B_value->setAlignment(Qt::AlignRight);
	latResult_512B_value->setStyleSheet(resultStyleSheet2);
	latResult_512B_value->setFont(*normalFont);
	latResult_512B_value->setText(QString("default"));

	latResult_1KB_value = new QLabel(this);
	latResult_1KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_1KB_value->setAlignment(Qt::AlignRight);
	latResult_1KB_value->setStyleSheet(resultStyleSheet1);
	latResult_1KB_value->setFont(*normalFont);
	latResult_1KB_value->setText(QString("default"));

	latResult_2KB_value = new QLabel(this);
	latResult_2KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_2KB_value->setAlignment(Qt::AlignRight);
	latResult_2KB_value->setStyleSheet(resultStyleSheet2);
	latResult_2KB_value->setFont(*normalFont);
	latResult_2KB_value->setText(QString("default"));

	latResult_4KB_value = new QLabel(this);
	latResult_4KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_4KB_value->setAlignment(Qt::AlignRight);
	latResult_4KB_value->setStyleSheet(resultStyleSheet1);
	latResult_4KB_value->setFont(*normalFont);
	latResult_4KB_value->setText(QString("default"));

	latResult_8KB_value = new QLabel(this);
	latResult_8KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_8KB_value->setAlignment(Qt::AlignRight);
	latResult_8KB_value->setStyleSheet(resultStyleSheet2);
	latResult_8KB_value->setFont(*normalFont);
	latResult_8KB_value->setText(QString("default"));

	latResult_16KB_value = new QLabel(this);
	latResult_16KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_16KB_value->setAlignment(Qt::AlignRight);
	latResult_16KB_value->setStyleSheet(resultStyleSheet1);
	latResult_16KB_value->setFont(*normalFont);
	latResult_16KB_value->setText(QString("default"));

	latResult_32KB_value = new QLabel(this);
	latResult_32KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_32KB_value->setAlignment(Qt::AlignRight);
	latResult_32KB_value->setStyleSheet(resultStyleSheet2);
	latResult_32KB_value->setFont(*normalFont);
	latResult_32KB_value->setText(QString("default"));

	latResult_64KB_value = new QLabel(this);
	latResult_64KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_64KB_value->setAlignment(Qt::AlignRight);
	latResult_64KB_value->setStyleSheet(resultStyleSheet1);
	latResult_64KB_value->setFont(*normalFont);
	latResult_64KB_value->setText(QString("default"));

	latResult_128KB_value = new QLabel(this);
	latResult_128KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_128KB_value->setAlignment(Qt::AlignRight);
	latResult_128KB_value->setStyleSheet(resultStyleSheet2);
	latResult_128KB_value->setFont(*normalFont);
	latResult_128KB_value->setText(QString("default"));

	latResult_256KB_value = new QLabel(this);
	latResult_256KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_256KB_value->setAlignment(Qt::AlignRight);
	latResult_256KB_value->setStyleSheet(resultStyleSheet1);
	latResult_256KB_value->setFont(*normalFont);
	latResult_256KB_value->setText(QString("default"));

	latResult_512KB_value = new QLabel(this);
	latResult_512KB_value->setFrameStyle(QFrame::NoFrame);
	latResult_512KB_value->setAlignment(Qt::AlignRight);
	latResult_512KB_value->setStyleSheet(resultStyleSheet2);
	latResult_512KB_value->setFont(*normalFont);
	latResult_512KB_value->setText(QString("default"));

	latResult_1MB_value = new QLabel(this);
	latResult_1MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_1MB_value->setAlignment(Qt::AlignRight);
	latResult_1MB_value->setStyleSheet(resultStyleSheet1);
	latResult_1MB_value->setFont(*normalFont);
	latResult_1MB_value->setText(QString("default"));

	latResult_2MB_value = new QLabel(this);
	latResult_2MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_2MB_value->setAlignment(Qt::AlignRight);
	latResult_2MB_value->setStyleSheet(resultStyleSheet2);
	latResult_2MB_value->setFont(*normalFont);
	latResult_2MB_value->setText(QString("default"));

	latResult_4MB_value = new QLabel(this);
	latResult_4MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_4MB_value->setAlignment(Qt::AlignRight);
	latResult_4MB_value->setStyleSheet(resultStyleSheet1);
	latResult_4MB_value->setFont(*normalFont);
	latResult_4MB_value->setText(QString("default"));

	latResult_8MB_value = new QLabel(this);
	latResult_8MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_8MB_value->setAlignment(Qt::AlignRight);
	latResult_8MB_value->setStyleSheet(resultStyleSheet2);
	latResult_8MB_value->setFont(*normalFont);
	latResult_8MB_value->setText(QString("default"));

	latResult_16MB_value = new QLabel(this);
	latResult_16MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_16MB_value->setAlignment(Qt::AlignRight);
	latResult_16MB_value->setStyleSheet(resultStyleSheet1);
	latResult_16MB_value->setFont(*normalFont);
	latResult_16MB_value->setText(QString("default"));

	latResult_32MB_value = new QLabel(this);
	latResult_32MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_32MB_value->setAlignment(Qt::AlignRight);
	latResult_32MB_value->setStyleSheet(resultStyleSheet2);
	latResult_32MB_value->setFont(*normalFont);
	latResult_32MB_value->setText(QString("default"));

	latResult_64MB_value = new QLabel(this);
	latResult_64MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_64MB_value->setAlignment(Qt::AlignRight);
	latResult_64MB_value->setStyleSheet(resultStyleSheet1);
	latResult_64MB_value->setFont(*normalFont);
	latResult_64MB_value->setText(QString("default"));

	latResult_128MB_value = new QLabel(this);
	latResult_128MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_128MB_value->setAlignment(Qt::AlignRight);
	latResult_128MB_value->setStyleSheet(resultStyleSheet2);
	latResult_128MB_value->setFont(*normalFont);
	latResult_128MB_value->setText(QString("default"));

	latResult_256MB_value = new QLabel(this);
	latResult_256MB_value->setFrameStyle(QFrame::NoFrame);
	latResult_256MB_value->setAlignment(Qt::AlignRight);
	latResult_256MB_value->setStyleSheet(resultStyleSheet1);
	latResult_256MB_value->setFont(*normalFont);
	latResult_256MB_value->setText(QString("default"));

	label_lattest_title = new QLabel(this);
	label_lattest_title->setFrameStyle(QFrame::NoFrame);
	label_lattest_title->setFont(*title_font);
	label_lattest_title->setAlignment(Qt::AlignLeft);
	label_lattest_title->setText(QStringLiteral("Latency Test"));

	label_stride_title = new QLabel(this);
	label_stride_title->setFrameStyle(QFrame::NoFrame);
	label_stride_title->setFont(*normalFont);
	label_stride_title->setText(QStringLiteral("stride"));

	lineedit_stride = new QLineEdit(this);
	lineedit_stride->setFont(*normalFont);
	lineedit_stride->setText(QStringLiteral(""));
	lineedit_stride->setMinimumWidth(50);
	lineedit_stride->setMaximumHeight(20);

	btn_lat_begin = new QPushButton(this);
	btn_lat_begin->setFont(*normalFont);
	btn_lat_begin->setText(QString("Run"));

	btn_openBWChartWindow = new QPushButton(this);
	btn_openBWChartWindow->setFont(*normalFont);
	btn_openBWChartWindow->setText(QString("Chart View"));

	btn_openLATChartWindow = new QPushButton(this);
	btn_openLATChartWindow->setFont(*normalFont);
	btn_openLATChartWindow->setText(QString("Chart View"));

	bwResult.append(bwResult_512B_value);
	bwResult.append(bwResult_1KB_value);
	bwResult.append(bwResult_2KB_value);
	bwResult.append(bwResult_4KB_value);
	bwResult.append(bwResult_8KB_value);
	bwResult.append(bwResult_16KB_value);
	bwResult.append(bwResult_32KB_value);
	bwResult.append(bwResult_64KB_value);
	bwResult.append(bwResult_128KB_value);
	bwResult.append(bwResult_256KB_value);
	bwResult.append(bwResult_512KB_value);
	bwResult.append(bwResult_1MB_value);
	bwResult.append(bwResult_2MB_value);
	bwResult.append(bwResult_4MB_value);
	bwResult.append(bwResult_8MB_value);
	bwResult.append(bwResult_16MB_value);
	bwResult.append(bwResult_32MB_value);
	bwResult.append(bwResult_64MB_value);
	bwResult.append(bwResult_128MB_value);
	bwResult.append(bwResult_256MB_value);

	latResult.append(latResult_512B_value);
	latResult.append(latResult_1KB_value);
	latResult.append(latResult_2KB_value);
	latResult.append(latResult_4KB_value);
	latResult.append(latResult_8KB_value);
	latResult.append(latResult_16KB_value);
	latResult.append(latResult_32KB_value);
	latResult.append(latResult_64KB_value);
	latResult.append(latResult_128KB_value);
	latResult.append(latResult_256KB_value);
	latResult.append(latResult_512KB_value);
	latResult.append(latResult_1MB_value);
	latResult.append(latResult_2MB_value);
	latResult.append(latResult_4MB_value);
	latResult.append(latResult_8MB_value);
	latResult.append(latResult_16MB_value);
	latResult.append(latResult_32MB_value);
	latResult.append(latResult_64MB_value);
	latResult.append(latResult_128MB_value);
	latResult.append(latResult_256MB_value);
}
void Test_Memory::setupLayout()
{
	QWidget *widget = new QWidget(this);
	widget->setWindowFlags(Qt::FramelessWindowHint);
	widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	QGridLayout *sublayout = new QGridLayout;
	sublayout->setVerticalSpacing(10);
	sublayout->setHorizontalSpacing(5);
	sublayout->setContentsMargins(30, 20, 30, 20);//row: col:
												  //row1
	sublayout->addWidget(label_bwtest_title, 0, 0, 1, 4);
	//row2
	//row3
	sublayout->addWidget(label_function_title, 2, 0, 1, 1);
	sublayout->addWidget(checkbox_fun_WriterAVX, 2, 1, 1, 1);
	sublayout->addWidget(checkbox_fun_WriterSSE2, 2, 2, 1, 1);
	//row4
	sublayout->addWidget(checkbox_fun_WriterSSE2_bypass, 3, 1, 1, 1);
	sublayout->addWidget(checkbox_fun_CopySSE_bypass, 3, 2, 1, 1);
	//row5
	sublayout->addWidget(checkbox_fun_CopySSE, 4, 1, 1, 1);
	sublayout->addWidget(checkbox_fun_CopyAVX, 4, 2, 1, 1);
	//row6
	sublayout->addWidget(checkbox_fun_ReaderSSE2, 5, 1, 1, 1);
	sublayout->addWidget(checkbox_fun_ReaderAVX, 5, 2, 1, 1);
	//row7
	sublayout->addWidget(label_hyperthread_title, 6, 0, 1, 1);
	sublayout->addWidget(checkbox_hyperthread, 6, 1, 1, 1);
	//row8
	sublayout->addWidget(btn_bw_begin, 7, 0, 1, 1);
	sublayout->addWidget(btn_openBWChartWindow, 7, 1, 1, 1);
	//row9
	//sublayout->addWidget(bwResult,7,2,1,7,Qt::AlignLeft|Qt::AlignBottom);
	sublayout->addWidget(bwResult_512B_title, 8, 0);
	sublayout->addWidget(bwResult_1KB_title, 9, 0);
	sublayout->addWidget(bwResult_2KB_title, 10, 0);
	sublayout->addWidget(bwResult_4KB_title, 11, 0);
	sublayout->addWidget(bwResult_8KB_title, 12, 0);
	sublayout->addWidget(bwResult_16KB_title, 13, 0);
	sublayout->addWidget(bwResult_32KB_title, 14, 0);
	sublayout->addWidget(bwResult_64KB_title, 15, 0);
	sublayout->addWidget(bwResult_128KB_title, 16, 0);
	sublayout->addWidget(bwResult_256KB_title, 17, 0);
	sublayout->addWidget(bwResult_512KB_title, 18, 0);
	sublayout->addWidget(bwResult_1MB_title, 19, 0);
	sublayout->addWidget(bwResult_2MB_title, 20, 0);
	sublayout->addWidget(bwResult_4MB_title, 21, 0);
	sublayout->addWidget(bwResult_8MB_title, 22, 0);
	sublayout->addWidget(bwResult_16MB_title, 23, 0);
	sublayout->addWidget(bwResult_32MB_title, 24, 0);
	sublayout->addWidget(bwResult_64MB_title, 25, 0);
	sublayout->addWidget(bwResult_128MB_title, 26, 0);
	sublayout->addWidget(bwResult_256MB_title, 27, 0);
	auto it = bwResult.begin();
	unsigned int rowNum = 8;
	for (unsigned int i = 0; i < 20; i++)
	{
		sublayout->addWidget(*it, rowNum, 1, 1, 3);
		rowNum++;
		it++;
	}
	//row29
	//row30
	sublayout->addWidget(label_lattest_title, 29, 0, 1, 4);
	//row31
	//row32
	sublayout->addWidget(label_stride_title, 31, 0, 1, 1);
	sublayout->addWidget(lineedit_stride, 31, 1, 1, 1);
	sublayout->addWidget(btn_lat_begin, 31, 2, 1, 1);
	sublayout->addWidget(btn_openLATChartWindow, 31, 3, 1, 1);
	//row13
	it = latResult.begin();
	rowNum = 32;
	for (unsigned int i = 0; i < 20; i++)
	{
		sublayout->addWidget(*it, rowNum, 1, 1, 3);
		rowNum++;
		it++;
	}
	sublayout->addWidget(latResult_512B_title, 32, 0);
	sublayout->addWidget(latResult_1KB_title, 33, 0);
	sublayout->addWidget(latResult_2KB_title, 34, 0);
	sublayout->addWidget(latResult_4KB_title, 35, 0);
	sublayout->addWidget(latResult_8KB_title, 36, 0);
	sublayout->addWidget(latResult_16KB_title, 37, 0);
	sublayout->addWidget(latResult_32KB_title, 38, 0);
	sublayout->addWidget(latResult_64KB_title, 39, 0);
	sublayout->addWidget(latResult_128KB_title, 40, 0);
	sublayout->addWidget(latResult_256KB_title, 41, 0);
	sublayout->addWidget(latResult_512KB_title, 42, 0);
	sublayout->addWidget(latResult_1MB_title, 43, 0);
	sublayout->addWidget(latResult_2MB_title, 44, 0);
	sublayout->addWidget(latResult_4MB_title, 45, 0);
	sublayout->addWidget(latResult_8MB_title, 46, 0);
	sublayout->addWidget(latResult_16MB_title, 47, 0);
	sublayout->addWidget(latResult_32MB_title, 48, 0);
	sublayout->addWidget(latResult_64MB_title, 49, 0);
	sublayout->addWidget(latResult_128MB_title, 50, 0);
	sublayout->addWidget(latResult_256MB_title, 51, 0);

	widget->setLayout(sublayout);

	scrollarea = new QScrollArea;
	scrollarea->setAlignment(Qt::AlignCenter);
	scrollarea->setBackgroundRole(QPalette::Window);
	scrollarea->setFrameStyle(QFrame::NoFrame);
	scrollarea->setWidget(widget);
	scrollarea->setWidgetResizable(true);
	scrollarea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(scrollarea);
	setLayout(layout);
}
void Test_Memory::setConnection()
{
	connect(btn_bw_begin, SIGNAL(clicked(bool)), this, SLOT(begin_bw()));
	connect(btn_lat_begin, SIGNAL(clicked(bool)), this, SLOT(begin_lat()));
	connect(btn_openBWChartWindow, SIGNAL(clicked(bool)), this, SLOT(openBWchartWindow()));
	connect(btn_openLATChartWindow, SIGNAL(clicked(bool)), this, SLOT(openLATchartWindow()));
}
void Test_Memory::initializeData()
{}
void Test_Memory::openBWchartWindow()
{
	if(memoryBWTestWindow == NULL)
		memoryBWTestWindow = new Window_memoryTest(this, QString("Bandwidth(GB/s)"),1300,800);
	memoryBWTestWindow->initializeChart();
	bw_chartWindow = true;
	/*
	for (unsigned int i = 0; i < bwtestResults.length(); i++)
	{
		memoryBWTestWindow->drawSeries(bwtestResults.at(i),false);
	}
	*/
	memoryBWTestWindow->show();
}
void Test_Memory::openLATchartWindow()
{
	if(memoryLATTestWindow == NULL)
		memoryLATTestWindow = new Window_memoryTest(this, QString("Latency(GB/s)"),2000,800);
	memoryLATTestWindow->initializeChart();
	lat_chartWindow = true;
	/*
	for (unsigned int i = 0; i < bwtestResults.length(); i++)
	{
		memoryBWTestWindow->drawSeries(bwtestResults.at(i),false);
	}
	*/
	memoryLATTestWindow->show();
}
void Test_Memory::begin_bw()
{
	if (beginflag1)
	{
		btn_bw_begin->setText(QString("Run"));
		process_bw->kill();
		beginflag1 = false;
		testedFunNum = testFunctionList.length();
	}
	else
	{
		btn_bw_begin->setText(QString("Stop"));
		beginflag1 = true;
		testFunctionList.clear();
		testedFunNum = 0;
		if (checkbox_fun_ReaderSSE2->isChecked())
		{
			testFunctionList << "10";
			testFunNum++;
		}
		if (checkbox_fun_WriterSSE2->isChecked())
		{
			testFunctionList << "11";
			testFunNum++;
		}
		if (checkbox_fun_CopySSE->isChecked())
		{
			testFunctionList << "12";
			testFunNum++;
		}
		if (checkbox_fun_WriterSSE2_bypass->isChecked())
		{
			testFunctionList << "13";
			testFunNum++;
		}
		if (checkbox_fun_CopySSE_bypass->isChecked())
		{
			testFunctionList << "14";
			testFunNum++;
		}
		if (checkbox_fun_ReaderAVX->isChecked())
		{
			testFunctionList << "20";
			testFunNum++;
		}
		if (checkbox_fun_WriterAVX->isChecked())
		{
			testFunctionList << "21";
			testFunNum++;
		}
		if (checkbox_fun_CopyAVX->isChecked())
		{
			testFunctionList << "22";
			testFunNum++;
		}
		if (checkbox_hyperthread->isChecked())
		{
			hyperthread_flag = true;
		}
		if (!testFunctionList.isEmpty())
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

    btn_bw_begin->setText(QString("Stop"));
	beginflag1 = true;
    QString program = "./mem_benchmark.exe";
	//QString program = "./debug/mem_benchmark.exe";
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
        QFile *file = new QFile("./mem_benchmark.txt");
        file->open(QIODevice::ReadOnly);
        QByteArray b= file->readAll();
        QJsonParseError *error=new QJsonParseError;
        QJsonDocument jsonfile = QJsonDocument::fromJson(b,error);
        if(error->error==QJsonParseError::NoError)
        {
            if(jsonfile.isObject())
            {
                QJsonObject jsonobject = jsonfile.object();
                QJsonValue value;
                value = jsonobject.value("bandwidth");
				double dvalue = value.toDouble()*100;
				unsigned int intvalue = dvalue;
				dvalue = intvalue;
				dvalue = dvalue / 100;
                testResult<<QString("%0").arg(dvalue);
				auto it = bwResult.begin();
				it += testedSizeNum;
				(*it)->setText(QString("%0GB/S").arg(dvalue));
				testedSizeNum++;
				bwtestResults.append(dvalue);
				if(bw_chartWindow)
					memoryBWTestWindow->drawSeries(bwtestResults,false);
				
                update();
                if(testedSizeNum==20)
                {
                    testedFunNum++;
                    testedSizeNum=0;
                    testResult.clear();
					bwtestResults.clear();
                }         
            }
        }
    }
    else
    {
		/*
		QMessageBox *messagebox = new QMessageBox(this);
		messagebox->setText(QString("test fail:%0  %1").arg(exitStatus).arg(exitCode));
        messagebox->exec();
		*/
        
    }
    if(testFunctionList.length()>testedFunNum)
    {
        testFunction(testFunctionList.at(testedFunNum));
    }
    else
    {
        beginflag1 = false;
        btn_bw_begin->setText(QString("Run"));
    }
}
void Test_Memory::begin_lat()
{
	if (beginflag2)
	{
		btn_lat_begin->setText(QString("Run"));
		process_lat->kill();
		beginflag2 = false;
		testedSizeNum_lat = testLength_lat.length();
	}
	else
	{
		testedSizeNum_lat = 0;
		str_stride = lineedit_stride->text();
		unsigned int i = str_stride.toInt();
		QRegExp regexp("[0-9]+");
		if (regexp.exactMatch(str_stride) && (i >= 8) && (i <= 64))
		{
			btn_lat_begin->setText(QString("Stop"));
			beginflag2 = true;
			test_lat(str_stride);
		}
		else
		{
			QMessageBox *messagebox = new QMessageBox(this);
			messagebox->setText(QString("invalid input(8-64)"));
			messagebox->exec();
		}
	}
}
void Test_Memory::test_lat(QString para_stride)
{
	beginflag2 = true;
    QString program = "./mem_benchmark.exe";
	//QString program = "./debug/mem_benchmark.exe";
    QStringList parameter;
    parameter<<"lat"<<testLength_lat.at(testedSizeNum_lat)<<para_stride;
    process_lat = new QProcess(this);
    process_lat->start(program,parameter);
    connect(process_lat,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(ifNext_lat(int,QProcess::ExitStatus)));
}
void Test_Memory::ifNext_lat(int exitCode, QProcess::ExitStatus exitStatus)
{
    if(exitStatus == QProcess::NormalExit)
    {
        QFile *file = new QFile("./mem_benchmark.txt");
        file->open(QIODevice::ReadOnly);
        QByteArray b= file->readAll();
        QJsonParseError *error=new QJsonParseError;
        QJsonDocument jsonfile = QJsonDocument::fromJson(b,error);
        if(error->error==QJsonParseError::NoError)
        {
            if(jsonfile.isObject())
            {
				QJsonObject jsonobject = jsonfile.object();
				QJsonValue value;
				value = jsonobject.value("latency");
				double dvalue = value.toDouble();
				unsigned int i = 0;
				while (!qFloor(dvalue))
				{
					dvalue = dvalue * 10;
					i++;
				}
				if (i<10)
					dvalue = dvalue*qPow(10, 10 - i);
				dvalue = dvalue*100;
				unsigned int intvalue = dvalue;
				dvalue = intvalue;
				dvalue = dvalue / 100;
				testResult << QString("%0").arg(dvalue);
				auto it = latResult.begin();
				it += testedSizeNum_lat;
				(*it)->setText(QString("%0GB/S").arg(dvalue));
				testedSizeNum_lat++;
				lattestResults.append(dvalue);
				if(lat_chartWindow)
					memoryLATTestWindow->drawSeries(lattestResults, false);
                /*
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
				*/
                update();
                if(testedSizeNum_lat==20)
                {
                    testedSizeNum=0;
					lattestResults.clear();
                    testResult_lat.clear();
                }
            }
        }
    }
    else
    {
		/*
		QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("test fail:%0  %1").arg(exitStatus).arg(exitCode));
        messagebox->exec();
		*/
 
    }
    if(testedSizeNum_lat<testLength_lat.length())
    {
        test_lat(str_stride);
    }
    else
    {
		beginflag2 = false;
        btn_lat_begin->setText(QString("Run"));
    }
}
void Test_Memory::reset()
{
	scrollarea->verticalScrollBar()->setValue(0);
}