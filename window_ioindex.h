#ifndef WINDOW_IOINDEX_H
#define WINDOW_IOINDEX_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QRegExp>
#include <QMessageBox>
class Window_IOIndex : public QWidget
{
    Q_OBJECT
public:
    explicit Window_IOIndex(QWidget *parent = nullptr);

signals:
    void send_input(unsigned int index,unsigned int data);

public slots:
private slots:
    void done();
private:
    QLineEdit *lineedit_index = new QLineEdit(this);
    QLineEdit *lineedit_data = new QLineEdit(this);

    unsigned int input_index;
    unsigned int input_data;
};

#endif // WINDOW_IOINDEX_H
