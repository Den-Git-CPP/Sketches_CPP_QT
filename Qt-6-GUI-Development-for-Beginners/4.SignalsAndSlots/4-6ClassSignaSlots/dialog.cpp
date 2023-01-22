#include <QtDebug>

#include "dialog.h"
#include "seconddialog.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  setupUi(this);
}


void MainWindow::on_pushButton_clicked()
{
    SecondDialog dialog;
    if (dialog.exec()) {
        qDebug()<<dialog.lineEdit->text();
    }
}
