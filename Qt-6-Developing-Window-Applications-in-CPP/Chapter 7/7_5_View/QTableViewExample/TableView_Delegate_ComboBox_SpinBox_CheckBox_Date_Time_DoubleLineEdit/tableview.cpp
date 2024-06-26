#include "tableview.h"

#include <QStandardItemModel>

#include "itemdelegate.h"

#define MAXCOL 6

TableView::TableView (QStringList items)
{
    resize (600, 300);

    model = new QStandardItemModel (4, MAXCOL);
    setModel (model);

    model->setHeaderData (0, Qt::Horizontal, QObject::tr ("Имя"));
    model->setHeaderData (1, Qt::Horizontal, QObject::tr ("День рождения"));
    model->setHeaderData (2, Qt::Horizontal, QObject::tr ("Профессия"));
    model->setHeaderData (3, Qt::Horizontal, QObject::tr ("Доход"));
    model->setHeaderData (4, Qt::Horizontal, QObject::tr ("Дата"));
    model->setHeaderData (5, Qt::Horizontal, QObject::tr ("Время"));

#if 1
    for (int col = 0; col < MAXCOL; ++col) {
        if (col == 0) {
            ReadOnlyDelegate* readOnly = new ReadOnlyDelegate;
            setItemDelegateForColumn (col, readOnly);
        }
        if (col == 1) {
            DoubleLineEditDelegate* lineEdit = new DoubleLineEditDelegate;
            lineEdit->setRange (0, 999, 6);
            setItemDelegateForColumn (col, lineEdit);
        }
        if (col == 2) {
            SpinBoxDelegate* spinBox = new SpinBoxDelegate;
            setItemDelegateForColumn (col, spinBox);
        }
        if (col == 3) {
            ComboDelegate* combo = new ComboDelegate;
            combo->setItems (items);
            setItemDelegateForColumn (col, combo);
        }
        if (col == 4) {
            DateDelegate* date = new DateDelegate;
            setItemDelegateForColumn (col, date);
        }
        if (col == 5) {
            TimeDelegate* time = new TimeDelegate;
            setItemDelegateForColumn (col, time);
        }
        for (int row = 0; row < 4; ++row) {
            QModelIndex index = model->index (row, col, QModelIndex ());
            if (col == 1)
                model->setData (index, 0);
            else
                model->setData (index, QString ("%1%2").arg (row).arg (col));
        }
    }
#else
    QFile file ("E:\Qt\MyDelegate\a.txt");
    QTextStream out (&file);
    if (!file.open (QIODevice::ReadOnly | QIODevice::Text)) return;
    while (out.atEnd ()) {
        QString data         = out.readLine ();
        QStringList dataList = data.split (",");
        int rows             = model->rowCount ();
        model->setRowCount (rows + 1);
        for (int col = 0; col < 4; ++col) {
            QModelIndex index = model->index (rows, col, QModelIndex ());
            model->setData (index, dataList.at (col));
        }
    }
#endif
}

QString TableView::GetItemData (int row, int col)
{
    QModelIndex index = model->index (row, col, QModelIndex ());
    return model->data (index).toString ();
}
