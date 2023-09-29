#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QMoveEvent>
#include <QResizeEvent>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
protected:
   void moveEvent(QMoveEvent *e) override;
   void resizeEvent(QResizeEvent *e) override;
};
#endif // WIDGET_H
