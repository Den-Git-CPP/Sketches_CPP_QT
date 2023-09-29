#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStringListModel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QListView");
   window.resize(500, 200);

   QListView *view = new QListView();
   QStringList list;
   for (int i = 1; i < 101; ++i) {
      list << QString("Пункт %1").arg(i);
   }
   QStringListModel *model = new QStringListModel(list, &window);

   view->setModel(model);

   QPushButton *btn1 = new QPushButton("Сделать элемент с индексом 50 текущим");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      view->setFocus();
      view->setCurrentIndex(model->index(50));
   });

   window.show();
   return app.exec();
}



