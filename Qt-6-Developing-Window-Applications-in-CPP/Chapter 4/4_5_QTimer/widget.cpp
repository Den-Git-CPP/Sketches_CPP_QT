#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   timer = new QTimer(this);
   label = new QLabel("");
   label->setAlignment(Qt::AlignCenter);
   btn1 = new QPushButton("Запустить");
   btn2 = new QPushButton("Остановить");
   btn2->setEnabled(false);
   vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(btn2, SIGNAL(clicked()),
           this, SLOT(on_btn2_clicked()));
   connect(timer, SIGNAL(timeout()),
           this, SLOT(on_timeout()));
}

void Widget::on_btn1_clicked()
{
   timer->start(1000); // 1 секунда
   btn1->setEnabled(false);
   btn2->setEnabled(true);
}

void Widget::on_btn2_clicked()
{
   timer->stop();
   btn1->setEnabled(true);
   btn2->setEnabled(false);
}

void Widget::on_timeout()
{
   QTime t = QTime::currentTime();
   label->setText(t.toString("HH:mm:ss"));
}

Widget::~Widget() {}

