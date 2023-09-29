#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Отслеживание состояния окна");
   window.resize(350, 100);
   window.show();
   return app.exec();
}

