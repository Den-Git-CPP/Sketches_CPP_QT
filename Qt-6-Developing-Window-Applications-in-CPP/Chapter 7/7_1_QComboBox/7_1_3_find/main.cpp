#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>

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
   comboBox->addItem("Пункт", QVariant(11));
   QPushButton *btn1 = new QPushButton("Найти элементы");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(comboBox);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << comboBox->findText("пункт 3", Qt::MatchFixedString);
      qDebug() << comboBox->findText("^[а-яёА-ЯЁ]+$", Qt::MatchRegularExpression);
      qDebug() << comboBox->findText("Пункт 80");
      qDebug() << comboBox->findData(QVariant(10));
   });

   window.show();
   return app.exec();
}


