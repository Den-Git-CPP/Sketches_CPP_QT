#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCompleter>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QLineEdit");
   window.resize(350, 70);

   QLineEdit *lineEdit = new QLineEdit();
   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(lineEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << lineEdit->text();
      lineEdit->setSelection(0, 6);
      qDebug() << lineEdit->selectedText();
   });

   window.show();
   return app.exec();
}
