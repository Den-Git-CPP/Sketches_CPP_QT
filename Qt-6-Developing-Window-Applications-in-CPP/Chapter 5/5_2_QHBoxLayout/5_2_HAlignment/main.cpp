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
   window.resize(400, 50);
   QPushButton *btn1 = new QPushButton("Right");
   QPushButton *btn2 = new QPushButton("No");
   QPushButton *btn3 = new QPushButton("Left");

   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn1, 0, Qt::AlignRight);
   hbox->addWidget(btn2);
   hbox->addWidget(btn3, 0, Qt::AlignLeft);

   window.setLayout(hbox);

   window.show();
   return app.exec();
}

