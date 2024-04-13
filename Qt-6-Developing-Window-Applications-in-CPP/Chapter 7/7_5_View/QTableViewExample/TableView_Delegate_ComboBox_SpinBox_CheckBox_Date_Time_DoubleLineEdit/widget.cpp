#include "widget.h"
#include "ui_widget.h"

#include <QStandardItemModel>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QFile>
#include <QTextStream>

#include "tableview.h"

Widget::Widget (QWidget* parent) : QWidget (parent), ui (new Ui::Widget)
{
    ui->setupUi (this);
    resize (500, 300);

    QHBoxLayout* hlayout = new QHBoxLayout (this);
    m_pTabWidget         = new QTabWidget (this);
    hlayout->addWidget (m_pTabWidget);

    QPushButton* btn = new QPushButton (tr ("Получить данные"), this);
    connect (btn, SIGNAL (clicked (bool)), this, SLOT (onBtn_clicked ()));
    hlayout->addWidget (btn);

    QStringList items;
    items.append ("музыка");
    items.append ("искусство");
    items.append ("физическая культура");
    items.append ("Производительность");
    TableView* table1 = new TableView (items);
    m_pTabWidget->addTab (table1, tr ("tab1"));

    items.clear ();
    items.append ("музыка1");
    items.append ("искусство1");
    items.append ("физическая культура1");
    items.append ("Производительность1");
    TableView* table2 = new TableView (items);
    m_pTabWidget->addTab (table2, tr ("tab2"));

    setLayout (hlayout);
}

Widget::~Widget ()
{
    delete ui;
}

void Widget::onBtn_clicked ()
{
    TableView* table = static_cast<TableView*> (m_pTabWidget->currentWidget ());
    for (int row = 0; row < 4; ++row) {
        QString data = table->GetItemData (0, row);
        qDebug () << "data:" << data;
    }
}
