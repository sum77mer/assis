#ifndef WIDGET_MAINTAB_H
#define WIDGET_MAINTAB_H
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
class Widget_mainTab : public QPushButton
{
    Q_OBJECT
public:
    Widget_mainTab(QWidget *parent=0);
    ~Widget_mainTab();
    void setIcon(QString icon_name);
    void setText(const QString text);
    void setMousePress(bool mouse_press);
protected:
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QString iconName;
    QString btnTitle;
    unsigned int btnWidth;
    unsigned int btnHeight;
    enum Status{NORMAL, ENTER, PRESS, NOSTATUS};
    Status btnStatus;
    bool mousePress;
    bool choosed;
};

#endif // WIDGET_MAINTAB_H
