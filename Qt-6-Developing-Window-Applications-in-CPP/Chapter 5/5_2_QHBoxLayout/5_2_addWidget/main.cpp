#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Выравнивание по горизонтали");
   window.resize(450, 50);
   QPushButton *btn1 = new QPushButton("1");
   QPushButton *btn2 = new QPushButton("2");
   QPushButton *btn3 = new QPushButton("3");
   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn1, 10, Qt::AlignLeft);
   hbox->addWidget(btn2, 10);
   hbox->addWidget(btn3, 0, Qt::AlignRight);
   window.setLayout(hbox);

   window.show();
   return app.exec();
}

