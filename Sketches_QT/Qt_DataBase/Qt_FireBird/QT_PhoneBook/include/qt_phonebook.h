#pragma once

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
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

  private:
    Ui::QT_PhoneBook* ui;
    QSqlDatabase db;
};
