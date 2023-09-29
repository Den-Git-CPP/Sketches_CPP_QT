#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QMessageBox");
   window.resize(300, 70);
   window.show();
   return app.exec();
}
