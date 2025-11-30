#pragma once

#include <QMainWindow>
#include <QSettings>
QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow (QWidget* parent = nullptr);
    ~MainWindow ();

    void saveSettings ();
    void loadSettings ();

  private:
    Ui::MainWindow* ui;
    QSettings* Settings;
};
