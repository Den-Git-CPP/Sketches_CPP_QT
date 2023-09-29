#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QDial");
   window.resize(350, 300);
   window.show();
   return app.exec();
}

