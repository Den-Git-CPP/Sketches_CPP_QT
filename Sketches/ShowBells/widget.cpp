#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{   this->resize(180,70);
    this->setWindowTitle("Alarm");
    this->setWindowFlags(Qt::Window
                         |Qt::WindowCloseButtonHint);

    icon=new QIcon (":/resource/alarm.png");
    this->setWindowIcon(*icon); // Значок для окна

    label = new QLabel();
    ft=     new QFont("Arial", 12, QFont::Bold); // Устанавливаем размер шрифта
    pa=     new QPalette();
    pa->setColor(QPalette::WindowText,Qt::darkBlue); // Устанавливаем цвет шрифта

    label->setFont(*ft);
    label->setPalette(*pa);
    label->setAlignment(Qt::AlignCenter);
    label->setText("Комп не спит");

    vbox= new QVBoxLayout();
    vbox->addWidget(label);

    this->setLayout(vbox);
    bells= new lb_bells();

    timer_show_bells =new QTimer(this);
    timer_show_bells->setInterval(6000);// интервал 10 сек
    connect(timer_show_bells,&QTimer::timeout,this,&Widget::Show_Bells);
    timer_show_bells->start();

}

Widget::~Widget()
{
  //  delete bells;
}

void Widget::Show_Bells()
{   bells->show();
    //   qDebug()<<"Show Bells"<<QTime::currentTime().toString();
    timer_close_bells =new QTimer(this);
    timer_close_bells->setInterval(2000);// интервал 2 сек
    timer_close_bells->setSingleShot(true);

    connect(timer_close_bells,&QTimer::timeout,[=]{
        bells->close();
        //     qDebug()<<"Close Bells"<<QTime::currentTime().toString();
    });
    timer_close_bells->start();

}
