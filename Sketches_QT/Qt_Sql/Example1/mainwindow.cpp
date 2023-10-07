#include "mainwindow.h"

#include <QDir>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto layout = new QVBoxLayout;

    auto mainwidget = new QWidget;
    auto button1 = new QPushButton("add row");
    auto button2 = new QPushButton("model");
    auto button3 = new QPushButton("query");
    m_Table = new QTableView;

    layout->addWidget(m_Table);
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    mainwidget->setLayout(layout);
    setCentralWidget(mainwidget);

    QObject::connect(button1, &QPushButton::clicked, this, &MainWindow::slotAddRecord);
    QObject::connect(button2, &QPushButton::clicked, this, &MainWindow::slotSubmit);
    QObject::connect(button3, &QPushButton::clicked, this, &MainWindow::slotQuery);
    connectDB();
}

void MainWindow::connectDB()
{
    qDebug() << __func__;

    for(const auto& driver: QSqlDatabase::drivers())
        qDebug() << "Driver available:" << driver;

    auto homepath = QDir::homePath();
    qDebug() << "Home path:" << homepath;

    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(homepath + QDir::separator() + "testDB.db");

    if(!db.isValid())
    {
        qWarning() << "DB not valid";
        return;
    }

    if(!db.open())
    {
        qWarning() << "DB not open";
        return;
    }

    qDebug() << "DB valid & open:" <<  db.databaseName();

    auto query = QSqlQuery(db);
    if(!query.exec("CREATE TABLE IF NOT EXISTS MyTable ( Firstname TEXT, Lastname TEXT, Telephone INT);"))
    {
        qWarning() << "ERROR at tabble creating:" << query.lastError().text().simplified();
        return;
    }

    auto model = new QSqlTableModel(this,db);
    model->setTable("MyTable");
    model->select();
    m_Table->setModel(model);

    for(const auto& table : db.tables())
        qDebug() << "table available:" << table;
}

void MainWindow::slotAddRecord()
{
    qDebug() << __func__;

    auto model = m_Table->model();
    int row = model->rowCount();
    if(model->insertRow(row))
        qDebug() << "row added";
    else
        qWarning() << "ERROR at row adding";
}

void MainWindow::slotSubmit()
{
    qDebug() << __func__;

    auto model = m_Table->model();
    int row = model->rowCount();

    if(model->insertRow(row))
        qDebug() << "row added";
    else
    {
        qWarning() << "ERROR at row adding";
        return;
    }

    model->setData(model->index(row, 0), "Семён");
    model->setData(model->index(row, 1), "Горбунков");
    model->setData(model->index(row, 2), "322223322");

    if(model->submit())
      qDebug() << "record submitted";
    else
    {
        qWarning() << "ERROR at record submitting";
        return;
    }
}

void MainWindow::slotQuery()
{
    qDebug() << __func__;

    auto db = QSqlDatabase::database();
    if(!db.isOpen())
    {
       qWarning() << "DB not open";
        return;
    }

    auto query = QSqlQuery(db);
    auto querytext = QString("INSERT INTO MyTable ( Firstname,  Lastname,  Telephone ) "
                             "VALUES ( 'Свирид', 'Голохвастов', 77885566 );");

    if(!query.exec(querytext))
    {
        qWarning() << "Query ERROR:" << query.lastError().text().simplified();
        return;
    }

    qDebug() << "query submitted";

    auto model = qobject_cast<QSqlTableModel*>(m_Table->model());
    if(model)
        model->select();
    else
        qWarning() << "model not present";
}

