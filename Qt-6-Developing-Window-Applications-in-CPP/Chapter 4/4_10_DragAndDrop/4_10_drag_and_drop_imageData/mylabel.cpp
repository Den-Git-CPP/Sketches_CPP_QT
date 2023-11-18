#include "mylabel.h"

MyLabel::MyLabel(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setAlignment(Qt::AlignCenter);
   setFrameStyle(QFrame::Box | QFrame::Plain);
   startPos = QPointF();
}

void MyLabel::mousePressEvent(QMouseEvent *e)
{
   if (e->buttons() & Qt::LeftButton) {
      startPos = e->position();
   }
   else {
      startPos = QPointF();
      e->ignore();
   }
   QLabel::mousePressEvent(e);
}

void MyLabel::mouseMoveEvent(QMouseEvent *e)
{
   if (startPos.isNull()) {
      e->ignore();
      QLabel::mouseMoveEvent(e);
      return;
   }
   int length = (e->position() - startPos).manhattanLength();
   if (length <= QApplication::startDragDistance()) {
      e->ignore();
      QLabel::mouseMoveEvent(e);
      return;
   }
   QMimeData *data = new QMimeData();
   data->setImageData(QImage("C:\\cpp\\projectsQt\\Test\\pixmap.png"));
   QDrag *drag = new QDrag(this);
   drag->setMimeData(data);
   drag->setPixmap(QPixmap("C:\\cpp\\projectsQt\\Test\\pixmap.png"));
   drag->setHotSpot(QPoint(40, 40));

   connect(drag, SIGNAL(actionChanged(Qt::DropAction)),
           this, SLOT(on_action_changed(Qt::DropAction)));
   connect(drag, SIGNAL(targetChanged(QObject*)),
           this, SLOT(on_target_changed(QObject*)));

   Qt::DropAction action = drag->exec(
            Qt::MoveAction | Qt::CopyAction, Qt::MoveAction);
   if (action == Qt::CopyAction) {
      qDebug() << "Завершено действие CopyAction";
   }
   else if (action == Qt::MoveAction) {
      qDebug() << "Завершено действие MoveAction";
   }
   else if (action == Qt::IgnoreAction) {
      qDebug() << "Действие отменено";
   }
   QLabel::mouseMoveEvent(e);
}

void MyLabel::on_action_changed(Qt::DropAction action)
{
   if (action == Qt::CopyAction) {
      qDebug() << "Действие изменено на CopyAction";
   }
   else if (action == Qt::MoveAction) {
      qDebug() << "Действие изменено на MoveAction";
   }
}

void MyLabel::on_target_changed(QObject *target)
{
   qDebug() << "Изменен компонент-приемник" << target;
}
