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
   painter.drawChord(50, 50, 80, 80, 0, 16 * 90);
   painter.drawChord(QRect(150, 50, 80, 80), 16 * 90, 16 * 180);
   painter.drawChord(QRectF(50., 150., 80., 80.), 0, -16 * 90);
   painter.drawChord(150, 150, 80, 80, -16 * 90, -16 * 90);

}
