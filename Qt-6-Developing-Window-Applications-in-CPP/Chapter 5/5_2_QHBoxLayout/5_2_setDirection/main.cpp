#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Выравнивание по горизонтали в обратном порядке");
   window.resize(300, 50);
   QPushButton *btn1 = new QPushButton("1");
   QPushButton *btn2 = new QPushButton("2");
   QPushButton *btn3 = new QPushButton("3");

   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->setDirection(QBoxLayout::RightToLeft);
   hbox->addWidget(btn1);
   hbox->addWidget(btn2);
   hbox->addWidget(btn3);

   window.setLayout(hbox);

   window.show();
   return app.exec();
}
