#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QSortFilterProxyModel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QSortFilterProxyModel");
   window.resize(600, 500);

   QTableView *view1 = new QTableView();
   QTableView *view2 = new QTableView();
   view1->setSortingEnabled(true);

   QStandardItemModel *model = new QStandardItemModel(&window);
   model->setRowCount(4);
   model->setColumnCount(4);
   for (int row = 0, r = model->rowCount(); row < r; ++row) {
      for (int col = 0, c = model->columnCount(); col < c; ++col) {
         QStandardItem *item = new QStandardItem(
                        QString("%1, %2").arg(row).arg(col));
         model->setItem(row, col, item);
      }
   }
   QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(&window);
   proxyModel->setSourceModel(model);

   view1->setModel(proxyModel);
   view2->setModel(model);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view1);
   vbox->addWidget(view2);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {

   });

   window.show();
   return app.exec();
}



