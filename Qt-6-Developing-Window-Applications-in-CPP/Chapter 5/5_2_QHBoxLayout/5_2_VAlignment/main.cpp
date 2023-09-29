#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("Align");
   window.resize(300, 150);
   QPushButton *btn1 = new QPushButton("Bottom");
   QPushButton *btn2 = new QPushButton("No");
   QPushButton *btn3 = new QPushButton("Top");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btn1, 0, Qt::AlignBottom);
   vbox->addWidget(btn2);
   vbox->addWidget(btn3, 0, Qt::AlignTop);

   window.setLayout(vbox);

   window.show();
   return app.exec();
}

