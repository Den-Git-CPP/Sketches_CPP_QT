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
   textEdit->setPlainText("Блок 1\nБлок 2\nБлок 3\nБлок 4\nБлок 5 jjkh hkjhkjh khk hkh khk jhkh hkh khk hk hkh hkj hk hkhk k kjh kh jh kh khk hkh khk hkjh kh kh kjh kjhkj h kh kh kjh khk hk kh kh k");

   QPushButton *btn1 = new QPushButton("Снять выделение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      textEdit->setFocus();
      QTextCursor cur = textEdit->textCursor();
      if (cur.hasSelection()) {
         cur.clearSelection();
         textEdit->setTextCursor(cur);
      }
   });

   window.show();
   return app.exec();
}

