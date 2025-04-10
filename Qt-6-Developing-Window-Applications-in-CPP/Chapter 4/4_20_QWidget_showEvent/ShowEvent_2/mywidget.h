#pragma once

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MyWidget;
}
QT_END_NAMESPACE

class MyWidget : public QWidget {
    Q_OBJECT

  public:
    MyWidget (QWidget* parent = nullptr);

    ~MyWidget ();

  protected:
    void showEvent (QShowEvent* event) override;

  private:
    Ui::MyWidget* ui;
    QTimer* m_timer;
    void update ();
};
