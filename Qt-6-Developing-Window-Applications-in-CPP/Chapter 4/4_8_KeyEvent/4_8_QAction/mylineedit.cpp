#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent)
   : QLineEdit(parent), id(-1)
{}

bool MyLineEdit::event(QEvent *e)
{
   if (e->type() == QEvent::Shortcut) {
      QShortcutEvent *s = static_cast<QShortcutEvent*>(e);
      if (id == s->shortcutId()) {
         setFocus(Qt::ShortcutFocusReason);
         return true;
      }
   }
   return QLineEdit::event(e);
}



