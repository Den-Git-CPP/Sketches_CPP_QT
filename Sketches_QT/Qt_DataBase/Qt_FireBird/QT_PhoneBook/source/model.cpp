#include "include/model.h"

Model::Model (QObject* parent) : QSqlTableModel{ parent } {}

QVariant Model::data (const QModelIndex& idx, int role) const
{
    if (idx.isValid () && (idx.column () == 0 || idx.column () == 2) && role == Qt::DisplayRole) {
        QString result = QSqlTableModel::data (idx, role).toString ();
        result.replace ("%20", " ");
        return result;
    }
    return QSqlTableModel::data (idx, role);
}
