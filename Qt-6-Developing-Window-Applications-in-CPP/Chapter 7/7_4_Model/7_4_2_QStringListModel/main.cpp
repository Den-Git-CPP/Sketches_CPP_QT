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
   window.resize(350, 200);

   QListView *listView = new QListView();
   QStringList list;
   for (int i = 1; i < 11; ++i) {
      list << QString("Пункт %1").arg(i);
   }
   QStringListModel *model = new QStringListModel(list, &window);
   model->insertRows(1, 1);
   QModelIndex ind = model->index(1);
   model->setData(ind, QString("Новый элемент"));
   model->sort(0, Qt::DescendingOrder);
   listView->setModel(model);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(listView);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      QModelIndex ind = listView->currentIndex();
      if (ind.isValid()) {
         qDebug() << "Данные:" << ind.data();
         qDebug() << "row:" << ind.row();
      }
      else {
         qDebug() << "Нет текущего элемента";
      }
   });

   window.show();
   return app.exec();
}



