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

   painter.setPen(QPen(Qt::red, 2));
   painter.setBrush(QBrush(Qt::green));
   painter.drawEllipse(50, 50, 80, 80);
   painter.drawEllipse(QRect(150, 50, 80, 40));
   painter.drawEllipse(QRectF(50., 150., 40., 80.));
   painter.drawEllipse(QPoint(190, 190), 10, 30);
   painter.drawEllipse(QPointF(190., 250.), 80., 20.);

}
