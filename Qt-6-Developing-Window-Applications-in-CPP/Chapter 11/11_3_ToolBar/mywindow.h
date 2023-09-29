#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "widget.h"
#include <QMainWindow>
#include <QToolBar>
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
   QToolBar *toolBar;
   QToolBar *toolBar2;
   QAction *actOpen;
   QAction *actClose;
   QAction *actQuit;
private:
   void add_tool_bar();
};

#endif // MYWINDOW_H
