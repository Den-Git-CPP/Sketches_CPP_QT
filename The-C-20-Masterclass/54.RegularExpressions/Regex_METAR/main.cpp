#include <QApplication>

#include "include/downloader.h"
#include "include/widget.h"

int main (int argc, char* argv [])
{
    QApplication a (argc, argv);
    Widget w;
    w.show ();
    return a.exec ();
}
