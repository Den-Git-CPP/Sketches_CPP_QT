#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   spinBox = new QSpinBox();
   spinBox->setRange(0, 100);
   spinBox->setValue(10);
   spinBox->setSingleStep(5);
   spinBox->setPrefix("текст до (");
   spinBox->setSuffix(") текст после");

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(spinBox);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(spinBox, SIGNAL(valueChanged(int)),
           this, SLOT(on_valueChanged(int)));
   connect(spinBox, SIGNAL(textChanged(QString)),
           this, SLOT(on_textChanged(QString)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   qDebug() << spinBox->text();
   qDebug() << spinBox->prefix();
   qDebug() << spinBox->suffix();
   qDebug() << spinBox->value();
   qDebug() << spinBox->cleanText();
}

void Widget::on_valueChanged(int n)
{
   qDebug() << "on_valueChanged" << n;
}

void Widget::on_textChanged(const QString &s)
{
   qDebug() << "on_textChanged" << s;
}
