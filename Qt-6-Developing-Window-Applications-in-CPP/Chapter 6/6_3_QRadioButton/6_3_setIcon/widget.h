#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QRadioButton>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_radio1_toggled(bool);
   void on_radio2_toggled(bool);
private:
   QRadioButton *radio1;
   QRadioButton *radio2;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
