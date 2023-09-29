#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStackedLayout>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_current_changed(int);
   void on_btn1_clicked();
   void on_btn2_clicked();
private:
   QLabel *label1;
   QLabel *label2;
   QPushButton *btn1;
   QPushButton *btn2;
   QVBoxLayout *vbox;
   QHBoxLayout *hbox;
   QStackedLayout *stack;
   int id1;
   int id2;
};
#endif // WIDGET_H
