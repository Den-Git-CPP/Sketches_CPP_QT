#include "mylabel.h"

MyLabel::MyLabel(const QString &text, QWidget *parent)
   : QLabel(text, parent)

{
   setFocusPolicy(Qt::StrongFocus);
   setAlignment(Qt::AlignCenter);
}

void MyLabel::focusInEvent(QFocusEvent *e)
{
   grabKeyboard();
   QLabel::focusInEvent(e);
}

void MyLabel::focusOutEvent(QFocusEvent *e)
{
   releaseKeyboard();
   QLabel::focusOutEvent(e);
}

void MyLabel::keyPressEvent(QKeyEvent *e)
{
   QStringList msg, modifiers;
   if (e->modifiers() & Qt::ShiftModifier) {
      modifiers << "Shift";
   }
   if (e->modifiers() & Qt::ControlModifier) {
      modifiers << "Ctrl";
   }
   if (e->modifiers() & Qt::AltModifier) {
      modifiers << "Alt";
   }
   if (modifiers.isEmpty()) {
      modifiers << "No";
   }
   if (e->matches(QKeySequence::Copy)) {
      msg << "Нажата комбинация <Ctrl>+<C>";
   }
   if (e->key() == Qt::Key_B) {
      msg << "Нажата клавиша <B>";
   }
   QString s = QString("Код: %1, символ: %2\nmodifiers: ")
                  .arg(e->key()).arg(e->text());
   s += modifiers.join(L'+') + "\n";
   s += msg.join(L'\n');
   setText(s);
   e->ignore();
   QLabel::keyPressEvent(e);
}

void MyLabel::keyReleaseEvent(QKeyEvent *e)
{
   qDebug() << "Клавиша отпущена";
   QLabel::keyReleaseEvent(e);
}
