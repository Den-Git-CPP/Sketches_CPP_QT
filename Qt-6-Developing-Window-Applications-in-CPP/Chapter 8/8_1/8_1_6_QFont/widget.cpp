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
   QPen pen(Qt::black);
   painter.setPen(pen);
   painter.setBrush(QBrush(Qt::white));
   painter.drawRect(3, 3, 294, 294);
   painter.setPen(QPen(Qt::red, 5, Qt::SolidLine));

   QFont font("Tahoma", 16);
   QFontMetrics fm(font);
   qDebug() << fm.height();               // 25
   qDebug() << fm.boundingRect("Строка"); // QRect(0,-21 65x25)

   painter.setFont(font);
   painter.drawText(50, 50, "Строка");

}
