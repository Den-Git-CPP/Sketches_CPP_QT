#include <QApplication>
#include "ComboBoxDelegate.h"

int main (int argc, char* argv [])
{
    QApplication app (argc, argv);
    QWidget wid;
    QAbstractItemModel* table1 = new QStandardItemModel (&wid);
    table1->insertColumns (0, 2);
    table1->insertRows (0, 10);
    for (int i = 0; i < table1->rowCount (); ++i) {
        table1->setData (table1->index (i, 0), i + 1);
        table1->setData (table1->index (i, 1), QChar ('A' + i + 1));
    }

    QAbstractItemModel* table2 = new QStandardItemModel (&wid);
    table2->insertColumns (0, 2);
    table2->insertRows (0, 10);
    for (int i = 0; i < table2->rowCount (); ++i) {
        table2->setData (table2->index (i, 0), i + 100);
        table2->setData (table2->index (i, 1), QChar ('a' + i + 1));
    }
    QAbstractItemModel* table3 = new QStandardItemModel (&wid);
    table3->insertColumns (0, 2);
    table3->insertRows (0, 10);

    QTableView* table1View = new QTableView (&wid);
    table1View->setModel (table1);
    QTableView* table2View = new QTableView (&wid);
    table2View->setModel (table2);
    QTableView* table3View = new QTableView (&wid);
    table3View->setModel (table3);
    ComboDelegate* delegate1 = new ComboDelegate (table3);
    delegate1->setComboModel (table1);
    delegate1->setComboColumn (1);
    ComboDelegate* delegate2 = new ComboDelegate (table3);
    delegate2->setComboModel (table2);
    delegate2->setComboColumn (0);
    table3View->setItemDelegateForColumn (0, delegate1);
    table3View->setItemDelegateForColumn (1, delegate2);
    QHBoxLayout* lay = new QHBoxLayout (&wid);
    lay->addWidget (table1View);
    lay->addWidget (table2View);
    lay->addWidget (table3View);
    wid.show ();
    return app.exec ();
}
