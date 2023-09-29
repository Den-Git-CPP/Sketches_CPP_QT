#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   label = new QLabel();
   label->setFrameStyle(QFrame::Box | QFrame::Plain);
   label->setText("Этот текст можно редактировать");
   label->setTextInteractionFlags(Qt::TextEditorInteraction);

   btn1 = new QPushButton("Получить значение");
   vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(label, SIGNAL(linkActivated(QString)),
           this, SLOT(on_link_activated(QString)));
}

void Widget::on_btn1_clicked()
{
   qDebug() << label->textInteractionFlags();
}

void Widget::on_link_activated(const QString &s)
{
   qDebug() << s;
}


Widget::~Widget() {}
