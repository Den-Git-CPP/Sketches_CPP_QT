#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QRegularExpressionValidator>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QComboBox");
   window.resize(350, 100);

   QComboBox *comboBox = new QComboBox();
   comboBox->setEditable(true);
   comboBox->setInsertPolicy(QComboBox::InsertAtTop);
   QRegularExpression p("[а-яё]+");
   QRegularExpressionValidator *validator =
            new QRegularExpressionValidator(p, &window);
   comboBox->setValidator(validator);

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


