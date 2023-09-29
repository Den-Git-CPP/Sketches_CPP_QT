#include "mywindow.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   MyWindow window;
   window.setWindowTitle("Класс QMainWindow");
   window.resize(500, 350);
   window.show();
   return app.exec();
}
