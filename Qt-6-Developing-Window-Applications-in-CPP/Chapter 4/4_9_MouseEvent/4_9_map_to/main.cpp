#include "mylabel.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("События мыши");
   window.resize(350, 100);
   MyLabel *label = new MyLabel("Щелкните мышью в окне", &window);
   label->setFrameStyle(QFrame::Box | QFrame::Plain);
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
