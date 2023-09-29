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
   window.resize(200, 200);

   QListView *view = new QListView();
   view->setLayoutMode(QListView::Batched);
   view->setBatchSize(100);

   QStringList list;
   for (int i = 1; i < 100001; ++i) {
      list << QString("Пункт %1").arg(i);
   }
   QStringListModel *model = new QStringListModel(list, &window);

   QStringList list2;
   for (int i = 1; i < 11; ++i) {
      list2 << QString("Пункт %1").arg(i);
   }
   QStringListModel *model2 = new QStringListModel(list2, &window);

   view->setModel(model2);

   QPushButton *btn1 = new QPushButton("Установить модель");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      view->setModel(model);
      btn1->setEnabled(false);
   });

   window.show();
   return app.exec();
}
