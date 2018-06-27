#ifndef WIDGET_SIDETAB_H
#define WIDGET_SIDETAB_H
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
class Widget_sideTab : public QPushButton
{
    Q_OBJECT
public:
    Widget_sideTab(QWidget *parent=0,unsigned int width=20,unsigned int height=10,QString title="undefined");
    ~Widget_sideTab();
    void setMousePress(bool mouse_press);
protected:
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *evnet);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QString btnTitle;
    unsigned int btnWidth;
    unsigned int btnHeight;
    enum Status{NORMAL, ENTER, PRESS, NOSTATUS};
    Status btnStatus;
    bool mousePress;
    bool choosedflag;
};

#endif // WIDGET_SIDETAB_H
