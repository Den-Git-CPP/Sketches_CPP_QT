#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   lineEdit = new QLineEdit();
   btnCut = new QPushButton("Вырезать");
   btnPaste = new QPushButton("Вставить");
   vbox = new QVBoxLayout();
   vbox->addWidget(lineEdit);
   vbox->addWidget(btnCut);
   vbox->addWidget(btnPaste);
   setLayout(vbox);
   connect(btnCut, SIGNAL(clicked()), this, SLOT(on_cut()));
   connect(btnPaste, SIGNAL(clicked()), this, SLOT(on_paste()));
   connect(QApplication::clipboard(), SIGNAL(dataChanged()),
           this, SLOT(on_change_clipboard()));
}

void Widget::on_cut()
{
   QString text = lineEdit->text();
   if (!text.isEmpty()) {
      QApplication::clipboard()->setText(text);
      lineEdit->setText("");
   }
}

void Widget::on_paste()
{
   QString text = QApplication::clipboard()->text();
   if (!text.isEmpty()) {
      lineEdit->setText(text);
   }
}

void Widget::on_change_clipboard()
{
   qDebug() << "Данные в буфере обмена изменены";
}

Widget::~Widget() {}
