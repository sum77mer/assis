#ifndef WINDOW_SIO_H
#define WINDOW_SIO_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QRegExp>
#include <QMessageBox>
class Window_SIO : public QWidget
{
    Q_OBJECT
public:
    explicit Window_SIO(QWidget *parent = nullptr);

signals:
    void send_input(unsigned int index,unsigned int data);
public slots:
private slots:
    void done();
private:
    QLineEdit *lineedit_index = new QLineEdit(this);
    QLineEdit *lineedit_data = new QLineEdit(this);
};

#endif // WINDOW_SIO_H
