#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QButtonGroup");
   window.resize(350, 80);
   window.show();
   return app.exec();
}
