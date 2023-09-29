#include <QVBoxLayout>
#include "mylabel.h"
#include "mylabel2.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("drag & drop");
   window.resize(350, 200);

   MyLabel *label = new MyLabel("Щелкните здесь мышью\n"
      "и перетащите в текстовый редактор\n(например, в WordPad)"
      "\nили на надпись ниже");
   MyLabel2 *label2 = new MyLabel2("Перетащите сюда текст");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(label2);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
