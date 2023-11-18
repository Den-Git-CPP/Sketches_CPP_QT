#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QClipboard>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_cut();
   void on_paste();
   void on_change_clipboard();
private:
   QLineEdit *lineEdit;
   QPushButton *btnCut;
   QPushButton *btnPaste;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
