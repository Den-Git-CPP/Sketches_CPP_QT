#include "include/qt_phonebook.h"
#include "source/ui_qt_phonebook.h"

#include <QList>

QT_PhoneBook::QT_PhoneBook (QWidget* parent) : QMainWindow (parent), ui (new Ui::QT_PhoneBook)
{
    ui->setupUi (this);
    this->setWindowTitle ("Поиск по базе данных");

    // ui->tableView->setFixedSize (ui->centralwidget->width (), ui->centralwidget->height ());
    connect_db (); // подключили БД
    init_model (); // инициализировали Модель

    model->setHeaderData (0, Qt::Horizontal, tr ("Имя"));
    model->setHeaderData (1, Qt::Horizontal, tr ("Телефон"));
    model->setHeaderData (2, Qt::Horizontal, tr ("Департамент"));
    ui->tableView->horizontalHeader ()->setStretchLastSection (true);
    ui->tableView->setModel (model);
}

QT_PhoneBook::~QT_PhoneBook ()
{
    delete ui;
    if (db.open ()) {
        db.close ();
        qDebug () << "The database connection is close.";
    }
}

void QT_PhoneBook::on_lineEdit_FIO_textChanged (const QString& arg1)
{ // выборка по ФИО
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "JOIN rphones ON rabonents.ID= rphones.abonid "
                        "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rabonents.NAME LIKE '"
                        + arg1 + "%' ORDER BY rabonents.NAME";

    update_date_in_model (query_str);
}

void QT_PhoneBook::on_lineEdit_TlfNumber_textChanged (const QString& arg1)
{ // выборка по номеру телефона
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "JOIN rphones ON rabonents.ID= rphones.abonid "
                        "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rphones.PHONE LIKE '%"
                        + arg1 + "%' ORDER BY rphones.PHONE";

    update_date_in_model (query_str);
}

void QT_PhoneBook::connect_db ()
{
    // подключили БД
    //db = QSqlDatabase::addDatabase ("QIBASE");
    //db.setUserName ("SYSDBA");
    //db.setPassword ("masterkey");
    //db.setDatabaseName ("E:\\ProjectQT\\QT_PhoneBook\\resources\\test_rpr.fdb");
    

    // const QString hostName      = "";
    const QString dbFileName = "C:\\test_rpr.fdb";
    const QString userName   = "SYSDBA";
    const QString password   = "masterkey";
    const QString serverType = "1";
    //   const QString clientLibrary = QString ("C:\\QTPROJECT\\build-untitled-MinGW_11_2_0_64-Debug\\fbclient.dll");
    QSqlDatabase db = QSqlDatabase::addDatabase ("QIBASE", "Connection_1");
    if (!db.isValid ()) {
        qDebug () << db.lastError ().text ();
    }
    else {
        qDebug () << "The database is valid.";
    }
    // db.setHostName (hostName);
    db.setDatabaseName (dbFileName);
    db.setUserName (userName);
    db.setPassword (password);
    db.setConnectOptions (QString ("Database=%1;"
                                   "User=%2;"
                                   "Password=%3;"
                                   "ServerType=%4;"
                                   "ClientLibrary=%5;")
                            .arg (dbFileName)
                            .arg (userName)
                            .arg (password)
                            .arg (serverType)
      //  .arg (clientLibrary)
    );

    // контроль ошибок при подключении
    if (db.open ()) {
        ui->statusbar->showMessage ("The database connection is open.", 2000);
        qDebug () << "The database connection is open.";
    }
    else {
        ui->statusbar->showMessage (db.lastError ().text (), 2000);
        qDebug () << db.lastError ().text ();
    };
}

void QT_PhoneBook::init_model ()
{ // Модель данных
    model->setQuery ("SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                     "FROM rabonents "
                     "JOIN rphones ON rabonents.ID= rphones.abonid "
                     "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                     "ORDER BY rabonents.NAME",
      db);

    //    QSqlQuery query ("SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
    //                     "FROM rabonents "
    //                     "JOIN rphones ON rabonents.ID= rphones.abonid "
    //                     "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
    //                     "ORDER BY rabonents.NAME",
    //      db);
    //    query.exec ();
    //    model->setQuery (query);
}

void QT_PhoneBook::update_date_in_model (const QString& query_string)
{
    if (!query_string.isEmpty ()) {
        model->setQuery (query_string, db);
    }
    else {
        model->setQuery ("SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                         "FROM rabonents "
                         "JOIN rphones ON rabonents.ID= rphones.abonid "
                         "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                         "ORDER BY rabonents.NAME",
          db);
    }
}
