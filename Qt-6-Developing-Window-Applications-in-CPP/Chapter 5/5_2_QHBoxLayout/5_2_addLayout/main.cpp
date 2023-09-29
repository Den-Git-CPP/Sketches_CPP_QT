#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Вложение контейнеров");
   window.resize(300, 150);
   QPushButton *btn1 = new QPushButton("1");
   QPushButton *btn2 = new QPushButton("2");
   QPushButton *btn3 = new QPushButton("3");
   QPushButton *btn4 = new QPushButton("4");
   QPushButton *btn5 = new QPushButton("5");
   QPushButton *btn6 = new QPushButton("6");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   vbox->addWidget(btn3);

   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn4);
   hbox->addWidget(btn5);
   hbox->addWidget(btn6);

   vbox->addLayout(hbox);

   window.setLayout(vbox);

   window.show();
   return app.exec();
}

