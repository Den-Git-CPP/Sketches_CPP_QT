#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHeaderView>
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
   void on_sectionPressed(int);
   void on_sectionClicked(int);
   void on_sectionDoubleClicked(int);
   void on_sectionMoved(int,int,int);
   void on_sectionResized(int,int,int);

private:
   QTableView *view;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H

