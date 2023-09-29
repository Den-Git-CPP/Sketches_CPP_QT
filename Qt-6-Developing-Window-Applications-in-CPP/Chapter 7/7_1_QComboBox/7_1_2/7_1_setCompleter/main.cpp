#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QStyle>
#include <QCompleter>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QComboBox");
   window.resize(350, 100);

   QComboBox *comboBox = new QComboBox();
   comboBox->setEditable(true);
   comboBox->setInsertPolicy(QComboBox::InsertAtTop);
   QStringList list;
   list << "кадр" << "каменный" << "камень" << "камера";
   QCompleter *completer = new QCompleter(list, &window);
   completer->setCaseSensitivity(Qt::CaseInsensitive);
   comboBox->setCompleter(completer);

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


