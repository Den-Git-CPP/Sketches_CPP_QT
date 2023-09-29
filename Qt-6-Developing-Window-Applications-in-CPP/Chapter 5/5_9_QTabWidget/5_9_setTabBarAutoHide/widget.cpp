#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   tab = new QTabWidget();
   label1 = new QLabel("Содержимое вкладки 1");
   label2 = new QLabel("Содержимое вкладки 2");
   tab->addTab(label1, "Вкладка &1");
   tab->addTab(label2, "Вкладка &2");
   tab->setTabBarAutoHide(true);
   tab->setCurrentIndex(0);
   btn1 = new QPushButton("Удалить вкладку 1");
   vbox = new QVBoxLayout();
   vbox->addWidget(tab);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   tab->removeTab(0);
   delete label1;
   label1 = nullptr;
   btn1->setEnabled(false);
}

Widget::~Widget() {}
