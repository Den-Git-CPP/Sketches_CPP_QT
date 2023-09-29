#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDoubleSpinBox>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_valueChanged(double);
   void on_textChanged(const QString &);
private:
   QDoubleSpinBox *spinBox;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
