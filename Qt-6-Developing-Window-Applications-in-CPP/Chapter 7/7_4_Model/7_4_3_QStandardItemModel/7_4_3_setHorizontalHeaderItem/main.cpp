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
   model->setRowCount(3);
   model->setColumnCount(4);
   for (int row = 0, r = model->rowCount(); row < r; ++row) {
      for (int col = 0, c = model->columnCount(); col < c; ++col) {
         QStandardItem *item = new QStandardItem(
                        QString("%1, %2").arg(row).arg(col));
         model->setItem(row, col, item);
      }
   }
   model->setHorizontalHeaderItem(0, new QStandardItem("A"));
   model->setHorizontalHeaderItem(1, new QStandardItem("B"));
   model->setHorizontalHeaderItem(2, new QStandardItem("C"));
   model->setHorizontalHeaderItem(3, new QStandardItem("D"));

   model->setVerticalHeaderItem(0, new QStandardItem("01"));
   model->setVerticalHeaderItem(1, new QStandardItem("02"));
   model->setVerticalHeaderItem(2, new QStandardItem("03"));
   view->setModel(model);

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
      }
      else {
         qDebug() << "Нет текущего элемента";
      }
   });

   window.show();
   return app.exec();
}



