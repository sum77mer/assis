#ifndef HARD_OTHER_H
#define HARD_OTHER_H
#include <QWidget>

class Hard_Other : public QWidget
{
    Q_OBJECT
public:
    Hard_Other(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // HARD_OTHER_H
