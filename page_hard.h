#ifndef PAGE_HARD_H
#define PAGE_HARD_H
#include <QWidget>
#include <QDebug>
#include "widget_sidetabgroup.h"
#include <QStackedWidget>
#include "hard_zhxx.h"
#include "hard_board.h"
#include "hard_cpu.h"
#include "hard_memory.h"
#include "hard_pci.h"
#include "hard_storage.h"
#include "hard_gfx.h"
#include "hard_net.h"
#include "hard_other.h"
#include <QPushButton>
#include <QList>
class Page_hard : public QWidget
{
    Q_OBJECT
public:
    Page_hard(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void turnPage(int index);
    void reportWindow();
    void onAutoRefresh();
    void onManualRefresh();
    void outputReport();
    void Compare();
private:
    Widget_sideTabGroup *sideTabGroup;
    QStackedWidget *stackWidget;
    Hard_ZHXX *hardZHXX;
    Hard_Board *hardBoard;
    Hard_CPU *hardCPU;
    Hard_Memory *hardMemory;
    Hard_GFX *hardGFX;
    Hard_PCI *hardPCI;
    Hard_Storage *hardStorage;
    Hard_Net *hardNet;
    Hard_Other *hardOther;

    QPushButton *pbtnautofresh;
    QPushButton *pbtnfresh;
    QPushButton *pbtnoutput;
    QPushButton *pbtncompare;
    bool autorefreshflag=true;

    struct Disk_info{
        QString dir;
        QStringList file_list;
    };
    QList<Disk_info> diskinfo_list;
};

#endif // PAGE_HARD_H
