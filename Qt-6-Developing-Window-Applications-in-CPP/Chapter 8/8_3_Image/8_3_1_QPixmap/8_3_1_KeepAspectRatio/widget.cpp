#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(600, 600);
   pix = QPixmap("G:\\Qt-6-Developing-Window-Applications-in-CPP\\Chapter 8\\8_3_Image\\8_3_1_QPixmap\\8_3_1_KeepAspectRatio\\photo.jpg");
   pix = pix.scaled(250, 300,
             Qt::KeepAspectRatio,
             Qt::FastTransformation);

}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   painter.drawPixmap(0, 0, pix);
}
