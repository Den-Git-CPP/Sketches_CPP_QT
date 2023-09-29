#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Изменить указатель");
   vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   setLayout(vbox);
   QObject::connect(btn1, SIGNAL(clicked()),
                    this, SLOT(on_btn1_clicked()));
}

void Widget::on_btn1_clicked()
{
   QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
   btn1->setEnabled(false);
   QTimer::singleShot(5000, this, SLOT(on_timeout()));
}

void Widget::on_timeout()
{
   QApplication::restoreOverrideCursor();
   btn1->setEnabled(true);
}

Widget::~Widget() {}

