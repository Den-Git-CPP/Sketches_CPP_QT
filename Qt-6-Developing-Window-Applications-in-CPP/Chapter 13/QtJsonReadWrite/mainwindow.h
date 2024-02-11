#pragma once
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow (QWidget* parent = 0);
    ~MainWindow ();

  private slots:
    void on_pushButton_clicked ();

  private:
    Ui::MainWindow* ui;
};
