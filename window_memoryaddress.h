#ifndef WINDOW_MEMORYADDRESS_H
#define WINDOW_MEMORYADDRESS_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QRegExp>
#include <QMessageBox>
class Window_memoryAddress : public QWidget
{
    Q_OBJECT
public:
    explicit Window_memoryAddress(QWidget *parent = nullptr);

signals:
    void send_input(unsigned int addr);
public slots:
private slots:
    void done();
private:
    QLineEdit *lineedit_address;
};

#endif // WINDOW_MEMORYADDRESS_H
