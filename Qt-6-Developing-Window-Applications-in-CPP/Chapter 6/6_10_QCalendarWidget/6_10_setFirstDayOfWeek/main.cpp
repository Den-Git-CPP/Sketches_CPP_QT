#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QCalendarWidget");
   window.resize(300, 70);

   QCalendarWidget *calendar = new QCalendarWidget();
   calendar->setFirstDayOfWeek(Qt::Sunday);

   QPushButton *btn1 = new QPushButton("Вывести значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(calendar);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << calendar->selectedDate();
      qDebug() << calendar->yearShown() << calendar->monthShown();
   });

   window.show();
   return app.exec();
}

