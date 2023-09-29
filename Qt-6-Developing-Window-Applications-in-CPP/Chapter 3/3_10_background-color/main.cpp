#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPalette>
#include <QColor>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Изменение цвета фона окна");
   window.resize(350, 70);
   QPalette pal = window.palette();
   pal.setColor(QPalette::Normal, QPalette::Window,
                QColor(0, 128, 0));
   pal.setColor(QPalette::Inactive, QPalette::Window,
                QColor(255, 0, 0));
   window.setPalette(pal);

   QLabel *label = new QLabel("Текст надписи");
   label->setAlignment(Qt::AlignCenter);
   label->setStyleSheet("background-color: #ffffff;");
   label->setAutoFillBackground(true);
   QVBoxLayout *vbox = new QVBoxLayout;
   vbox->addWidget(label);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}
