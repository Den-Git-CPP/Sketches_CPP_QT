// forked https://evileg.com/ru/post/419/
#pragma once
#include <QMainWindow>
#include <QtCore>
// #include <QtGui>
// #include <QtWidgets>

#include <QFileDialog>
#include <QFile>
#include <QDir>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow (QWidget* parent = 0);
    ~MainWindow ();

  private:
    Ui::MainWindow* ui;

    // Слот добавления нового текста в массив текстов
    void onAddButtonClicked ();
    // Слот удаления всей информации о текстах в текущем объекте
    void onClearButtonClicked ();
    // Слот сохранения текстов в json файл
    void onSaveButtonClicked ();
    // Слот загрузки текстов в программу из json файла
    void onLoadButtonClicked ();

    // Текущий json объект, с которым производится работа
    QJsonObject m_currentJsonObject;
};
