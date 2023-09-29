#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   tab = new QTabWidget();
   label1 = new QLabel("Содержимое вкладки 1");
   label2 = new QLabel("Содержимое вкладки 2");
   tab->addTab(label1, "Вкладка &1");
   tab->addTab(label2, "Вкладка &2");
   tab->addTab(new QLabel("Содержимое вкладки 3"), "Вкладка &3");
   tab->addTab(new QLabel("Содержимое вкладки 4"), "Вкладка &4");
   tab->addTab(new QLabel("Содержимое вкладки 5"), "Вкладка &5");
   tab->addTab(new QLabel("Содержимое вкладки 6"), "Вкладка &6");
   tab->setUsesScrollButtons(true);
   tab->setCurrentIndex(0);
   btn1 = new QPushButton("Получить значение");
   vbox = new QVBoxLayout();
   vbox->addWidget(tab);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   qDebug() << tab->usesScrollButtons();
}

Widget::~Widget() {}
