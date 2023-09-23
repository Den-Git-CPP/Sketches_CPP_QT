#pragma once

#include <QMainWindow>
#include <QMenu>           //2
#include <QMessageBox>     //3
#include <QSystemTrayIcon> //1

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow (QWidget* parent = nullptr);
    ~MainWindow ();

  private slots: // 4 slots
    void changeEvent (QEvent*);
    void trayIconActivated (QSystemTrayIcon::ActivationReason reason);
    void trayActionExecute ();
    void setTrayIconActions ();
    void showTrayIcon ();

  private:
    Ui::MainWindow* ui;

    QMenu* trayIconMenu; // 5 QMenu  Action QSystemTrayIcon //6 add png file
    QAction* minimizeAction;
    QAction* restoreAction;
    QAction* quitAction;
    QSystemTrayIcon* trayIcon;
};
