#ifndef WIDGET_PUSHBUTTON_H
#define WIDGET_PUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
class Widget_PushButton : public QPushButton
{
    Q_OBJECT
public:
    Widget_PushButton(QWidget *parent=0);
    ~Widget_PushButton();
    void setIcon(QString icon_name);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void leaveEvent(QEvent *);
    void enterEvent(QEvent *);
private:
    enum Status{NORMAL, ENTER, PRESS, NOSTATUS};
    Status status;
    QString iconName;
    bool mousePress;

    unsigned int btnWidth;
    unsigned int btnHeight;
};

#endif // WIDGET_PUSHBUTTON_H
