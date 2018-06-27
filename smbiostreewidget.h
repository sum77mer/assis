#ifndef SMBIOSTREEWIDGET_H
#define SMBIOSTREEWIDGET_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QChar>
#include <QStringList>
#include "libheaders/smbioslib.h"
using namespace SV_ASSIST::DMI_SMBIOS;
class smbiostreewidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit smbiostreewidget(QWidget *parent = nullptr);
    void UpdateData();
signals:
    void SMBIOSReady(bool);
public slots:
private:
	QTreeWidgetItem *father;
	~smbiostreewidget();
};

#endif // SMBIOSTREEWIDGET_H
