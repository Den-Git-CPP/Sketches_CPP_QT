#include "firstform.h"
#include "secondform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    // Instantiating the forms
        FirstForm first;
        SecondForm second;

        // Connecting the signal we created in the first form
        // with the slot created in the second form
        QObject::connect(&first, SIGNAL(newTextEntered(const QString&)),
                         &second, SLOT(onNewTextEntered(const QString&)));

        // Showing them
        first.show();
        second.show();

    return a.exec();
}
