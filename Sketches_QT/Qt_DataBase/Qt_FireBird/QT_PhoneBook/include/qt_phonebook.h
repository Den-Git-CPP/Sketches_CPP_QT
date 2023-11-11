#pragma once

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QMap>
#include <QDebug>
#include <QUrl>
#include "model.h"

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

  private:
    Ui::QT_PhoneBook* ui;
    QSqlDatabase db;
    Model* model = new Model (this); // унаследован от QSqlTableModel с переопределением метода data
    QMap<QString,int>* map_init_ComboBox = new QMap<QString,int>; // QMap для сортировки и заполнения ComBox
    void connect_db ();
    void update_date_in_model (const QString& query_string);

    QString StringRequestAllData ();
};
