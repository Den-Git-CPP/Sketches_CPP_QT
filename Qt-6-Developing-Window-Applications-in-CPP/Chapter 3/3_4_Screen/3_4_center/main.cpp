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
   QRect rect = screen->geometry();
   int x = (rect.width() - window.frameSize().width()) / 2;
   int y = (rect.height() - window.frameSize().height()) / 2;
   window.move(x, y);

   return app.exec();
}
