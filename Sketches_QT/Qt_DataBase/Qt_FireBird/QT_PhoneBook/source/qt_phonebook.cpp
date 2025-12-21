#include "include/qt_phonebook.h"
#include "source/ui_qt_phonebook.h"

#include "include/add_dbf.h"
#include "source/ui_qt_phonebook.h"

QT_PhoneBook::QT_PhoneBook (QWidget* parent) : QMainWindow (parent), ui (new Ui::QT_PhoneBook)
{
    ui->setupUi (this);
    this->setWindowTitle ("Поиск по базе данных");
    db = QSqlDatabase::addDatabase ("QIBASE");
    connect_db ();
    model = new Model (this);

    alldata ();
    ui->tableView->setModel (model);
    model->setHeaderData (0, Qt::Horizontal, tr ("Имя"));
    model->setHeaderData (1, Qt::Horizontal, tr ("Телефон"));
    model->setHeaderData (2, Qt::Horizontal, tr ("Департамент"));

    ui->tableView->setSelectionBehavior (QAbstractItemView::SelectRows); // select a line

    ui->tableView->setFixedSize (1240, 470);
    ui->tableView->resizeColumnToContents (0);                                          // ширина столбцов по контенту
    ui->tableView->horizontalHeader ()->setSectionResizeMode (0, QHeaderView::Fixed);   // Фиксация ширины столбца
    ui->tableView->setColumnWidth (1, 180);                                             // ширина столбца
    ui->tableView->horizontalHeader ()->setSectionResizeMode (1, QHeaderView::Fixed);   // Фиксация ширины столбца
    ui->tableView->horizontalHeader ()->setSectionResizeMode (2, QHeaderView::Stretch); // Растгивание ширины столбца

    add_dbf=new Add_DBF();

}

QT_PhoneBook::~QT_PhoneBook ()
{
    // if (db.open ()) {
    //     db.close ();
    //     qDebug () << "The database connection is close.";
    // }
    delete ui;
}
void QT_PhoneBook::on_lineEdit_FIO_textChanged (const QString& arg1)
{
    //// проверка заглавности первой буквы
    QString tmp_arg = arg1;
    if (!arg1.isEmpty () &&                              // если arg1 не пуст и
        (ui->lineEdit_FIO->text ().first (1).isLower ()) // первая буква маленькая
    ) {
        tmp_arg = ui->lineEdit_FIO->text ().first (1).toUpper ();                   // переводим в вепхний регистр
        ui->lineEdit_FIO->setText (ui->lineEdit_FIO->text ().first (1).toUpper ()); // lineEdit_FIO первая буква верхний регистр
    }

    // выборка по ФИО
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "JOIN rphones ON rabonents.ID= rphones.abonid "
                        "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rabonents.NAME LIKE '"
                        + tmp_arg + "%' ORDER BY rabonents.NAME";

    model->setQuery (query_str);
}
void QT_PhoneBook::on_lineEdit_TlfNumber_textChanged (const QString& arg1)
{

    // выборка по ФИО
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "LEFT JOIN rphones ON rabonents.ID= rphones.abonid "
                        "LEFT JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rphones.PHONE LIKE '%"
                        + arg1 + "%' ORDER BY rabonents.NAME";

    model->setQuery (query_str);
}

void QT_PhoneBook::connect_db ()
{ //
  // Путь до БД

    path_SettingsFile = QApplication::applicationDirPath () + QDir::separator () + "Settings.ini";
label1:
    QFile file (path_SettingsFile);

    if (file.exists ()) {
        qDebug () << "File exists!";
        readSettings ();
        // Теперь можно безопасно попробовать открыть и работать с файлом
    }
    else {
        path_SettingsFile = QFileDialog::getOpenFileName (this, "Open", QApplication::applicationDirPath (), "Settings(*.ini)");
        goto label1;
    }
    // подключаемся
    db.setUserName (USERNAME);
    db.setPassword (PASSWORD);
    db.setDatabaseName (DATABASENAME);
    writeSettings ();

    // контроль ошибок при подключении
    if (db.open ()) {
        ui->statusbar->showMessage ("The database connection is open.", 20000);
        qDebug () << "The database connection is open.";
    }
    else {
        ui->statusbar->showMessage (db.lastError ().text (), 20000);
        // qDebug () << "ERROR:" << db.lastError ().QSqlError::nativeErrorCode ().toStdString ();
        // qDebug () << "ERROR:" << db.lastError ().text ();
        qDebug () << "ERROR:" << db.lastError ().driverText ();
        if (db.lastError ().driverText () == "Error opening database") {
            QString path_db = QApplication::applicationDirPath () + QDir::separator () + "DB" + QDir::separator ();
            DATABASENAME    = QFileDialog::getOpenFileName (this, "Укажите файл базы данных", path_db, "Firebird (*.FDB)");
            QSettings settings (path_SettingsFile, QSettings::IniFormat);
            settings.beginGroup ("DatabaseDefaultValue");
            settings.setValue ("DATABASENAME", DATABASENAME);
            settings.endGroup ();
            writeSettings ();
            goto label1;
        }
    };
    //
}

void QT_PhoneBook::alldata ()
{ // всех данныхх
    work_with_query ("");
}

void QT_PhoneBook::work_with_query (const QString& query_str)
{
    QSqlQuery query (db);

    if (!query_str.isEmpty ()) {
        // данные по запросу
        query.prepare (query_str);
    }
    else {
        // все данные если запрос пустой
        query.prepare ("SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                       "FROM rabonents "
                       "JOIN rphones ON rabonents.ID= rphones.abonid "
                       "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                       "ORDER BY rabonents.NAME");
    }
    query.exec (); // запросили

    int num{ 0 };
    while (query.next ()) {
         map_init_ComboBox->insert(query.value ("rgroups.NAME").toUrl ().toString (),num++);
       // qDebug()<<query.value ("rgroups.NAME").toUrl ().toString ();
    }

    if (ui->comboBox->count () == 0) {
        // если comboBox
        foreach (QString key, map_init_ComboBox->keys ()) { // заполнили ComboBox из QMap
            ui->comboBox->addItem (key);
          //   int value= map_init_ComboBox->value(key);
          //    qDebug() << key << ":" << value;
        }
    }

    // перенсли данные в Model
    model->setQuery (std::move (query));
}

void QT_PhoneBook::writeSettings ()
{
    QSettings settings (QApplication::applicationDirPath () + QDir::separator () + "Settings.ini", // default place Settings.ini
      QSettings::IniFormat);
    settings.beginGroup ("DatabaseDefaultValue");
    settings.setValue ("USERNAME", USERNAME);
    settings.setValue ("PASSWORD", PASSWORD);
    settings.setValue ("DATABASENAME", DATABASENAME);
    settings.endGroup ();
}

void QT_PhoneBook::readSettings ()
{
    QSettings settings (path_SettingsFile, QSettings::IniFormat);
    settings.beginGroup ("DatabaseDefaultValue");
    USERNAME     = settings.value ("USERNAME", "").toString ();
    PASSWORD     = settings.value ("PASSWORD", "").toString ();
    DATABASENAME = settings.value ("DATABASENAME", "").toString ();
    settings.endGroup ();
}

void QT_PhoneBook::on_comboBox_textActivated (const QString& arg1)
{
    // забрали текст из ComboBox
    // создали аргумент запроса из поля
    // если номер группы<10 и != 0 тогда прибавляем нолик спереди для правильного запроса
    QString arg1_correct{ arg1 };

    // вставили в запрос для выборки по департаменту
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "LEFT JOIN rphones ON rabonents.ID= rphones.abonid "
                        "LEFT JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rgroups.NAME= '"
                        + arg1_correct.replace (QString (" "), QString ("%20")) + "' ORDER BY rabonents.NAME";
    model->setQuery (query_str);
}

void QT_PhoneBook::on_action_triggered()
{
    add_dbf->show();
}

