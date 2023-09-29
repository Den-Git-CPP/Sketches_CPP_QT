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
   label->setAlignment(Qt::AlignCenter);
   // label->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
   // label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
   // label->setAlignment(Qt::AlignRight | Qt::AlignBottom);
   label->setFrameStyle(QFrame::Box | QFrame::Plain);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
