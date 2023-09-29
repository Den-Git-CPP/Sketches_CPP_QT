#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QBrush");
   window.resize(350, 450);
   Widget *w = new Widget();
   w->setParent(&window);
   window.show();
   return app.exec();
}

