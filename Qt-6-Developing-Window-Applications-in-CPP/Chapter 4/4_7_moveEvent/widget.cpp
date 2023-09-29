#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{}

void Widget::moveEvent(QMoveEvent *e)
{
   qDebug() << "moveEvent" << e->pos().x() << e->pos().y();
   QWidget::moveEvent(e);
}

void Widget::resizeEvent(QResizeEvent *e)
{
   qDebug() << "resizeEvent"
            << e->size().width() << e->size().height();
   QWidget::resizeEvent(e);
}

Widget::~Widget() {}

