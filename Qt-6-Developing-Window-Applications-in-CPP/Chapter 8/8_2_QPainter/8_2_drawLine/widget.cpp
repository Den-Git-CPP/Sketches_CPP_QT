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

   painter.setPen(QPen(Qt::red, 4, Qt::SolidLine));
   painter.drawLine(QLine(20, 50, 280, 50));

   painter.setPen(QPen(Qt::red, 4, Qt::DashLine));
   painter.drawLine(QLineF(20., 100., 280., 100.));

   painter.setPen(QPen(Qt::red, 4, Qt::DotLine));
   painter.drawLine(QPoint(20, 150), QPoint(280, 150));

   painter.setPen(QPen(Qt::red, 4, Qt::DashDotLine));
   painter.drawLine(QPointF(20., 200.),
                    QPointF(280., 200.));

   painter.setPen(QPen(Qt::red, 4, Qt::DashDotDotLine));
   painter.drawLine(20, 250, 280, 250);

}
