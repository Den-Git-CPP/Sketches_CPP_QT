#pragma once

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QWidget>
#include <Qstring>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void on_pushButton_Select_All_clicked();

private:
  Ui::Widget *ui;
  QSqlDatabase db;
  QSqlTableModel *model;
};
