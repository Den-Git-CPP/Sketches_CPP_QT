#include "widget.h"

#include <QColorDialog>
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
   QColor color = QColorDialog::getColor(QColor(255, 0, 0), this,
                  "Заголовок окна", QColorDialog::ShowAlphaChannel);
   if (color.isValid()) {
      qDebug() << color.red() << color.green() << color.blue()
               << color.alpha();
   }
}

