#ifndef SOFT_CONFIG_H
#define SOFT_CONFIG_H
#include <QWidget>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
class Soft_Config : public QWidget
{
    Q_OBJECT
public:
    Soft_Config(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void config();
private:
    QCheckBox *checkbox_administrator;
    QCheckBox *checkbox_defender;
    QCheckBox *checkbox_customer_experience_program;
    QCheckBox *checkbox_bluescreen_autoreboot;
    QCheckBox *checkbox_firewall;
    QCheckBox *checkbox_operation_center;
    QCheckBox *checkbox_power_options;
    QCheckBox *checkbox_update;
    QCheckBox *checkbox_system_protect;
};

#endif // SOFT_CONFIG_H
