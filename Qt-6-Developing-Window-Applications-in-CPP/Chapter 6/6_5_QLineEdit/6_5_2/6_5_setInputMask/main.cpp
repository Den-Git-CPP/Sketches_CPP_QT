#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QLineEdit");
   window.resize(350, 100);
   window.show();
   return app.exec();
}
