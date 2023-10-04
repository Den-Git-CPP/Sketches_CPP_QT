
#include "mainwindow.h"
#include <QApplication>

int main (int argc, char* argv [])
{
    QApplication a (argc, argv);
    QFile file (":/resource/Ubuntu.qss");
    file.open (QFile::ReadOnly);
    QString styleSheet = QLatin1String (file.readAll ());
    qApp->setStyleSheet (styleSheet);

    MainWindow w;
    w.show ();

    return a.exec ();
}
