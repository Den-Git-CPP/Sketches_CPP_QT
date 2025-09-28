#pragma once

#include <QWidget>
#include <QTime>
#include <QTimerEvent>

namespace Ui {
    class n_bells;
}

class n_bells : public QWidget {
    Q_OBJECT

  public:
    explicit n_bells (QWidget* parent = nullptr);
    ~n_bells ();

  protected:
    void timerEvent (QTimerEvent* event) override;
    void showEvent (QShowEvent* event) override;
    // void closeEvent (QCloseEvent* event) override;

  private:
    Ui::n_bells* ui;
    int timer_close{ -1 };
};
