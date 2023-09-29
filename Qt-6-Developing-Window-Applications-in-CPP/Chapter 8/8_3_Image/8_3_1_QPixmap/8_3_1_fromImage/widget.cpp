#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(600, 600);
   QImage img("G:\\ProjectQT\\CH08\\8_3_Image\\8_3_1_QPixmap\\8_3_1_QPixmap\\photo.jpg");
   pix = QPixmap::fromImage(img);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawPixmap(0, 0, pix);
}
