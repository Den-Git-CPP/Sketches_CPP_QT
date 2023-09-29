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
   window.resize(600, 200);

   QListView *view = new QListView();
   view->setDragDropMode(QAbstractItemView::DragDrop);
   view->setDefaultDropAction(Qt::MoveAction);
   QStringList list;
   for (int i = 1; i < 11; ++i) {
      list << QString("Пункт %1").arg(i);
   }
   QStringListModel *model = new QStringListModel(list, &window);
   view->setModel(model);

   QListView *view2 = new QListView();
   view2->setDragDropMode(QAbstractItemView::DropOnly);
   QStringList list2;
   QStringListModel *model2 = new QStringListModel(list2, &window);
   view2->setModel(model2);

   QHBoxLayout *vbox = new QHBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(view2);
   window.setLayout(vbox);

   window.show();
   return app.exec();
}



