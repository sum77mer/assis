#ifndef WINDOW_IOBASE_H
#define WINDOW_IOBASE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QRegExp>
#include <QMessageBox>
class Window_IOBase : public QWidget
{
    Q_OBJECT
public:
    explicit Window_IOBase(QWidget *parent = nullptr);

signals:
    void send_input(unsigned int addr,bool acpi_flag);
public slots:
private slots:
    void done();
private:
    QLineEdit *lineedit_address = new QLineEdit(this);
    QCheckBox *checkbox_ACPI = new QCheckBox(this);

    unsigned int address;
    bool ACPI_flag = false;

};

#endif // WINDOW_IOBASE_H
