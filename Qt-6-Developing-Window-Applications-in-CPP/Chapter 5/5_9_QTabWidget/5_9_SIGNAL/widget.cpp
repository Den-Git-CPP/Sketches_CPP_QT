#include "widget.h"

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   tab = new QTabWidget();
   label1 = new QLabel("Содержимое вкладки 1");
   label2 = new QLabel("Содержимое вкладки 2");
   tab->addTab(label1, "Вкладка &1");
   tab->addTab(label2, "Вкладка &2");
   tab->setTabsClosable(true);
   tab->setCurrentIndex(0);
   btn1 = new QPushButton("Получить значение");
   vbox = new QVBoxLayout();
   vbox->addWidget(tab);
   vbox->addWidget(btn1);
   setLayout(vbox);
   connect(btn1, SIGNAL(clicked()),
           this, SLOT(on_btn1_clicked()));
   connect(tab, SIGNAL(currentChanged(int)),
           this, SLOT(on_current_changed(int)));
   connect(tab, SIGNAL(tabCloseRequested(int)),
           this, SLOT(on_tab_close(int)));

   connect(tab, SIGNAL(tabBarClicked(int)),
           this, SLOT(on_tabBarClicked(int)));
   connect(tab, SIGNAL(tabBarDoubleClicked(int)),
           this, SLOT(on_tabBarDoubleClicked(int)));
}

void Widget::on_btn1_clicked()
{
   qDebug() << tab->tabsClosable();
}

void Widget::on_tab_close(int index)
{
   qDebug() << "on_tab_close" << index;
}

void Widget::on_current_changed(int index)
{
   qDebug() << "on_current_changed" << index;
}

void Widget::on_tabBarClicked(int index)
{
   qDebug() << "on_tabBarClicked" << index;
}

void Widget::on_tabBarDoubleClicked(int index)
{
   qDebug() << "on_tabBarDoubleClicked" << index;
}

Widget::~Widget() {}
