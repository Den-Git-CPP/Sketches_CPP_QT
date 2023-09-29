#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   splitter = new QSplitter(Qt::Vertical);
   splitter->setChildrenCollapsible(false);
   label1 = new QLabel("Содержимое компонента 1");
   label2 = new QLabel("Содержимое компонента 2");
   label1->setFrameStyle(QFrame::Box | QFrame::Plain);
   label2->setFrameStyle(QFrame::Box | QFrame::Plain);
   splitter->addWidget(label1);
   splitter->addWidget(label2);
   btn1 = new QPushButton("Получить значение");
   vbox = new QVBoxLayout();
   vbox->addWidget(splitter);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   qDebug() << splitter->childrenCollapsible();
}

Widget::~Widget() {}
