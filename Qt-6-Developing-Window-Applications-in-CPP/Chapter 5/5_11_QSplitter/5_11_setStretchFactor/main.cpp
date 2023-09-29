#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QSplitter");
   window.resize(350, 250);
   window.show();
   return app.exec();
}
