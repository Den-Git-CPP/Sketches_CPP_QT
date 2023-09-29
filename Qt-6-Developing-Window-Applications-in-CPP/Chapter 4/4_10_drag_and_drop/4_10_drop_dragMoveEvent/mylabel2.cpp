#include "mylabel2.h"

MyLabel2::MyLabel2(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setAlignment(Qt::AlignCenter);
   setFrameStyle(QFrame::Box | QFrame::Plain);
   setAcceptDrops(true);
}

void MyLabel2::dragEnterEvent(QDragEnterEvent *e)
{
   if (e->mimeData()->hasText()) {
      e->acceptProposedAction();
   }
}

void MyLabel2::dropEvent(QDropEvent *e)
{
   if (e->mimeData()->hasText()) {
      setText(e->mimeData()->text());
      e->accept();
   }
   else e->ignore();
}

void MyLabel2::dragMoveEvent(QDragMoveEvent *e)
{
   if (e->mimeData()->hasText()) {
      QRect rect(0, 0, 50, 50);
      if (e->answerRect().intersects(rect)) {
         e->accept(rect);
      }
      else {
         e->ignore();
      }
   }
}
