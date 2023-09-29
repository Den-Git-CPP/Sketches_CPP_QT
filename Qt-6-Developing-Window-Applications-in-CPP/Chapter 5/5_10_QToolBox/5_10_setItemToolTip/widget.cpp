#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   toolBox = new QToolBox();
   label1 = new QLabel("Содержимое вкладки 1");
   label2 = new QLabel("Содержимое вкладки 2");
   toolBox->addItem(label1, "Вкладка &1");
   toolBox->addItem(label2, "Вкладка &2");
   toolBox->setItemToolTip(0, "Это текст подсказки для вкладки 1");
   toolBox->setItemToolTip(1, "Это текст подсказки для вкладки 2");
   toolBox->setCurrentIndex(0);
   btn1 = new QPushButton("Получить значение");
   vbox = new QVBoxLayout();
   vbox->addWidget(toolBox);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   qDebug() << toolBox->itemToolTip(0);
}

Widget::~Widget() {}
