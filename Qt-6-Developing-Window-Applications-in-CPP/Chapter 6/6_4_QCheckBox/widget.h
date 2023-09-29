#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_state_changed1(int);
   void on_state_changed2(int);
   void on_state_changed3(int);
   void on_checkBox1_toggled(bool);
private:
   QCheckBox *checkBox1;
   QCheckBox *checkBox2;
   QCheckBox *checkBox3;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
