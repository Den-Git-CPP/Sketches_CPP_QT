#pragma once
#include <QStyledItemDelegate>
#include <QDebug>
#include <QTableView>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QComboBox>

class ComboDelegate : public QStyledItemDelegate {
    Q_DISABLE_COPY (ComboDelegate)
  public:
    ComboDelegate (QObject* parent = nullptr);
    QAbstractItemModel* comboModel () const;

    void setComboModel (QAbstractItemModel* comboModel);
    int comboColumn () const;
    void setComboColumn (int comboColumn);

    QWidget* createEditor (QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex&) const override;
    void setEditorData (QWidget* editor, const QModelIndex& index) const override;
    void setModelData (QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;
    void updateEditorGeometry (QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex&) const override;

  private:
    QAbstractItemModel* m_comboModel;
    int m_comboColumn;
};
