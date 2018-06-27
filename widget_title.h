#ifndef WIDGET_TITLE_H
#define WIDGET_TITLE_H
#include <QDebug>
#include <QWidget>
#include "widget_maintab.h"
#include "widget_pushbutton.h"
#include <QAction>
#include "window_about.h"
#include "window_config.h"
#include "window_help.h"
class Widget_Title : public QWidget
{
    Q_OBJECT
public:
    Widget_Title(QWidget *parent=0);
signals:
    void closeWindow();
    void minimizeWindow();
    void turnPage(int index);
private slots:
    void pageChange(QString index);
    void aboutWindow(QAction *action);
    void helpWindow(QAction *action);
    void configWindow();
protected:
    void paintEvent(QPaintEvent *event);
private:
    QList<Widget_mainTab *> btnList;
    Widget_PushButton *close_btn;
    Widget_PushButton *min_btn;
    Widget_PushButton *config_btn;
    Widget_PushButton *more_btn;
    QAction *helpaction;
    QAction *aboutaction;
    Window_about *windowAbout;
    Window_help *windowHelp;
    Window_config *windowConfig;
};

#endif // WIDGET_TITLE_H
