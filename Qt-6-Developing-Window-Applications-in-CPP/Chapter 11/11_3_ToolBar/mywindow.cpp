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
   add_tool_bar();
}

void MyWindow::on_btn1_clicked()
{
   qDebug() << "Нажата кнопка";
}

void MyWindow::on_open()
{
   qDebug() << "Выбран пункт Open";
}

void MyWindow::add_tool_bar()
{
   toolBar = new QToolBar("MyToolBar");
   actOpen = new QAction("Open");
   QIcon icoComputer = style()->standardIcon(
                        QStyle::SP_ComputerIcon);
   actOpen->setIcon(icoComputer);
   actOpen->setShortcut(QKeySequence::Open);
   connect(actOpen, SIGNAL(triggered()),
           this, SLOT(on_open()));
   toolBar->addAction(actOpen);

   QIcon ico = style()->standardIcon(
                        QStyle::SP_MessageBoxCritical);
   actClose = toolBar->addAction(ico, "Close",
                                 qApp, SLOT(quit()));
   actClose->setShortcut(QKeySequence::Close);
   addToolBar(Qt::TopToolBarArea, toolBar);
   toolBar2 = new QToolBar("MyToolBar2");
   QIcon ico2 = style()->standardIcon(
                        QStyle::SP_DialogCloseButton);
   actQuit = toolBar2->addAction(ico2, "Quit", qApp->quit);
   actQuit->setShortcut(QKeySequence::Quit);
   addToolBar(Qt::TopToolBarArea, toolBar2);
}
