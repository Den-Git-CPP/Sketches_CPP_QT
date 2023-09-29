#include <QApplication>
#include <QWidget>
#include <QScreen>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Заголовок окна");
   window.resize(350, 70);
   window.move(window.width() * -2, 0);
   window.show();

   QScreen *screen = QApplication::primaryScreen();
   QRect rect = screen->availableGeometry();
   int x = rect.x() + rect.width() - window.frameSize().width();
   window.move(x, rect.y());

   return app.exec();
}
