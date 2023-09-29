#include "mywindow.h"
#include <QStyle>

MyWindow::MyWindow(QWidget *parent)
   : QMainWindow(parent)
{
   w = new Widget();
   setCentralWidget(w);
   connect(w->btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   add_menu();
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

   menuFile->addAction("Пункт &1");
   QIcon ico = style()->standardIcon(
                                QStyle::SP_MessageBoxCritical);
   menuFile->addAction(ico, "Пункт &2");

   menuFile->addSeparator();

   menuFile->addAction("Выход", qApp,
                       SLOT(quit()), QKeySequence::fromString("Ctrl+Q"));

   menuBar()->addMenu(menuFile);
}
