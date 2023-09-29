#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Выравнивание по горизонтали");
   window.resize(300, 50);
   QPushButton *btn1 = new QPushButton("1");
   QPushButton *btn2 = new QPushButton("2");
   QPushButton *btn3 = new QPushButton("3");
   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn1);
   hbox->insertWidget(-1, btn2); // Добавление в конец
   hbox->insertWidget(0, btn3);  // Добавление в начало
   window.setLayout(hbox);

   window.show();
   return app.exec();
}

