#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   comboBox = new QComboBox();
   comboBox->setEditable(true);
   for (int i = 1; i < 11; ++i) {
      comboBox->addItem(QString("Пункт %1").arg(i));
   }

   btn1 = new QPushButton("Получить значение");

   vbox = new QVBoxLayout();
   vbox->addWidget(comboBox);
   vbox->addWidget(btn1);
   setLayout(vbox);

   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(comboBox, SIGNAL(activated(int)),
           this, SLOT(on_activated(int)));
   connect(comboBox, SIGNAL(textActivated(QString)),
           this, SLOT(on_textActivated(QString)));
   connect(comboBox, SIGNAL(currentIndexChanged(int)),
           this, SLOT(on_currentIndexChanged(int)));
   connect(comboBox, SIGNAL(currentTextChanged(QString)),
           this, SLOT(on_currentTextChanged(QString)));
   connect(comboBox, SIGNAL(editTextChanged(QString)),
           this, SLOT(on_editTextChanged(QString)));
   connect(comboBox, SIGNAL(highlighted(int)),
           this, SLOT(on_highlighted(int)));
   connect(comboBox, SIGNAL(textHighlighted(QString)),
           this, SLOT(on_textHighlighted(QString)));
}

Widget::~Widget() {}

void Widget::on_btn1_clicked()
{
   comboBox->setCurrentIndex(3);
}

void Widget::on_activated(int index)
{
   qDebug() << "on_activated" << index;
}

void Widget::on_textActivated(const QString &text)
{
   qDebug() << "on_textActivated" << text;
}

void Widget::on_currentIndexChanged(int index)
{
   qDebug() << "on_currentIndexChanged" << index;
}

void Widget::on_currentTextChanged(const QString &text)
{
   qDebug() << "on_currentTextChanged" << text;
}

void Widget::on_editTextChanged(const QString &text)
{
   qDebug() << "on_editTextChanged" << text;
}

void Widget::on_highlighted(int index)
{
   qDebug() << "on_highlighted" << index;
}

void Widget::on_textHighlighted(const QString &text)
{
   qDebug() << "on_textHighlighted" << text;
}
