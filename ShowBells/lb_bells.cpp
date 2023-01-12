#include "lb_bells.h"

lb_bells::lb_bells(QWidget *parent) : QWidget(parent)
{
    this->resize(180,70);
    this->setWindowTitle("Alarm");
    this->setWindowFlags(Qt::Window
                         |Qt::WindowCloseButtonHint);

    icon=new QIcon (":/resource/alarm.png");
    this->setWindowIcon(*icon); // Значок для окна

    QLabel *label = new QLabel();
    label->setPixmap(QPixmap(":/resource/alarm.png"));
    label->setAutoFillBackground(true);

    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(label);
    this->setLayout(vbox);

}

