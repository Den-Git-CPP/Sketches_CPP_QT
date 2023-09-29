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
   dateTimeEdit->setDateTime(QDateTime::currentDateTime());

   QPushButton *btn1 = new QPushButton("Сделать текущей секцию с годом");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(dateTimeEdit);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      dateTimeEdit->setFocus();
      dateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);
      //dateTimeEdit->setCurrentSectionIndex(2);
   });

   window.show();
   return app.exec();
}


