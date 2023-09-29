#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("AlignAbsolute");
   window.resize(400, 150);
   QPushButton *btn1 = new QPushButton("1");
   QPushButton *btn2 = new QPushButton("2");
   QPushButton *btn3 = new QPushButton("3");
   QPushButton *btn4 = new QPushButton("4");
   QPushButton *btn5 = new QPushButton("5");
   QPushButton *btn6 = new QPushButton("6");

   window.setLayoutDirection(Qt::RightToLeft);

   QVBoxLayout *vbox = new QVBoxLayout();

   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn1);
   hbox->addWidget(btn2);
   hbox->addWidget(btn3, 0, Qt::AlignLeft);
   vbox->addLayout(hbox);

   QHBoxLayout *hbox2 = new QHBoxLayout();
   hbox2->addWidget(btn4);
   hbox2->addWidget(btn5);
   hbox2->addWidget(btn6, 0, Qt::AlignAbsolute | Qt::AlignLeft);
   vbox->addLayout(hbox2);

   vbox->addLayout(hbox);

   window.setLayout(vbox);

   window.show();
   return app.exec();
}
