#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QPushButton");
   window.resize(350, 50);
   window.show();
   return app.exec();
}
