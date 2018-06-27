#include "window_iobase.h"

Window_IOBase::Window_IOBase(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::Window|Qt::WindowCloseButtonHint);
    QLabel *label1 = new QLabel(this);
    label1->setFrameStyle(QFrame::NoFrame);
    label1->setText("IO Base");

    checkbox_ACPI->setText("ACPI Power Management Base");

    QPushButton *btn_ok = new QPushButton(this);
    btn_ok->setText("OK");
    connect(btn_ok,SIGNAL(clicked(bool)),this,SLOT(done()));

    QPushButton *btn_cancel = new QPushButton(this);
    btn_cancel->setText("Cancel");
    connect(btn_cancel,SIGNAL(clicked(bool)),this,SLOT(close()));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label1,0,0,Qt::AlignCenter);
    layout->addWidget(lineedit_address,0,1,Qt::AlignCenter);
    layout->addWidget(checkbox_ACPI,1,0,1,2,Qt::AlignCenter);
    layout->addWidget(btn_ok,2,0,Qt::AlignCenter);
    layout->addWidget(btn_cancel,2,1,Qt::AlignCenter);
    this->setLayout(layout);
}
void Window_IOBase::done()
{
    QString str_address = lineedit_address->text();
    QRegExp regexp("[0-9a-fA-F]+");
    if(regexp.exactMatch(str_address))
    {
        //str_address -> address
        if(checkbox_ACPI->isChecked())
            ACPI_flag = true;
        else
            ACPI_flag = false;
        emit send_input(str_address.toInt(),ACPI_flag);
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(this);
        messagebox->setText("invalid input");
        messagebox->exec();
    }
    this->close();
}
