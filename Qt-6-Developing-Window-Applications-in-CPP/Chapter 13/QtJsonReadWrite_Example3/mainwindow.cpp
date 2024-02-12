#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{
    ui->setupUi (this);
    // Метод1
    connect (ui->createButton, &QPushButton::clicked, this, &MainWindow::createJsonFile_1);
    connect (ui->readButton, &QPushButton::clicked, this, &MainWindow::readJsonFile_1);
    connect (ui->writeButton, &QPushButton::clicked, this, &MainWindow::writeJsonFile_1);
    // Метод2
    connect (ui->createButton_2, &QPushButton::clicked, this, &MainWindow::createJsonFile_2);
    connect (ui->readButton_2, &QPushButton::clicked, this, &MainWindow::readJsonFile_2);
    connect (ui->writeButton_2, &QPushButton::clicked, this, &MainWindow::writeJsonFile_2);
}

MainWindow::~MainWindow ()
{
    delete ui;
}

void MainWindow::createJsonFile_1 ()
{ // Чтобы создать JSON-файл с помощью QJsonDocument
    // Step 1: Создайте QJsonObject и добавьте к нему пары ключ-значение.
    QJsonObject jsonObject;
    jsonObject ["name"] = "John";
    jsonObject ["age"]  = 30;
    jsonObject ["city"] = "New York";

    // Step 2: Создайте QJsonDocument с помощью QJsonObject.
    QJsonDocument jsonDocument (jsonObject);

    // Step 3: Запишите QJsonDocument в файл.
    QFile file ("./resource/example1.json");
    file.open (QIODevice::WriteOnly);
    file.write (jsonDocument.toJson ());
    file.close ();
}

void MainWindow::readJsonFile_1 ()
{ // Чтение JSON-файлов с помощью QJsonDocument
    // Step 1: Считайте JSON-файл в QByteArray
    QFile file ("./resource/example1.json");
    file.open (QIODevice::ReadOnly);
    QByteArray jsonData = file.readAll ();
    file.close ();

    // Step 2: Создайте QJsonDocument с помощью QByteArray.
    QJsonDocument jsonDocument = QJsonDocument::fromJson (jsonData);

    // Step 3: Извлеките QJsonObject из QJsonDocument .
    QJsonObject jsonObject = jsonDocument.object ();

    // Доступ к значениям values в обьекте QJsonObject.
    QString name = jsonObject ["name"].toString ();
    int age      = jsonObject ["age"].toInt ();
    QString city = jsonObject ["city"].toString ();
    qDebug () << "name:\t" << name << "\nage:\t" << age << "\ncity:\t" << city;
}

void MainWindow::writeJsonFile_1 ()
{
    // Step 1: Считайте JSON-файл в QByteArray.
    QFile file ("./resource/example1.json");
    file.open (QIODevice::ReadOnly);
    QByteArray jsonData = file.readAll ();
    file.close ();

    // Step 2: Создайте QJsonDocument с помощью QByteArray.
    QJsonDocument jsonDocument = QJsonDocument::fromJson (jsonData);

    // Step 3: Измените QJsonObject.
    QJsonObject jsonObject = jsonDocument.object ();
    jsonObject ["city"]    = "Los Angeles";

    // Step 4: Создайте новый QJsonDocument, используя измененный QJsonObject.
    QJsonDocument newJsonDocument (jsonObject);

    // Step 5: Запишите новый QJsonDocument в файл.
    file.open (QIODevice::WriteOnly);
    file.write (newJsonDocument.toJson ());
    file.close ();
}

void MainWindow::createJsonFile_2 ()
{ // create a JSON object
    QJsonObject person;
    person ["name"] = "John";
    person ["age"]  = 30;
    person ["city"] = "New York";

    // create a JSON array
    QJsonArray hobbies;
    hobbies.append ("reading");
    hobbies.append ("traveling");
    hobbies.append ("photography");

    // add the array to the object
    person ["hobbies"] = hobbies;

    // create a JSON document
    QJsonDocument doc (person);

    // write the document to a file
    QFile file ("./resource/person1.json");
    if (file.open (QIODevice::WriteOnly)) {
        file.write (doc.toJson ());
        file.close ();
    }
}

void MainWindow::readJsonFile_2 ()
{
    // read the JSON file into a QByteArray
    QFile file ("./resource/person1.json");
    if (file.open (QIODevice::ReadOnly)) {
        QByteArray data = file.readAll ();
        file.close ();

        // parse the JSON document
        QJsonDocument doc = QJsonDocument::fromJson (data);

        // get the root object
        QJsonObject person = doc.object ();

        // get the values
        QString name = person ["name"].toString ();
        int age      = person ["age"].toInt ();
        QString city = person ["city"].toString ();
        qDebug () << "name:\t" << name << "\nage:\t" << age << "\ncity:\t" << city;

        // get the hobbies array
        QJsonArray hobbies = person ["hobbies"].toArray ();

        // iterate over the array
        foreach (const QJsonValue& value, hobbies) {
            QString hobby = value.toString ();
            // do something with the hobby
            qDebug () << hobby;
        }
    }
}

void MainWindow::writeJsonFile_2 ()
{
    // read the JSON file into a QByteArray
    QFile file ("person.json");
    if (file.open (QIODevice::ReadOnly)) {
        QByteArray data = file.readAll ();
        file.close ();

        // parse the JSON document
        QJsonDocument doc = QJsonDocument::fromJson (data);

        // get the root object
        QJsonObject person = doc.object ();

        // modify the values
        person ["age"]  = 31;
        person ["city"] = "San Francisco";

        // add a new hobby to the array
        QJsonArray hobbies = person ["hobbies"].toArray ();
        hobbies.append ("cooking");
        person ["hobbies"] = hobbies;

        // create a new document
        QJsonDocument newDoc (person);

        // write the document to a file
        if (file.open (QIODevice::WriteOnly)) {
            file.write (newDoc.toJson ());
            file.close ();
        }
    }
}
