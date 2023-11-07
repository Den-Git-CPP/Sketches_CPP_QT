#include "include/qt_phonebook.h"
#include "source/ui_qt_phonebook.h"

#include <QList>

QT_PhoneBook::QT_PhoneBook (QWidget* parent) : QMainWindow (parent), ui (new Ui::QT_PhoneBook)
{
    ui->setupUi (this);
    this->setWindowTitle ("Поиск по базе данных");

    // ui->tableView->setFixedSize (ui->centralwidget->width (), ui->centralwidget->height ());
    connect_db ();             // подключили БД
    update_date_in_model (""); // инициализировали Модель

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
{
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "JOIN rphones ON rabonents.ID= rphones.abonid "
                        "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rabonents.NAME LIKE '"
                        + arg1 + "%' ORDER BY rabonents.NAME";

    update_date_in_model (query_str);
}

void QT_PhoneBook::connect_db ()
{ // подключили БД
    db = QSqlDatabase::addDatabase ("QIBASE");
    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
    db.setDatabaseName ("G:\\ProjectQT\\QT_PhoneBook\\resources\\test_rpr.fdb");
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

QString QT_PhoneBook::StringRequestAllData ()
{
    return "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
           "FROM rabonents "
           "JOIN rphones ON rabonents.ID= rphones.abonid "
           "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
           "ORDER BY rabonents.NAME";
}

void QT_PhoneBook::update_date_in_model (const QString& query_string)
{
    QSqlQuery query (db);
    query.prepare (StringRequestAllData ());

    if (!query_string.isEmpty ()) {
        query.prepare (query_string);
    }
    else {
        query.prepare (StringRequestAllData ());
    }
    query.exec ();
    model->setQuery (std::move (query));
}
