#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPalette>
#include <QPixmap>
#include <QBrush>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Изображение в качестве фона");
   window.resize(350, 70);

   QPalette pal = window.palette();
   pal.setBrush(QPalette::Normal, QPalette::Window,
       QBrush(QPixmap("G:\\ProjectQT\\CH03\\3_11_background-image\\texture2.jpg")));

   window.setPalette(pal);

   QLabel *label = new QLabel("Текст надписи");
   label->setAlignment(Qt::AlignCenter);
   label->setStyleSheet(
    "background-image: url(G:\\ProjectQT\\CH03\\3_11_background-image\\texture.jpg);");
   label->setAutoFillBackground(true);
   QVBoxLayout *vbox = new QVBoxLayout;
   vbox->addWidget(label);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
