#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   label = new QLabel();
   label->setFrameStyle(QFrame::Box | QFrame::Plain);
   label->setText("Этот текст можно выделить");
   label->setTextInteractionFlags(Qt::TextSelectableByMouse);
   label->setFocusPolicy(Qt::StrongFocus);

   btn1 = new QPushButton("Выделить текст");
   vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   qDebug() << label->hasSelectedText();
   label->setSelection(3, 10);
   qDebug() << label->hasSelectedText();
   qDebug() << label->selectedText();
   qDebug() << label->selectionStart();
   label->setFocus();
}

Widget::~Widget() {}
