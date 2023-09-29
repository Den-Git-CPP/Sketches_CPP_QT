#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QColor>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QColor");
   window.resize(350, 200);

   QPalette pal = window.palette();
   QColor white = QColor::fromHsv(0, 0, 255, 255);
   pal.setColor(QPalette::Normal, QPalette::Window,
                white);
   window.setPalette(pal);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << QColor::colorNames();
      qDebug() << QColor::isValidColor("lightcyan"); // true
      QColor white("white");
      qDebug() << white.name(); // "#ffffff"
      QColor whiteHSV = QColor::fromHsv(0, 0, 255);
      QColor whiteRGB = whiteHSV.convertTo(QColor::Rgb);
      qDebug() << whiteRGB; // QColor(ARGB 1, 1, 1, 1)
   });

   window.show();
   return app.exec();
}



