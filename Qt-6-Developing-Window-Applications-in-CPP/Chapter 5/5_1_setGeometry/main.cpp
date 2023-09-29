#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Абсолютное позиционирование");
   window.resize(300, 120);
   QLabel *label = new QLabel("Текст надписи", &window);
   QPushButton *btn1 = new QPushButton("Текст на кнопке", &window);
   label->setGeometry(10, 10, 280, 60);
   btn1->resize(280, 30);
   btn1->move(10, 80);
   window.show();
   return app.exec();
}
