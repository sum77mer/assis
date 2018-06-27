#include "window_sio.h"

Window_SIO::Window_SIO(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::Window|Qt::WindowCloseButtonHint);

    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText(QString("Index Port"));

    lineedit_index->setFixedWidth(80);
    lineedit_index->setMaximumHeight(20);

    QPushButton *btn_ok = new QPushButton(this);
    btn_ok->setText(QString("OK"));

    connect(btn_ok,SIGNAL(clicked(bool)),this,SLOT(done()));

    QLabel *label2 = new QLabel(this);
    label2->setFrameStyle(QFrame::NoFrame);
    label2->setText(QString("Data Port"));

    lineedit_data->setFixedWidth(80);
    lineedit_data->setMaximumHeight(20);

    QPushButton *btn_cancel = new QPushButton(this);
    btn_cancel->setText(QString("Cancel"));
    connect(btn_cancel,SIGNAL(clicked(bool)),this,SLOT(close()));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->setRowStretch(0,0);
    layout->setRowStretch(1,0);
    layout->addWidget(label1,0,0,1,1,Qt::AlignCenter);
    layout->addWidget(lineedit_index,0,1,1,1,Qt::AlignCenter);
    layout->addWidget(btn_ok,0,2,1,1,Qt::AlignCenter);

    layout->addWidget(label2,1,0,1,1,Qt::AlignCenter);
    layout->addWidget(lineedit_data,1,1,1,1,Qt::AlignCenter);
    layout->addWidget(btn_cancel,1,2,1,1,Qt::AlignCenter);

    this->setLayout(layout);
}
void Window_SIO::done()
{
    QString str_index = lineedit_index->text();
    QString str_data = lineedit_data->text();
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_index)&&regexp.exactMatch(str_data))
    {
        emit send_input(str_index.toInt(),str_data.toInt());
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText("invalid input");
        messagebox->exec();
    }
    this->close();
}
