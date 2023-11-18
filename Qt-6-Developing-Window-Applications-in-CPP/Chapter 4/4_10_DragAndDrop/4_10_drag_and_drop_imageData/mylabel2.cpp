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
   if (e->mimeData()->hasImage()) {
      e->acceptProposedAction();
   }
}

void MyLabel2::dropEvent(QDropEvent *e)
{
   if (e->mimeData()->hasImage()) {
      QImage image = qvariant_cast<QImage>(e->mimeData()->imageData());
      setPixmap(QPixmap::fromImage(image));
      e->accept();
   }
   else e->ignore();
}
