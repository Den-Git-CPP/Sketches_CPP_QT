#pragma once

#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QXmlStreamAttribute>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
private slots:
  /* Слоты обработчиков кнопок, работающих с записью в файл */
  void on_generateButton_clicked();
  void on_dialogButton_clicked();

  /* Слоты обработчиков кнопок, работающих с чтением из файла */
  void on_readButton_clicked();
  void on_dialogReadButton_clicked();

private:
  Ui::MainWindow *ui;
};
