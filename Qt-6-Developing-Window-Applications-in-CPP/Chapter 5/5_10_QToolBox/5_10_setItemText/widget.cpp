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
   btn1 = new QPushButton("Изменить заголовок");
   vbox = new QVBoxLayout();
   vbox->addWidget(toolBox);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   toolBox->setItemText(0, "Новый текст заголовка");
   btn1->setEnabled(false);
}

Widget::~Widget() {}
