#include "smbiostextbrowser.h"

smbiostextbrowser::smbiostextbrowser(QWidget *parent) : QTextBrowser(parent)
{

}

void smbiostextbrowser::ReciveSMBIOSReady(bool Ready)
{
    if(Ready)
    {
        QFile file("J:/00_qt_code/build-untitled-Qt_5_11_0_msvc2015_x86-Debug/debug/HardWare/DMI/smbios.txt");
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << "Can not open";
            return;
        }
        QTextStream in(&file);
        while(in.atEnd() == 0)
        {
           this->setText(in.readAll());
        }
        file.close();
    }
    else
    {
        this->setText(tr("Not Support SMBIOS"));
        this->setEnabled(false);
    }
}

void smbiostextbrowser::ReciveSMBIOSloc(QTreeWidgetItem *item, int columns)
{
	Q_UNUSED(columns)
    this->clear();
    bool set = false, exit = false;
    QFile file("J:/00_qt_code/build-untitled-Qt_5_11_0_msvc2015_x86-Debug/debug/HardWare/DMI/smbios.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Can not open";
        return;
    }
    QTextStream in(&file);
    QString text;
    if(item->text(0) == tr("SMBIOS"))
    {
        text = in.readAll();
    }
    else
    {
        while(in.atEnd() == 0 && !exit)
        {
            QString line = in.readLine();
            if(line == item->text(0))
            {
               set = true;
            }
            else if(set && line.contains('['))
            {
                exit = true;
                set = false;
            }
            if(set)
            {
                text.append(line);
                text.append("\n");
            }
        }
    }

    this->setText(text);
    file.close();
}

