#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStandardItemModel>
#include <QTableView>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTableView");
   window.resize(500, 200);

   QTableView *view = new QTableView();
   QStandardItemModel *model = new QStandardItemModel(&window);
   model->setRowCount(4);
   model->setColumnCount(4);
   view->setSelectionBehavior(QAbstractItemView::SelectItems);
   for (int row = 0, r = model->rowCount(); row < r; ++row) {
      for (int col = 0, c = model->columnCount(); col < c; ++col) {
         QStandardItem *item = new QStandardItem(
                        QString("%1, %2").arg(row).arg(col));
         model->setItem(row, col, item);
      }
   }
   view->setModel(model);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      QItemSelectionModel *m = view->selectionModel();
      QModelIndexList list = m->selectedIndexes();
      for (int i = 0, c = list.size(); i < c; ++i) {
         QModelIndex ind = list[i];
         if (ind.isValid()) {
            qDebug() << "Данные:" << ind.data().toString();
            qDebug() << "row:" << ind.row() << "column:" << ind.column();
         }
      }
      if (list.size() == 0) {
         qDebug() << "Нет выделенных элементов";
      }
   });

   window.show();
   return app.exec();
}







