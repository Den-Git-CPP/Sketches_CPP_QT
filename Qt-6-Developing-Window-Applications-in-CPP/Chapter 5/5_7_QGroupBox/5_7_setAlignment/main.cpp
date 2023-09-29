#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QGroupBox>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QGroupBox");
   window.resize(350, 80);
   QRadioButton *radio1 = new QRadioButton("&Да");
   QRadioButton *radio2 = new QRadioButton("&Нет");
   QVBoxLayout *vbox = new QVBoxLayout();
   QGroupBox *box = new QGroupBox("&Вы знаете язык C++?");
   box->setAlignment(Qt::AlignHCenter);
   // box->setAlignment(Qt::AlignRight);
   // box->setAlignment(Qt::AlignLeft);
   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(radio1);
   hbox->addWidget(radio2);
   box->setLayout(hbox);
   vbox->addWidget(box);
   window.setLayout(vbox);
   radio1->setChecked(true);

   window.show();
   return app.exec();
}

