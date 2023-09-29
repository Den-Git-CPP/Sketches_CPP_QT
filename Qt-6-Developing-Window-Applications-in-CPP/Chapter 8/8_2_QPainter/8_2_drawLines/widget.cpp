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

   QList<QLine> list1;
   list1 << QLine(20, 50, 280, 50) << QLine(20, 60, 280, 60);
   painter.drawLines(list1);

   QList<QLineF> list2;
   list2 << QLineF(20., 70., 280., 70.) << QLineF(20., 80., 280., 80.);
   painter.drawLines(list2);

   static const QLine lines1[2] = {
      QLine(20, 90, 280, 90),
      QLine(20, 100, 280, 100)
   };
   painter.drawLines(lines1, 2);

   static const QLineF lines2[2] = {
      QLineF(20., 110., 280., 110.),
      QLineF(20., 120., 280., 120.)
   };
   painter.drawLines(lines2, 2);

   QList<QPoint> list3;
   list3 << QPoint(20, 130) << QPoint(280, 130)
         << QPoint(20, 140) << QPoint(280, 140);
   painter.drawLines(list3);

   QList<QPointF> list4;
   list4 << QPointF(20., 150.) << QPointF(280., 150.)
         << QPointF(20., 160.) << QPointF(280., 160.);
   painter.drawLines(list4);

}
