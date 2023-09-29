#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollBar>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QScrollBar");
   window.resize(350, 100);

   QScrollBar *scrollBar = new QScrollBar(Qt::Horizontal);
   scrollBar->setRange(0, 100);
   scrollBar->setValue(40);

   QPushButton *btn1 = new QPushButton("Вывести значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(scrollBar);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << scrollBar->value();
   });

   window.show();
   return app.exec();
}
