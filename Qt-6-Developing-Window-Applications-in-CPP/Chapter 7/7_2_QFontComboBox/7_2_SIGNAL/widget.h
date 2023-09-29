#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFontComboBox>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_currentFontChanged(const QFont&);

private:
   QFontComboBox *comboBox;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H

