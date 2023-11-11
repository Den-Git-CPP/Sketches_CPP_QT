#include "widget.h"
#include <QDoubleValidator>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   lineEdit = new QLineEdit();
   QDoubleValidator *validator = new QDoubleValidator(
                                        0.0, 100.0, 2, this);
   validator->setNotation(QDoubleValidator::StandardNotation);
   lineEdit->setValidator(validator);
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
      qDebug() << "Значение не соответствует условию";
   }
}
