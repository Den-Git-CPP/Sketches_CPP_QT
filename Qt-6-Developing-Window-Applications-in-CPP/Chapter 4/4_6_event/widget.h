#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
   bool event(QEvent *e) override;
};
#endif // WIDGET_H
