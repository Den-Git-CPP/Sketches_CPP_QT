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

   QTextEdit *textEdit = new QTextEdit("Значение <b>по умолчанию</b>");

   QPushButton *btn1 = new QPushButton("Уменьшить");
   QPushButton *btn2 = new QPushButton("Увеличить");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      textEdit->setFocus();
      textEdit->zoomOut();
   });
   QObject::connect(btn2, &QPushButton::clicked, [=]() {
      textEdit->setFocus();
      textEdit->zoomIn();
   });

   window.show();
   return app.exec();
}
