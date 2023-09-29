#include "widget.h"
#include <QButtonGroup>
#include <QLabel>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   radio1 = new QRadioButton("Да");
   radio2 = new QRadioButton("Нет");
   radio3 = new QRadioButton("Да");
   radio4 = new QRadioButton("Нет");

   QButtonGroup *buttonGroup1 = new QButtonGroup(this);
   buttonGroup1->addButton(radio1, 1);
   buttonGroup1->addButton(radio2, 2);
   QButtonGroup *buttonGroup2 = new QButtonGroup(this);
   buttonGroup2->addButton(radio3, 1);
   buttonGroup2->addButton(radio4, 2);

   QLabel *label1 = new QLabel("Вы знаете язык C++?");
   QLabel *label2 = new QLabel("Вы знаете Qt?");

   vbox = new QVBoxLayout();
   vbox->addWidget(label1);
   vbox->addWidget(radio1);
   vbox->addWidget(radio2);
   vbox->addWidget(label2);
   vbox->addWidget(radio3);
   vbox->addWidget(radio4);
   setLayout(vbox);

   radio1->setChecked(true);
   radio3->setChecked(true);

   connect(buttonGroup1, SIGNAL(buttonClicked(QAbstractButton*)),
           this, SLOT(on_group1_buttonClicked(QAbstractButton*)));
   connect(buttonGroup2, SIGNAL(buttonClicked(QAbstractButton*)),
           this, SLOT(on_group2_buttonClicked(QAbstractButton*)));
}

Widget::~Widget() {}

void Widget::on_group1_buttonClicked(QAbstractButton *button)
{
   qDebug() << "group1" << button->text();
}

void Widget::on_group2_buttonClicked(QAbstractButton *button)
{
   qDebug() << "group2" << button->text();
}
