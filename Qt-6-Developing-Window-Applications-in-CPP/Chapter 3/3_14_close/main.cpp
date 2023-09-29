#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Закрытие окна из программы");
   window.resize(350, 70);

   QPushButton *button = new QPushButton("Закрыть окно", &window);
   button->setFixedSize(150, 30);
   button->move(75, 20);
   QObject::connect(button, SIGNAL(clicked()),
                    &window, SLOT(close()));
   window.show();
   return app.exec();
}
