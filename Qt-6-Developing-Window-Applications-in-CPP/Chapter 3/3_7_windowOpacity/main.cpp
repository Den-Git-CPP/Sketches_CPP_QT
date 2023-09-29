#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Полупрозрачное окно");
   window.resize(350, 100);
   window.setWindowOpacity(0.5);
   window.show();
   qDebug() << window.windowOpacity(); // 0.498039
   return app.exec();
}
