#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFontComboBox>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QFontComboBox");
   window.resize(350, 100);

   QFontComboBox *comboBox = new QFontComboBox();
   comboBox->setCurrentFont(QFont("Verdana"));

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(comboBox);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << comboBox->currentFont().family();
   });

   window.show();
   return app.exec();
}


