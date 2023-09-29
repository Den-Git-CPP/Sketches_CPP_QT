#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Кнопка");
   btn2 = new QPushButton("Нажми меня");

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
   qDebug() << "Кнопка нажата";
}

void Widget::on_btn2_clicked()
{
   btn1->animateClick();
}

Widget::~Widget() {}
