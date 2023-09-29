#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   slider = new QSlider(Qt::Horizontal);
   slider->setMinimum(0);
   slider->setMaximum(100);
   slider->setSliderPosition(40);
   slider->setSingleStep(10);
   slider->setPageStep(20);
   slider->setTracking(false);
   slider->setTickPosition(QSlider::TicksBelow);

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(slider);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(slider, SIGNAL(valueChanged(int)),
           this, SLOT(on_valueChanged(int)));
   connect(slider, SIGNAL(sliderMoved(int)),
           this, SLOT(on_sliderMoved(int)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   qDebug() << slider->value();
   qDebug() << slider->sliderPosition();
}

void Widget::on_valueChanged(int pos)
{
   qDebug() << "on_valueChanged" << pos;
   qDebug() << "value - " << slider->value();
   qDebug() << "sliderPosition - " << slider->sliderPosition();
   qDebug() << "-----------------------";
}

void Widget::on_sliderMoved(int pos)
{
   qDebug() << "on_sliderMoved" << pos;
   qDebug() << "value - " << slider->value();
   qDebug() << "sliderPosition - " << slider->sliderPosition();
}
