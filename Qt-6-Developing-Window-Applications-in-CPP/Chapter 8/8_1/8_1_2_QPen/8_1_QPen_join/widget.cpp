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
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine,
                       Qt::SquareCap, Qt::MiterJoin));
   QList<QPoint> list1;
   list1 << QPoint(20, 20) << QPoint(120, 20) << QPoint(20, 120);
   painter.drawPolygon(list1);
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine,
                       Qt::SquareCap, Qt::BevelJoin));
   QList<QPoint> list2;
   list2 << QPoint(180, 20) << QPoint(280, 20) << QPoint(280, 120);
   painter.drawPolygon(list2);
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine,
                       Qt::SquareCap, Qt::RoundJoin));
   QList<QPoint> list3;
   list3 << QPoint(20, 180) << QPoint(20, 280) << QPoint(120, 280);
   painter.drawPolygon(list3);
   painter.setPen(QPen(Qt::red, 15, Qt::SolidLine,
                       Qt::SquareCap, Qt::SvgMiterJoin));
   QList<QPoint> list4;
   list4 << QPoint(280, 180) << QPoint(280, 280) << QPoint(180, 280);
   painter.drawPolygon(list4);

}
