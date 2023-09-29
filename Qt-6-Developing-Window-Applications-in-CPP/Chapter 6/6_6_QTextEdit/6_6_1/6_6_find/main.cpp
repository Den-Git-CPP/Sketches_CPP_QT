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
   textEdit->setPlainText("текст\nтекст\nТЕКСТ\nтекст\nтекст\nтекст\nтекст\nтекст\nтекст\nтекст\n");

   QPushButton *btn1 = new QPushButton("Найти в обратном порядке с учетом регистра");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      textEdit->setFocus();
      textEdit->find("текст",
                     QTextDocument::FindCaseSensitively |
                     QTextDocument::FindBackward);
   });

   window.show();
   return app.exec();
}
