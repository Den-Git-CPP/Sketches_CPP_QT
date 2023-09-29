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
   painter.setPen(QPen(Qt::black));
   painter.setBrush(QBrush(Qt::white));
   painter.drawRect(3, 3, 294, 294);

   painter.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::FlatCap));
   static const QPoint points[3] = {
      QPoint(50, 50),
      QPoint(150, 50),
      QPoint(250, 50)
   };
   painter.drawPoints(points, 3);
   static const QPointF pointsf[3] = {
      QPointF(50., 100.),
      QPointF(150., 100.),
      QPointF(250., 100.)
   };
   painter.drawPoints(pointsf, 3);

   painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::FlatCap));
   QPolygon polygon;
   polygon << QPoint(20, 150) << QPoint(280, 150) << QPoint(150, 250);
   painter.drawPoints(polygon);

   painter.setPen(QPen(Qt::green, 5, Qt::SolidLine, Qt::FlatCap));
   QPolygonF polygonf;
   polygonf << QPointF(20., 250.) << QPointF(280., 250.) << QPointF(150., 150.);
   painter.drawPoints(polygonf);


}
