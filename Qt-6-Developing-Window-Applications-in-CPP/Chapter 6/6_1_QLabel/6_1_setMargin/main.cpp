#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QLabel");
   window.resize(350, 70);

   QLabel *label = new QLabel("Текст надписи");
   label->setFrameStyle(QFrame::Box | QFrame::Plain);
   label->setMargin(20);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
