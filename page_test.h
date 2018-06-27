#ifndef PAGE_TEST_H
#define PAGE_TEST_H
#include <QWidget>
#include <QDebug>
#include "widget_sidetabgroup.h"
#include "test_cpu.h"
#include "test_memory.h"
#include "test_storage.h"
#include <QStackedWidget>
class Page_test : public QWidget
{
    Q_OBJECT
public:
    Page_test(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void turnPage(int index);
    void reportWindow();
    void outputReport();
private:
    Widget_sideTabGroup *sideTabGroup;
    QStackedWidget *stackWidget;
    Test_CPU *testCPU;
    Test_Memory *testMemory;
    Test_Storage *testStorage;

    QPushButton *pbtnoutput;
};

#endif // PAGE_TEST_H
