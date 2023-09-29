#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Всплывающие подсказки");
   window.setWindowFlags(Qt::Window |
                         Qt::WindowCloseButtonHint |
                         Qt::WindowContextHelpButtonHint);
   window.resize(300, 70);

   QPushButton *button = new QPushButton("Закрыть окно", &window);
   button->setFixedSize(150, 30);
   button->move(75, 20);

   button->setToolTip("Это всплывающая подсказка для кнопки");
   window.setToolTip("Это всплывающая подсказка для окна");
   button->setWhatsThis("Это справка для кнопки");
   window.setWhatsThis("Это справка для окна");

   QObject::connect(button, SIGNAL(clicked()),
                    qApp, SLOT(quit()));
   window.show();
   return app.exec();
}
