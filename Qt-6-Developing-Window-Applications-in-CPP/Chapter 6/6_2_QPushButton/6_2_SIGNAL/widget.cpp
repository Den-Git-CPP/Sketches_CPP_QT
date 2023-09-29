#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Обычная кнопка");
   btn2 = new QPushButton("Кнопка-переключатель");
   btn2->setCheckable(true);

   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(btn1, SIGNAL(pressed()),
           this, SLOT(on_btn1_pressed()));
   connect(btn1, SIGNAL(released()),
           this, SLOT(on_btn1_released()));
   connect(btn2, SIGNAL(toggled(bool)),
           this, SLOT(on_btn2_toggled(bool)));
}

void Widget::on_btn1_clicked()
{
   qDebug() << "Сигнал clicked";
}

void Widget::on_btn1_pressed()
{
   qDebug() << "Сигнал pressed";
}

void Widget::on_btn1_released()
{
   qDebug() << "Сигнал released";
}

void Widget::on_btn2_toggled(bool status)
{
   qDebug() << "Сигнал toggled" << status;
}

Widget::~Widget() {}
