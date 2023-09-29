#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDial>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QDial");
   window.resize(350, 100);

   QDial *dial = new QDial();
   dial->setRange(0, 100);
   dial->setValue(40);
   dial->setNotchesVisible(true);
   dial->setNotchTarget(2.0);

   QPushButton *btn1 = new QPushButton("Вывести значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(dial);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << dial->value();
   });

   window.show();
   return app.exec();
}


