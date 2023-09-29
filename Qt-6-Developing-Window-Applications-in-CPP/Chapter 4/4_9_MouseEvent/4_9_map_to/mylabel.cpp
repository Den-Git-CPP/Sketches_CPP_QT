#include "mylabel.h"

MyLabel::MyLabel(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setAlignment(Qt::AlignCenter);
   grabMouse();
   prnt = parent;
}

void MyLabel::mousePressEvent(QMouseEvent *e)
{
   QString s = QString( "X: %1, Y: %2, global X: %3, global Y: %4")
                  .arg(e->position().x()).arg(e->position().y())
                  .arg(e->globalPosition().x())
                  .arg(e->globalPosition().y());
   setText(s);
   // Преобразование из глобальных координат в координаты компонента
   QPointF p1 = mapFromGlobal(e->globalPosition());
   qDebug() << "mapFromGlobal - " << p1;
   // Преобразование из координат компонента в глобальные координаты
   QPointF p2 = mapToGlobal(e->position());
   qDebug() << "mapToGlobal - " << p2;
   // Преобразование в координаты родителя
   QPointF p3 = mapToParent(e->position());
   qDebug() << "mapToParent - " << p3;
   // Преобразование координат родителя в координаты компонента
   QPointF p4 = mapFromParent(p3);
   qDebug() << "mapFromParent - " << p4;
   // Преобразование в координаты родителя
   QPointF p5 = mapTo(prnt, e->position());
   qDebug() << "mapTo - " << p5;
   // Преобразование координат родителя в координаты компонента
   QPointF p6 = mapFrom(prnt, p5);
   qDebug() << "mapFrom - " << p6;
   e->ignore();
   QLabel::mousePressEvent(e);
}
