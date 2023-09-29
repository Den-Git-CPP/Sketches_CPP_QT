#include "widget.h"

#include <QFontDialog>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   btn1 = new QPushButton("Отобразить диалоговое окно...");
   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   bool ok;
   QFont font = QFontDialog::getFont(&ok, QFont("Tahoma", 16),
                                     this, "Заголовок окна");
   if (ok) {
      qDebug() << font.family() << font.pointSize();
   }
}

