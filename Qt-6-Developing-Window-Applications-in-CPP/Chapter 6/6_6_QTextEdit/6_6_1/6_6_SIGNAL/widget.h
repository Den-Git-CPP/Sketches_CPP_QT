#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_copy(bool);
   void on_undo(bool);
   void on_redo(bool);
   void on_format_changed(const QTextCharFormat&);
   void on_position_changed();
   void on_selection_changed();
   void on_text_changed();

private:
   QTextEdit *textEdit;
   QPushButton *btn1;
   QVBoxLayout *vbox;
};
#endif // WIDGET_H
