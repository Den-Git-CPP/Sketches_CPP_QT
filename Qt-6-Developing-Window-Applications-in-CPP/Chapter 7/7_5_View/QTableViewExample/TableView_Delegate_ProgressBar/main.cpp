#include "progressbardemo.h"

#include <QApplication>

int main( int argc, char* argv[] ) {
    QApplication a( argc, argv );

    ProgressBarDemo w;
    w.show();

    return a.exec();
}
