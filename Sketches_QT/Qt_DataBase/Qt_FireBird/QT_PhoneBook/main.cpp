#include "include/qt_phonebook.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QT_PhoneBook PhoneBook;
    PhoneBook.show();
    return a.exec();
}
