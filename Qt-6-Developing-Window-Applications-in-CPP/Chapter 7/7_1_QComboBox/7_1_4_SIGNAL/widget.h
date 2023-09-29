#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_activated(int);
   void on_textActivated(const QString&);
   void on_currentIndexChanged(int);
   void on_currentTextChanged(const QString&);
   void on_editTextChanged(const QString&);
   void on_highlighted(int);
   void on_textHighlighted(const QString&);
private:
   QComboBox *comboBox;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H

