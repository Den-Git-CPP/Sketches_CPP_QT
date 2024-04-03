#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QAxObject>
namespace Ui {
    class MainWindow;
}

typedef struct record {
    QString year;
    QString total;
    QString admit;
    QString rate;
} Record;

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow (QWidget* parent = 0);
    ~MainWindow ();

  private slots:

    void on_writeWordPushButton_clicked ();

    void on_readWordPushButton_clicked ();

  private:
    Ui::MainWindow* ui;

    //
    QAxObject* myword;
    QAxObject* mydocs;
    QAxObject* document;
    QAxObject* paragraph;

    QAxObject* mytable;
    QList<Record> myrecord;
};

#endif // MAINWINDOW_H
