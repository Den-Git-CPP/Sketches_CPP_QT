#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Изменение положения окна и его размеров");
   window.resize(350, 100);
   window.show();
   return app.exec();
}

