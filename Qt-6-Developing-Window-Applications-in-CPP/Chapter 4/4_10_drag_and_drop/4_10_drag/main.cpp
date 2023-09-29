#include <QVBoxLayout>
#include "mylabel.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("drag");
   window.resize(350, 100);

   MyLabel *label = new MyLabel("Щелкните здесь мышью\n"
      "и перетащите в текстовый редактор\n(например, в WordPad)");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
