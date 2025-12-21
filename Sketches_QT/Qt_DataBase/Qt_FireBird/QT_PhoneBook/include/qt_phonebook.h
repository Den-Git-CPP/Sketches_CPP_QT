#pragma once

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QString>
#include <QMap>
#include <QDebug>
#include <QUrl>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QSettings>
#include "model.h"
#include "add_dbf.h"
namespace Ui {
    class QT_PhoneBook;
}

class QT_PhoneBook : public QMainWindow {
    Q_OBJECT

  public:
    explicit QT_PhoneBook (QWidget* parent = nullptr);
    ~QT_PhoneBook ();

  private slots:
    void on_lineEdit_FIO_textChanged (const QString& arg1);
    void on_lineEdit_TlfNumber_textChanged (const QString& arg1);

    void on_comboBox_textActivated (const QString& arg1);

    void on_action_triggered();

  private:
    Ui::QT_PhoneBook* ui;
    QString path_SettingsFile{ "" };
    QString USERNAME{ "" };
    QString PASSWORD{ "" };
    QString DATABASENAME{ "" };

    QSqlDatabase db;
    Model* model;
    QMap<QString, int>* map_init_ComboBox = new QMap<QString, int>; // QMap для сортировки и заполнения ComBox

    Add_DBF* add_dbf;

    void connect_db ();
    void alldata ();
    void work_with_query (const QString& query_str);
    void writeSettings ();
    void readSettings ();
};
