#include "widget.h"
#include <QImageWriter>


Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(600, 600);
   pix = QPixmap("G:\\Qt-6-Developing-Window-Applications-in-CPP\\Chapter 8\\8_3_Image\\8_3_1_QPixmap\\8_3_1_save\\photo.jpg");
   pix.save("G:\\Qt-6-Developing-Window-Applications-in-CPP\\Chapter 8\\8_3_Image\\8_3_1_QPixmap\\8_3_1_save\\photo.png", "PNG");
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawPixmap(0, 0, pix);
}
