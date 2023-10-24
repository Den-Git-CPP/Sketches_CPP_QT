#include "include/qt_phonebook.h"
#include "./ui_qt_phonebook.h"

QT_PhoneBook::QT_PhoneBook (QWidget* parent) : QMainWindow (parent), ui (new Ui::QT_PhoneBook)
{
    ui->setupUi (this);
    this->setWindowTitle ("Поиск по базе данных");
}

QT_PhoneBook::~QT_PhoneBook ()
{
    delete ui;
}
