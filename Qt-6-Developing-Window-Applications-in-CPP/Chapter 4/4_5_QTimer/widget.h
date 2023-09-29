#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTime>
#include <QTimer>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_btn2_clicked();
   void on_timeout();
private:
   QLabel *label;
   QPushButton *btn1;
   QPushButton *btn2;
   QVBoxLayout *vbox;
   QTimer *timer;
};
#endif // WIDGET_H
