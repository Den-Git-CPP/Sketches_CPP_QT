#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Widget window;
   window.setWindowTitle("Класс QDialogButtonBox");
   window.resize(300, 150);
   window.show();
   return app.exec();
}
