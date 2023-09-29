#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDateTimeEdit>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_timeChanged(QTime);
   void on_dateChanged(QDate);
   void on_dateTimeChanged(const QDateTime&);
private:
   QDateTimeEdit *dateTimeEdit;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
