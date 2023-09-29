#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Выравнивание по сетке");
   window.resize(300, 100);
   QPushButton *btn1 = new QPushButton("1");
   QPushButton *btn2 = new QPushButton("2");
   QPushButton *btn3 = new QPushButton("3");
   QPushButton *btn4 = new QPushButton("4");

   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn3);
   hbox->addWidget(btn4);

   QGridLayout *grid = new QGridLayout();
   grid->addWidget(btn1, 0, 0);
   grid->addWidget(btn2, 0, 1);
   grid->addLayout(hbox, 1, 0, 1, 2);
   window.setLayout(grid);

   window.show();
   return app.exec();
}
