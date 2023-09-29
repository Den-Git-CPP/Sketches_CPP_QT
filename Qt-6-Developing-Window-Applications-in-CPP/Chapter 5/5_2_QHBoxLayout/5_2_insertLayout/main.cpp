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
   QPushButton *btn7 = new QPushButton("7");
   QPushButton *btn8 = new QPushButton("8");
   QPushButton *btn9 = new QPushButton("9");


   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   vbox->addWidget(btn3);

   QHBoxLayout *hbox1 = new QHBoxLayout();
   hbox1->addWidget(btn4);
   hbox1->addWidget(btn5);
   hbox1->addWidget(btn6);

   QHBoxLayout *hbox2 = new QHBoxLayout();
   hbox2->addWidget(btn7);
   hbox2->addWidget(btn8);
   hbox2->addWidget(btn9);

   vbox->insertLayout(2, hbox1);
   vbox->insertLayout(4, hbox2);

   window.setLayout(vbox);

   window.show();
   return app.exec();
}

