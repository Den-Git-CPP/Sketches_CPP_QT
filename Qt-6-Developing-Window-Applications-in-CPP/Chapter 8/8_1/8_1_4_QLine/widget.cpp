#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(300, 410);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   QPen pen(Qt::black);
   painter.setPen(pen);
   painter.setBrush(QBrush(Qt::white));
   painter.drawRect(3, 3, 294, 294);
   painter.setPen(QPen(Qt::red, 5));
   QLine line1(QPoint(20, 50), QPoint(280, 50));
   painter.drawLine(line1);
   QLine line2(20, 100, 280, 100);
   painter.drawLine(line2);
   qDebug() << line1.p1() << line1.p2();
   qDebug() << line2.x1() << line2.y1() << line2.x2() << line2.y2();
}
