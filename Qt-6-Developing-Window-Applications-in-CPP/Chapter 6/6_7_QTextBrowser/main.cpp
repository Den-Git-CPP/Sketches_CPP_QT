#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTextBrowser");
   window.resize(800, 600);

   QTextBrowser *textBrowser = new QTextBrowser();
   textBrowser->setSource(QUrl("file:///G:/ProjectQT/CH06/6_7_QTextBrowser/test.html"));

   QPushButton *btn1 = new QPushButton("Вывести адрес и перейти домой");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(textBrowser);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << textBrowser->source().toString();
      textBrowser->home();
   });

   window.show();
   return app.exec();
}

