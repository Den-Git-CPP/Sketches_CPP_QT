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
   painter.setRenderHint(QPainter::Antialiasing);
   painter.setPen(QPen(Qt::black));
   painter.setBrush(QBrush(Qt::white));
   painter.drawRect(3, 3, 294, 294);

   painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
   static const QPoint points[4] = {
      QPoint(20, 30),
      QPoint(280, 30),
      QPoint(20, 80),
      QPoint(280, 80)
   };
   painter.drawPolyline(points, 4);

   static const QPointF points2[4] = {
      QPointF(20., 100.),
      QPointF(280., 100.),
      QPointF(20., 140.),
      QPointF(280., 140.)
   };
   painter.drawPolyline(points2, 4);

   painter.setPen(QPen(Qt::blue, 5));

   QPolygon polygon;
   polygon << QPoint(20, 150) << QPoint(280, 150)
           << QPoint(150, 250);
   painter.drawPolyline(polygon);

   painter.setPen(QPen(Qt::green, 5));
   QPolygonF polygonF;
   polygonF << QPointF(20., 250.) << QPointF(280., 250.)
           << QPointF(150., 150.);
   painter.drawPolyline(polygonF);

}
