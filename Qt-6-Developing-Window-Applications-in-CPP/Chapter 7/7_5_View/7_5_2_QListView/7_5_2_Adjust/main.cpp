#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QListView");
   window.resize(500, 200);

   QListView *view = new QListView();
   view->setSelectionMode(QAbstractItemView::ExtendedSelection);
   view->setViewMode(QListView::IconMode);
   view->setResizeMode(QListView::Adjust);

   QStandardItemModel *model = new QStandardItemModel(&window);
   model->setRowCount(6);
   model->setColumnCount(1);

   QIcon icon1 = window.style()->standardIcon(QStyle::SP_MessageBoxCritical);
   QStandardItem *item1 = new QStandardItem(icon1, QString("1"));
   model->setItem(0, 0, item1);

   QIcon icon2 = window.style()->standardIcon(QStyle::SP_MessageBoxInformation);
   QStandardItem *item2 = new QStandardItem(icon2, QString("2"));
   model->setItem(1, 0, item2);

   QIcon icon3 = window.style()->standardIcon(QStyle::SP_MessageBoxWarning);
   QStandardItem *item3 = new QStandardItem(icon3, QString("3"));
   model->setItem(2, 0, item3);

   QIcon icon4 = window.style()->standardIcon(QStyle::SP_MessageBoxQuestion);
   QStandardItem *item4 = new QStandardItem(icon4, QString("4"));
   model->setItem(3, 0, item4);

   QIcon icon5 = window.style()->standardIcon(QStyle::SP_ComputerIcon);
   QStandardItem *item5 = new QStandardItem(icon5, QString("5"));
   model->setItem(4, 0, item5);

   QIcon icon6 = window.style()->standardIcon(QStyle::SP_DesktopIcon);
   QStandardItem *item6 = new QStandardItem(icon6, QString("6"));
   model->setItem(5, 0, item6);

   view->setModel(model);
   view->setModelColumn(0);

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
            qDebug() << "row:" << ind.row();
         }
      }
      if (list.size() == 0) {
         qDebug() << "Нет выделенных элементов";
      }
   });

   window.show();
   return app.exec();
}
