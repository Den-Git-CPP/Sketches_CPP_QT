#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowsubi; }
QT_END_NAMESPACE

class MainWindowsubi : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowsubi(QWidget *parent = nullptr);
    ~MainWindowsubi();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
private:
    Ui::MainWindowsubi *ui;
};

