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

   QHeaderView *hHeader = view->horizontalHeader();
   hHeader->setSectionsMovable(true);

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(hHeader, SIGNAL(sectionPressed(int)),
           this, SLOT(on_sectionPressed(int)));
   connect(hHeader, SIGNAL(sectionClicked(int)),
           this, SLOT(on_sectionClicked(int)));
   connect(hHeader, SIGNAL(sectionDoubleClicked(int)),
           this, SLOT(on_sectionDoubleClicked(int)));
   connect(hHeader, SIGNAL(sectionMoved(int,int,int)),
           this, SLOT(on_sectionMoved(int,int,int)));
   connect(hHeader, SIGNAL(sectionResized(int,int,int)),
           this, SLOT(on_sectionResized(int,int,int)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
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
   };
}

void Widget::on_sectionPressed(int ind)
{
   qDebug() << "on_sectionPressed" << ind;
}

void Widget::on_sectionClicked(int ind)
{
   qDebug() << "on_sectionClicked" << ind;
}

void Widget::on_sectionDoubleClicked(int ind)
{
   qDebug() << "on_sectionDoubleClicked" << ind;
}

void Widget::on_sectionMoved(int ind, int o, int n)
{
   qDebug() << "on_sectionMoved" << ind << o << n;
}

void Widget::on_sectionResized(int ind, int o, int n)
{
   qDebug() << "on_sectionResized" << ind << o << n;
}
