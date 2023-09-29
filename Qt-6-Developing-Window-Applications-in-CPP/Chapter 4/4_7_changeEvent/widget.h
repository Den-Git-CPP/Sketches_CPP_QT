#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QShowEvent>
#include <QHideEvent>
#include <QPushButton>
#include <QVBoxLayout>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
protected:
   void changeEvent(QEvent *e) override;
   void showEvent(QShowEvent *e) override;
   void hideEvent(QHideEvent *e) override;
private:
   QPushButton *btn1;
   QPushButton *btn2;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
