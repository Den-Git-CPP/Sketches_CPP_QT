#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   splitter = new QSplitter(Qt::Vertical);
   label1 = new QLabel("Содержимое компонента 1");
   label2 = new QLabel("Содержимое компонента 2");
   label1->setFrameStyle(QFrame::Box | QFrame::Plain);
   label2->setFrameStyle(QFrame::Box | QFrame::Plain);
   splitter->addWidget(label1);
   splitter->addWidget(label2);
   btn1 = new QPushButton("Запомнить размеры");
   btn2 = new QPushButton("Восстановить размеры");
   vbox = new QVBoxLayout();
   vbox->addWidget(splitter);
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   setLayout(vbox);
   state = splitter->saveState();
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(btn2, SIGNAL(clicked()),
           this, SLOT(on_btn2_clicked()));
}

void Widget::on_btn1_clicked()
{
   state = splitter->saveState();
}

void Widget::on_btn2_clicked()
{
   splitter->restoreState(state);
}

Widget::~Widget() {}
