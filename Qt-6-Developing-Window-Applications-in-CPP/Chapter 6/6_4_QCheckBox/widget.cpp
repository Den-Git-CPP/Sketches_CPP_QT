#include "widget.h"
#include <QStyle>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   checkBox1 = new QCheckBox("&Unchecked");
   checkBox2 = new QCheckBox("&PartiallyChecked");
   checkBox3 = new QCheckBox("&Checked");

   checkBox2->setTristate(true);
   checkBox1->setCheckState(Qt::Unchecked);
   checkBox2->setCheckState(Qt::PartiallyChecked);
   checkBox3->setCheckState(Qt::Checked);

   QIcon icon1 = style()->standardIcon(QStyle::SP_DialogOkButton);
   checkBox1->setIcon(icon1);
   QIcon icon2 = style()->standardIcon(QStyle::SP_MessageBoxCritical);
   checkBox2->setIcon(icon2);

   vbox = new QVBoxLayout();
   vbox->addWidget(checkBox1);
   vbox->addWidget(checkBox2);
   vbox->addWidget(checkBox3);
   setLayout(vbox);

   connect(checkBox1, SIGNAL(stateChanged(int)),
           this, SLOT(on_state_changed1(int)));
   connect(checkBox2, SIGNAL(stateChanged(int)),
           this, SLOT(on_state_changed2(int)));
   connect(checkBox3, SIGNAL(stateChanged(int)),
           this, SLOT(on_state_changed3(int)));
   connect(checkBox1, SIGNAL(toggled(bool)),
           this, SLOT(on_checkBox1_toggled(bool)));
}

Widget::~Widget() {}

void Widget::on_state_changed1(int status)
{
   qDebug() << "checkBox1" << status;
}

void Widget::on_state_changed2(int status)
{
   qDebug() << "checkBox2" << status;
}

void Widget::on_state_changed3(int status)
{
   qDebug() << "checkBox3" << status;
}

void Widget::on_checkBox1_toggled(bool status)
{
   qDebug() << "checkBox1" << status;
}
