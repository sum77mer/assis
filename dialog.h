/*

*/
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "widget_title.h"
#include "page_hard.h"
#include "page_soft.h"
#include "page_test.h"
#include <QDebug>
#include <QStackedWidget>
#include <QPoint>
class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    void paintEvent(QPaintEvent *);
private slots:
    void turnPage(int index);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    void init();
private:
    Widget_Title *title;
    Page_hard *pageHard;
    Page_soft *pageSoft;
    Page_test *pageTest;
    QStackedWidget *stackWidget;
    bool mousemove;
    QPoint oldPos;
};

#endif // DIALOG_H
