#include <QApplication>
#include <QWidget>
#include <QGridLayout>
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

   QGridLayout *grid = new QGridLayout();
   grid->addWidget(btn1, 0, 0);
   grid->addWidget(btn2, 0, 1);
   grid->addWidget(btn3, 1, 0);
   grid->addWidget(btn4, 1, 1);
   window.setLayout(grid);

   window.show();
   return app.exec();
}
