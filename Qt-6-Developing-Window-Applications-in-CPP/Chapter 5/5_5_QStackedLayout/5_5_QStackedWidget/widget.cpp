#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   label1 = new QLabel("Страница 1");
   label2 = new QLabel("Страница 2");
   label1->setFrameStyle(QFrame::Box | QFrame::Plain);
   label2->setFrameStyle(QFrame::Box | QFrame::Plain);
   btn1 = new QPushButton("Отобразить страницу 1");
   btn2 = new QPushButton("Отобразить страницу 2");
   vbox = new QVBoxLayout();
   hbox = new QHBoxLayout();
   hbox->addWidget(btn1);
   hbox->addWidget(btn2);
   vbox->addLayout(hbox);

   stack = new QStackedWidget();
   id1 = stack->addWidget(label1);
   id2 = stack->addWidget(label2);
   vbox->addWidget(stack);

   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()), this, SLOT(on_btn1_clicked()));
   connect(btn2, SIGNAL(clicked()), this, SLOT(on_btn2_clicked()));
   // Назначение обработчика смены компонента
   connect(stack, SIGNAL(currentChanged(int)),
           this, SLOT(on_current_changed(int)));
}

void Widget::on_current_changed(int index)
{
   // Вызывается при изменении компонента
   qDebug() << index;
}

void Widget::on_btn1_clicked()
{
   stack->setCurrentIndex(id1);     // Изменение по индексу
}

void Widget::on_btn2_clicked()
{
   stack->setCurrentWidget(label2); // Изменение по указателю
}

Widget::~Widget() {}
