#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStandardItemModel>
#include <QTreeView>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTreeView");
   window.resize(500, 400);

   QTreeView *view = new QTreeView();
   QStandardItemModel *model = new QStandardItemModel(&window);
   model->setColumnCount(4);

   QStandardItem *parent = new QStandardItem(3, 4);
   parent->setText("Элемент-родитель");
   for (int row = 0; row < 3; ++row) {
      for (int col = 0; col < 4; ++col) {
         QStandardItem *item = new QStandardItem(
                        QString("%1, %2").arg(row).arg(col));
         parent->setChild(row, col, item);
      }
   }
   model->appendRow(parent);

   parent->setSelectable(false);

   QStandardItem *item2 = new QStandardItem("Пункт нельзя выделить");
   item2->setSelectable(false);
   model->appendRow(item2);

   QStandardItem *item3 = new QStandardItem("Пункт нельзя редактировать");
   item3->setEditable(false);
   model->appendRow(item3);

   QStandardItem *item4 = new QStandardItem("С пунктом нельзя взаимодействовать");
   item4->setEnabled(false);
   model->appendRow(item4);

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



