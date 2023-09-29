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
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine));
   QPolygon polygon;
   polygon << QPoint(20, 20) << QPoint(120, 20) << QPoint(20, 120);
   painter.drawPolygon(polygon);

   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine));
   QList<QPoint> list;
   list << QPoint(180, 20) << QPoint(280, 20) << QPoint(280, 120);
   QPolygon polygon2(list);

   painter.drawPolygon(polygon2);
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine));
   QRect rect(20, 160, 100, 100);
   QPolygon polygon3(rect, false);
   painter.drawPolygon(polygon3);

   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine));
   QRect rect2(160, 160, 100, 100);
   QPolygon polygon4(rect2, true);
   painter.drawPolygon(polygon4);

}
