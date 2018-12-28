#ifndef WIDGET_SIDETAB_H
#define WIDGET_SIDETAB_H
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <qfont.h>
class Widget_sideTab : public QPushButton
{
    Q_OBJECT
public:
    Widget_sideTab(QWidget *parent=0,QString title="undefined");
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
	double scaleV = 1;
	double scaleH = 1;
    unsigned int btnWidth;
    unsigned int btnHeight = 38;
	unsigned int dotR = 4;
	unsigned int leftMargin = 15;
    enum Status{NORMAL, ENTER, PRESS, NOSTATUS};
    Status btnStatus;
    bool mousePress;
    bool choosedflag;

	QColor backgroundColor_normal = QColor(245,245,245);//white
	QColor backgroundColor_enter = QColor(200,200,200);//darkgray
	QColor backgroundColor_choosed = QColor(0, 0, 0);//black
	QColor titleColor_normal = QColor(0, 0, 0);//black
	QColor titleColor_enter = QColor(255, 255, 255);//black
};

#endif // WIDGET_SIDETAB_H
