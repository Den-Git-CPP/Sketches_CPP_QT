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
{ // выборка по ФИО
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "JOIN rphones ON rabonents.ID= rphones.abonid "
                        "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rabonents.NAME LIKE '"
                        + arg1 + "%' ORDER BY rabonents.NAME";

    update_date_in_model (query_str);
}
void QT_PhoneBook::on_lineEdit_TlfNumber_textChanged (const QString& arg1)
{
    // выборка по ФИО
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "JOIN rphones ON rabonents.ID= rphones.abonid "
                        "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rphones.PHONE LIKE '%"
                        + arg1 + "%' ORDER BY rabonents.NAME";

    update_date_in_model (query_str);
}

void QT_PhoneBook::connect_db ()
{ // подключили БД
    db = QSqlDatabase::addDatabase ("QIBASE");
    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
    db.setDatabaseName ("G:\\ProjectQT\\QT_PhoneBook\\resources\\test_rpr.fdb");
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

    while (query.next ()) {
        // пока есть значение Query  заполняем Map
        map_init_ComboBox->insert (query.value ("rgroups.NAME").toString ().section (".", 0, 0).toInt (), // номер департмента
          query.value ("rgroups.NAME").toString ().section (".", 1, 1).replace (QString ("%20"), QString (" ")).trimmed () // название департамента
        );
    }

    // заполнили отсортированный map_init_ComboBox
    foreach (int key, map_init_ComboBox->keys ()) {
        ui->comboBox->addItem (QString::number (key) + " " + map_init_ComboBox->value (key));
    }

    // перенсли данные в Model
    model->setQuery (std::move (query));
}

void QT_PhoneBook::on_comboBox_textActivated (const QString& arg1)
{
    QString Str_arg{ arg1.split (' ').first () }; // забрали текст из ComboBox
    // создали аргумент запроса из поля
    // если номер группы<10 и != 0 тогда прибавляем нолик спереди для правильного запроса
    if ((Str_arg.toInt () != 0) and (Str_arg.toInt () < 10)) {
        Str_arg.prepend ("0");
    }
    Str_arg.append (".");

    // вставили в запрос для выборки по департаменту
    QString query_str = "SELECT rabonents.NAME, rphones.PHONE, rgroups.NAME "
                        "FROM rabonents "
                        "JOIN rphones ON rabonents.ID= rphones.abonid "
                        "JOIN rgroups ON rabonents.GROUPID= rgroups.id "
                        "WHERE rgroups.NAME LIKE '"
                        + Str_arg
                        + "%' "
                          "ORDER BY rabonents.NAME ";
    update_date_in_model (query_str);
}
