#include "widget.h"
#include "mydialog.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Отобразить диалоговое окно...");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   MyDialog dialog(this);
   int result = dialog.exec();
   if (result == QDialog::Accepted) {
       qDebug() << dialog.lineEdit->text();
   }
   else {
      qDebug() << "Нажата кнопка Cancel" << result;
   }
}

