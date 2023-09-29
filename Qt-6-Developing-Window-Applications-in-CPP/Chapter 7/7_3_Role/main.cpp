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
   comboBox->setItemData(0, "Новое значение", Qt::DisplayRole);
   QIcon ico = window.style()->standardIcon(QStyle::SP_MessageBoxCritical);
   comboBox->setItemData(0, ico, Qt::DecorationRole);
   comboBox->setItemData(0, QFont("Courier New", 16), Qt::FontRole);
   comboBox->setItemData(1, Qt::AlignRight, Qt::TextAlignmentRole);
   comboBox->setItemData(2,
                        QBrush(QColor("black"), Qt::SolidPattern),
                        Qt::BackgroundRole);
   comboBox->setItemData(2,
                        QBrush(QColor("white"), Qt::SolidPattern),
                        Qt::ForegroundRole);
   comboBox->setItemData(3, Qt::Checked, Qt::CheckStateRole);
   comboBox->setItemData(0, QVariant(50), Qt::UserRole);
   comboBox->setItemData(0, "Это текст всплывающей подсказки",
                         Qt::ToolTipRole);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(comboBox);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << comboBox->itemData(comboBox->currentIndex()).toInt();
   });

   window.show();
   return app.exec();
}



