#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QDateEdit");
   window.resize(300, 70);

   QDateEdit *dateEdit = new QDateEdit();
   dateEdit->setDate(QDate::currentDate());
   dateEdit->setCalendarPopup(true);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(dateEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << dateEdit->date();
   });

   window.show();
   return app.exec();
}


