#pragma once

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
// #include <QSqlTableModel>
#include <QSqlQueryModel>
#include <Qstring>
#include <QDebug>

namespace Ui {
    class QT_PhoneBook;
}

class QT_PhoneBook : public QMainWindow {
    Q_OBJECT

  public:
    QT_PhoneBook (QWidget* parent = nullptr);
    ~QT_PhoneBook ();

  private slots:

    void on_lineEdit_FIO_textChanged (const QString& arg1);

  private:
    Ui::QT_PhoneBook* ui;
    QSqlDatabase db;
    // QSqlTableModel* model;
    QSqlQueryModel* model_SqlQuery;
};
