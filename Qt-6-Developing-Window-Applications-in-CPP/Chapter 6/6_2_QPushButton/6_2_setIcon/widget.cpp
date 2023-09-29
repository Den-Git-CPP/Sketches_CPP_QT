#include "widget.h"
#include <QStyle>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton();
   QIcon icon = style()->standardIcon(QStyle::SP_DriveNetIcon);
   btn1->setIcon(icon);
   btn1->setIconSize(QSize(32, 32));

   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   qDebug() << "Кнопка нажата";
}

Widget::~Widget() {}
