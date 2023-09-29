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
   spinBox->setMinimumHeight(50);
   spinBox->setRange(0, 100);
   spinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(spinBox);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << spinBox->value();
   });

   window.show();
   return app.exec();
}


