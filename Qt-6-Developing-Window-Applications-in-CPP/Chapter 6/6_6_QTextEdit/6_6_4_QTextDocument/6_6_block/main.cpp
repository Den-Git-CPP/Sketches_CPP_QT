#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QTextBlock>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTextEdit");
   window.resize(350, 250);

   QTextEdit *textEdit = new QTextEdit();
   QTextDocument *document = new QTextDocument(&window);
   document->setPlainText("Блок 1\nБлок 2\nБлок 3\nБлок 4\nБлок 5");
   textEdit->setDocument(document);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << textEdit->document()->firstBlock().text();
      qDebug() << textEdit->document()->lastBlock().text();
      qDebug() << textEdit->document()->findBlock(0).text();
      qDebug() << textEdit->document()->findBlockByNumber(4).text();
   });

   window.show();
   return app.exec();
}

