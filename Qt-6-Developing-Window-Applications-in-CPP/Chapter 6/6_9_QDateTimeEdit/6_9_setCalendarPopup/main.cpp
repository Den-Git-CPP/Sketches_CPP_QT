#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QDateTimeEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QDateTimeEdit");
   window.resize(300, 70);

   QDateTimeEdit *dateTimeEdit = new QDateTimeEdit();
   QDateTime dt = QDateTime::currentDateTime();
   dateTimeEdit->setDateTime(dt);
   dateTimeEdit->setCalendarPopup(true);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(dateTimeEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << dateTimeEdit->dateTime();
   });

   window.show();
   return app.exec();
}


