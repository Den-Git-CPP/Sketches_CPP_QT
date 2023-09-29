#include "widget.h"

#include <QMessageBox>
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
   QMessageBox::StandardButton result = QMessageBox::question(
                  this, "Текст заголовка",
                  "Вы действительно хотите выполнить действие?",
                  QMessageBox::Yes | QMessageBox::No |
                  QMessageBox::Cancel,
                  QMessageBox::Cancel);
   if (result == QMessageBox::Yes) {
      qDebug() << "Нажата кнопка Yes";
   }
   else if (result == QMessageBox::No) {
      qDebug() << "Нажата кнопка No";
   }
   else if (result == QMessageBox::Cancel) {
      qDebug() << "Нажата кнопка Cancel, кнопка Закрыть или клавиша <Esc>";
   }
   else {
      qDebug() << "Нажата кнопка" << result;
   }
}

