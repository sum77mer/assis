#ifndef PAGE_SOFT_H
#define PAGE_SOFT_H
#include <QWidget>
#include <QDebug>
#include "widget_sidetabgroup.h"
#include "soft_zhxx.h"
#include "soft_config.h"
#include <QStackedWidget>
class Page_soft : public QWidget
{
    Q_OBJECT
public:
    Page_soft(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void turnPage(int index);
    void reportWindow();
    void onAutoRefresh();
    void onManualRefresh();
    void outputReport();
private:
    Widget_sideTabGroup *sideTabGroup;
    QStackedWidget *stackWidget;
    Soft_ZHXX *softZHXX;
    Soft_Config *softConfig;

    QPushButton *pbtnautofresh;
    QPushButton *pbtnfresh;
    QPushButton *pbtnoutput;
};

#endif // PAGE_SOFT_H
