#include "widget.h"
#include <QGroupBox>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Кнопка 1");
   btn2 = new QPushButton("Кнопка 2");
   btn1->setCheckable(true);
   btn2->setCheckable(true);
   btn1->setChecked(true);
   btn1->setAutoExclusive(true);
   btn2->setAutoExclusive(true);

   QGroupBox *box = new QGroupBox("Группа кнопок-переключателей");
   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn1);
   hbox->addWidget(btn2);
   box->setLayout(hbox);

   vbox = new QVBoxLayout();
   vbox->addWidget(box);
   setLayout(vbox);
}

Widget::~Widget() {}
