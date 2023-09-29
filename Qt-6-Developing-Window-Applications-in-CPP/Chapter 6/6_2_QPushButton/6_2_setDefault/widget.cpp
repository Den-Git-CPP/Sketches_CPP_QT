#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Обычная кнопка");
   btn2 = new QPushButton("Кнопка по умолчанию");
   btn1->setAutoDefault(true);
   btn2->setAutoDefault(true);
   btn2->setDefault(false);
   btn2->setDefault(true);
   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(btn2, SIGNAL(clicked()),
           this, SLOT(on_btn2_clicked()));
}

void Widget::on_btn1_clicked()
{
   qDebug() << "Нажата кнопка 1";
}

void Widget::on_btn2_clicked()
{
   qDebug() << "Нажата кнопка 2";
}


Widget::~Widget() {}
