#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Нажми меня");
   btn2 = new QPushButton("Кнопка 2");
   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(btn2, SIGNAL(clicked()),
           this, SLOT(on_btn2_clicked()));
   connect(this, SIGNAL(mysignal(int,int)),
           this, SLOT(on_mysignal(int,int)));
}

void Widget::on_btn1_clicked()
{
   qDebug() << "Нажата кнопка 1";
   // Генерируем сигналы
   emit btn2->clicked();
   emit mysignal(10, 20);
}

void Widget::on_btn2_clicked()
{
   qDebug() << "Нажата кнопка 2";
}

void Widget::on_mysignal(int a, int b)
{
   qDebug() << "on_mysignal" << a << b;
}

Widget::~Widget() {}
