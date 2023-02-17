#pragma once

#include "maintaf.h"
#include "xml2.h"
#include "xmlparser.h"
#include <QMainWindow>

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

  private slots:
    void on_pushButton_clicked ();

    void on_pushButton_2_clicked ();

  private:
    Ui::MainWindow* ui;
    XMLParser* xmlparser = nullptr;
    XML2* xmlparser2     = nullptr;
    MainTAF* main_TAF    = nullptr;
};
