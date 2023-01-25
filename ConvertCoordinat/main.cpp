#include "convertcoordinat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConvertCoordinat w;
    w.setWindowIcon(QIcon (":/resource/avia.ico")); // Значок для окна
    w.show();
    return a.exec();
}
