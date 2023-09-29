#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTextEdit");
   window.resize(350, 250);

   QTextEdit *textEdit = new QTextEdit();
   textEdit->setFontPointSize(30);
   textEdit->setPlainText("Значение по умолчанию");

   QPushButton *btn1 = new QPushButton("Изменить размер шрифта");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      textEdit->setFontPointSize(12);
   });

   window.show();
   return app.exec();
}

