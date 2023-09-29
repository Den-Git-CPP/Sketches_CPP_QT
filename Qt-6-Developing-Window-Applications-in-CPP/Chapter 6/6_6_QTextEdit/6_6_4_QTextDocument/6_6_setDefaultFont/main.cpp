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
   document->setDefaultFont(QFont("Tahoma", 30, QFont::Bold));
   document->setPlainText("Текст внутри поля");
   textEdit->setDocument(document);

   QPushButton *btn1 = new QPushButton("Поиск фрагмента");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      textEdit->document()->setDefaultFont(
                QFont("Tahoma", 12, QFont::Normal, false));
   });

   window.show();
   return app.exec();
}

