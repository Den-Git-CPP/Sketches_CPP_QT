#include "assistantodwgt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AssistantODWgt w;
    w.show();
    return a.exec();
}
