#pragma once

#include <QWidget>
#include <QTimer>
#include <QPropertyAnimation>

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
    QPropertyAnimation* animation;
};
