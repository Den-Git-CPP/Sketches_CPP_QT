#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   calendar = new QCalendarWidget();

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(calendar);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(calendar, SIGNAL(activated(QDate)),
           this, SLOT(on_activated(QDate)));
   connect(calendar, SIGNAL(clicked(QDate)),
           this, SLOT(on_clicked_calendar(QDate)));
   connect(calendar, SIGNAL(selectionChanged()),
           this, SLOT(on_selectionChanged()));
   connect(calendar, SIGNAL(currentPageChanged(int,int)),
           this, SLOT(on_currentPageChanged(int,int)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   qDebug() << calendar->selectedDate();
}

void Widget::on_activated(QDate d)
{
   qDebug() << "on_activated" << d;
}

void Widget::on_clicked_calendar(QDate d)
{
   qDebug() << "on_clicked_calendar" << d;
}

void Widget::on_selectionChanged()
{
   qDebug() << "on_selectionChanged";
}

void Widget::on_currentPageChanged(int year, int month)
{
   qDebug() << "on_currentPageChanged" << year << month;
}
