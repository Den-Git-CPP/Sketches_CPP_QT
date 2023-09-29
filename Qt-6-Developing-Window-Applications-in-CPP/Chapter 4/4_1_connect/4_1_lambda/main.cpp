#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

void on_clicked() {
   qDebug() << "Нажата кнопка 1. on_clicked()";
}
void on_clicked2() {
   qDebug() << "Нажата кнопка 1. on_clicked2()";
}

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Назначение обработчиков сигналов");
   window.resize(350, 70);

   QPushButton *btn1 = new QPushButton("Кнопка 1");
   QPushButton *btn2 = new QPushButton("Кнопка 2");
   QVBoxLayout *vbox = new QVBoxLayout();

   vbox->addWidget(btn1);
   vbox->addWidget(btn2);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, on_clicked);
   QObject::connect(btn1, &QPushButton::clicked, on_clicked2);
   //Lambda
   QObject::connect(btn2, &QPushButton::clicked,
      [=]() {
         qDebug() << "Нажата кнопка 2";
      });
   window.show();

   return app.exec();
}

