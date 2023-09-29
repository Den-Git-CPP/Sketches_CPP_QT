#include "mylabel.h"

MyLabel::MyLabel(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setAlignment(Qt::AlignCenter);
   grabMouse();
}

void MyLabel::wheelEvent(QWheelEvent *e)
{
   if (e->buttons() & Qt::LeftButton) {
      qDebug() << "Нажата левая кнопка мыши";
   }
   if (e->buttons() & Qt::RightButton) {
      qDebug() << "Нажата правая кнопка мыши";
   }
   if (e->buttons() & Qt::MiddleButton) {
      qDebug() << "Нажата средняя кнопка мыши";
   }
   if ((e->buttons() & Qt::LeftButton) &&
       (e->buttons() & Qt::RightButton)) {
      qDebug() << "Левая и правая кнопки нажаты";
   }
   QString s = QString("X: %1, Y: %2, global X: %3, global Y: %4")
                  .arg(e->position().x()).arg(e->position().y())
                  .arg(e->globalPosition().x())
                  .arg(e->globalPosition().y());
   setText(s);
   qDebug() << "angleDelta" << e->angleDelta();
   qDebug() << "pixelDelta" << e->pixelDelta();
   qDebug() << "scenePosition" << e->scenePosition();
   qDebug() << "modifiers" << e->modifiers();
   QLabel::wheelEvent(e);
}
