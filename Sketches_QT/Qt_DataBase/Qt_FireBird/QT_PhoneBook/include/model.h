#pragma once

#include <QObject>
#include <QSqlTableModel>

class Model : public QSqlTableModel {
  public:
    explicit Model (QObject* parent = nullptr);
    QVariant data (const QModelIndex& idx, int role) const;
};
