#include "mywidget.h"
#include "./ui_mywidget.h"

MyWidget::MyWidget (QWidget* parent) : QWidget (parent), ui (new Ui::MyWidget)
{
    ui->setupUi (this);
    animation = new QPropertyAnimation (this, "geometry");
    animation->setDuration (1000); // Set animation duration
    animation->setStartValue (QRect (10, 10, 0, 0));
    animation->setEndValue (QRect (10, 10, 200, 200));
}

MyWidget::~MyWidget ()
{
    delete ui;
}

void MyWidget::showEvent (QShowEvent* event)
{
    animation->start ();
    QWidget::showEvent (event);
}
