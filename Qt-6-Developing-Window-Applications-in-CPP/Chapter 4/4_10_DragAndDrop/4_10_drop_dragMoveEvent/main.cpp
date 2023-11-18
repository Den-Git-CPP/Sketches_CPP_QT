#include <QApplication>
#include <QVBoxLayout>
#include "mylabel2.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("drop. dragEnterEvent");
   window.resize(350, 200);

   MyLabel2 *label = new MyLabel2("Перетащите сюда текст");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
