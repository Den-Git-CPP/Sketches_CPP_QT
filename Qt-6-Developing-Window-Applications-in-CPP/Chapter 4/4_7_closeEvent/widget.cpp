#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{}

void Widget::closeEvent(QCloseEvent *e)
{
   QMessageBox::StandardButton result;
   result = QMessageBox::question(this,
               "Подтверждение закрытия окна",
               "Вы действительно хотите закрыть окно?",
               QMessageBox::Yes | QMessageBox::No,
               QMessageBox::No);
   if (result == QMessageBox::Yes) {
      e->accept();
      QWidget::closeEvent(e);
   }
   else {
      e->ignore();
   }
}

Widget::~Widget() {}

