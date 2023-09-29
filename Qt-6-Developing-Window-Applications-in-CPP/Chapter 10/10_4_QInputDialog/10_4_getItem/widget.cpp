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
   QStringList list;
   list << "Пункт 1" << "Пункт 2" << "Пункт 3";
   QString text = QInputDialog::getItem(this,
                   "Это заголовок окна", "Это текст подсказки",
                   list, 1, false, &ok);
   if (ok) {
      qDebug() << "Выбрано значение:" << text;
   }
}

