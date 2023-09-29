#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   splitter = new QSplitter(Qt::Vertical);
   label1 = new QLabel("Содержимое компонента 1");
   label2 = new QLabel("Содержимое компонента 2");
   label3 = new QLabel("Содержимое компонента 3");
   label1->setFrameStyle(QFrame::Box | QFrame::Plain);
   label2->setFrameStyle(QFrame::Box | QFrame::Plain);
   label3->setFrameStyle(QFrame::Box | QFrame::Plain);
   splitter->addWidget(label1);
   splitter->addWidget(label2);
   btn1 = new QPushButton("Добавить компонент");
   vbox = new QVBoxLayout();
   vbox->addWidget(splitter);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   splitter->insertWidget(0, label3);
   btn1->setEnabled(false);
}

Widget::~Widget() {}
