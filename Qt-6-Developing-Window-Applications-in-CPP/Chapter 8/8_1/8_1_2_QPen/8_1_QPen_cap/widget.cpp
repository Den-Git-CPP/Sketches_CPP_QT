#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(300, 300);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   QPen pen(Qt::black);
   painter.setPen(pen);
   painter.setBrush(QBrush(Qt::white));
   painter.drawRect(3, 3, 294, 294);
   painter.drawLine(20, 20, 20, 280);
   painter.drawLine(280, 20, 280, 280);
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine, Qt::FlatCap));
   painter.drawLine(20, 50, 280, 50);
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine, Qt::SquareCap));
   painter.drawLine(20, 100, 280, 100);
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine, Qt::RoundCap));
   painter.drawLine(20, 150, 280, 150);

}
