#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "widget.h"
#include <QMainWindow>
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QDockWidget>
#include <QLabel>

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

   QToolBar *toolBar;
   QToolBar *toolBar2;
   QAction *actClose;
   QAction *actQuit;

   QDockWidget *dw;
   QDockWidget *dw2;
   QLabel *lbl;
   QLabel *lbl2;
private:
   void add_menu();
   void add_tool_bar();
   void add_dock_widget();
};

#endif // MYWINDOW_H
