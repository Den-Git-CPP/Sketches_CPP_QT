#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   toolBox = new QToolBox();
   label1 = new QLabel("Содержимое вкладки 1");
   label2 = new QLabel("Содержимое вкладки 2");
   toolBox->addItem(label1, "Вкладка &1");
   toolBox->addItem(label2, "Вкладка &2");
   toolBox->setCurrentIndex(0);
   btn1 = new QPushButton("Добавить вкладку");
   vbox = new QVBoxLayout();
   vbox->addWidget(toolBox);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   toolBox->setUpdatesEnabled(false); // Для предотвращения мерцания
   int ind = toolBox->insertItem(-1, new QLabel("Содержимое вкладки 3"),
                            "Вкладка &3");
   toolBox->setCurrentIndex(ind);
   toolBox->setUpdatesEnabled(true);
   btn1->setEnabled(false);
}

Widget::~Widget() {}
