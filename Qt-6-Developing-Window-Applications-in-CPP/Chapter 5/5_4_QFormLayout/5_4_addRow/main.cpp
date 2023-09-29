#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget window;
   window.setWindowTitle("addRow");
   window.resize(300, 150);
   QLabel *label1 = new QLabel("&Название:");
   QLabel *label2 = new QLabel("&Описание:");
   QLineEdit *lineEdit = new QLineEdit();
   QTextEdit *textEdit = new QTextEdit();
   QPushButton *btn1 = new QPushButton("&Отправить");
   QPushButton *btn2 = new QPushButton("&Очистить");

   label1->setBuddy(lineEdit);
   label2->setBuddy(textEdit);

   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(btn1);
   hbox->addWidget(btn2);

   QFormLayout *form = new QFormLayout();
   form->addRow(label1, lineEdit);
   form->addRow(label2, textEdit);
   form->addRow(hbox);
   window.setLayout(form);

   window.show();
   return app.exec();
}
