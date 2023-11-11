#include "include/qt_phonebook.h"
#include <QApplication>
#include <QIcon>

int main (int argc, char* argv [])
{
    QApplication a (argc, argv);
    QT_PhoneBook PhoneBook;
  //  PhoneBook.setWindowIcon (QIcon (":/resources/TLF_Ico.ico")); // Значок для окна
    PhoneBook.show ();
    return a.exec ();
}
