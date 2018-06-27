#include "window_config.h"
#include <QGridLayout>
#include <QLabel>
Window_config::Window_config(QWidget *parent)
{
    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::NoFrame);
    label->setText(QStringLiteral("xxx"));
    label->setAlignment(Qt::AlignLeft);
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(label);
    layout->setContentsMargins(0,0,0,0);

    setFixedSize(600,500);
    setLayout(layout);
}
