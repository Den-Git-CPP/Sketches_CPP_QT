#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_valueChanged(int);
   void on_textChanged(const QString &);
private:
   QSpinBox *spinBox;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
