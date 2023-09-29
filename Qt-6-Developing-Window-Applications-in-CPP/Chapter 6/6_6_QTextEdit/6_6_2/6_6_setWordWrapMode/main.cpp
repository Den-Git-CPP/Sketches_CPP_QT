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

   QTextEdit *textEdit = new QTextEdit("setWordWrapMode() задает режим переноса строк. В качестве значения могут быть указаны следующие константы:");
   textEdit->setWordWrapMode(QTextOption::NoWrap);
   //textEdit->setWordWrapMode(QTextOption::WordWrap);
   //textEdit->setWordWrapMode(QTextOption::ManualWrap);
   //textEdit->setWordWrapMode(QTextOption::WrapAnywhere);
   //textEdit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << textEdit->wordWrapMode();
   });

   window.show();
   return app.exec();
}

