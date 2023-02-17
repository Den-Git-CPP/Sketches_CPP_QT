#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
    ui->setupUi (this);

    main_TAF   = new MainTAF (this);
    xmlparser  = new XMLParser (this);
    xmlparser2 = new XML2 (this);
}

MainWindow::~MainWindow () { delete ui; }

void MainWindow::on_pushButton_clicked () { xmlparser->Read (main_TAF); }

void MainWindow::on_pushButton_2_clicked ()
{ //
    xmlparser2->Read ();
}
