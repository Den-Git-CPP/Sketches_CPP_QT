#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   view = new QTableView();
   QStandardItemModel *model = new QStandardItemModel(this);
   model->setRowCount(3);
   model->setColumnCount(4);
   for (int row = 0, r = model->rowCount(); row < r; ++row) {
      for (int col = 0, c = model->columnCount(); col < c; ++col) {
         QStandardItem *item = new QStandardItem(
                        QString("%1, %2").arg(row).arg(col));
         model->setItem(row, col, item);
      }
   }
   view->setModel(model);
   QStringList list;
   list << "A" << "B" << "C" << "D";
   model->setHorizontalHeaderLabels(list);
   QStringList list2;
   list2 << "01" << "02" << "03";
   model->setVerticalHeaderLabels(list2);

   QItemSelectionModel *selModel = new QItemSelectionModel(model, this);
   view->setSelectionModel(selModel);

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(selModel, SIGNAL(currentChanged(QModelIndex,QModelIndex)),
           this, SLOT(on_currentChanged(QModelIndex,QModelIndex)));
   connect(selModel, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
           this, SLOT(on_currentRowChanged(QModelIndex,QModelIndex)));
   connect(selModel, SIGNAL(currentColumnChanged(QModelIndex,QModelIndex)),
           this, SLOT(on_currentColumnChanged(QModelIndex,QModelIndex)));
   connect(selModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
           this, SLOT(on_selectionChanged(QItemSelection,QItemSelection)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   view->setFocus();
   view->selectionModel()->clearSelection();
}

void Widget::on_currentChanged(const QModelIndex &ind1, const QModelIndex &ind2)
{
   qDebug() << "on_currentChanged" << ind1 << ind2;
}

void Widget::on_currentRowChanged(const QModelIndex &ind1, const QModelIndex &ind2)
{
   qDebug() << "on_currentRowChanged" << ind1 << ind2;
}

void Widget::on_currentColumnChanged(const QModelIndex &ind1, const QModelIndex &ind2)
{
   qDebug() << "on_currentColumnChanged" << ind1 << ind2;
}

void Widget::on_selectionChanged(const QItemSelection &, const QItemSelection &)
{
   qDebug() << "on_selectionChanged";
}
