#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
    ui->setupUi (this);
    Settings = new QSettings (this);
    loadSettings ();
}

MainWindow::~MainWindow ()
{
    saveSettings ();
    delete ui;
}

void MainWindow::saveSettings ()
{
    // запись настроек
    Settings->setValue ("Title", windowTitle ());
}

void MainWindow::loadSettings ()
{
    // считывание настроек
    setWindowTitle (Settings->value ("Title", "MainFormSettings").toString ());
}
