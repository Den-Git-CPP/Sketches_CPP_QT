#include "widget.h"

#include <QInputDialog>
#include <QVBoxLayout>

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
   bool ok;
   int n = QInputDialog::getInt(this, "Это заголовок окна",
                         "Это текст подсказки",
                         50, 0, 100, 2, &ok);
   if (ok) {
      qDebug() << "Введено значение:" << n;
   }
}

