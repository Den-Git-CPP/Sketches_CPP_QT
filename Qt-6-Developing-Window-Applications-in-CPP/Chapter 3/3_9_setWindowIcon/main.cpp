#include <QApplication>
#include <QWidget>
#include <QIcon>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Смена значка в заголовке окна");
   window.resize(350, 70);
   QIcon ico("G:\\ProjectQT\\CH03\\3_9_setWindowIcon\\test.jpg");
   window.setWindowIcon(ico); // Значок для окна
   app.setWindowIcon(ico);    // Значок для приложения
   window.show();
   return app.exec();
}
