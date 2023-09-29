#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   lineEdit = new QLineEdit();
   lineEdit->setInputMask("Дата: 99.B9.9999;#");  // Дата: ##.##.####
   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(lineEdit);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   if (lineEdit->hasAcceptableInput()) {
      qDebug() << lineEdit->text();
   }
   else {
      qDebug() << "Значение не соответствует маске";
   }
}
