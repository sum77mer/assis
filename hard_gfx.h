#ifndef HARD_GFX_H
#define HARD_GFX_H
#include <QWidget>

class Hard_GFX : public QWidget
{
    Q_OBJECT
public:
    Hard_GFX(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // HARD_GFX_H
