#include "widget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QPainter");
   window.resize(600, 600);
   Widget *w = new Widget();
   w->setParent(&window);
   window.show();
   return app.exec();
}

