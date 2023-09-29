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
   QBrush brush1(Qt::green, Qt::Dense5Pattern);
   painter.fillRect(50, 50, 80, 80, brush1);

   QBrush brush2(Qt::green, Qt::CrossPattern);
   painter.fillRect(QRect(150, 50, 80, 80), brush2);

   QBrush brush3(Qt::green, Qt::DiagCrossPattern);
   painter.fillRect(QRectF(50., 150., 80., 80.), brush3);
   painter.fillRect(QRect(150, 150, 80, 80), Qt::green);

}
