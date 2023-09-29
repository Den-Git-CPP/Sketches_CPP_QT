#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_currentChanged(const QModelIndex&, const QModelIndex&);
   void on_currentRowChanged(const QModelIndex&, const QModelIndex&);
   void on_currentColumnChanged(const QModelIndex&, const QModelIndex&);
   void on_selectionChanged(const QItemSelection&, const QItemSelection&);

private:
   QTableView *view;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H

