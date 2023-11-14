#include "include/qt_phonebook.h"
#include "source/ui_qt_phonebook.h"

QT_PhoneBook::QT_PhoneBook (QWidget* parent) : QMainWindow (parent), ui (new Ui::QT_PhoneBook)
{
    ui->setupUi (this);
    this->setWindowTitle ("Поиск по базе данных");

    // ui->tableView->setFixedSize (ui->centralwidget->width (), ui->centralwidget->height ());
    connect_db ();             // подключили БД
    update_date_in_model (""); // инициализировали Модель

    model->setHeaderData (0, Qt::Horizontal, tr ("Имя"));
    model->setHeaderData (1, Qt::Horizontal, tr ("Телефон"));
    model->setHeaderData (2, Qt::Horizontal, tr ("Департамент"));
    ui->tableView->setSelectionBehavior (QAbstractItemView::SelectRows); // select a line
    ui->tableView->setModel (model);
    // ui->tableView->setFixedSize (1240, 470);
    ui->tableView->resizeColumnToContents (0);                                          // ширина столбцов по контенту
    ui->tableView->horizontalHeader ()->setSectionResizeMode (0, QHeaderView::Fixed);   // Фиксация ширины столбца
    ui->tableView->setColumnWidth (1, 180);                                             // ширина столбца
    ui->tableView->horizontalHeader ()->setSectionResizeMode (1, QHeaderView::Fixed);   // Фиксация ширины столбца
    ui->tableView->horizontalHeader ()->setSectionResizeMode (2, QHeaderView::Stretch); // Растгивание ширины столбца
}

QT_PhoneBook::~QT_PhoneBook ()
{
    delete ui;
    if (db.open ()) {
        db.close ();
        qDebug () << "The database connection is close.";
    }
}
void QT_PhoneBook::on_lineEdit_FIO_textChanged (const QString& arg1)
{
    // проверка заглавности первой буквы
    QString tmp_arg = arg1;
    if (!arg1.isEmpty () &&                                                         // если arg1 не пуст и
        (ui->lineEdit_FIO->text ().first (1).isLower ())                            // первая буква маленькая
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

    update_date_in_model (query_str);
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

    update_date_in_model (query_str);
}

void QT_PhoneBook::connect_db ()
{ // подключили БД
    db = QSqlDatabase::addDatabase ("QIBASE");
    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
    db.setDatabaseName ("C:\\test_rpr.fdb");
    // контроль ошибок при подключении
    if (db.open ()) {
        ui->statusbar->showMessage ("The database connection is open.", 2000);
        qDebug () << "The database connection is open.";
    }
    else {
        ui->statusbar->showMessage (db.lastError ().text (), 2000);
        qDebug () << db.lastError ().text ();
    };
}

QString QT_PhoneBook::StringRequestAllData ()
{
    return "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
           "FROM rabonents "
           "JOIN rphones ON rabonents.ID= rphones.abonid "
           "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
           "ORDER BY rabonents.NAME";
}

void QT_PhoneBook::update_date_in_model (const QString& query_string)
{
    QSqlQuery query (db);

    if (!query_string.isEmpty ()) {
        // данные по запросу
        query.prepare (query_string);
    }
    else {
        // все данные если запрос пустой
        query.prepare (StringRequestAllData ());
    }
    query.exec (); // запросили

    int num{ 0 };
    while (query.next ()) {
        map_init_ComboBox->insert (query.value ("rgroups.NAME").toUrl ().toString (), num++);
    }

    if (ui->comboBox->count () == 0) {
        // если comboBox
        foreach (QString key, map_init_ComboBox->keys ()) { // заполнили ComboBox из QMap
            ui->comboBox->addItem (key);
            // int value= map_init_ComboBox->value(key);
            //  qDebug() << key << ":" << value;
        }
    }
    // перенсли данные в Model
    model->setQuery (std::move (query));
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
    update_date_in_model (query_str);
}
