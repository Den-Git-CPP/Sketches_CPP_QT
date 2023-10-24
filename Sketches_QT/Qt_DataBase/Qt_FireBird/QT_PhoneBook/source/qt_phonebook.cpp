#include "include/qt_phonebook.h"

QT_PhoneBook::QT_PhoneBook (QWidget* parent) : QWidget (parent)
{
    this->setWindowTitle ("Поиск по базе данных");
    this->resize (350, 150);
    lbl_FIO           = new QLabel ("ФИО", this);
    l_edit_FIO        = new QLineEdit (this);
    lbl_TlfNumber     = new QLabel ("Номер телефона", this);
    l_edit_TlfNumber  = new QLineEdit (this);
    lbl_Department    = new QLabel ("Депртамент", this);
    l_edit_Department = new QLineEdit (this);

    grid = new QGridLayout (this);
    grid->addWidget (lbl_FIO, 0, 0);
    grid->addWidget (l_edit_FIO, 0, 1);
    grid->addWidget (lbl_TlfNumber, 1, 0);
    grid->addWidget (l_edit_TlfNumber, 1, 1);
    grid->addWidget (lbl_Department, 2, 0);
    grid->addWidget (l_edit_Department, 2, 1);

    this->setLayout (grid);
}

QT_PhoneBook::~QT_PhoneBook () {}
