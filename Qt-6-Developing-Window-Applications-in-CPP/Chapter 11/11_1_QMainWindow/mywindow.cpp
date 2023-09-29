#include "mywindow.h"
#include <QStyle>

MyWindow::MyWindow(QWidget *parent)
   : QMainWindow(parent)
{
   w = new Widget();
   setCentralWidget(w);
   connect(w->btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   setIconSize(QSize(32, 32));
   // setAnimated(false);
   setDockOptions(QMainWindow::AnimatedDocks |
                  QMainWindow::AllowTabbedDocks);
   setTabPosition(Qt::LeftDockWidgetArea,
                  QTabWidget::North);
   setTabPosition(Qt::RightDockWidgetArea,
                  QTabWidget::North);
   setTabShape(QTabWidget::Triangular);
   add_menu();
   add_tool_bar();
   add_dock_widget();
   statusBar()->showMessage("Текст в строке состояния");
}

void MyWindow::on_btn1_clicked()
{
   qDebug() << "Нажата кнопка";
}

void MyWindow::on_open()
{
   qDebug() << "Выбран пункт меню Open";
}

void MyWindow::add_menu()
{
   menuFile = new QMenu("&File");
   actOpen = new QAction("Open");
   actOpen->setShortcut(QKeySequence::Open);
   connect(actOpen, SIGNAL(triggered()),
           this, SLOT(on_open()));
   menuFile->addAction(actOpen);
   menuBar()->addMenu(menuFile);
}

void MyWindow::add_tool_bar()
{
   toolBar = new QToolBar("MyToolBar");
   QIcon ico = style()->standardIcon(
                        QStyle::SP_MessageBoxCritical);
   actClose = toolBar->addAction(ico, "Close",
                                 qApp->quit);
   actClose->setShortcut(QKeySequence::Close);
   addToolBar(Qt::TopToolBarArea, toolBar);
   // addToolBarBreak(Qt::TopToolBarArea);
   toolBar2 = new QToolBar("MyToolBar2");
   QIcon ico2 = style()->standardIcon(
                        QStyle::SP_DialogCloseButton);
   actQuit = toolBar2->addAction(ico2, "Quit", qApp->quit);
   actQuit->setShortcut(QKeySequence::Quit);
   // insertToolBar(toolBar, toolBar2);
   addToolBar(Qt::TopToolBarArea, toolBar2);
   // insertToolBarBreak(toolBar2);
}

void MyWindow::add_dock_widget()
{
   dw = new QDockWidget("MyDockWidget1");
   lbl = new QLabel("Содержимое панели 1");
   lbl->setWordWrap(true);
   lbl->setFrameStyle(QFrame::Box | QFrame::Plain);
   dw->setWidget(lbl);
   addDockWidget(Qt::LeftDockWidgetArea, dw);

   dw2 = new QDockWidget("MyDockWidget2");
   lbl2 = new QLabel("Содержимое панели 2");
   lbl2->setWordWrap(true);
   lbl2->setFrameStyle(QFrame::Box | QFrame::Plain);
   dw2->setWidget(lbl2);
   addDockWidget(Qt::LeftDockWidgetArea, dw2, Qt::Vertical);
}
