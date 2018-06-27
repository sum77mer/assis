#include "test_cpu.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QProcess>
#include <QFile>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFont>
Test_CPU::Test_CPU(QWidget *parent)
{
    setFixedSize(800,594);
    setWindowFlags(Qt::FramelessWindowHint);

    QFont title_font("Arial",12,QFont::Bold);
    QFont item_font("Arial",10,QFont::Normal);
    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setFont(title_font);
    label1->setText(QStringLiteral("Branch Prediction Test"));

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setFont(item_font);
    label2->setText(QStringLiteral("CPU Queen"));

    label_cpuqueen->setFrameStyle(QFrame::NoFrame);
    label_cpuqueen->setText(QStringLiteral("default"));
    label_cpuqueen->setFont(item_font);

    QLabel *label3 = new QLabel(this);
    label3->setFrameStyle(QFrame::NoFrame);
    label3->setFont(title_font);
    label3->setText(QStringLiteral("Floating Point Test"));

    QLabel *label4 = new QLabel(this);
    label4->setFrameStyle(QFrame::NoFrame);
    label4->setFont(item_font);
    label4->setText(QStringLiteral("Julia"));

    label_julia->setFrameStyle(QFrame::NoFrame);
    label_julia->setText(QStringLiteral("default"));
    label_julia->setFont(item_font);

    QLabel *label5 = new QLabel(this);
    label5->setFrameStyle(QFrame::NoFrame);
    label5->setFont(item_font);
    label5->setText(QStringLiteral("Mandel"));

    label_mandel->setFrameStyle(QFrame::NoFrame);
    label_mandel->setText(QStringLiteral("default"));
    label_mandel->setFont(item_font);

    QLabel *label6 = new QLabel(this);
    label6->setFrameStyle(QFrame::NoFrame);
    label6->setFont(title_font);
    label6->setText(QStringLiteral("Data Stream Test"));

    QLabel *label7 = new QLabel(this);
    label7->setFrameStyle(QFrame::NoFrame);
    label7->setFont(item_font);
    label7->setText(QStringLiteral("zlib"));

    label_zlib_compress->setFrameStyle(QFrame::NoFrame);
    label_zlib_compress->setText(QStringLiteral("default"));
    label_zlib_compress->setFont(item_font);

    QLabel *label8 = new QLabel(this);
    label8->setFrameStyle(QFrame::NoFrame);
    label8->setFont(item_font);
    label8->setText(QStringLiteral("zlib"));

    label_zlib_uncompress->setFrameStyle(QFrame::NoFrame);
    label_zlib_uncompress->setText(QStringLiteral("default"));
    label_zlib_uncompress->setFont(item_font);

    QLabel *label9 = new QLabel(this);
    label9->setFrameStyle(QFrame::NoFrame);
    label9->setFont(item_font);
    label9->setText(QStringLiteral("aes"));

    label_aes_decrypto->setFrameStyle(QFrame::NoFrame);
    label_aes_decrypto->setText(QStringLiteral("default"));
    label_aes_decrypto->setFont(item_font);

    QLabel *label10 = new QLabel(this);
    label10->setFrameStyle(QFrame::NoFrame);
    label10->setFont(item_font);
    label10->setText(QStringLiteral("aes"));

    label_aes_encrypto->setFrameStyle(QFrame::NoFrame);
    label_aes_encrypto->setText(QStringLiteral("default"));
    label_aes_encrypto->setFont(item_font);

    QLabel *label11 = new QLabel(this);
    label11->setFrameStyle(QFrame::NoFrame);
    label11->setFont(item_font);
    label11->setText(QStringLiteral("sna-256"));

    label_sna->setFrameStyle(QFrame::NoFrame);
    label_sna->setText(QStringLiteral("default"));
    label_sna->setFont(item_font);

    btn_begin = new QPushButton(this);
    btn_begin->setText(QString("Begin"));

    connect(btn_begin,SIGNAL(clicked(bool)),this,SLOT(begin()));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->setRowStretch(0,0);
    layout->setRowStretch(1,0);
    layout->setRowStretch(2,0);
    layout->setRowStretch(3,0);
    layout->setRowStretch(4,0);
    layout->setRowStretch(5,0);
    layout->setRowStretch(6,0);
    layout->setRowStretch(7,0);
    layout->setRowStretch(8,0);
    layout->setRowStretch(9,0);
    layout->setRowStretch(10,0);
    layout->setRowStretch(11,0);
    layout->setRowStretch(12,0);
    layout->setRowStretch(15,1);
    layout->setRowMinimumHeight(2,20);
    layout->setRowMinimumHeight(6,20);
    layout->setRowMinimumHeight(13,20);
    layout->setColumnStretch(0,0);
    layout->setColumnStretch(1,0);
    layout->setColumnStretch(2,0);
    layout->setColumnStretch(3,1);
    layout->addWidget(label1,
                      0,1,1,2,Qt::AlignLeft);

    layout->addWidget(label2,
                      1,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_cpuqueen,
                      1,2,1,1,Qt::AlignLeft);

    layout->addWidget(label3,
                      3,1,1,2,Qt::AlignLeft);

    layout->addWidget(label4,
                      4,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_julia,
                      4,2,1,1,Qt::AlignLeft);

    layout->addWidget(label5,
                      5,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_mandel,
                      5,2,1,1,Qt::AlignLeft);

    layout->addWidget(label6,
                      7,1,1,2,Qt::AlignLeft);

    layout->addWidget(label7,
                      8,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_zlib_compress,
                      8,2,1,1,Qt::AlignLeft);

    layout->addWidget(label8,
                      9,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_zlib_uncompress,
                      9,2,1,1,Qt::AlignLeft);

    layout->addWidget(label9,
                      10,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_aes_decrypto,
                      10,2,1,1,Qt::AlignLeft);

    layout->addWidget(label10,
                      11,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_aes_encrypto,
                      11,2,1,1,Qt::AlignLeft);

    layout->addWidget(label11,
                      12,1,1,1,Qt::AlignLeft);
    layout->addWidget(label_sna,
                      12,2,1,1,Qt::AlignLeft);

    layout->addWidget(btn_begin,14,1,1,2,Qt::AlignLeft);


    setLayout(layout);
}
void Test_CPU::paintEvent(QPaintEvent *event)
{}
void Test_CPU::begin()
{
    btn_begin->setText(QString("running"));
    btn_begin->setEnabled(false);
    QString program = "J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/debug/cpu_bench.exe";
    QStringList arguments;
    arguments<<"run_all";
    QProcess *process = new QProcess(this);
    process->start(program,arguments);
    connect(process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(testProcessFinished(int,QProcess::ExitStatus)));
    qDebug()<<"error:"<<process->error()<<" state:"<<process->state()<<" directory:"<<process->workingDirectory();
}
void Test_CPU::testProcessFinished(int exitCode,QProcess::ExitStatus exitStatus)
{
    if(exitStatus == QProcess::NormalExit)
    {
        QFile *file = new QFile("J:/00_qt_code/project/2_sv_assistant/version2_0/2-0withC/SV-ASSIST/cpu_score.txt");
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
                label_cpuqueen->setText(str_queen);

                value = jsonobject.value("julia");
                const QString str_julia = QString("%0").arg(value.toDouble());
                label_julia->setText(str_julia);

                value = jsonobject.value("mandel");
                const QString str_mandel = QString("%0").arg(value.toDouble());
                label_mandel->setText(str_mandel);

                value = jsonobject.value("zlib_compress");
                const QString str_zlib_compress = QString("%0").arg(value.toDouble());
                label_zlib_compress->setText(str_zlib_compress);

                value = jsonobject.value("zlib_uncompress");
                const QString str_zlib_uncompress = QString("%0").arg(value.toDouble());
                label_zlib_uncompress->setText(str_zlib_uncompress);


                value = jsonobject.value("aes_decrypto");
                const QString str_aes_decrypto = QString("%0").arg(value.toDouble());
                label_aes_decrypto->setText(str_aes_decrypto);

                value = jsonobject.value("aes_encrypto");
                const QString str_aes_encrypto = QString("%0").arg(value.toDouble());
                label_aes_encrypto->setText(str_aes_encrypto);

                value = jsonobject.value("sha_256");
                const QString str_sha = QString("%0").arg(value.toDouble());
                label_sna->setText(str_sha);

                update();
            }
            btn_begin->setText(QString("Begin"));
            btn_begin->setEnabled(true);
        }
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText("test failed");
        messagebox->exec();
    }
}
