#ifndef SOFT_ZHXX_H
#define SOFT_ZHXX_H
#include <QWidget>
#include <QDebug>
class Soft_ZHXX : public QWidget
{
    Q_OBJECT
public:
    Soft_ZHXX(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // SOFT_ZHXX_H
