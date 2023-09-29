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
   QInputDialog dialog(this);
   dialog.setWindowTitle("Это заголовок окна");
   dialog.setLabelText("Это текст подсказки");
   dialog.setOkButtonText("&Ввод");
   dialog.setCancelButtonText("&Отмена");
   dialog.setInputMode(QInputDialog::IntInput);
   dialog.setIntRange(0, 100);
   dialog.setIntStep(10);
   dialog.setIntValue(50);
   int result = dialog.exec();
   if (result == QDialog::Accepted) {
       qDebug() << dialog.intValue();
   }
   else {
      qDebug() << "Нажата кнопка Cancel";
   }
}

