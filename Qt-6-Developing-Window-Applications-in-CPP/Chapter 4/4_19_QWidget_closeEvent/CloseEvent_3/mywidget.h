#pragma once

#include <QWidget>
#include <QCloseEvent>
#include <QMessageBox>

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
    void closeEvent (QCloseEvent* event) override;

  private:
    Ui::MyWidget* ui;
    void cleanupResources ();
    bool isClosingAllowed ();
};
