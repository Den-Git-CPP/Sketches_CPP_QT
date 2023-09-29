#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QLineEdit>

class MyDialog : public QDialog
{
   Q_OBJECT
public:
   explicit MyDialog(QWidget *parent=nullptr);
public:
   QVBoxLayout *mainBox;
   QDialogButtonBox *box;
   QLineEdit *lineEdit;
};

#endif // MYDIALOG_H
