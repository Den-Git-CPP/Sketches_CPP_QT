#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Выравнивание по вертикали");
   window.resize(300, 120);
   QPushButton *btn1 = new QPushButton("1");
   QPushButton *btn2 = new QPushButton("2");
   QPushButton *btn3 = new QPushButton("3");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   vbox->addWidget(btn3);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
