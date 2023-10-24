#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  db = QSqlDatabase::addDatabase("QIBASE");
  db.setUserName("SYSDBA");
  db.setPassword("masterkey");
  db.setDatabaseName("G:\\test25.fdb");
  /// db.setHostName("localhost");

  // db = QSqlDatabase::addDatabase("QMSQL");
  // db.setHostName("127.0.0.1");
  // db.setDatabaseName("test");
  // db.setUserName("root");
  // db.setPassword("12345");

  if (db.open()) {
    qDebug("The database connection is open.");
  } else {
    qDebug() << db.lastError().text();
  };
}

Widget::~Widget() { delete ui; }

void Widget::on_pushButton_clicked() {
  QSqlQuery q = QSqlQuery(db);
  QString q_str{"SELECT * FROM COUNTRY"};
  // обработка ошибок
  if (!q.exec(q_str)) {
    qDebug() << db.lastError().databaseText();
    qDebug() << db.lastError().driverText();
    return;
  }
  while (q.next()) {
    qDebug() << q.record();
  }
}
