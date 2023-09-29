#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QPushButton>
#include <QTextCharFormat>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QCalendarWidget");
   window.resize(300, 70);

   QCalendarWidget *calendar = new QCalendarWidget();
   QTextCharFormat f;
   f.setFont(QFont("Tahoma", 16, QFont::Bold));
   f.setBackground(QBrush(QColor("green")));
   calendar->setHeaderTextFormat(f);

   QPushButton *btn1 = new QPushButton("Вывести значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(calendar);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      qDebug() << calendar->selectedDate();
   });

   window.show();
   return app.exec();
}

