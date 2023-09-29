#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   comboBox = new QFontComboBox();

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(comboBox);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(comboBox, SIGNAL(currentFontChanged(QFont)),
           this, SLOT(on_currentFontChanged(QFont)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   qDebug() << comboBox->currentFont().family();
}

void Widget::on_currentFontChanged(const QFont &f)
{
   qDebug() << "on_currentFontChanged" << f.family();
}
