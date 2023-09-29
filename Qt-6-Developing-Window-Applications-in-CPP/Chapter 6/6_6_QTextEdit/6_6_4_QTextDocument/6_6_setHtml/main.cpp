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
   QTextDocument *document = new QTextDocument(&window);
   document->setHtml("<p><font color=red>Текст в формате <b>HTML</b></font></p>");
   textEdit->setDocument(document);

   QPushButton *btn1 = new QPushButton("Получить текст");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << textEdit->document()->toHtml();
   });

   window.show();
   return app.exec();
}

