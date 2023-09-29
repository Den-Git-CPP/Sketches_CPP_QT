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
   view->expandAll();

   QPushButton *btn1 = new QPushButton("Скрыть все дочерние элементы");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      view->collapseAll();
   });

   window.show();
   return app.exec();
}
