#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QCloseEvent>
#include <QMessageBox>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
protected:
  void closeEvent(QCloseEvent *e) override;
};
#endif // WIDGET_H
