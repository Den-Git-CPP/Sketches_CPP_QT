#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCalendarWidget>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_activated(QDate);
   void on_clicked_calendar(QDate);
   void on_selectionChanged();
   void on_currentPageChanged(int,int);
private:
   QCalendarWidget *calendar;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
