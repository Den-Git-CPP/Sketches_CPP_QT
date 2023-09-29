#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>

class MyDialog : public QDialog
{
   Q_OBJECT
public:
   explicit MyDialog(QWidget *parent=nullptr);
public:
   QVBoxLayout *mainBox;
   QHBoxLayout *hbox;
   QPushButton *btnOK;
   QPushButton *btnCancel;
   QLineEdit *lineEdit;
};

#endif // MYDIALOG_H
