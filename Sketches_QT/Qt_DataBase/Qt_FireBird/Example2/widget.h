#pragma once

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QWidget>
#include <Qstring>
#include <QDir>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

  public:
    Widget (QWidget* parent = nullptr);
    ~Widget ();

  private slots:
    void on_pushButton_Select_All_clicked ();

    void on_pushButton_Sumit_clicked ();

    void on_pushButton_Revert_clicked ();

    void on_pushButton_Reselect_clicked ();

    void on_pushButton_AddRow_clicked ();

    void on_pushButton_DelRow_clicked ();

  private:
    Ui::Widget* ui;
    QSqlDatabase db;
    QSqlTableModel* model;
    QSqlQueryModel* model2;
};
