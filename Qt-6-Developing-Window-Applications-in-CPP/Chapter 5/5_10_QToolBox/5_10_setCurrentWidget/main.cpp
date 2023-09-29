#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QToolBox");
   window.resize(400, 150);
   window.show();
   return app.exec();
}
