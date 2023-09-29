#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QStringListModel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QComboBox");
   window.resize(350, 100);

   QComboBox *comboBox = new QComboBox();
   QStringList list;
   for (int i = 1; i < 11; ++i) {
      list << QString("Пункт %1").arg(i);
   }
   QStringListModel *model = new QStringListModel(list, &window);
   comboBox->setModel(model);

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


