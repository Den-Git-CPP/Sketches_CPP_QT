#include <QApplication>
#include <QWidget>
#include <QScreen>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Вывод окна по центру экрана");
   window.resize(350, 70);
   window.move(window.width() * -2, 0);
   window.show();

   QScreen *screen = QApplication::primaryScreen();
   QRect rect = screen->availableGeometry();
   window.move(rect.center() - window.rect().center());

   return app.exec();
}
