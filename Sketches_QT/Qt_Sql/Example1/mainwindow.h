#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTableView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QTableView* m_Table;
    void connectDB();

private slots:
    void slotAddRecord();
    void slotSubmit();
    void slotQuery();
};
#endif // MAINWINDOW_H
