#include "mylabel.h"

MyLabel::MyLabel(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setAlignment(Qt::AlignCenter);
   // Обрабатываем любые перемещения мыши
   setMouseTracking(true);
   // в пределах всего окна, а не комопонета
   grabMouse();
}

void MyLabel::mouseMoveEvent(QMouseEvent *e)
{
   QString s = QString( "X: %1, Y: %2, global X: %3, global Y: %4")
                  .arg(e->position().x()).arg(e->position().y())
                  .arg(e->globalPosition().x())
                  .arg(e->globalPosition().y());
   setText(s);
   qDebug() << "scenePosition:" << e->scenePosition();
   e->ignore();
   QLabel::mouseMoveEvent(e);
}
