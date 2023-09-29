#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Заголовок окна");
   window.resize(350, 70);
   window.setWindowFlags(Qt::Window |
                         Qt::CustomizeWindowHint);

   QPushButton *btnQuit = new QPushButton("&Закрыть окно");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btnQuit);
   window.setLayout(vbox);
   QObject::connect(btnQuit, SIGNAL(clicked()),
                    &app, SLOT(quit()));

   window.show();
   return app.exec();
}
