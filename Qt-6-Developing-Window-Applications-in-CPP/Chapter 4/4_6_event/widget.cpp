#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{}

bool Widget::event(QEvent *e)
{
   if (e->type() == QEvent::KeyPress) {
      qDebug() << "Нажата клавиша на клавиатуре";
      QKeyEvent *k = static_cast<QKeyEvent*>(e);
      qDebug() << "Код:" << k->key() << "текст:" << k->text();
   }
   else if (e->type() == QEvent::Close) {
      qDebug() << "Окно закрыто";
   }
   else if (e->type() == QEvent::MouseButtonPress) {
      qDebug() << "Щелчок мышью. Координаты:";
      QMouseEvent *m = static_cast<QMouseEvent*>(e);
      qDebug() << "Координаты:" << m->position();
   }
   return QWidget::event(e); // Отправляем дальше
}

Widget::~Widget() {}



