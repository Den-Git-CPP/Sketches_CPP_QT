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
   painter.setBrush(QBrush(Qt::green, Qt::Dense5Pattern));

   painter.drawRect(50, 50, 80, 80);

   painter.setBrush(QBrush(Qt::green, Qt::CrossPattern));
   painter.drawRect(QRect(150, 50, 80, 80));

   painter.setBrush(QBrush(Qt::green, Qt::DiagCrossPattern));
   painter.drawRect(QRectF(50., 150., 80., 80.));

   painter.setPen(QPen(Qt::red, 0, Qt::NoPen));
   painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
   painter.drawRect(QRect(150, 150, 80, 80));

}
