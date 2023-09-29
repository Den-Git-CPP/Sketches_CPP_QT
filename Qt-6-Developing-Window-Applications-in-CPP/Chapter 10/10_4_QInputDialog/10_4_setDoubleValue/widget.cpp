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
   dialog.setInputMode(QInputDialog::DoubleInput);
   dialog.setDoubleRange(0.0, 100.0);
   dialog.setDoubleDecimals(2);
   dialog.setDoubleValue(50.0);
   dialog.setDoubleStep(0.1);
   int result = dialog.exec();
   if (result == QDialog::Accepted) {
       qDebug() << dialog.doubleValue();
   }
   else {
      qDebug() << "Нажата кнопка Cancel";
   }
}

