#include "widget.h"
#include <QMenu>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Кнопка с меню");
   QMenu *menu = new QMenu();
   menu->addAction("Пункт 1");
   menu->addAction("Пункт 2");
   menu->addAction("Пункт 3");
   btn1->setMenu(menu);

   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   setLayout(vbox);
}

Widget::~Widget() {}
