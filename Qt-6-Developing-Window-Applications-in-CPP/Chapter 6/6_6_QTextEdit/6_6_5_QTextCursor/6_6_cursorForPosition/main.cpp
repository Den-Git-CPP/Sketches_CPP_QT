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

   QTextEdit *textEdit = new QTextEdit("Значение по умолчанию");

   QPushButton *btn1 = new QPushButton("Установить курсор");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      textEdit->setFocus();
      QTextCursor cur = textEdit->cursorForPosition(QPoint(100, 5));
      textEdit->setTextCursor(cur);
   });

   window.show();
   return app.exec();
}

