#include "include/qt_phonebook.h"
#include "source/ui_qt_phonebook.h"

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
        qDebug () << "The database connection is open.";
    }
    else {
        ui->statusbar->showMessage (db.lastError ().text (), 2000);
        qDebug () << db.lastError ().text ();
    };

    model_SqlQuery = new QSqlQueryModel (this);
    model_SqlQuery->setQuery ("SELECT COUNTRY, CURRENCY FROM COUNTRY ORDER BY COUNTRY", db);
    model_SqlQuery->setHeaderData (0, Qt::Horizontal, tr ("Страна"));
    model_SqlQuery->setHeaderData (1, Qt::Horizontal, tr ("Валюта"));
    ui->tableView->setModel (model_SqlQuery);

    // // Модель данных
    // model = new QSqlTableModel (this, db);
    // model->setEditStrategy (QSqlTableModel::OnManualSubmit);
    // model->setTable ("COUNTRY");
    // model->select ();

    // ui->tableView->setModel (model);
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
    QString query_str{};

    if (!ui->lineEdit_FIO->text ().isEmpty ()) {
        query_str = "SELECT COUNTRY,CURRENCY "          //
                    "FROM COUNTRY WHERE COUNTRY LIKE '" //
                    + arg1 +                            //
                    "%' ORDER BY COUNTRY";
        qDebug () << query_str;
    }
    else {
        query_str = "SELECT COUNTRY, CURRENCY FROM COUNTRY ORDER BY COUNTRY";
    };
    model_SqlQuery->setQuery (query_str, db);
    ui->tableView->setModel (model_SqlQuery);
}
