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
      if (e->proposedAction() == Qt::CopyAction) {
         e->acceptProposedAction();
         return;
      }
      if (e->possibleActions() & Qt::CopyAction) {
         e->setDropAction(Qt::CopyAction);
         e->accept();
      }
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
