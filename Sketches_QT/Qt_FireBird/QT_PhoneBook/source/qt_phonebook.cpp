#include "include/qt_phonebook.h"

QT_PhoneBook::QT_PhoneBook (QWidget* parent) : QWidget (parent)
{
    this->setWindowTitle ("Поиск по базе данных");
    this->resize (350, 150);
    lbl_FIO        = new QLabel ("ФИО", this);
    lbl_TlfNumber  = new QLabel ("Номер телефона", this);
    lbl_Department = new QLabel ("Депртамент", this);

    vbox = new QVBoxLayout (this);
    vbox->addWidget (lbl_FIO);
    vbox->addWidget (lbl_TlfNumber);
    vbox->addWidget (lbl_Department);

    this->setLayout (vbox);
}

QT_PhoneBook::~QT_PhoneBook () {}
