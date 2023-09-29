#include <QApplication>
#include <QWidget>
#include <QScreen>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Вывод окна по центру экрана");
   window.resize(350, 70);

   QScreen *screen = QApplication::primaryScreen();
   QRect rect = screen->geometry();
   int x = (rect.width() - window.width()) / 2;
   int y = (rect.height() - window.height()) / 2;
   window.move(x, y);

   window.show();
   return app.exec();
}
