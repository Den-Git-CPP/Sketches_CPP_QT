#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QGroupBox>

void on_clicked(bool a) {
   qDebug() << "on_clicked" << a;
}

void on_toggled(bool a) {
   qDebug() << "on_toggled" << a;
}

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
   box->setCheckable(true);
   QHBoxLayout *hbox = new QHBoxLayout();
   hbox->addWidget(radio1);
   hbox->addWidget(radio2);
   box->setLayout(hbox);
   vbox->addWidget(box);
   window.setLayout(vbox);
   radio1->setChecked(true);

   QObject::connect(box, &QGroupBox::clicked,
                    on_clicked);
   QObject::connect(box, &QGroupBox::toggled,
                    on_toggled);

   window.show();
   return app.exec();
}

