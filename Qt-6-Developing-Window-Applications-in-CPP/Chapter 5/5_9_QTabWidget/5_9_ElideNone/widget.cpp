#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   tab = new QTabWidget();
   label1 = new QLabel("Содержимое вкладки 1");
   label2 = new QLabel("Содержимое вкладки 2");
   tab->addTab(label1, "Вкладка с длинным названием");
   tab->addTab(label2, "Вкладка &2");
   tab->setElideMode(Qt::ElideNone);
   tab->setCurrentIndex(0);
   btn1 = new QPushButton("Проверить значение");
   vbox = new QVBoxLayout();
   vbox->addWidget(tab);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   qDebug() << tab->elideMode();
}

Widget::~Widget() {}
