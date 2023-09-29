#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   label = new QLabel("Устано&вить фокус на поле 1");
   line1 = new QLineEdit();
   label->setBuddy(line1);
   line2 = new MyLineEdit();
   line2->id = line2->grabShortcut(QKeySequence::mnemonic("&е"));
   btn1 = new QPushButton("&Убрать фокус с поля 1");
   vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(line1);
   vbox->addWidget(line2);
   vbox->addWidget(btn1);
   setLayout(vbox);
   QObject::connect(btn1, SIGNAL(clicked()),
                    this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   line1->clearFocus();
}

Widget::~Widget() {}

