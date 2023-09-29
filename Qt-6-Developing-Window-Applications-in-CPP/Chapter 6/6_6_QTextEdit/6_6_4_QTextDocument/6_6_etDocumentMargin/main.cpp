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
   document->setDocumentMargin(10);
   document->setHtml("<html><body><p>Текст внутри поля</p></body></html>");
   textEdit->setDocument(document);

   QPushButton *btn1 = new QPushButton("Изменить отступ");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      textEdit->document()->setDocumentMargin(5);
   });

   window.show();
   return app.exec();
}

