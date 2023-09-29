#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Назначение клавиш быстрого доступа");
   window.resize(350, 150);
   window.show();
   return app.exec();
}

