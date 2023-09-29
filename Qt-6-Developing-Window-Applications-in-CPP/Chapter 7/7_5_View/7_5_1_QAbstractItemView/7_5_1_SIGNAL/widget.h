#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStringListModel>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_activated(const QModelIndex&);
   void on_clicked(const QModelIndex&);
   void on_doubleClicked(const QModelIndex&);
   void on_entered(const QModelIndex&);
   void on_pressed(const QModelIndex&);
   void on_viewportEntered();

private:
   QListView *view;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H

