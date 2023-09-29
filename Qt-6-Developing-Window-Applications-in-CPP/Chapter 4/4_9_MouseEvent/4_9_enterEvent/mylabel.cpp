#include "mylabel.h"

MyLabel::MyLabel(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setAlignment(Qt::AlignCenter);
}

void MyLabel::enterEvent(QEnterEvent *e)
{
   QString s = QString( "X: %1, Y: %2, global X: %3, global Y: %4")
                  .arg(e->position().x())
                  .arg(e->position().y())
                  .arg(e->globalPosition().x())
                  .arg(e->globalPosition().y());
   setText("Указатель в области компонента\n" + s);
   QLabel::enterEvent(e);
}

void MyLabel::leaveEvent(QEvent *e)
{
   setText("Указатель вне области компонента");
   QLabel::leaveEvent(e);
}
