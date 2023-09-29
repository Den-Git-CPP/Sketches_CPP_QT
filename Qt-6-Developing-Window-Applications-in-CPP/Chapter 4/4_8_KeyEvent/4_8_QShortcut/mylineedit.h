#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QShortcutEvent>

class MyLineEdit : public QLineEdit
{
   Q_OBJECT
public:
   MyLineEdit(QWidget *parent=nullptr);
protected:
   bool event(QEvent *e) override;
public:
   int id;
};

#endif // MYLINEEDIT_H
