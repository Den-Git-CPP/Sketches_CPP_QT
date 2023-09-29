#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   label = new QLabel("Содержимое страницы");
   btn1 = new QPushButton("Кнопка");
   box = new QVBoxLayout();
   box->addWidget(label);
   box->addWidget(btn1);
   setLayout(box);
}

Widget::~Widget() {}
