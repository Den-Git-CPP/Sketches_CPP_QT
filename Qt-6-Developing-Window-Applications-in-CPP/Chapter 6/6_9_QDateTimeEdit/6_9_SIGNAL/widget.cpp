#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   dateTimeEdit = new QDateTimeEdit();
   dateTimeEdit->setDateTime(QDateTime::currentDateTime());

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(dateTimeEdit);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(dateTimeEdit, SIGNAL(timeChanged(QTime)),
           this, SLOT(on_timeChanged(QTime)));
   connect(dateTimeEdit, SIGNAL(dateChanged(QDate)),
           this, SLOT(on_dateChanged(QDate)));
   connect(dateTimeEdit, SIGNAL(dateTimeChanged(QDateTime)),
           this, SLOT(on_dateTimeChanged(QDateTime)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   qDebug() << dateTimeEdit->dateTime();
}

void Widget::on_timeChanged(QTime t)
{
   qDebug() << "on_timeChanged" << t;
}

void Widget::on_dateChanged(QDate d)
{
   qDebug() << "on_dateChanged" << d;
}

void Widget::on_dateTimeChanged(const QDateTime & dt)
{
   qDebug() << "on_dateTimeChanged" << dt;
}
