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
   comboBox->setItemText(0, "Новое значение");
   QIcon ico = window.style()->standardIcon(QStyle::SP_MessageBoxCritical);
   comboBox->setItemIcon(0, ico);
   comboBox->setItemData(0, QVariant(50), Qt::UserRole);
   comboBox->setItemData(0, "Это текст всплывающей подсказки",
                         Qt::ToolTipRole);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(comboBox);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << comboBox->currentText();
      qDebug() << comboBox->itemData(comboBox->currentIndex()).toInt();
   });

   window.show();
   return app.exec();
}

