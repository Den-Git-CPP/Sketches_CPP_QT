#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   view = new QListView();
   view->setMouseTracking(true);
   QStringList list;
   for (int i = 1; i < 11; ++i) {
      list << QString("Пункт %1").arg(i);
   }
   QStringListModel *model = new QStringListModel(list, this);
   view->setModel(model);

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(view, SIGNAL(activated(QModelIndex)),
           this, SLOT(on_activated(QModelIndex)));
   connect(view, SIGNAL(clicked(QModelIndex)),
           this, SLOT(on_clicked(QModelIndex)));
   connect(view, SIGNAL(doubleClicked(QModelIndex)),
           this, SLOT(on_doubleClicked(QModelIndex)));
   connect(view, SIGNAL(entered(QModelIndex)),
           this, SLOT(on_entered(QModelIndex)));
   connect(view, SIGNAL(pressed(QModelIndex)),
           this, SLOT(on_pressed(QModelIndex)));
   connect(view, SIGNAL(viewportEntered()),
           this, SLOT(on_viewportEntered()));
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

void Widget::on_activated(const QModelIndex &m)
{
   qDebug() << "on_activated" << m.data();
}

void Widget::on_clicked(const QModelIndex &m)
{
   qDebug() << "on_clicked" << m.data();
}

void Widget::on_doubleClicked(const QModelIndex &m)
{
   qDebug() << "on_doubleClicked" << m.data();
}

void Widget::on_entered(const QModelIndex &m)
{
   qDebug() << "on_entered" << m.data();
}

void Widget::on_pressed(const QModelIndex &m)
{
   qDebug() << "on_pressed" << m.data();
}

void Widget::on_viewportEntered()
{
   qDebug() << "on_viewportEntered";
}
