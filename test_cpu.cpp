#include "test_cpu.h"
#include "UIdata.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QProcess>
#include <QFile>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFont>
#include <qbrush.h>
Test_CPU::Test_CPU(QWidget *parent)
{
    setWindowFlags(Qt::FramelessWindowHint);

	initializeUI();
	setupLayout();
	setConnection();
	initializeData();
}
void Test_CPU::initializeUI()
{
	//QFont item_font("Arial", 15, QFont::Normal);
	//QFont btnFont("Arial", 15, QFont::Normal);

	btn_begin = new QPushButton(this);
	btn_begin->setFont(*normalFont);
	btn_begin->setText(QString("Run"));

	connect(btn_begin, SIGNAL(clicked(bool)), this, SLOT(begin()));

	title_branch = new QLabel(this);
	title_branch->setFrameStyle(QFrame::NoFrame);
	title_branch->setAlignment(Qt::AlignLeft);
	title_branch->setFont(*title_font);
	title_branch->setText(QStringLiteral("Branch Prediction Test"));

	title_float = new QLabel(this);
	title_float->setFrameStyle(QFrame::NoFrame);
	title_float->setAlignment(Qt::AlignLeft);
	title_float->setFont(*title_font);
	title_float->setText(QStringLiteral("Floating Point Test"));

	title_dataStream = new QLabel(this);
	title_dataStream->setFrameStyle(QFrame::NoFrame);
	title_dataStream->setAlignment(Qt::AlignLeft);
	title_dataStream->setFont(*title_font);
	title_dataStream->setText(QStringLiteral("Data Stream Test"));

	title_cpuqueen = new QLabel(this);
	title_cpuqueen->setFrameStyle(QFrame::NoFrame);
	title_cpuqueen->setAlignment(Qt::AlignLeft);
	title_cpuqueen->setStyleSheet(resultStyleSheet1);
	title_cpuqueen->setFont(*normalFont);
	title_cpuqueen->setText(QStringLiteral("CPU Queen"));

	
	title_julia = new QLabel(this);
	title_julia->setFrameStyle(QFrame::NoFrame);
	title_julia->setAlignment(Qt::AlignLeft);
	title_julia->setStyleSheet(resultStyleSheet1);
	title_julia->setFont(*normalFont);
	title_julia->setText(QStringLiteral("Julia"));

	title_mandel = new QLabel(this);
	title_mandel->setFrameStyle(QFrame::NoFrame);
	title_mandel->setAlignment(Qt::AlignLeft);//129, 199, 212, 60
	title_mandel->setStyleSheet(resultStyleSheet2);
	title_mandel->setFont(*normalFont);
	title_mandel->setText(QStringLiteral("Mandel"));

	title_zlibCompress = new QLabel(this);
	title_zlibCompress->setFrameStyle(QFrame::NoFrame);
	title_zlibCompress->setAlignment(Qt::AlignLeft);
	title_zlibCompress->setStyleSheet(resultStyleSheet1);
	title_zlibCompress->setFont(*normalFont);
	title_zlibCompress->setText(QStringLiteral("zlib compress"));
	

	title_zlibUncompress = new QLabel(this);
	title_zlibUncompress->setFrameStyle(QFrame::NoFrame);
	title_zlibUncompress->setAlignment(Qt::AlignLeft);
	title_zlibUncompress->setStyleSheet(resultStyleSheet2);
	title_zlibUncompress->setFont(*normalFont);
	title_zlibUncompress->setText(QStringLiteral("zlib uncompress"));

	title_aesDecrypto = new QLabel(this);
	title_aesDecrypto->setFrameStyle(QFrame::NoFrame);
	title_aesDecrypto->setAlignment(Qt::AlignLeft);
	title_aesDecrypto->setStyleSheet(resultStyleSheet1);
	title_aesDecrypto->setFont(*normalFont);
	title_aesDecrypto->setText(QStringLiteral("aes decrypto"));

	title_aesEncrypto = new QLabel(this);
	title_aesEncrypto->setFrameStyle(QFrame::NoFrame);
	title_aesEncrypto->setAlignment(Qt::AlignLeft);
	title_aesEncrypto->setStyleSheet(resultStyleSheet2);
	title_aesEncrypto->setFont(*normalFont);
	title_aesEncrypto->setText(QStringLiteral("aes encrypto"));

	title_sna = new QLabel(this);
	title_sna->setFrameStyle(QFrame::NoFrame);
	title_sna->setAlignment(Qt::AlignLeft);
	title_sna->setStyleSheet(resultStyleSheet1);
	title_sna->setFont(*normalFont);
	title_sna->setText(QStringLiteral("sna-256"));

	
	value_cpuqueen = new QLabel(this);
	//value_cpuqueen->setFrameStyle(QFrame::NoFrame);
	value_cpuqueen->setAlignment(Qt::AlignRight);
	value_cpuqueen->setText(QStringLiteral("default"));
	value_cpuqueen->setStyleSheet(resultStyleSheet1);
	value_cpuqueen->setFont(*normalFont);

	value_julia = new QLabel(this);
	value_julia->setFrameStyle(QFrame::NoFrame);
	value_julia->setAlignment(Qt::AlignRight);
	value_julia->setStyleSheet(resultStyleSheet1);
	value_julia->setText(QStringLiteral("default"));
	value_julia->setFont(*normalFont);

	value_mandel = new QLabel(this);
	value_mandel->setFrameStyle(QFrame::NoFrame);
	value_mandel->setAlignment(Qt::AlignRight);
	value_mandel->setStyleSheet(resultStyleSheet2);
	value_mandel->setText(QStringLiteral("default"));
	value_mandel->setFont(*normalFont);

	value_zlibCompress = new QLabel(this);
	value_zlibCompress->setFrameStyle(QFrame::NoFrame);
	value_zlibCompress->setAlignment(Qt::AlignRight);
	value_zlibCompress->setStyleSheet(resultStyleSheet1);
	value_zlibCompress->setText(QStringLiteral("default"));
	value_zlibCompress->setFont(*normalFont);

	value_zlibUncompress = new QLabel(this);
	value_zlibUncompress->setFrameStyle(QFrame::NoFrame);
	value_zlibUncompress->setAlignment(Qt::AlignRight);
	value_zlibUncompress->setStyleSheet(resultStyleSheet2);
	value_zlibUncompress->setText(QStringLiteral("default"));
	value_zlibUncompress->setFont(*normalFont);

	value_aesDecrypto = new QLabel(this);
	value_aesDecrypto->setFrameStyle(QFrame::NoFrame);
	value_aesDecrypto->setAlignment(Qt::AlignRight);
	value_aesDecrypto->setStyleSheet(resultStyleSheet1);
	value_aesDecrypto->setText(QStringLiteral("default"));
	value_aesDecrypto->setFont(*normalFont);

	value_aesEncrypto = new QLabel(this);
	value_aesEncrypto->setFrameStyle(QFrame::NoFrame);
	value_aesEncrypto->setAlignment(Qt::AlignRight);
	value_aesEncrypto->setStyleSheet(resultStyleSheet2);
	value_aesEncrypto->setText(QStringLiteral("default"));
	value_aesEncrypto->setFont(*normalFont);

	value_sna = new QLabel(this);
	value_sna->setFrameStyle(QFrame::NoFrame);
	value_sna->setAlignment(Qt::AlignRight);
	value_sna->setStyleSheet(resultStyleSheet1);
	value_sna->setText(QStringLiteral("default"));
	value_sna->setFont(*normalFont);
}
void Test_CPU::setupLayout()
{
	QGridLayout *layout = new QGridLayout;
	layout->setContentsMargins(30, 20, 30, 10);
	layout->setVerticalSpacing(5);
	layout->setHorizontalSpacing(0);
	layout->setRowStretch(0, 0);
	layout->setRowStretch(1, 0);
	layout->setRowStretch(2, 0);
	layout->setRowStretch(3, 0);
	layout->setRowStretch(4, 0);
	layout->setRowStretch(5, 0);
	layout->setRowStretch(6, 0);
	layout->setRowStretch(7, 0);
	layout->setRowStretch(8, 0);
	layout->setRowStretch(9, 0);
	layout->setRowStretch(10, 0);
	layout->setRowStretch(11, 0);
	layout->setRowStretch(12, 0);
	layout->setRowStretch(15, 1);
	layout->setRowMinimumHeight(2, 20);
	layout->setRowMinimumHeight(6, 20);
	layout->setRowMinimumHeight(13, 20);
	//layout->setColumnStretch(0,1);
	//layout->setColumnStretch(1,0);



	layout->addWidget(title_branch,
		0, 0, 1, 2);

	layout->addWidget(title_cpuqueen,
		1, 0, 1, 1);
	layout->addWidget(value_cpuqueen,
		1, 1, 1, 1);

	layout->addWidget(title_float,
		3, 0, 1, 2);

	layout->addWidget(title_julia,
		4, 0, 1, 1);
	layout->addWidget(value_julia,
		4, 1, 1, 1);

	layout->addWidget(title_mandel,
		5, 0, 1, 1);
	layout->addWidget(value_mandel,
		5, 1, 1, 1);

	layout->addWidget(title_dataStream,
		7, 0, 1, 2);

	layout->addWidget(title_zlibCompress,
		8, 0, 1, 1);
	layout->addWidget(value_zlibCompress,
		8, 1, 1, 1);

	layout->addWidget(title_zlibUncompress,
		9, 0, 1, 1);
	layout->addWidget(value_zlibUncompress,
		9, 1, 1, 1);

	layout->addWidget(title_aesDecrypto,
		10, 0, 1, 1);
	layout->addWidget(value_aesDecrypto,
		10, 1, 1, 1);

	layout->addWidget(title_aesEncrypto,
		11, 0, 1, 1);
	layout->addWidget(value_aesEncrypto,
		11, 1, 1, 1);

	layout->addWidget(title_sna,
		12, 0, 1, 1);
	layout->addWidget(value_sna,
		12, 1, 1, 1);

	layout->addWidget(btn_begin, 14, 0, 1, 2, Qt::AlignCenter);

	setLayout(layout);
}
void Test_CPU::setConnection()
{}
void Test_CPU::initializeData()
{}
void Test_CPU::paintEvent(QPaintEvent *event)
{
}
void Test_CPU::begin()
{
	if (!beginflag)
	{
		btn_begin->setText(QString("Stop"));
		//btn_begin->setEnabled(false);
		QString program = "./cpu_bench.exe";
		//debug
		//QString program = "./debug/cpu_bench.exe";
		QStringList arguments;
		arguments << "run_all";
		process = new QProcess(this);
		process->start(program, arguments);
		connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(testProcessFinished(int, QProcess::ExitStatus)));
		qDebug() << "error:" << process->error() << " state:" << process->state() << " directory:" << process->workingDirectory();
		beginflag = true;
	}
	else
	{
		btn_begin->setText(QString("Run"));
		process->kill();
		beginflag = false;
	}
    
}
void Test_CPU::testProcessFinished(int exitCode,QProcess::ExitStatus exitStatus)
{
    if(exitStatus == QProcess::NormalExit)
    {
        QFile *file = new QFile("./cpu_score.txt");
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
                value = jsonobject.value("queen");
                const QString str_queen = QString("%0").arg(value.toDouble());
                value_cpuqueen->setText(str_queen);

                value = jsonobject.value("julia");
                const QString str_julia = QString("%0").arg(value.toDouble());
                value_julia->setText(str_julia);

                value = jsonobject.value("mandel");
                const QString str_mandel = QString("%0").arg(value.toDouble());
                value_mandel->setText(str_mandel);

                value = jsonobject.value("zlib_compress");
                const QString str_zlib_compress = QString("%0").arg(value.toDouble());
                value_zlibCompress->setText(str_zlib_compress);

                value = jsonobject.value("zlib_uncompress");
                const QString str_zlib_uncompress = QString("%0").arg(value.toDouble());
                value_zlibUncompress->setText(str_zlib_uncompress);


                value = jsonobject.value("aes_decrypto");
                const QString str_aes_decrypto = QString("%0").arg(value.toDouble());
                value_aesDecrypto->setText(str_aes_decrypto);

                value = jsonobject.value("aes_encrypto");
                const QString str_aes_encrypto = QString("%0").arg(value.toDouble());
                value_aesEncrypto->setText(str_aes_encrypto);

                value = jsonobject.value("sha_256");
                const QString str_sha = QString("%0").arg(value.toDouble());
                value_sna->setText(str_sha);

                update();
            }
            btn_begin->setText(QString("Run"));
			beginflag = !beginflag;
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText(QString("test failed:testProcessFinished,exitCode:%0 exitStatus:%1").arg(exitCode).arg(exitStatus));
        messagebox->exec();
    }
}
void Test_CPU::reset()
{

}