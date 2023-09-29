#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   slider = new QDial();
   slider->setMinimum(0);
   slider->setMaximum(100);
   slider->setSliderPosition(40);
   slider->setSingleStep(10);
   slider->setPageStep(20);
   slider->setTracking(false);
   slider->setNotchesVisible(true);
   slider->setNotchTarget(2.0);

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
   connect(slider, SIGNAL(sliderPressed()),
           this, SLOT(on_sliderPressed()));
   connect(slider, SIGNAL(sliderReleased()),
           this, SLOT(on_sliderReleased()));
   connect(slider, SIGNAL(rangeChanged(int,int)),
           this, SLOT(on_rangeChanged(int,int)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   slider->setMinimum(10);
   slider->setMaximum(90);
}

void Widget::on_valueChanged(int pos)
{
   qDebug() << "on_valueChanged" << pos;
}

void Widget::on_sliderMoved(int pos)
{
   qDebug() << "on_sliderMoved" << pos;
}

void Widget::on_sliderPressed()
{
   qDebug() << "on_sliderPressed";
}

void Widget::on_sliderReleased()
{
   qDebug() << "on_sliderReleased";
}

void Widget::on_rangeChanged(int min, int max)
{
   qDebug() << "on_rangeChanged" << min << max;
}
