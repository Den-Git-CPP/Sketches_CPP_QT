# Работа с базами данных
## Соединиться с базой :    
### Работа с базами данных MSQL
   db = QSqlDatabase::addDatabase("QMSQL");
   db.setHostName("127.0.0.1");
   db.setDatabaseName("test");
   db.setUserName("root");
   db.setPassword("12345");

### Работа с базами данных IBASE
  db = QSqlDatabase::addDatabase("QIBASE");
  db.setUserName("SYSDBA");
  db.setPassword("masterkey");
  db.setDatabaseName("G:\\test25.fdb");

## Выполнение инструкций SQL
### QSqlQuery SELECT
QSqlQuery query;
query.exec("SELECT name, salary FROM employee WHERE salary > 50000");

## Цикл, перебирающий все записи по порядку:
 while (query.next()) {
     QString name = query.value(0).toString();
     int salary = query.value(1).toInt();
     qDebug() << name << salary;
   }
### QSqlQuery INSERT
QSqlQuery query;
query.exec("INSERT INTO employee (id, name, salary) "
"VALUES (1001, 'Thad Beaumont', 65000)");

- синтаксис вставки значений: поименованые параметры и позиционные параметры.    
QSqlQuery query;
query.prepare("INSERT INTO employee (id, name, salary) "
          "VALUES (:id, :name, :salary)");
query.bindValue(":id", 1001);
query.bindValue(":name", "Thad Beaumont");
query.bindValue(":salary", 65000);
query.exec();

- вставка с помощью позиционного параметра     
QSqlQuery query;
query.prepare("INSERT INTO employee (id, name, salary) "
          "VALUES (?, ?, ?)");
query.addBindValue(1001);
query.addBindValue("Thad Beaumont");
query.addBindValue(65000);
query.exec();