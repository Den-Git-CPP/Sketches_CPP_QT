#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   line1 = new MyLineEdit(1);
   line2 = new MyLineEdit(2);
   btn1 = new QPushButton("Установить фокус на поле 2");
   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(line1);
   vbox->addWidget(line2);
   setLayout(vbox);
   QObject::connect(btn1, SIGNAL(clicked()),
                    line2, SLOT(setFocus()));
   // Задаем порядок обхода с помощью клавиши <Tab>
   QWidget::setTabOrder(line1, line2);
   QWidget::setTabOrder(line2, btn1);
}

Widget::~Widget() {}

