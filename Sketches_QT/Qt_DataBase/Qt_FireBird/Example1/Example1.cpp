#include <QCoreApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QSqlRecord>
#include <QDir>

int main (int argc, char* argv [])
{
    QCoreApplication a (argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase ("QIBASE");

    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
    /// db.setHostName("localhost");
    // Путь до БД
    QString path_db = QCoreApplication::applicationDirPath () + QDir::separator () + "DB" + QDir::separator ();
    db.setDatabaseName (path_db + "test25.fdb");
    // Нормализовали путь
    path_db = QDir::cleanPath (path_db);
    // попытались соединиться
    if (db.open ()) {
        qDebug ("The database connection is open.");
        QStringList tablesDB (db.tables ());
        for (const QString& tables : tablesDB) {
            qDebug () << tables;
        }
    }
    else {
        qDebug () << db.lastError ().text ();
    }

    QSqlQuery sqlQuery (db); // создаем объект запроса
    QString query_str = "SELECT * FROM COUNTRY";
    sqlQuery.exec (query_str);

    QSqlRecord rec = sqlQuery.record ();

    if (sqlQuery.exec (query_str)) {
        qDebug () << query_str;
        qDebug () << "Number of columns: " << rec.count ();

        while (sqlQuery.next ()) {
            QString name = sqlQuery.value (0).toString ();

            name.replace (QString ("%20"), QString (" "));
            qDebug () << name;
        }
    }
    else {
        qDebug () << "Query Failed...";
    }

    db.close ();

    return a.exec ();
}
