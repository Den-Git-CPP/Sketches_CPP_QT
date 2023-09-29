#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_changed(int, int);
   void on_finished();
   void on_return();
   void on_selection();
   void on_text_changed(const QString&);
   void on_text_edited(const QString&);
private:
   QLineEdit *lineEdit;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
