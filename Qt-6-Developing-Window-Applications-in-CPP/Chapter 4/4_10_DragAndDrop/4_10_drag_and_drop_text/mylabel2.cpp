#include "mylabel2.h"

MyLabel2::MyLabel2(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setFixedSize(330, 80);
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
