#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTextEdit");
   window.resize(350, 250);

   QTextEdit *textEdit = new QTextEdit("Значение <b>по умолчанию</b>");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   window.setLayout(vbox);
   window.show();
   qDebug() << textEdit->toPlainText();
   qDebug() << textEdit->toHtml();
   return app.exec();
}
