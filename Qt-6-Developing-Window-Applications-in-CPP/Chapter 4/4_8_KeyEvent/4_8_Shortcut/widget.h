#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "mylineedit.h"

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
private:
   QLabel *label;
   QLineEdit *line1;
   MyLineEdit *line2;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
