#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QSlider");
   window.resize(350, 100);

   QSlider *slider = new QSlider(Qt::Horizontal);
   slider->setMinimum(0);
   slider->setMaximum(100);
   slider->setValue(40);
   slider->setSingleStep(10);
   slider->setPageStep(20);
   slider->setInvertedAppearance(true);
   slider->setInvertedControls(false);
   slider->setTickPosition(QSlider::TicksBelow);

   QPushButton *btn1 = new QPushButton("Вывести значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(slider);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << slider->value();
   });

   window.show();
   return app.exec();
}

