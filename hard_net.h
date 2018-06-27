#ifndef HARD_NET_H
#define HARD_NET_H
#include <QWidget>

class Hard_Net : public QWidget
{
    Q_OBJECT
public:
    Hard_Net(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // HARD_NET_H
