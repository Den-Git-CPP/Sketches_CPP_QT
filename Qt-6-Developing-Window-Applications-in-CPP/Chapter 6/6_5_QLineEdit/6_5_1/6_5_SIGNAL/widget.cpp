#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   lineEdit = new QLineEdit();
   btn1 = new QPushButton("Изменить текст программно");

   vbox = new QVBoxLayout();
   vbox->addWidget(lineEdit);
   vbox->addWidget(new QLineEdit());
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(lineEdit, SIGNAL(cursorPositionChanged(int,int)),
           this, SLOT(on_changed(int,int)));
   connect(lineEdit, SIGNAL(editingFinished()),
           this, SLOT(on_finished()));
   connect(lineEdit, SIGNAL(returnPressed()),
           this, SLOT(on_return()));
   connect(lineEdit, SIGNAL(selectionChanged()),
           this, SLOT(on_selection()));
   connect(lineEdit, SIGNAL(textChanged(QString)),
           this, SLOT(on_text_changed(QString)));
   connect(lineEdit, SIGNAL(textEdited(QString)),
           this, SLOT(on_text_edited(QString)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   lineEdit->setText("Новый текст");
}

void Widget::on_changed(int oldPos, int newPos)
{
   qDebug() << "on_changed" << oldPos << newPos;
}

void Widget::on_finished()
{
   qDebug() << "on_finished";
}

void Widget::on_return()
{
   qDebug() << "on_return";
}

void Widget::on_selection()
{
   qDebug() << "on_selection";
}

void Widget::on_text_changed(const QString &s)
{
   qDebug() << "on_text_changed" << s;
}

void Widget::on_text_edited(const QString &s)
{
   qDebug() << "on_text_edited" << s;
}
