#pragma once

#include <QMainWindow>
#include <QTime>
#include "n_bells.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class mwBells2;
}
QT_END_NAMESPACE

class mwBells2 : public QMainWindow {
    Q_OBJECT

  public:
    mwBells2 (QWidget* parent = nullptr);
    ~mwBells2 ();

  protected:
    void timerEvent (QTimerEvent* event) override;
    void showEvent (QShowEvent* event) override;

  private:
    Ui::mwBells2* ui;
    int timer_id{ -1 };
    n_bells* bells{ nullptr };
};
