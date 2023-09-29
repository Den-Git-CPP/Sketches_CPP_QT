#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QFormLayout>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QLineEdit");
   window.resize(350, 70);

   QLineEdit *lineEdit1 = new QLineEdit();
   QLineEdit *lineEdit2 = new QLineEdit();
   QLineEdit *lineEdit3 = new QLineEdit();
   QLineEdit *lineEdit4 = new QLineEdit();
   lineEdit1->setEchoMode(QLineEdit::Normal);
   lineEdit2->setEchoMode(QLineEdit::NoEcho);
   lineEdit3->setEchoMode(QLineEdit::Password);
   lineEdit4->setEchoMode(QLineEdit::PasswordEchoOnEdit);

   QFormLayout *form = new QFormLayout();
   form->addRow("&Normal:", lineEdit1);
   form->addRow("No&Echo:", lineEdit2);
   form->addRow("&Password:", lineEdit3);
   form->addRow("PasswordEchoOn&Edit:", lineEdit4);
   window.setLayout(form);
   window.show();
   return app.exec();
}
