#include "mainwindow.h"

#include <QApplication>

int main (int argc, char* argv [])
{
    QApplication a (argc, argv);
    QApplication::setOrganizationName ("Levolex");
    QApplication::setApplicationName ("MainFormSettings");
    MainWindow w;
    w.show ();
    return a.exec ();
}
