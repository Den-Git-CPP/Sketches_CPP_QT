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
   comboBox->setIconSize(QSize(32, 32));
   for (int i = 1; i < 11; ++i) {
      comboBox->addItem(QString("Пункт %1").arg(i), QVariant(i));
   }
   QIcon ico = window.style()->standardIcon(QStyle::SP_MessageBoxCritical);
   comboBox->insertItem(0, ico, "Пункт 11");
   QPushButton *btn1 = new QPushButton("Получить индекс текущего элемента");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(comboBox);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << "Индекс:" << comboBox->currentIndex();
   });

   window.show();
   return app.exec();
}


