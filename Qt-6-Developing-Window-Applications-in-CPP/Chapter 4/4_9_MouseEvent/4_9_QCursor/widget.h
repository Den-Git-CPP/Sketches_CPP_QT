#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
protected:
   void mousePressEvent(QMouseEvent *e) override;
private:
   QLabel *label;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
