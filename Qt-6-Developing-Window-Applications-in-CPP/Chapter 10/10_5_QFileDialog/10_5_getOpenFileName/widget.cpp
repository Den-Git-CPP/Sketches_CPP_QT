#include "widget.h"

#include <QFileDialog>
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
   QString f = QFileDialog::getOpenFileName(this,
                    "Заголовок окна", "C:\\cpp\\projectsQt\\Test",
                    "All (*);;Images (*.png *.jpg)");
   qDebug() << f;
}

