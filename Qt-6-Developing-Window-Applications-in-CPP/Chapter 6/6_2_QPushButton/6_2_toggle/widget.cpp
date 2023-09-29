#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Кнопка");
   btn2 = new QPushButton("Нажми меня");
   btn1->setCheckable(true);
   btn1->setChecked(true);

   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   setLayout(vbox);
   connect(btn1, SIGNAL(toggled(bool)),
           this, SLOT(on_btn1_toggled(bool)));
   connect(btn2, SIGNAL(clicked()),
           this, SLOT(on_btn2_clicked()));
}

void Widget::on_btn1_toggled(bool status)
{
   qDebug() << "Кнопка переключена" << status;
}

void Widget::on_btn2_clicked()
{
   btn1->toggle();
}

Widget::~Widget() {}
