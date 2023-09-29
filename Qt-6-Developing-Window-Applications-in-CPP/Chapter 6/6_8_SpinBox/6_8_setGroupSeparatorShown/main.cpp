#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpinBox>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QSpinBox");
   window.resize(350, 70);

   QSpinBox *spinBox = new QSpinBox();
   spinBox->setRange(0, 10000000);
   spinBox->setValue(1000000);
   spinBox->setGroupSeparatorShown(true);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(spinBox);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << spinBox->text();
   });

   window.show();
   return app.exec();
}


