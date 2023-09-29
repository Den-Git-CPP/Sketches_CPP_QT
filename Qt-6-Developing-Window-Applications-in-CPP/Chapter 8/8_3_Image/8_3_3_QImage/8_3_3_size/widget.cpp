#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(600, 600);
   img = QImage("G:\\Qt-6-Developing-Window-Applications-in-CPP\\Chapter 8\\8_3_Image\\8_3_3_QImage\\8_3_3_size\\photo.jpg");
   qDebug() << img.width() << img.height();
   qDebug() << img.size() << img.rect();
   qDebug() << img.depth() << img.format();
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawImage(0, 0, img);
}
