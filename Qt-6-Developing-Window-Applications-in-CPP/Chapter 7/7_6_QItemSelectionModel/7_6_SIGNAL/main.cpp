#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QItemSelectionModel");
   window.resize(500, 200);
   window.show();
   return app.exec();
}


