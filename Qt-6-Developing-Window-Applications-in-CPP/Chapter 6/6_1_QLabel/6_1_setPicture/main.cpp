#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPicture>
#include <QPainter>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QLabel");
   window.resize(350, 70);

   QLabel *label = new QLabel();
   QPicture picture;
   QPainter painter;
   painter.begin(&picture);
   painter.fillRect(10, 10, 480, 330, QBrush(Qt::red));
   painter.end();
   label->setPicture(picture);
   label->setAutoFillBackground(true);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
