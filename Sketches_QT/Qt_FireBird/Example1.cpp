#include <QCoreApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QSqlRecord>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  QSqlDatabase db = QSqlDatabase::addDatabase("QIBASE");

  db.setUserName("SYSDBA");
  db.setPassword("masterkey");
 /// db.setHostName("localhost");
  db.setDatabaseName("G:\\test.fdb");
  
  if (db.open()){
      qDebug("The database connection is open.");
  }else{
     qDebug() << db.lastError().text();
  }

  QSqlQuery sqlQuery(db);/cсоздаем объект запроса
  QString query_str="SELECT RABONENTS.NAME FROM RABONENTS ORDER BY NAME";
//  QString query_str="SELECT * FROM RABONENTS";

  //sqlQuery.exec(query_str);
  QSqlRecord rec = sqlQuery.record();

  if(sqlQuery.exec(query_str)){
     qDebug() << query_str ;
     qDebug() << "Number of columns: " << rec.count();

     while (sqlQuery.next()) {
         QString name = sqlQuery.value(0).toString();

         name.replace(QString("%20"), QString(" "));
         qDebug() << name ;
     }

  }
  else{
     qDebug() << "Query Failed...";
  }

  db.close();
  return a.exec();
}
