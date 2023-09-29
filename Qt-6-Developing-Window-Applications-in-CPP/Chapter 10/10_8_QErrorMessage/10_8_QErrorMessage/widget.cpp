#include "widget.h"

#include <QErrorMessage>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   dialog = new QErrorMessage(this);

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
   dialog->showMessage("Это текст сообщения об ошибке");
}

