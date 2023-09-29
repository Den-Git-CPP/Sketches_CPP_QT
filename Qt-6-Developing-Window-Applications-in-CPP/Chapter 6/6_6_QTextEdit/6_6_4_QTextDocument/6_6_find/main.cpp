#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QRegularExpression>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTextEdit");
   window.resize(350, 250);

   QTextEdit *textEdit = new QTextEdit();
   QTextDocument *document = new QTextDocument(&window);
   document->setPlainText("текст\nтекст\nТЕКСТ\nтекст\nтекст\nтекст\nтекст\nтекст\nтекст\nтекст\n");
   textEdit->setDocument(document);

   QPushButton *btn1 = new QPushButton("Поиск фрагмента");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      QRegularExpression p("Т[А-Я]+Т");
      QTextCursor cursor = textEdit->document()->find(p, 0);
      if (!cursor.isNull()) {
         textEdit->setTextCursor(cursor);
      }
   });

   window.show();
   return app.exec();
}

