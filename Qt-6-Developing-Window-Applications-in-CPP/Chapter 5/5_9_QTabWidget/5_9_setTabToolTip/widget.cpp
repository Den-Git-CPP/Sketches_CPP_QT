#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   tab = new QTabWidget();
   label1 = new QLabel("Содержимое вкладки 1");
   label2 = new QLabel("Содержимое вкладки 2");
   tab->addTab(label1, "Вкладка &1");
   tab->addTab(label2, "Вкладка &2");
   tab->setTabToolTip(0, "Это текст подсказки для вкладки 1");
   tab->setTabToolTip(1, "Это текст подсказки для вкладки 2");
   tab->setTabWhatsThis(0, "Это текст справки для вкладки 1");
   tab->setTabWhatsThis(1, "Это текст справки для вкладки 2");

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
   qDebug() << tab->tabToolTip(0);
   qDebug() << tab->tabWhatsThis(0);
}

Widget::~Widget() {}
