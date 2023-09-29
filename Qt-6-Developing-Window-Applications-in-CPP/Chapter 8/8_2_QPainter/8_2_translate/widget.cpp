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

   painter.fillRect(10, 10, 50, 50, Qt::red);
   painter.save();
   painter.translate(105, 105);
   painter.rotate(45.0);
   painter.fillRect(-25, -25, 50, 50, Qt::green);
   painter.restore();
   painter.save();
   painter.translate(105, 105);
   painter.rotate(20.0);
   painter.fillRect(-25, -25, 50, 50, Qt::black);
   painter.restore();
   painter.fillRect(150, 150, 50, 50, Qt::blue);
}
