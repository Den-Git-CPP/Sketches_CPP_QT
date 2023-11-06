#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent), ui (new Ui::MainWindow)
{

    ui->setupUi (this);
    ///------------------
    // подключили БД
    /*  ==================== 1 СПОСОБ================
   db = QSqlDatabase::addDatabase ("QIBASE");
   db.setUserName ("SYSDBA");
   db.setPassword ("masterkey");

   //   db.setUserName ("admin");
   //   db.setPassword ("12345");
   db.setDatabaseName ("C:\test_rpr.fdb");
    */
    /*  ==================== 2 СПОСОБ================
    // Set database configurations.;
    QString filePath          = "C:\test_rpr.fdb";
    QString userName          = "SYSDBA";
    QString password          = "masterkey";
    QString connectionString_ = "server type=Embedded; auto_commit=True; auto_commit_level=4096; connection lifetime=1; DataBase=\"%1\"";
    db                        = QSqlDatabase::addDatabase ("QIBASE");
    db.setDatabaseName (filePath);
    db.setUserName (userName);
    db.setPassword (password);

    QString connectionString = QString (connectionString_).arg (filePath);
    db.setConnectOptions (connectionString);
   */

    // const QString hostName      = "";
    const QString dbFileName    = "C:\\test_rpr.fdb";
    const QString userName      = "SYSDBA";
    const QString password      = "masterkey";
    const QString serverType    = "1";
    const QString clientLibrary = QString ("C:\\QTPROJECT\\build-untitled-MinGW_11_2_0_64-Debug\\fbclient.dll");

    QSqlDatabase db = QSqlDatabase::addDatabase ("QIBASE", "Connection_1");

    if (!db.isValid ()) {
        ui->label->setText (db.lastError ().text ());
    }
    else {
        ui->label->setText ("The database is valid.");
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
                            .arg (clientLibrary));

    //-----------------------------DEBUG-------------------
    if (db.open ()) {
        qDebug () << "The database connection is open.";
        ui->label_2->setText ("The database connection is open.");
    }
    else {
        ui->label_2->setText ("ERROR!!:" + db.lastError ().text () + "\n" + db.lastError ().nativeErrorCode ());
        qDebug () << db.lastError ().text ();
    };
    //////////-----------------
}

MainWindow::~MainWindow ()
{
    delete ui;
}
