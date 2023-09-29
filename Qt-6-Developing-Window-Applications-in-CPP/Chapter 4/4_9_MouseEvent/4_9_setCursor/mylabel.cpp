#include "mylabel.h"

MyLabel::MyLabel(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setAlignment(Qt::AlignCenter);
   setCursor(QCursor(Qt::WaitCursor));
}
