#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   tab = new QTabWidget();
   label1 = new QLabel("Содержимое вкладки 1");
   label2 = new QLabel("Содержимое вкладки 2");
   tab->addTab(label1, "Вкладка &1");
   tab->addTab(label2, "Вкладка &2");
   tab->setCurrentIndex(0);
   btn1 = new QPushButton("Добавить вкладку");
   vbox = new QVBoxLayout();
   vbox->addWidget(tab);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   tab->setUpdatesEnabled(false); // Для предотвращения мерцания
   int ind = tab->insertTab(-1, new QLabel("Содержимое вкладки 3"),
                            "Вкладка &3");
   tab->setCurrentIndex(ind);
   tab->setUpdatesEnabled(true);
   btn1->setEnabled(false);
}

Widget::~Widget() {}
