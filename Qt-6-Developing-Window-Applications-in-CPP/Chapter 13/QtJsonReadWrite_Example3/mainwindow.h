#pragma once
#include <QMainWindow>

#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    explicit MainWindow (QWidget* parent = 0);
    ~MainWindow ();
    // Метод 1: использование QJsonDocument
    void createJsonFile_1 (); // Создание JSON-файл с помощью QJsonDocument
    void readJsonFile_1 ();   // Чтение JSON-файлов с помощью QJsonDocument
    void writeJsonFile_1 ();  // Запись JSON-файлов с помощью QJsonDocument

    // Метод 2: использование QJsonObject и QJsonArray
    void createJsonFile_2 (); // Создание JSON-файл с помощью  QJsonObject и QJsonArray
    void readJsonFile_2 ();   // Чтение JSON-файлов с помощью  QJsonObject и QJsonArray
    void writeJsonFile_2 ();  // Запись JSON-файлов с помощью  QJsonObject и QJsonArray

  private:
    Ui::MainWindow* ui;
};
