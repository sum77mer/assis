#include "window_memoryaddress.h"

Window_memoryAddress::Window_memoryAddress(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::Window|Qt::WindowCloseButtonHint);
    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::NoFrame);
    label->setText(QString("Start Address:"));

    lineedit_address = new QLineEdit(this);
    lineedit_address->setFixedWidth(100);
    lineedit_address->setMaximumHeight(20);

    QPushButton *btn1 = new QPushButton(this);
    btn1->setText(QString("OK"));

    connect(btn1,SIGNAL(clicked(bool)),this,SLOT(done()));

    QPushButton *btn2 = new QPushButton(this);
    btn2->setText(QString("Cancel"));
    connect(btn2,SIGNAL(clicked(bool)),this,SLOT(close()));

    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(10,20,10,10);
    layout->addWidget(label,0,0,1,1,Qt::AlignCenter);
    layout->addWidget(lineedit_address,0,1,1,2,Qt::AlignCenter);
    layout->addWidget(btn1,1,0,1,1,Qt::AlignCenter);
    layout->addWidget(btn2,1,1,1,1,Qt::AlignCenter);

    this->setLayout(layout);
    this->show();
}
void Window_memoryAddress::done()
{
    QString str_addr = lineedit_address->text();
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_addr))
    {
		bool ok;
        emit send_input(str_addr.toInt(&ok,16));
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText("invalid input");
        messagebox->exec();
    }
    this->close();
}
