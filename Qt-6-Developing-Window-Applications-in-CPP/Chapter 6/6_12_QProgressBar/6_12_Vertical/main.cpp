#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QProgressBar>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QProgressBar");
   window.resize(350, 420);

   QProgressBar *progressBar = new QProgressBar();
   progressBar->setRange(0, 100);
   progressBar->setValue(50);
   progressBar->setOrientation(Qt::Vertical);

   QPushButton *btn1 = new QPushButton("Вывести значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(progressBar);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << progressBar->value();
   });

   window.show();
   return app.exec();
}

