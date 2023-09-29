#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Управление отступами");
   window.resize(400, 150);
   QPushButton *btn1 = new QPushButton("1");
   QPushButton *btn2 = new QPushButton("2");
   QPushButton *btn3 = new QPushButton("3");
   QPushButton *btn4 = new QPushButton("4");
   QPushButton *btn5 = new QPushButton("5");
   QPushButton *btn6 = new QPushButton("6");

   QVBoxLayout *vbox = new QVBoxLayout();

   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->setContentsMargins(0, 0, 0, 0);
   hbox->setSpacing(0);
   hbox->addWidget(btn1);
   hbox->addWidget(btn2);
   hbox->addWidget(btn3);
   vbox->addLayout(hbox);

   QHBoxLayout *hbox2 = new QHBoxLayout();
   hbox2->setContentsMargins(30, 30, 30, 30);
   hbox2->setSpacing(20);
   hbox2->addWidget(btn4);
   hbox2->addWidget(btn5);
   hbox2->addWidget(btn6);
   vbox->addLayout(hbox2);

   vbox->addLayout(hbox);

   window.setLayout(vbox);

   window.show();
   return app.exec();
}
