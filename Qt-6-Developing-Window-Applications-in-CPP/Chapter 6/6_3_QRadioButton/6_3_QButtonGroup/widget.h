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
   void on_group1_buttonClicked(QAbstractButton *button);
   void on_group2_buttonClicked(QAbstractButton *button);
private:
   QRadioButton *radio1;
   QRadioButton *radio2;
   QRadioButton *radio3;
   QRadioButton *radio4;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
