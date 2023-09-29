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

   QTextEdit *textEdit = new QTextEdit("setLineWrapMode() задает режим переноса строк. В качестве значения могут быть указаны следующие атрибуты из класса QTextEdit:");
   //textEdit->setLineWrapMode(QTextEdit::NoWrap);
   textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
   //textEdit->setLineWrapMode(QTextEdit::FixedPixelWidth);
   //textEdit->setLineWrapMode(QTextEdit::FixedColumnWidth);
   textEdit->setLineWrapColumnOrWidth(70);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << textEdit->lineWrapMode();
   });

   window.show();
   return app.exec();
}

