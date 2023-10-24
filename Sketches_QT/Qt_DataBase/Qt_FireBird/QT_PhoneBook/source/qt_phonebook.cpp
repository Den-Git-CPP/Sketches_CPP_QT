#include "include/qt_phonebook.h"
#include "./ui_qt_phonebook.h"

QT_PhoneBook::QT_PhoneBook (QWidget* parent) : QMainWindow (parent), ui (new Ui::QT_PhoneBook)
{
    ui->setupUi (this);
    this->setWindowTitle ("Поиск по базе данных");

    // подключили БД
    db = QSqlDatabase::addDatabase ("QIBASE");
    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
    db.setDatabaseName ("G:\\ProjectQT\\QT_PhoneBook\\resources\\test25.fdb");
    // контроль ошибок при подключении
    if (db.open ()) {
        ui->statusbar->showMessage ("The database connection is open.", 2000);
        qDebug ("The database connection is open.");
    }
    else {
        ui->statusbar->showMessage (db.lastError ().text (), 2000);
        ui->statusbar->showMessage (db.lastError ().text (), 2000);

        qDebug () << db.lastError ().text ();
    };
}

QT_PhoneBook::~QT_PhoneBook ()
{
    delete ui;
}
