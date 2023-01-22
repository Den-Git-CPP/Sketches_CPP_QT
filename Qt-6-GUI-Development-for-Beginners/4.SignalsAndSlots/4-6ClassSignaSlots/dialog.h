#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_dialog.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H

