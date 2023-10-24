#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  // db = QSqlDatabase::addDatabase("QMSQL");
  // db.setHostName("127.0.0.1");
  // db.setDatabaseName("test");
  // db.setUserName("root");
  // db.setPassword("12345");
  // 1. Подключил базу
  db = QSqlDatabase::addDatabase("QIBASE");
  db.setUserName("SYSDBA");
  db.setPassword("masterkey");
  db.setDatabaseName("G:\\test25.fdb");
  // 2. Проверил на соединение
  if (db.open()) {
    qDebug("The database connection is open.");
  } else {
    qDebug() << db.lastError().text();
  };
  // 7.Создали модель данных
  model = new QSqlTableModel(this, db);
  model->setEditStrategy(
      QSqlTableModel::OnManualSubmit); // стратегия изменения в таблице
  model->setTable("COUNTRY");
  model->select();

  // 8.Соединили с отображением
  ui->tableView->setModel(model);
  ui->comboBox->setModel(model);
  ui->comboBox->setModelColumn(1);
}

Widget::~Widget() { delete ui; }

void Widget::on_pushButton_Select_All_clicked() {
  // 3.Создал обьект запроса
  QSqlQuery q = QSqlQuery(db);
  // 4. Создал строку запроса
  QString q_str{"SELECT * FROM COUNTRY"};
  // 5. Если ошибки при выполнении запроса
  if (!q.exec(q_str)) {
    qDebug() << db.lastError().databaseText();
    qDebug() << db.lastError().driverText();
    return;
  }
  // 6. Выводим все записи согласно запроса SELECT * FROM COUNTRY
  while (q.next()) {
    qDebug() << q.record();
  }
}

void Widget::on_pushButton_Sumit_clicked() {
  model->submitAll(); // подтверждение изменений в таблице
}

void Widget::on_pushButton_Revert_clicked() {
  model->revertAll(); // откатить все обратно
}
