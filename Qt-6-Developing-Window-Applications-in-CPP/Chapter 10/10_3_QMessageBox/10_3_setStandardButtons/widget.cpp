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
   QMessageBox dialog(this);
   dialog.setIcon(QMessageBox::Critical);
   dialog.setWindowTitle("Текст заголовка");
   dialog.setText("Текст <b>сообщения</b><br>на двух строках");
   dialog.setInformativeText("Поясняющий <b>текст</b>");
   dialog.setDetailedText("Описание деталей");
   dialog.setStandardButtons(QMessageBox::Ok |
                             QMessageBox::Cancel);
   dialog.setDefaultButton(QMessageBox::Cancel);
   dialog.setEscapeButton(QMessageBox::Cancel);
   int result = dialog.exec();
   if (result == QMessageBox::Ok) {
       qDebug() << "Нажата кнопка OK";
   }
   else if (result == QMessageBox::Cancel) {
      qDebug() << "Нажата кнопка Cancel";
   }
   else {
      qDebug() << "Нажата кнопка" << result;
   }
}

