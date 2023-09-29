#include "mylabel.h"

MyLabel::MyLabel(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setAlignment(Qt::AlignCenter);
   // Запрет передачи события родителю
   setAttribute(Qt::WA_NoMousePropagation, true);
}

void MyLabel::mousePressEvent(QMouseEvent *e)
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

   QString s = QString( "X: %1, Y: %2, global X: %3, global Y: %4")
                  .arg(e->position().x()).arg(e->position().y())
                  .arg(e->globalPosition().x())
                  .arg(e->globalPosition().y());
   setText(s);
   qDebug() << "scenePosition:" << e->scenePosition();
   e->ignore();
   QLabel::mousePressEvent(e);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *e)
{
   qDebug() << "Отпускание кнопки";
   QLabel::mouseReleaseEvent(e);
}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *e)
{
   qDebug() << "Двойной щелчок";
   QLabel::mouseDoubleClickEvent(e);
}
