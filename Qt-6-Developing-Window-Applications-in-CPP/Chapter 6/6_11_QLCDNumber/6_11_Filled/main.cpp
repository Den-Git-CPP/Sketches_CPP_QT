#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QLCDNumber");
   window.resize(350, 150);

   QLCDNumber *lcd = new QLCDNumber(9);
   lcd->display(123456789);
   lcd->setSegmentStyle(QLCDNumber::Filled);

   QPushButton *btn1 = new QPushButton("Вывести значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(lcd);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << lcd->value();
      qDebug() << lcd->intValue();
   });

   window.show();
   return app.exec();
}

