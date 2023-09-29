#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDial>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_valueChanged(int);
   void on_sliderMoved(int);
   void on_sliderPressed();
   void on_sliderReleased();
   void on_rangeChanged(int,int);
private:
   QDial *slider;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H

