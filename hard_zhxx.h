#ifndef HARD_ZHXX_H
#define HARD_ZHXX_H
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
class Hard_ZHXX : public QWidget
{
    Q_OBJECT
public:
    Hard_ZHXX(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QLabel *label_computer_model = new QLabel(this);
    QLabel *label_os = new QLabel(this);
    QLabel *label_cpu = new QLabel(this);
    QLabel *label_mainboard = new QLabel(this);
    QLabel *label_memory = new QLabel(this);
    QLabel *label_disk = new QLabel(this);
    QLabel *label_graphic = new QLabel(this);
    QLabel *label_optical_driver = new QLabel(this);
    QLabel *label_audio = new QLabel(this);
    QLabel *label_network = new QLabel(this);

    QLabel *picLabel;
};

#endif // HARD_ZHXX_H
