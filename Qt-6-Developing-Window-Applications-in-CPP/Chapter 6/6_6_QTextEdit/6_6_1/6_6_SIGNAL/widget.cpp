#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   textEdit = new QTextEdit("Значение по умолчанию");
   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(textEdit, SIGNAL(copyAvailable(bool)),
           this, SLOT(on_copy(bool)));
   connect(textEdit, SIGNAL(undoAvailable(bool)),
           this, SLOT(on_undo(bool)));
   connect(textEdit, SIGNAL(redoAvailable(bool)),
           this, SLOT(on_redo(bool)));
   connect(textEdit, SIGNAL(cursorPositionChanged()),
           this, SLOT(on_position_changed()));
   connect(textEdit, SIGNAL(selectionChanged()),
           this, SLOT(on_selection_changed()));
   connect(textEdit, SIGNAL(textChanged()),
           this, SLOT(on_text_changed()));
   connect(textEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)),
           this, SLOT(on_format_changed(QTextCharFormat)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   textEdit->setFocus();
   QTextCharFormat f;
   f.setFontUnderline(true);
   textEdit->setCurrentCharFormat(f);
}

void Widget::on_copy(bool status)
{
   qDebug() << "on_copy" << status;
}

void Widget::on_undo(bool status)
{
   qDebug() << "on_undo" << status;
}

void Widget::on_redo(bool status)
{
   qDebug() << "on_redo" << status;
}

void Widget::on_format_changed(const QTextCharFormat &)
{
   qDebug() << "on_format_changed";
}

void Widget::on_position_changed()
{
   qDebug() << "on_position_changed";
}

void Widget::on_selection_changed()
{
   qDebug() << "on_selection_changed";
}

void Widget::on_text_changed()
{
   qDebug() << "on_text_changed";
}
