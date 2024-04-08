#include "specialwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpecialWidget sw;
    sw.show();
    return a.exec();
}
