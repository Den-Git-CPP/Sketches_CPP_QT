#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Назначение обработчиков сигналов");
   window.resize(350, 120);
   window.show();
   return app.exec();
}
