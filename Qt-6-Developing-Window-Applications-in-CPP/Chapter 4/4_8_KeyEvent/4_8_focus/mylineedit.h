#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QFocusEvent>

class MyLineEdit : public QLineEdit
{
   Q_OBJECT
public:
   MyLineEdit(int id, QWidget *parent=nullptr);
protected:
   void focusInEvent(QFocusEvent *e) override;
   void focusOutEvent(QFocusEvent *e) override;
private:
   int id_;
};

#endif // MYLINEEDIT_H
