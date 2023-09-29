#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "widget.h"
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

class MyWindow : public QMainWindow
{
   Q_OBJECT
public:
   explicit MyWindow(QWidget *parent = nullptr);
protected slots:
   void on_btn1_clicked();
   void on_open();
private:
   Widget *w;
   QMenu *menuFile;
   QAction *actOpen;
private:
   void add_menu();
};

#endif // MYWINDOW_H
