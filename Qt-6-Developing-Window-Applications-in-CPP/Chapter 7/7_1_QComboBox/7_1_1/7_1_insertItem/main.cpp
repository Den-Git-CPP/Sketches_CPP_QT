#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QStyle>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QComboBox");
   window.resize(350, 100);

   QComboBox *comboBox = new QComboBox();
   for (int i = 1; i < 11; ++i) {
      comboBox->addItem(QString("Пункт %1").arg(i), QVariant(i));
   }
   QIcon ico = window.style()->standardIcon(QStyle::SP_MessageBoxCritical);
   comboBox->insertItem(0, ico, "Пункт 11", QVariant(11));
   comboBox->insertItem(1, "Пункт 12", QVariant(12));

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(comboBox);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << comboBox->currentText();
   });

   window.show();
   return app.exec();
}

