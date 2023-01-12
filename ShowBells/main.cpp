#include "widget.h"
#include "lb_bells.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowIcon(QIcon ("G:\\ProjectQT\\ShowBells\\resource\\alarm.png")); // Значок для окна
    w.show();
    return a.exec();
}
