#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QErrorMessage>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
private:
   QPushButton *btn1;
   QErrorMessage *dialog;
};
#endif // WIDGET_H

