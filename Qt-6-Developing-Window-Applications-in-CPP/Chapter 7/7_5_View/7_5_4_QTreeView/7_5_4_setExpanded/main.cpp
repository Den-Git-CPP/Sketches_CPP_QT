#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStandardItemModel>
#include <QTreeView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTreeView");
   window.resize(500, 400);

   QTreeView *view = new QTreeView();
   QStandardItemModel *model = new QStandardItemModel(&window);
   model->setColumnCount(4);
   QStandardItem *parent = model->invisibleRootItem();
   for (int i = 0; i < 4; ++i) {
      QStandardItem *item = new QStandardItem(QString("Пункт %1-1").arg(i));
      parent->appendRow(item);
      parent = item;
   }

   parent = new QStandardItem(3, 4);
   parent->setText("Элемент-родитель");
   for (int row = 0; row < 3; ++row) {
      for (int col = 0; col < 4; ++col) {
         QStandardItem *item = new QStandardItem(
                        QString("%1, %2").arg(row).arg(col));
         parent->setChild(row, col, item);
      }
   }
   model->appendRow(parent);
   view->setModel(model);

   view->setColumnWidth(0, 200);
   view->setExpanded(view->model()->index(0, 0), true);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      QModelIndex ind = view->currentIndex();
      if (ind.isValid()) {
         qDebug() << "Данные:" << ind.data().toString();
         qDebug() << "row:" << ind.row() << "column:" << ind.column();
         QModelIndex ind_parent = ind.parent();
         if (ind_parent.isValid()) {
            qDebug() << "Родитель:" << ind_parent.data();
         }
         else {
            qDebug() << "Нет родителя";
         }
      }
      else {
         qDebug() << "Нет текущего элемента";
      }
   });

   window.show();
   return app.exec();
}
