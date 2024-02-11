#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
    ui->setupUi (this);

    // Подключение слотов обработчиков к сигналам клика по кнопкам
    connect (ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect (ui->clearButton, &QPushButton::clicked, this, &MainWindow::onClearButtonClicked);
    connect (ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
    connect (ui->loadButton, &QPushButton::clicked, this, &MainWindow::onLoadButtonClicked);
}

MainWindow::~MainWindow ()
{
    delete ui;
}

void MainWindow::onAddButtonClicked ()
{
    // Создаём объект текста
    QJsonObject textObject;
    textObject ["title"]   = ui->titleLineEdit->text ();              // Устанавливаем заголовок текста
    textObject ["content"] = ui->contentTextEdit->toPlainText ();     // Устанавливаем содержание текста
    QJsonArray textsArray = m_currentJsonObject ["texts"].toArray (); // Забираем текущий массив текстов, даже если он не существует, он будет создан автоматически
    textsArray.append (textObject);                                   // Добавляем объект текста в массив
    m_currentJsonObject ["texts"] = textsArray;                       // Сохраняем массив обратно в текущий объект

    // Устанавливаем текст всего Json объекта в текстовое поле для проверки
    ui->jsonDocumentTextEdit->setText (QJsonDocument (m_currentJsonObject).toJson (QJsonDocument::Indented));
}

void MainWindow::onClearButtonClicked ()
{
    m_currentJsonObject = QJsonObject (); // Пересоздаём новый текущий QJsonObject
    ui->jsonDocumentTextEdit->clear ();   // Очищаем текстовое поле
    // Устанавливаем текст всего Json объекта в текстовое поле, чтобы увидеть, что это пустой объект.
    // Увидите следующее -> {}
    ui->jsonDocumentTextEdit->setText (QJsonDocument (m_currentJsonObject).toJson (QJsonDocument::Indented));
}

void MainWindow::onSaveButtonClicked ()
{
    // С помощью диалогового окна получаем имя файла с абсолютным путём
    QString saveFileName = QFileDialog::getSaveFileName (this, //
      tr ("Save Json File"),                                   //
      QString (),
      tr ("JSON (*.json)") //
    );
    QFileInfo fileInfo (saveFileName); // С помощью QFileInfo
    QDir::setCurrent (fileInfo.path ()); // установим текущую рабочую директорию, где будет файл, иначе может не заработать
    // Создаём объект файла и открываем его на запись
    QFile jsonFile (saveFileName);
    if (!jsonFile.open (QIODevice::WriteOnly)) {
        return;
    }

    // Записываем текущий объект Json в файл
    jsonFile.write (QJsonDocument (m_currentJsonObject).toJson (QJsonDocument::Indented));
    jsonFile.close (); // Закрываем файл
}

void MainWindow::onLoadButtonClicked ()
{
    // Выбираем файл
    QString openFileName = QFileDialog::getOpenFileName (this, tr ("Open Json File"), QString (), tr ("JSON (*.json)"));
    QFileInfo fileInfo (openFileName);   // С помощью QFileInfo
    QDir::setCurrent (fileInfo.path ()); // установим текущую рабочую директорию, где будет файл
    // Создаём объект файла и открываем его на чтение
    QFile jsonFile (openFileName);
    if (!jsonFile.open (QIODevice::ReadOnly)) {
        return;
    }

    // Считываем весь файл
    QByteArray saveData = jsonFile.readAll ();
    // Создаём QJsonDocument
    QJsonDocument jsonDocument (QJsonDocument::fromJson (saveData));
    // Из которого выделяем объект в текущий рабочий QJsonObject
    m_currentJsonObject = jsonDocument.object ();
    // Очищаем текстовое поле
    ui->jsonDocumentTextEdit->clear ();
    // И устанавливаем в проверочное текстовое поле содержимое Json объекта
    ui->jsonDocumentTextEdit->setText (QJsonDocument (m_currentJsonObject).toJson (QJsonDocument::Indented));
}
