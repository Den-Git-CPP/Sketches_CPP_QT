#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   resize(300, 410);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *)
{
   QPainter painter(this);
   QPen pen(Qt::black);
   painter.setPen(pen);
   painter.setBrush(QBrush(Qt::white));
   painter.drawRect(3, 3, 294, 404);
   painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
   painter.drawRect(10, 10, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::Dense1Pattern));
   painter.drawRect(10, 50, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::Dense2Pattern));
   painter.drawRect(10, 90, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::Dense3Pattern));
   painter.drawRect(10, 130, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::Dense4Pattern));
   painter.drawRect(10, 170, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::Dense5Pattern));
   painter.drawRect(10, 210, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::Dense6Pattern));
   painter.drawRect(10, 250, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::Dense7Pattern));
   painter.drawRect(10, 290, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::CrossPattern));
   painter.drawRect(10, 330, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::HorPattern));
   painter.drawRect(10, 370, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::VerPattern));
   painter.drawRect(190, 10, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::BDiagPattern));
   painter.drawRect(190, 50, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::FDiagPattern));
   painter.drawRect(190, 90, 100, 30);
   painter.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
}
