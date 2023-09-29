#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimerEvent>
#include <QTime>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
protected:
   void timerEvent(QTimerEvent *event) override;
private slots:
   void on_btn1_clicked();
   void on_btn2_clicked();
private:
   QLabel *label;
   QPushButton *btn1;
   QPushButton *btn2;
   QVBoxLayout *vbox;
   int timer_id;
};
#endif // WIDGET_H
