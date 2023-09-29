#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_link_activated(const QString&);
   void on_link_hovered(const QString&);
private:
   QLabel *label;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
