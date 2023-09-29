#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(600, 600);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.setRenderHint(QPainter::Antialiasing);
   painter.setPen(QPen(Qt::black));
   painter.setBrush(QBrush(Qt::white));
   painter.drawRect(3, 3, 594, 594);

   QPixmap pixmap("G:\\ProjectQT\\CH08\\8_2_QPainter\\8_2_drawPixmap\\photo.jpg");
   painter.drawPixmap(3, 3, pixmap);
}
