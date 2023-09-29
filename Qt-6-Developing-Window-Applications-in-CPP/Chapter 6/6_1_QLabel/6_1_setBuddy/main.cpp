#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QLabel");
   window.resize(350, 70);

   QLabel *label = new QLabel("&Пароль");
   QLineEdit *lineEdit = new QLineEdit();
   label->setBuddy(lineEdit);

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(label);
   vbox->addWidget(lineEdit);
   vbox->addWidget(new QLineEdit());
   window.setLayout(vbox);
   window.show();
   return app.exec();
}
